#include <QApplication>

#include <QWidget>
#include <QPushButton>
#include <QVideoWidget>
#include <QVBoxLayout>

#include <QThread>

#include "src/core/camera/cameraCore.h"
#include "src/gui/camera/cameraGui.h"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);



    // Allow the event loop to process events
    qApp->processEvents();

    // Create CameraCore instance
    CameraCore cameraCore;

    // Create CameraGui instance
    CameraGui cameraGui;

    // Show the GUI
    cameraGui.show();

    return app.exec();
}
