#ifndef CAMERACORE_H
#define CAMERACORE_H

#include "src/core/iDeviceCore.h"

class cameraCore : public IDeviceCore
{
    void initialize() override;
    void start() override;
    void stop() override;
public:
    cameraCore();
};

#endif // CAMERACORE_H
