#ifndef AVALONCUSTOMIZER_H
#define AVALONCUSTOMIZER_H

#include <string>
#include <iostream>

//OPENCV LIBS
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

class AvalonCustomizer
{
public:
    AvalonCustomizer();
    void setPlano(Mat &novo);
    void setMoldura(Mat &novo);
    void setPersonagem(Mat &novo);
    void setVerso(Mat &novo);
    void setNome(std::string novo);
    Mat getCard();

private:
    Mat plano, moldura, personagem, verso;
    string nome;


};

#endif // AVALONCUSTOMIZER_H
