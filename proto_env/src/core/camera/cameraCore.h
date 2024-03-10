#ifndef CAMERACORE_H
#define CAMERACORE_H

#include <QCamera>
#include <QImageCapture>
#include <QMediaDevices>
#include <QMediaCaptureSession>
#include <QSharedPointer>

#include "src/core/iDeviceCore.h"

class cameraCore : public IDeviceCore
{

public:
    cameraCore();
    ~cameraCore();
    void initialize() override;
    void start() override;
    void stop() override;
private:
    QSharedPointer<QCamera> m_camera;
    QSharedPointer<QMediaCaptureSession> m_mediaCaptureSession;
};

#endif // CAMERACORE_H
