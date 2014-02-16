#-------------------------------------------------
#
# Project created by QtCreator 2014-02-11T23:49:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Wendynator
TEMPLATE = app

INCLUDEPATH +=  include/Qt \
                include/OpenCV \
                include/C++ \
                /usr/include/opencv2\
                /usr/include/opencv2/core\
                /usr/include/opencv2/imgproc\
                /usr/include/opencv2/highgui\
                /usr/include/opencv2/video



LIBS += -L/usr/local/lib \
        -lopencv_core \
        -lopencv_imgproc \
        -lopencv_highgui \
        -lopencv_ml \
        -lopencv_video \
        -lopencv_features2d \
        -lopencv_calib3d \
        -lopencv_objdetect \
        -lopencv_contrib \
        -lopencv_legacy \
        -lopencv_flann


SOURCES += main.cpp\
        mainwindow.cpp \
    cv2qtimage.cpp \
    ColorDetection.cpp \
    ColorSensor.cpp \
    Draw.cpp \
    myMath.cpp \
    TemplateMatchSensor.cpp \
    TemplateSensorConfigWindows.cpp

HEADERS  += mainwindow.h \
    cv2qtimage.h \
    InterfaceSensor.h \
    ColorDetection.h \
    ColorSensor.h \
    Draw.h \
    myMath.h \
    TemplateMatchSensor.h \
    SetTemplateWindows.h \
    TemplateSensorConfigWindows.h

FORMS    += mainwindow.ui \
    TemplateSensorConfigWindows.ui
