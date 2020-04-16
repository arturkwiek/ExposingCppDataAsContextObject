#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include "propertywrapper.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

//    QString strFirstName = "John";
//    QString strLastName = "Doe";

    PropertyWrapper propWrapper;
    QQmlApplicationEngine engine;

    propWrapper.setLastname("Doe");
    propWrapper.setFirstname("John");
//    engine.rootContext()->setContextProperty("mFirstName", QVariant::fromValue(strFirstName));
//    engine.rootContext()->setContextProperty("mLastName",QVariant::fromValue(strLastName));
    engine.rootContext()->setContextObject(&propWrapper);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
