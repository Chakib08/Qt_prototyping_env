#include "Camera/Gui/cameraGui.h"

CameraGui::CameraGui()
{
    m_videoWidget = new QVideoWidget(this);
    m_displayButton = new QPushButton("Display");
    m_saveImageButton = new QPushButton("Save Image");

    connect(m_displayButton, &QPushButton::clicked, this, &CameraGui::captureButtonClicked);
    //connect(m_saveImageButton, &QPushButton::clicked, this, &CameraGui::saveImageButtonClicked);

}

CameraGui::~CameraGui()
{
    delete m_saveImageButton;
    delete m_displayButton;
    delete m_videoWidget;
    delete m_mainWidget;
}

bool CameraGui::initGui()
{
    m_mainWidget = new QWidget();
    QVBoxLayout *vBoxLayout = new QVBoxLayout(m_mainWidget);
    m_mainWidget->resize(1080, 720);
    vBoxLayout->addWidget(m_displayButton);
    vBoxLayout->addWidget(m_saveImageButton);
    vBoxLayout->addWidget(m_videoWidget);
    return true;
}

QWidget *CameraGui::getMainWidget()
{
    return m_mainWidget;
}

QVideoWidget *CameraGui::getVideoWidget()
{
    return m_videoWidget;
}

void CameraGui::onVideoOutputAvailable(QObject *videoOutput)
{
    qInfo() << __func__<< "fill widget";
    m_videoWidget = qobject_cast<QVideoWidget*>(videoOutput);
}




