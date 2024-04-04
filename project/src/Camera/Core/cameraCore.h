#ifndef CameraCore_H
#define CameraCore_H

#include <QCamera>
#include <QImageCapture>
#include <QMediaDevices>
#include <QMediaCaptureSession>
#include <QSharedPointer>
#include <QVideoWidget>
#include <QPushButton>
#include <QCoreApplication>

#include "Common/Interfaces/Devices/Core/iDeviceCore.h"

class CameraCore : public IDeviceCore
{
    Q_OBJECT
public:
    CameraCore();
    ~CameraCore();
    void initialize() override;
    void start() override;
    void stop() override;
    void setVideoOutputToGui(QObject *videoOutput);
    QMediaCaptureSession* getMediaCaptureSession();

private:
    QCamera *m_camera;
    QMediaCaptureSession *m_mediaCaptureSession;
    QImageCapture *m_imageCapture;
    QString m_imageSavingPath;

public slots:
    void onCaptureButtonClicked();
    void onSaveImageButtonClicked();
    void onUpdatedImageSavingPath(const QString &path);
};

#endif // CameraCore_H
