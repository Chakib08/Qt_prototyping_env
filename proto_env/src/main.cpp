#include <QApplication>

#include <QWidget>
#include <QPushButton>
#include <QVideoWidget>
#include <QVBoxLayout>

#include <QThread>

#include "src/core/camera/cameraCore.h"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    QWidget* w = new QWidget();
    QVBoxLayout* vBoxLyout = new QVBoxLayout(w);
    QPushButton* displayButton = new QPushButton("Display");
    QPushButton*  saveImageButton = new QPushButton("Save Image");
    QVideoWidget* videoWidget = new QVideoWidget();

    w->resize(1080, 720);
    vBoxLyout->addWidget(displayButton);
    vBoxLyout->addWidget(saveImageButton);
    vBoxLyout->addWidget(videoWidget);

    cameraCore* cam = new cameraCore(displayButton, saveImageButton);

    // Allow the event loop to process events
    qApp->processEvents();

    w->show();

    return app.exec();
}
