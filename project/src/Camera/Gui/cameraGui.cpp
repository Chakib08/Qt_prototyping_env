#include "Camera/Gui/cameraGui.h"

CameraGui::CameraGui()
{
    m_videoWidget = QSharedPointer<QVideoWidget>(new QVideoWidget(this));
}

QSharedPointer<QVideoWidget> CameraGui::getVideoWidget()
{
    return m_videoWidget;
}
