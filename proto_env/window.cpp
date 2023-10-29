#include "window.h"
#include "ui_window.h"

Window::Window(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Window)
{
    ui->setupUi(this);
    m_videoWidget = new QVideoWidget(this);
    m_camera = new QCamera((QMediaDevices::defaultVideoInput()));
    m_mediaCaptrueSession = new QMediaCaptureSession(this);


    m_videoWidget->resize(640, 480);
    m_videoWidget->show();

    m_camera->start();

    m_mediaCaptrueSession->setCamera(m_camera);
    m_mediaCaptrueSession->setVideoOutput(m_videoWidget);

}

Window::~Window()
{
    delete ui;
    delete m_camera;
    delete m_videoWidget;
    delete m_mediaCaptrueSession;
}

