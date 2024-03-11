// cameraGui.h
#ifndef CAMERAGUI_H
#define CAMERAGUI_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QVideoWidget>
#include "src/core/camera/cameraCore.h"

class CameraGui : public QWidget {
    Q_OBJECT
public:
    explicit CameraGui(QWidget *parent = nullptr);

private slots:
    void startCamera();
    void saveImage();

private:
    QVBoxLayout *m_vBoxLayout;
    QPushButton *m_displayButton;
    QPushButton *m_saveImageButton;
    QVideoWidget *m_videoWidget;
    CameraCore *m_cameraCore;
};

#endif // CAMERAGUI_H
