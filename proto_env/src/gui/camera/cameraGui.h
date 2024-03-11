#ifndef CAMERAGUI_H
#define CAMERAGUI_H

#include <QWidget>
#include <QVideoWidget>
#include <QVBoxLayout>
#include <QSharedPointer>

#include "src/gui/IDeviceGui.h"


class cameraGui : public IDeviceGui
{
public:
    cameraGui();
    QSharedPointer<QVideoWidget> getVideoWidget();

private:
    QSharedPointer<QVideoWidget> m_videoWidget;

};

#endif // CAMERAGUI_H
