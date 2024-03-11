// cameraGui.cpp
#include "src/gui/camera/cameraGui.h"

CameraGui::CameraGui(QWidget *parent) : QWidget(parent), m_cameraCore(nullptr) {
    m_cameraCore = new CameraCore(this);

    m_displayButton = new QPushButton("Display");
    m_saveImageButton = new QPushButton("Save Image");
    m_videoWidget = new QVideoWidget();

    m_vBoxLayout = new QVBoxLayout(this);
    m_vBoxLayout->addWidget(m_displayButton);
    m_vBoxLayout->addWidget(m_saveImageButton);
    m_vBoxLayout->addWidget(m_videoWidget);

    connect(m_displayButton, &QPushButton::clicked, this, &CameraGui::startCamera);
    connect(m_saveImageButton, &QPushButton::clicked, this, &CameraGui::saveImage);
}

void CameraGui::startCamera() {
    m_cameraCore->startCamera();
}

void CameraGui::saveImage() {
    // You can specify the file path where you want to save the image
    m_cameraCore->saveImage("D:/Qt_dev/Qt_prototyping_env/proto_env/img");
}
