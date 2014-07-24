#-------------------------------------------------
#
# Project created by QtCreator 2014-07-23T19:53:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AvalonPersonalizado
TEMPLATE = app


INCLUDEPATH +=  /usr/include/opencv2\
                /usr/include/opencv2/core\
                /usr/include/opencv2/imgproc\
                /usr/include/opencv2/highgui\
                /usr/include/opencv2/video\


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
        -lopencv_flann \
        -lboost_iostreams \
        -lboost_system \
        -lboost_filesystem



SOURCES += main.cpp\
        mainwindow.cpp \
    AvalonCustomizer.cpp \
    QString2Strings.cpp \
    cv2qtimage.cpp

HEADERS  += mainwindow.h \
    AvalonCustomizer.h \
    QString2String.h \
    cv2qtimage.h

FORMS    += mainwindow.ui
