#include <iostream>
#include <vector>

//#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/tracking.hpp>
//#include <opencv2/highgui/highgui_c.h>

using namespace cv;
using namespace std;


struct mouse_info_struct { int x,y; };
struct mouse_info_struct mouse_info = {-1,-1}, last_mouse;

vector<Point> mousev,kalmanv;

void on_mouse(int event, int x, int y, int flags, void* param) {
	//if (event == CV_EVENT_LBUTTONUP) 
	{
		last_mouse = mouse_info;
		mouse_info.x = x;
		mouse_info.y = y;
		
//		cout << "got mouse " << x <<","<< y <<endl;
	}
}

void drawCross(Mat &img, Point center, Scalar color, float d){
	line( img, Point( center.x - d, center.y - d),
			Point( center.x + d, center.y + d ), color, 2, CV_AA, 0);
	line( img, Point( center.x + d, center.y - d ),
			Point( center.x - d, center.y + d ), color, 2, CV_AA, 0);
}


int main (int argc, char * const argv[]) {
    Mat img(500, 500, CV_8UC3);

    KalmanFilter KF(4, 2, 0);
    //kalman filter com 4 variáveis de estado e 2 de medida

    Mat_<float> state(4, 1); /* (x, y, Vx, Vy) */
    //vairável para guardar estado

    Mat processNoise(4, 1, CV_32F);
    //guarda o ruído

    Mat_<float> measurement(2,1);
    measurement.setTo(Scalar(0));
    //marca a medida inicial para (0,0);

    char code = (char)-1;
    //sinal de controle de parada
	
	namedWindow("mouse kalman");
	setMouseCallback("mouse kalman", on_mouse, 0);
	
	bool drawPast = false;

    for(;;)
    {
    	//seta variávei do modelo
    	//a princípio poderia variar em cada iteração, aqui tomamos ...
    	//...como constante
		if (mouse_info.x < 0 || mouse_info.y < 0) {
			//captura o novo estado(espera 30 sec para atualização)
			imshow("mouse kalman", img);
			waitKey(30);
			continue;
		}

		//define novo estado de posição
        KF.statePre.at<float>(0) = mouse_info.x;
		KF.statePre.at<float>(1) = mouse_info.y;

		//a velocidade é sempre 0?
		KF.statePre.at<float>(2) = 0;
		KF.statePre.at<float>(3) = 0;
		//modelo
		KF.transitionMatrix = *(Mat_<float>(4, 4) << 1,0,0,0,
													0,1,0,0,
													0,0,1,0,
													0,0,0,1);
		//medidas??
        setIdentity(KF.measurementMatrix);

        //erro no processo de medida??
        setIdentity(KF.processNoiseCov, Scalar::all(1e-4));

        //erro nas pedidas?
        setIdentity(KF.measurementNoiseCov, Scalar::all(1e-1));

        //erro a posteriori?
        setIdentity(KF.errorCovPost, Scalar::all(.1));
		
		mousev.clear();
		kalmanv.clear();
		//kalmanv é um vetor com a velocidade
		
        for(;;)
        {
            Mat prediction = KF.predict();

            //pega ponto predito
            Point predictPt(prediction.at<float>(0),prediction.at<float>(1));

            //pega a medida atual
            measurement(0) = mouse_info.x;
			measurement(1) = mouse_info.y;
			
			Point measPt(measurement(0),measurement(1));
			mousev.push_back(measPt);
			//mousev pega as medidas


			//corrige com os novos pontos
			Mat estimated = KF.correct(measurement);
			//
			Point statePt(estimated.at<float>(0),estimated.at<float>(1));
			kalmanv.push_back(statePt);
			//kalman ve mantes a saída de kalman filter
			
            // plot points
            img = Scalar::all(0);
            drawCross(img,  statePt, Scalar(255,255,255), 5 );
            drawCross(img,  measPt, Scalar(0,0,255), 5 );
			
            if(drawPast == true)
            {
            	//dezenha todas as linhas anteriores
				for (int i = 0; i < mousev.size()-1; i++)
					line(img, mousev[i], mousev[i+1], Scalar(255,255,0), 1);

				for (int i = 0; i < kalmanv.size()-1; i++)
					line(img, kalmanv[i], kalmanv[i+1], Scalar(0,255,0), 1);
            }

            imshow( "mouse kalman", img );

            code = (char)waitKey(100);
            if( code > 0 )
                break;
        }
        if( code == 27 || code == 'q' || code == 'Q' )
            break;
        if( code == 'p' || code == 'P' )
           drawPast = !drawPast;
    }
	
    return 0;
}
