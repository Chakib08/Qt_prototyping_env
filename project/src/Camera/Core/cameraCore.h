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
    ~CameraCore();
    void initialize() override;
    void start() override;
    void stop() override;
    void setVideoOutputToGui(QObject *videoOutput);

private:
    QCamera *m_camera;
    QMediaCaptureSession *m_mediaCaptureSession;
    QImageCapture *m_imageCapture;
    QObject *m_videoOutput;

public slots:
    void onCaptureButtonClicked();
    void onSaveImageButtonClicked(const QString &path);

signals:
    void videoOutputAvailable(QObject *videoOutput);
};

#endif // CameraCore_H
