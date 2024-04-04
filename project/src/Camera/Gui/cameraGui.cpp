#include "Camera/Gui/cameraGui.h"


CameraGui::CameraGui()
{
    m_videoWidget = new QVideoWidget(this);
    m_displayButton = new QPushButton();
    m_saveImageButton = new QPushButton();
    m_selectImagePathButton = new QPushButton();
    m_imageLineEditPath = new QLineEdit(QCoreApplication::applicationDirPath(), this);

    connect(m_displayButton, &QPushButton::clicked, this, &CameraGui::captureButtonClicked);
    connect(m_saveImageButton, &QPushButton::clicked, this, &CameraGui::saveImageButtonClicked);
    connect(m_selectImagePathButton, &QPushButton::clicked, this, &CameraGui::onUpdateImageLineEditPath);

}

CameraGui::~CameraGui()
{
    delete m_saveImageButton;
    delete m_displayButton;
    delete m_videoWidget;
    delete m_mainWidget;
}

bool CameraGui::initGui()
{
    m_mainWidget = new QWidget();
    QVBoxLayout *vBoxLayout = new QVBoxLayout(m_mainWidget);
    m_mainWidget->resize(1080, 720);

    QIcon displayIcon(":/icons/display.png");
    m_displayButton->setIcon(displayIcon);
    m_displayButton->setToolTip("Start streaming");
    vBoxLayout->addWidget(m_displayButton);

    // Take snapshot and save image
    QIcon snapShotIcon(":/icons/snapshot.png");
    m_saveImageButton->setIcon(snapShotIcon);
    m_saveImageButton->setToolTip("Take a snapshot and save it");
    vBoxLayout->addWidget(m_saveImageButton);

    // Select image saving path button
    QIcon folderIcon(":/icons/folder.png");
    m_selectImagePathButton->setIcon(folderIcon);
    m_selectImagePathButton->setGeometry(260, 50, 100, 30);
    m_selectImagePathButton->setToolTip("Select image saving path");
    vBoxLayout->addWidget(m_selectImagePathButton);

    // Image line edit path field
    m_imageLineEditPath->setGeometry(50, 50, 200, 30);
    vBoxLayout->addWidget(m_imageLineEditPath);


    vBoxLayout->addWidget(m_videoWidget);
    return true;
}

QWidget *CameraGui::getMainWidget()
{
    return m_mainWidget;
}

QVideoWidget *CameraGui::getVideoWidget()
{
    return m_videoWidget;
}

void CameraGui::onUpdateImageLineEditPath()
{
    QString newPath = QFileDialog::getExistingDirectory(this, "Select Directory", m_imageLineEditPath->text());
    if (!newPath.isEmpty()) {
        m_imageLineEditPath->setText(newPath);
    }
    emit updateImageSavingPath(m_imageLineEditPath->text());
}
