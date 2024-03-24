#ifndef CAMERAGUI_H
#define CAMERAGUI_H

#include <QWidget>
#include <QVideoWidget>
#include <QVBoxLayout>
#include <QSharedPointer>

#include "Common/Interfaces/Devices/Gui/iDeviceGui.h"


class CameraGui : public IDeviceGui
{
public:
    CameraGui();
    QSharedPointer<QVideoWidget> getVideoWidget();

private:
    QSharedPointer<QVideoWidget> m_videoWidget;

};

#endif // CAMERAGUI_H
