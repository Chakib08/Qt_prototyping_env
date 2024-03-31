#include "Camera/Gui/cameraGui.h"

CameraGui::CameraGui()
{
    m_videoWidget = new QVideoWidget(this);
    m_displayButton = new QPushButton("Display");
    m_saveImageButton = new QPushButton("Save Image");
}

CameraGui::~CameraGui()
{
    delete m_saveImageButton;
    delete m_displayButton;
    delete m_videoWidget;
}

bool CameraGui::initGui()
{
    /* GUI */
    QWidget *mainWidget = new QWidget();
    QVBoxLayout *vBoxLayout = new QVBoxLayout(mainWidget);
    mainWidget->resize(1080, 720);
    vBoxLayout->addWidget(m_displayButton);
    vBoxLayout->addWidget(m_saveImageButton);
    if (m_videoWidget) { // Check if m_videoWidget is not null
        vBoxLayout->addWidget(m_videoWidget);
    } else {
        qDebug() << "m_videoWidget is null!";
    }

    mainWidget->show();
    /* GUI End */

    return true;
}
