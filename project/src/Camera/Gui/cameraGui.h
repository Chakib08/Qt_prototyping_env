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
public:
    CameraGui();
    ~CameraGui();
    bool initGui();

private:
    QVideoWidget *m_videoWidget;
    QPushButton *m_displayButton;
    QPushButton *m_saveImageButton;
};

#endif // CAMERAGUI_H
