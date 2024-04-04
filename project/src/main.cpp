#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVideoWidget>
#include <QVBoxLayout>
#include <QStyleFactory>
#include <QThread>

#include "Camera/Controller/cameraController.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setStyle(QStyleFactory::create("Fusion"));

    // Allow the event loop to process events
    //qApp->processEvents();

    CameraController *camController = new CameraController();
    camController->initGui();
    camController->run();


    return app.exec();
}
