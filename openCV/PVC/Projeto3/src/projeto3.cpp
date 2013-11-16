#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <sstream>
#include <cassert>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
	VideoCapture video("/home/juarez408/Copy/UnB/2-2013/PVC/Projeto3/data/video.avi");
	Mat frame;
	if(!video.isOpened())
		{
			cout << "Video não pode ser aberto!" << endl;
			return -1;
		}

	//------------------------------------------------------------------
	//--------------------CRIA E DEFINE JANELAS-------------------------
	//------------------------------------------------------------------

	namedWindow( "Original Video", CV_WINDOW_AUTOSIZE );


	while(1)//LAÇO PRINCIPAL DO PROGRAMA
  		{
  			video >> frame;
			if(frame.empty())
				{
				cout << "frame não pôde ser capturado"<<endl;
				break;
				}
  			imshow("Original Video", frame);
  //------------------------------------------------------------------
  //--------------------ESPERA OU TERMINA A EXECUÇÃO------------------
  //------------------------------------------------------------------
            int wait_c = cvWaitKey(30);
  			if((char)wait_c == 27 )
  				{// char == 27 : ESC key
  				cout << "\n\n execução será encerrada!"<<endl;
  				break;
  				}
  		}//FIM DO LAÇO PRINCIPAL


	cout << "fim" <<endl;

	waitKey(0);

	return 0;
}
