#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVideoWidget>
#include <QVBoxLayout>
#include <QThread>

#include "Camera/Controller/cameraController.h"



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Allow the event loop to process events
    qApp->processEvents();

    CameraController *camController = new CameraController();
    camController->initGui();
    camController->run();


    return app.exec();
}
