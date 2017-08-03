#include <QGuiApplication>
#include <QQuickView>
#include <QtQml/QQmlEngine>

#include "plug.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // import name, import major verson, import minor version, element name
    qmlRegisterType<Plug>("com.itage", 1, 0, "Plug");

    QQuickView view;
    view.setSource(QUrl("qrc:/main.qml"));
    view.show();

    return app.exec();
}
