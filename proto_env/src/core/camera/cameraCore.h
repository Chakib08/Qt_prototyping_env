// cameraCore.h
#ifndef CAMERACORE_H
#define CAMERACORE_H

#include <QObject>
#include <QCamera>
#include <QMediaCaptureSession>
#include <QImageCapture>
#include <QMediaDevices>
#include <QVideoWidget>

class CameraCore : public QObject {
    Q_OBJECT
public:
    explicit CameraCore(QObject *parent = nullptr);
    ~CameraCore();

    void startCamera();
    void saveImage(const QString &filePath);

private:
    QCamera *m_camera;
    QMediaCaptureSession *m_mediaCaptureSession;
    QImageCapture *m_imageCapture;
};

#endif // CAMERACORE_H
