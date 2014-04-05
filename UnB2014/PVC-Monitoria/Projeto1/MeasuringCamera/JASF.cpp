#include "JASF.h"

void openVideo(VideoCapture &videoInput, int n){
    if(!videoInput.isOpened())
        videoInput.open(n);
    else
    {
        videoInput.release();
        videoInput.open(n);
    }
   }

VideoCapture JASF::initVideo(){
    bool sucesso = false;
    cv::VideoCapture video;
    for(int i = 0; i < 10; i++)
    {
        openVideo(video, i);
        if(video.isOpened()){
            sucesso = true;
            break;
        }
    }
    if(sucesso == false)
    {
        throw string("Vídeo não pode ser aberto!(ao menos de 0-10)");
    }

    return video;
}
