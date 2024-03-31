#include "window.h"
#include "ui_window.h"

Window::Window(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Window)
{
    ui->setupUi(this);
    m_videoWidget = new QVideoWidget(this);
    m_camera = new QCamera((QMediaDevices::defaultVideoInput()));
    m_mediaCaptrueSession = new QMediaCaptureSession(this);

    m_imageCapture = new QImageCapture();
    m_image = new QImage();


    /* GUI */
    QWidget *w = new QWidget();
    m_vBoxLyout = new QVBoxLayout(w);
    m_displayButton = new QPushButton("Display");
    m_saveImageButton = new QPushButton("Save Image");

    w->resize(1080, 720);
    m_vBoxLyout->addWidget(m_displayButton);
    m_vBoxLyout->addWidget(m_saveImageButton);
    m_vBoxLyout->addWidget(m_videoWidget);
    /* GUI End */

    // Connect the clicked signal of the button to the slotButtonClicked slot
    connect(m_displayButton, SIGNAL(clicked()), this, SLOT(slotButtonClicked()));

    // Save image
    connect(m_saveImageButton, SIGNAL(clicked()), this, SLOT(saveImage()));

    w->show();

}

Window::~Window()
{
    delete ui;
    delete m_camera;
    delete m_videoWidget;
    delete m_mediaCaptrueSession;
}

void Window::slotButtonClicked()
{
    // Display a message box with "button pushed"
    //QMessageBox::information(this, "Button Clicked", "Button pushed");
    //m_videoWidget->resize(400, 400);
    m_camera->start();
    m_mediaCaptrueSession->setCamera(m_camera);
    m_mediaCaptrueSession->setVideoOutput(m_videoWidget);
}

void Window::saveImage()
{
    m_mediaCaptrueSession->setImageCapture(m_imageCapture);
    m_imageCapture->captureToFile("D:/Qt_dev/Qt_prototyping_env/proto_env/img");
}

