#include "cameraCore.h"

void cameraCore::initialize()
{

}

void cameraCore::start()
{
    m_camera->start();
    m_mediaCaptureSession->setCamera(m_camera.data());
}

void cameraCore::stop()
{

}

cameraCore::cameraCore()
{
    m_camera = QSharedPointer<QCamera>(new QCamera(QMediaDevices::defaultVideoInput()));
    m_mediaCaptureSession = QSharedPointer<QMediaCaptureSession>(new QMediaCaptureSession(this));
}

cameraCore::~cameraCore()
{

}
