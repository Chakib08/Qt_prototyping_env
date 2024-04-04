#ifndef CAMERAGUI_H
#define CAMERAGUI_H

#include <QWidget>
#include <QVideoWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QIcon>
#include <QLineEdit>
#include <QCoreApplication>
#include <QFileDialog>

#include <QSharedPointer>

#include "Common/Interfaces/Devices/Gui/iDeviceGui.h"


class CameraGui : public IDeviceGui
{
    Q_OBJECT
public:
    CameraGui();
    ~CameraGui();
    bool initGui();
    QWidget* getMainWidget();
    QVideoWidget* getVideoWidget();

private:
    QWidget *m_mainWidget;
    QVideoWidget *m_videoWidget;
    QPushButton *m_displayButton;
    QPushButton *m_saveImageButton;
    QPushButton *m_selectImagePathButton;
    QLineEdit *m_imageLineEditPath;

signals:
    void captureButtonClicked();
    void saveImageButtonClicked();
    void updateImageSavingPath(const QString &path);

public slots:
    void onUpdateImageLineEditPath();

};

#endif // CAMERAGUI_H
