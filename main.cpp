#include <QGuiApplication>
#include <QQuickView>
#include <QQmlEngine>
#include <QQmlContext>
#include "message.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickView view;
    message msg;
    int age = 10;
    msg.setAge(age);
    view.engine()->rootContext()->setContextProperty("message", &msg);

    view.setSource(QUrl::fromLocalFile("main.qml"));

    QObject *obj = (QObject*)view.rootObject(); // setSorce後にcallしなければならない
    QObject::connect(obj, SIGNAL(debugPrint(QString)), &msg, SLOT(debugPrintSlot(QString)));

    view.show();

    return app.exec();
}
