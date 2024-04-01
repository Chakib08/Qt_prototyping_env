#include "Camera/Controller/cameraController.h"

CameraController::CameraController()
{
    this->m_cameraGui = new CameraGui();
    this->m_cameraCore = new CameraCore();


    connect(m_cameraCore, &CameraCore::videoOutputAvailable, m_cameraGui, &CameraGui::onVideoOutputAvailable);

    // Connect the clicked signal of the button to the slotButtonClicked slot
    connect(m_cameraGui, &CameraGui::captureButtonClicked, m_cameraCore, &CameraCore::onCaptureButtonClicked);

    // Save image
    connect(m_cameraGui, &CameraGui::saveImageButtonClicked, m_cameraCore, &CameraCore::onSaveImageButtonClicked);
}

CameraController::~CameraController()
{
    delete m_cameraCore;
    delete m_cameraGui;
}

bool CameraController::initGui()
{
    return m_cameraGui->initGui();
}

bool CameraController::run()
{
    QWidget *w = m_cameraGui->getMainWidget();
    QMediaCaptureSession* cap = m_cameraCore->getMediaCaptureSession();
    cap->setVideoOutput(m_cameraGui->getVideoWidget());
    w->show();
    return true;
}
