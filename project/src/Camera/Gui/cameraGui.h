#ifndef CAMERAGUI_H
#define CAMERAGUI_H

#include <QWidget>
#include <QVideoWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSharedPointer>

#include "Common/Interfaces/Devices/Gui/iDeviceGui.h"


class CameraGui : public IDeviceGui
{
    Q_OBJECT
public:
    CameraGui();
    ~CameraGui();
    bool initGui();
    QWidget* getMainWidget();
    QVideoWidget* getVideoWidget();

private:
    QWidget *m_mainWidget;
    QVideoWidget *m_videoWidget;
    QPushButton *m_displayButton;
    QPushButton *m_saveImageButton;

signals:
    void captureButtonClicked();
    void saveImageButtonClicked(QString &path);

public slots:
    void onVideoOutputAvailable(QObject* videoOutput);
};

#endif // CAMERAGUI_H
