#-------------------------------------------------
#
# Project created by QtCreator 2013-12-01T19:34:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjetoFinal
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

SOURCES += src/main.cpp\
        src/OpenCV/Draw.cpp \
        src/OpenCV//MyKalmanFilter.cpp \
        src/C++/myMath.cpp \
        src/Qt/UserInterface.cpp \
        src/Qt/cv2qtimage.cpp \
        src/Qt/myTimer.cpp \
        src/Qt/secondWindow.cpp \
    src/OpenCV/ColorDetection.cpp \
    src/Qt/PainelControle.cpp \
    src/Qt/MainLoop.cpp \
    Filtros.cpp


HEADERS  += include/C++/myString.h \
            include/C++/myMath.h \
            include/OpenCV/MyKalmanFilter.h \
            include/OpenCV/Draw.h \
            include/Qt/UserInterface.h \
            include/Qt/cv2qtimage.h \
            include/Qt/myTimer.h \
            include/Qt/secondWindow.h \
    include/OpenCV/ColorDetection.h \
    include/Qt/PainelControle.h \
    Filtros.h

FORMS    += UI/UserInterface.ui \
            UI/secondWindow.ui \
    UI/PainelControle.ui
