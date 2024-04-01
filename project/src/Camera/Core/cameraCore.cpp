#include "Camera/Core/cameraCore.h"

#include <QDebug>

CameraCore::CameraCore()
{
    m_camera = new QCamera(QMediaDevices::defaultVideoInput());
    m_mediaCaptureSession = new QMediaCaptureSession(this);
    m_imageCapture = new QImageCapture();
    m_videoOutput = new QObject(this);

    qInfo() << __func__;

    // Connect the clicked signal of the button to the slotButtonClicked slot
    //connect(display, SIGNAL(clicked()), this, SLOT(onCaptureButtonClicked()));

    // Save image
    //connect(save, SIGNAL(clicked()), this, SLOT(onSaveImageButtonClicked()));
}

CameraCore::~CameraCore()
{
    CameraCore::stop();
    delete m_videoOutput;
}

void CameraCore::initialize()
{

}

void CameraCore::start()
{
    m_camera->start();
    m_mediaCaptureSession->setCamera(m_camera);
    //setVideoOutputToGui(m_videoOutput);
    //m_mediaCaptureSession->setVideoOutput(m_videoOutput);
    qInfo() << __func__<< "start cap";
}

void CameraCore::stop()
{
    m_camera->stop();
}

void CameraCore::setVideoOutputToGui(QObject *videoOutput)
{
    qInfo() << __func__<< "emit";
    emit videoOutputAvailable(videoOutput);
}

void CameraCore::onCaptureButtonClicked()
{
    qInfo() << __func__<< "start";
    CameraCore::start();
}

void CameraCore::onSaveImageButtonClicked(const QString &path)
{
    m_mediaCaptureSession->setImageCapture(m_imageCapture);
    m_imageCapture->captureToFile(path);
}

QMediaCaptureSession* CameraCore::getMediaCaptureSession()
{
    return m_mediaCaptureSession;
}
