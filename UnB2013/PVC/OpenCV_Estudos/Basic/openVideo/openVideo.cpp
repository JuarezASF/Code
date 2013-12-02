#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/imgproc/imgproc.hpp>  // Gaussian Blur
#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O
#include <iostream>
#include <sstream>

using namespace std;
using namespace cv;


int main()
{
	VideoCapture video(0);
	Mat frame;
	/* número inteiro para pegar de uma câmera
	 * 
	 * 	-se tem uma câmera só use 0
	 * 	- vá aumentando de 1 em 1 para as demais
	 * 
	 * string para ler de umarquivo
	 *
	 * outra maneira seria usar:
	 * video.open(0); 
	 * */
	
	
	if ( !video.isOpened())
	  {
	  cout  << "Could not open webcam " <<endl;
	  return -1;
	  }//testa se o vídeo foi aberto com sucesso
	  
	namedWindow("video"	, CV_WINDOW_AUTOSIZE);
		
	while(1) //Show the image captured in the window and repeat
		{
		video >> frame;              // read
		if (frame.empty()) break;         // check if at end

		imshow( "video", frame );//imagem original
		int c = cvWaitKey(20);
		
		if((char)c==27 )// char 27 == esc
				break;

		}
	video.release();//o vídeo já seria liberado
	//coloco isso aqui para manter uma didática
	  
	return(0);

}
