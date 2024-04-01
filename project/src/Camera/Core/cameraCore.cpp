#include "Camera/Core/cameraCore.h"

CameraCore::CameraCore()
{
    m_camera = new QCamera(QMediaDevices::defaultVideoInput());
    m_mediaCaptureSession = new QMediaCaptureSession(this);
    m_imageCapture = new QImageCapture();
    m_videoOutput = new QObject(this);

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
    m_mediaCaptureSession->setVideoOutput(m_videoOutput);
}

void CameraCore::stop()
{
    m_camera->stop();
}

void CameraCore::setVideoOutputToGui(QObject *videoOutput)
{
    emit videoOutputAvailable(videoOutput);
}

void CameraCore::onCaptureButtonClicked()
{
    CameraCore::start();
}

void CameraCore::onSaveImageButtonClicked(const QString &path)
{
    m_mediaCaptureSession->setImageCapture(m_imageCapture);
    m_imageCapture->captureToFile(path);
}
