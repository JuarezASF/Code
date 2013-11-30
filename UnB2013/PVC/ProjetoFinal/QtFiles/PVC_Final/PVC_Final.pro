#-------------------------------------------------
#
# Project created by QtCreator 2013-11-28T00:35:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PVC_Final
TEMPLATE = app

INCLUDEPATH += ../../include/ \
                /usr/include/opencv2


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

SOURCES +=\
        projetofinal.cpp \
    ../../src/Draw.cpp \
    ../../src/MyKalmanFilter.cpp \
    ../../src/myMath.cpp \
    ../../src/ProjetoFinal.cpp \
    cv2qtimage.cpp \
    myTimer.cpp

HEADERS  += projetofinal.h \
    ../../include/myString.h \
    ../../include/myMath.h \
    ../../include/MyKalmanFilter.h \
    ../../include/Draw.h \
    cv2qtimage.h \
    myTimer.h

FORMS    += projetofinal.ui
