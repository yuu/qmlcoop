#pragma once

#include <QtCore/qdebug.h>
#include <QtCore/qobject.h>
#include <QtQml/qqml.h>
#include <QtQml/qqmlextensionplugin.h>
#include <QtCore/QList>
#include <QtGui/QOpenGLContext>

#include <array>

#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/lu.hpp>
#include <boost/numeric/ublas/matrix.hpp>

namespace ublas = boost::numeric::ublas;

class Plug : public QObject {
    Q_OBJECT

public:
    Plug() {}

    Q_INVOKABLE QList<double> invert_matrix(double x1, double y1, double x2, double y2, double x3, double y3,
                                            double x4, double y4) {
        std::array<GLfloat, 4 * 2> before = {(GLfloat)x1, (GLfloat)y1, (GLfloat)x2, (GLfloat)y2,
                                             (GLfloat)x3, (GLfloat)y3, (GLfloat)x4, (GLfloat)y4};
        std::array<GLfloat, 4 * 2> after = {.0, .0, .0, 1., 1., 1., 1., 0.};
        ublas::matrix<GLfloat> mat(8, 8);
        ublas::vector<GLfloat> vec(8);

        for (int i = 0; i < 8; i += 2) {
            int xi = i;
            int yi = i + 1;
            mat(i, 0) = before[xi];
            mat(i, 1) = before[yi];
            mat(i, 2) = 1;
            mat(i, 3) = mat(i, 4) = mat(i, 5) = 0;
            mat(i, 6) = -(before[xi] * after[xi]);
            mat(i, 7) = -(before[yi] * after[xi]);

            mat(i + 1, 0) = mat(i + 1, 1) = mat(i + 1, 2) = 0;
            mat(i + 1, 3) = before[xi];
            mat(i + 1, 4) = before[yi];
            mat(i + 1, 5) = 1;
            mat(i + 1, 6) = -(before[xi] * after[yi]);
            mat(i + 1, 7) = -(before[yi] * after[yi]);

            vec(xi) = after[xi];
            vec(yi) = after[yi];
        }

        ublas::matrix<GLfloat> inv(8, 8);
        invert_matrix(mat, inv);

        QList<double> out;
        ublas::vector<GLfloat> hparam = ublas::prod(inv, vec);
        for (auto&& x : hparam) out.append(x);

        return out;
    }

    template <class T>
    bool invert_matrix(const ublas::matrix<T>& mat_in, ublas::matrix<T>& mat_inverse) {
        ublas::matrix<T> in(mat_in);

        ublas::permutation_matrix<std::size_t> pm(in.size1());

        lu_factorize(in, pm);

        mat_inverse.assign(ublas::identity_matrix<T>(in.size1()));
        lu_substitute(in, pm, mat_inverse);

        return true;
    }
};
