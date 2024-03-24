#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QCamera>
#include <QImageCapture>
#include <QMediaDevices>
#include <QMediaCaptureSession>
#include <QVideoWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QString>
#include <QFileDialog>




QT_BEGIN_NAMESPACE
namespace Ui { class Window; }
QT_END_NAMESPACE

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    ~Window();

public slots:
    void slotButtonClicked();
    void saveImage();

private:
    Ui::Window *ui;
    QCamera *m_camera;
    QImageCapture *m_imageCapture;
    QMediaCaptureSession *m_mediaCaptrueSession;
    QVideoWidget *m_videoWidget;
    QVBoxLayout *m_vBoxLyout;
    QPushButton *m_displayButton;
    QPushButton *m_saveImageButton;
    QImage *m_image;
};
#endif // WINDOW_H
