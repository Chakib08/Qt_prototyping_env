#ifndef CAMERACORE_H
#define CAMERACORE_H

#include <QCamera>
#include <QImageCapture>
#include <QMediaDevices>
#include <QMediaCaptureSession>
#include <QSharedPointer>
#include <QVideoWidget>
#include <QPushButton>

#include "Common/Interfaces/Devices/Core/iDeviceCore.h"

class cameraCore : public IDeviceCore
{

public:
    cameraCore();
    cameraCore(QPushButton* display, QPushButton* save);
    ~cameraCore();
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
    void onSaveImageButtonClicked();
};

#endif // CAMERACORE_H
