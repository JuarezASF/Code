TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    JASF.cpp \
    ColorDetection.cpp \
    Filtros.cpp

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
        -lopencv_flann

HEADERS += \
    JASF.h \
    ColorDetection.h \
    Auxiliar.h \
    Filtros.h
