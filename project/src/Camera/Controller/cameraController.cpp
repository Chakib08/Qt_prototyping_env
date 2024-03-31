#include "Camera/Controller/cameraController.h"

CameraController::CameraController()
{
    this->m_cameraCore = new CameraCore();
    this->m_cameraGui = new CameraGui();
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
    return true;
}
