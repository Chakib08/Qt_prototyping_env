#ifndef IDEVICECORE_H
#define IDEVICECORE_H

#include <QObject>

class IDeviceCore : public QObject {
    Q_OBJECT
public:
    virtual void initialize() = 0;
    virtual void start() = 0;
    virtual void stop() = 0;
};

#endif // IDEVICECORE_H
