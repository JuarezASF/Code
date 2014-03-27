#-------------------------------------------------
#
# Project created by QtCreator 2014-03-25T14:22:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OracleKalman
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
        widget.cpp \
    MainLoop.cpp\
    myMath.cpp \
    Draw.cpp \
    cv2qtimage.cpp \
    ColorSensor.cpp \
    ColorDetection.cpp \
    ObjectToDetect.cpp \
    QString2Strings.cpp \
    Filtros.cpp


HEADERS  += widget.h \
    myMath.h \
    InterfaceSensor.h \
    Draw.h \
    cv2qtimage.h \
    ColorSensor.h \
    ColorDetection.h \
    ObjectToDetect.h \
    QString2String.h \
    Filtros.h \
    gnuplot-iostream.h

FORMS    += widget.ui
