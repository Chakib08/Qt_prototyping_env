QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    window.cpp

HEADERS += \
    window.h

FORMS += \
    window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



LIBS += C:\OpenCV-MinGW-Build\x64\mingw\bin\libopencv_highgui455.dll
LIBS += C:\OpenCV-MinGW-Build\x64\mingw\bin\libopencv_imgproc455.dll
LIBS += C:\OpenCV-MinGW-Build\x64\mingw\bin\libopencv_core455.dll
LIBS += C:\OpenCV-MinGW-Build\x64\mingw\bin\libopencv_imgcodecs455.dll

INCLUDEPATH += C:/OpenCV-MinGW-Build/include
DEPENDPATH += C:/OpenCV-MinGW-Build/include
