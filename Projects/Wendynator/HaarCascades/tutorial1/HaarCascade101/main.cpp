#include <iostream>
//C++ LIBS
#include <string>
#include <iostream>
#include <vector>

//OPENCV LIBS
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/background_segm.hpp>
#include <opencv2/video/tracking.hpp>
#include <opencv2/objdetect/objdetect.hpp>

using namespace std;
using namespace cv;

Mat img;
Mat gray;

const char* image_window = "Source Image";

int main(int argc, char **arg)
{
    cout << "Hello World do classificador em cascada!" << endl;

    //LÊ IMAGEM DE ENRTADA E CONVERTE PARA GRAYSCALE
    img = imread(arg[1]);
    cvtColor(img, gray, COLOR_BGR2GRAY);

    //INICIALIZA CLASSIFICADORES
    CascadeClassifier *faceDetector;
    CascadeClassifier *eyeDetector;
    faceDetector = new CascadeClassifier("/usr/include/opencv/data/haarcascade_frontalface_default.xml");
    eyeDetector = new CascadeClassifier("/usr/include/opencv/data/haarcascade_eye.xml");
    // na minha instação do opencv esses arquivos não existiam, tive que baixá-los e colocá-los nessa pasta
    // baixei os .xml dessa página https://github.com/Itseez/opencv/tree/master/data/haarcascades

    //OBJETOS SÃO DETECTADOS COMO UM VETOR DE RETÂNGULOS
    vector<Rect> faces;
    faceDetector->detectMultiScale(gray, faces, 1.1);
    cout << "Número de faces detectadas:" << faces.size() << endl;
    //PARA CADA FACE DETECTADA, PROCURAR POR OLHOS
    for(unsigned int i = 0; i < faces.size(); i++){
        rectangle(img, faces[i], Scalar(255, 0 ,0));
        Mat ROI(gray, faces[i]);
        Mat ROI_color(img, faces[i]);

        vector<Rect> eyes;
        eyeDetector->detectMultiScale(ROI, eyes);
        for(unsigned int j = 0; j < eyes.size(); j++)
            rectangle(ROI_color, eyes[j], Scalar(0, 255, 0));

        cout << "\t \t Número de olhos detectados na face " << i << ": " << eyes.size() << endl;
    }


    // Create windows
    namedWindow( image_window, WINDOW_AUTOSIZE );
    //MOSTRA IMAGEM FINAL
    imshow(image_window, img);
    //ESPERA COMANDO PARA ENCERRAR EXECUÇÃO
    waitKey(0);

    return 0;
}

