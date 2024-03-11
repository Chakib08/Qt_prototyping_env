#include "cameraCore.h"

void cameraCore::initialize()
{

}

void cameraCore::start()
{
    m_camera->start();
    m_mediaCaptureSession->setCamera(m_camera.data());
    m_mediaCaptureSession->setVideoOutput(m_videoOutput);
}

void cameraCore::stop()
{
    m_camera->stop();
}

const QObject *cameraCore::getVideoOutput()
{
    if(!m_videoOutput)
        return nullptr;
    return m_videoOutput;
}

void cameraCore::onCaptureButtonClicked()
{
    start();
}

void cameraCore::onSaveImageButtonClicked()
{
    m_mediaCaptureSession->setImageCapture(m_imageCapture.data());
    m_imageCapture->captureToFile("D:/Qt_dev/Qt_prototyping_env/proto_env/img");
}

cameraCore::cameraCore(QPushButton* display, QPushButton* save)
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

cameraCore::~cameraCore()
{
    delete m_videoOutput;
    stop();
}
