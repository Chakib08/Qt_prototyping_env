#ifndef CAMERACONTROLLER_H
#define CAMERACONTROLLER_H

#include "Common/Interfaces/Devices/Controller/iDeviceController.h"
#include "Camera/Core/cameraCore.h"
#include "Camera/Gui/cameraGui.h"


class CameraController : public IDeviceController
{
public:
    CameraController();
    ~CameraController();
private:
    CameraCore* m_cameraCore;
    CameraGui* m_cameraGui;

};

#endif // CAMERACONTROLLER_H
