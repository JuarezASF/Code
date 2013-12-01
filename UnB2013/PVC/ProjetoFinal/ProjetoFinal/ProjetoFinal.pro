#-------------------------------------------------
#
# Project created by QtCreator 2013-12-01T19:34:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjetoFinal
TEMPLATE = app

INCLUDEPATH +=  Draw \
                KalmanFilter\
                Math        \
                String        \
                QtClasses/Cv2QtImg        \
                QtClasses/UI        \
                QtClasses/Timer        \
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

SOURCES += main.cpp\
     QtClasses/UI/UserInterface.cpp \
    Draw/Draw.cpp \
    KalmanFilter/MyKalmanFilter.cpp \
    Math/myMath.cpp \
    QtClasses/Cv2QtImg/cv2qtimage.cpp \
    QtClasses/Timer/myTimer.cpp


HEADERS  += QtClasses/UI/UserInterface.h \
    String/myString.h \
    Math/myMath.h \
    KalmanFilter/MyKalmanFilter.h \
    Draw/Draw.h \
    QtClasses/Cv2QtImg/cv2qtimage.h \
    QtClasses/Timer/myTimer.h

FORMS    += QtClasses/UI/UserInterface.ui
