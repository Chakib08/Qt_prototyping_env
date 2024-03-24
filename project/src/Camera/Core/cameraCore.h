#ifndef CameraCore_H
#define CameraCore_H

#include <QCamera>
#include <QImageCapture>
#include <QMediaDevices>
#include <QMediaCaptureSession>
#include <QSharedPointer>
#include <QVideoWidget>
#include <QPushButton>

#include "Common/Interfaces/Devices/Core/iDeviceCore.h"

class CameraCore : public IDeviceCore
{

public:
    CameraCore();
    CameraCore(QPushButton* display, QPushButton* save);
    ~CameraCore();
    void initialize() override;
    void start() override;
    void stop() override;
    const QObject* getVideoOutput();

private:
    QSharedPointer<QCamera> m_camera;
    QSharedPointer<QMediaCaptureSession> m_mediaCaptureSession;
    QSharedPointer<QImageCapture> m_imageCapture;
    QObject* m_videoOutput;

public slots:
    void onCaptureButtonClicked();
    void onSaveImageButtonClicked(const QString &path);
};

#endif // CameraCore_H
