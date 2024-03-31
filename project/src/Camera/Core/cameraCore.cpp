#include "Camera/Core/cameraCore.h"

void CameraCore::initialize()
{

}

void CameraCore::start()
{
    m_camera->start();
    m_mediaCaptureSession->setCamera(m_camera.data());
    m_mediaCaptureSession->setVideoOutput(m_videoOutput);
}

void CameraCore::stop()
{
    m_camera->stop();
}

const QObject *CameraCore::getVideoOutput()
{
    if(!m_videoOutput)
        return nullptr;
    return m_videoOutput;
}

void CameraCore::onCaptureButtonClicked()
{
    CameraCore::start();
}

void CameraCore::onSaveImageButtonClicked(const QString &path)
{
    m_mediaCaptureSession->setImageCapture(m_imageCapture.data());
    m_imageCapture->captureToFile(path);
}

CameraCore::CameraCore(QPushButton* display, QPushButton* save)
{
    m_camera = QSharedPointer<QCamera>(new QCamera(QMediaDevices::defaultVideoInput()));
    m_mediaCaptureSession = QSharedPointer<QMediaCaptureSession>(new QMediaCaptureSession(this));
    m_imageCapture = QSharedPointer<QImageCapture>(new QImageCapture());
    m_videoOutput = new QObject(this);

    // Connect the clicked signal of the button to the slotButtonClicked slot
    connect(display, SIGNAL(clicked()), this, SLOT(onCaptureButtonClicked()));

    // Save image
    connect(save, SIGNAL(clicked()), this, SLOT(onSaveImageButtonClicked()));
}

CameraCore::~CameraCore()
{
    CameraCore::stop();
    delete m_videoOutput;
}
