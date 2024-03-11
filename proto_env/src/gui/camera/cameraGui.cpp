#include "cameraGui.h"

cameraGui::cameraGui()
{
    m_videoWidget = QSharedPointer<QVideoWidget>(new QVideoWidget(this));
}

QSharedPointer<QVideoWidget> cameraGui::getVideoWidget()
{
    return m_videoWidget;
}
