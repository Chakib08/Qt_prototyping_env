#include "Camera/Core/cameraCore.h"

CameraCore::CameraCore()
{
    m_camera = new QCamera(QMediaDevices::defaultVideoInput());
    m_mediaCaptureSession = new QMediaCaptureSession(this);
    m_imageCapture = new QImageCapture();
}

CameraCore::~CameraCore()
{
    CameraCore::stop();
}

void CameraCore::initialize()
{

}

void CameraCore::start()
{
    m_camera->start();
    m_mediaCaptureSession->setCamera(m_camera);
}

void CameraCore::stop()
{
    m_camera->stop();
}

void CameraCore::onCaptureButtonClicked()
{
    CameraCore::start();
}

void CameraCore::onSaveImageButtonClicked()
{
    m_mediaCaptureSession->setImageCapture(m_imageCapture);
    m_imageCapture->captureToFile(m_imageSavingPath);
}

void CameraCore::onUpdatedImageSavingPath(const QString &path)
{
    m_imageSavingPath = path;
}

QMediaCaptureSession* CameraCore::getMediaCaptureSession()
{
    return m_mediaCaptureSession;
}
