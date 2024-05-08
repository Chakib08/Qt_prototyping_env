QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD/src

SOURCES += \
    src/console/logger.cpp \
    src/console/logshandler.cpp \
    src/main.cpp \
    src/Camera/Controller/cameraController.cpp \
    src/Camera/Core/cameraCore.cpp \
    src/Camera/Gui/cameraGui.cpp \
    src/mainwindow.cpp

HEADERS += \
    src/Common/Interfaces/Logger/ilogappender.h \
    src/Common/Interfaces/Devices/Controller/iDeviceController.h \
    src/Common/Interfaces/Devices/Core/iDeviceCore.h \
    src/Common/Interfaces/Devices/Gui/iDeviceGui.h \
    src/Camera/Controller/cameraController.h \
    src/Camera/Core/cameraCore.h \
    src/Camera/Gui/cameraGui.h \
    src/console/logger.h \
    src/console/logshandler.h \
    src/mainwindow.h

RESOURCES += \
    resources/icons.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



#LIBS += C:\OpenCV-MinGW-Build\x64\mingw\bin\libopencv_highgui455.dll
#LIBS += C:\OpenCV-MinGW-Build\x64\mingw\bin\libopencv_imgproc455.dll
#LIBS += C:\OpenCV-MinGW-Build\x64\mingw\bin\libopencv_core455.dll
#LIBS += C:\OpenCV-MinGW-Build\x64\mingw\bin\libopencv_imgcodecs455.dll
#LIBS += C:\OpenCV-MinGW-Build\x64\mingw\bin\libopencv_video455.dll
#LIBS += C:\OpenCV-MinGW-Build\x64\mingw\bin\libopencv_videoio455.dll



INCLUDEPATH += C:/OpenCV-MinGW-Build/include
DEPENDPATH += C:/OpenCV-MinGW-Build/include

FORMS += \
    src/mainwindow.ui
