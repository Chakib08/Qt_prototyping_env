// cameraCore.cpp
#include "src/core/camera/cameraCore.h"

CameraCore::CameraCore(QObject *parent) : QObject(parent), m_camera(nullptr),
    m_mediaCaptureSession(nullptr), m_imageCapture(nullptr) {
    // Initialize camera and related objects
    m_camera = new QCamera(QMediaDevices::defaultVideoInput());
    m_mediaCaptureSession = new QMediaCaptureSession(this);
    m_imageCapture = new QImageCapture(this);
    m_mediaCaptureSession->setCamera(m_camera);
    m_mediaCaptureSession->setImageCapture(m_imageCapture);
}

CameraCore::~CameraCore() {
    delete m_camera;
    delete m_mediaCaptureSession;
    delete m_imageCapture;
}

void CameraCore::startCamera() {
    if (m_camera) {
        m_camera->start();
        m_mediaCaptureSession->setVideoOutput(new QVideoWidget());
    }
}

void CameraCore::saveImage(const QString &filePath) {
    if (m_imageCapture) {
        m_imageCapture->captureToFile(filePath);
    }
}
