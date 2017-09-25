#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QSettings>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QSettings settings;
    QQuickStyle::setStyle(settings.value("style", QQuickStyle::name()).toString());
    QStringList tempGaugeStyles = { QStringLiteral("Default"), QStringLiteral("Alternative") };

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("availableStyles", tempGaugeStyles);
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
