#ifndef IDEVICECONTROLLER_H
#define IDEVICECONTROLLER_H

#include <QObject>

class IDeviceController : public QObject {
    Q_OBJECT

    virtual bool initGui() = 0;
    virtual bool run() = 0;
};

#endif // IDEVICECONTROLLER_H
