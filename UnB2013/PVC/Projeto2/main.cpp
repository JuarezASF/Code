#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "ImgProcess.hpp"
#include <iostream>

using namespace cv;
using namespace std;

//#define HOUGH_SIMPLES
	//comente para usar a versão probabilística
//#define VIDEO_MODE
	//comente para usar a versão de imagem
//#define IMAGE_MODE
	//comente tudo acima para usar o modo da questão 3

//#define VIDEO_FROM_WEBCAM
	//comente para abir o vídeo .avi especificado


int lowThresholdCircles = 5;
int const max_lowThresholdCircles = 50;

int lowThresholdLinear = 130;
int const max_lowThresholdLinear = 250;

int main(int argc, char** argv)
{
#ifdef VIDEO_MODE
			const char* filename_video =
		"/home/juarez/Copy/UnB/2-2013/PVC/Projeto2/Firebird_Hover.avi";

			const char* save_frame_src =
		"/home/juarez/Copy/UnB/2-2013/PVC/Projeto2/images/src.jpg";

			const char* save_frame_show =
		"/home/juarez/Copy/UnB/2-2013/PVC/Projeto2/images/show.jpg";

	#ifdef VIDEO_FROM_WEBCAM
				VideoCapture video(0);
	#else
				VideoCapture video(filename_video);
	#endif
			if ( !video.isOpened())
			  {
			  cout  << "Could not open webcam " <<endl;
			  return -1;
			  }//testa se o vídeo foi aberto com sucesso

			const char* window1 = "original";
			const char* window2 = "(circles + lines)Hough";
			namedWindow(window1	, CV_WINDOW_AUTOSIZE);
			namedWindow(window2	, CV_WINDOW_AUTOSIZE);

			const char* track1 = "circlesHough minThereshold";
			createTrackbar( track1, window2,
						&lowThresholdCircles, max_lowThresholdCircles);

			const char* track2 = "linearHough minThereshold";
						createTrackbar( track2, window2,
									&lowThresholdLinear, max_lowThresholdLinear);

			Mat frame, show;

			while(1) //Show the image captured in the window and repeat
				{
				video >> frame;
				if (frame.empty()) break;

				frame.copyTo(show);

				#ifdef HOUGH_SIMPLES
					vector<Vec3f> lines;
				#else
					vector<Vec4i> lines;
				#endif
					vector<Vec3f> circles;

				getCirclesLines(frame, lines, circles);
				drawLines(show, lines);
				drawCircles(show, circles);

				imshow( window1, frame );
				imshow( window2, show );

				int wait_c = cvWaitKey(30);

				if((char)wait_c==27 )// char 27 == esc
						break;
				if((char)wait_c == 112)//p
					{
						imwrite( save_frame_show, show);
						imwrite( save_frame_src, frame);
					}


				}
			video.release();//o vídeo já seria liberado
			//coloco isso aqui para manter uma didática
	#else
		#ifdef IMAGE_MODE
			const char* filename =
			"/home/juarez/Copy/UnB/2-2013/PVC/Projeto2/images/linesCircles.jpg";

			const char* filename2 =
			"/home/juarez/Copy/UnB/2-2013/PVC/Projeto2/images/triangle.jpg";

			const char* save_triangles_show =
		"/home/juarez/Copy/UnB/2-2013/PVC/Projeto2/images/show_triangles.jpg";

			const char* save_circles_show =
		"/home/juarez/Copy/UnB/2-2013/PVC/Projeto2/images/show_circles.jpg";


			Mat src = imread(filename, 1);
			Mat src2 = imread(filename2, 1);

			 if(src.empty())
			 	 {
				 cout << "can not open " << filename << endl;
				 return -1;
			 	 }

			 if(src2.empty())
			 	{
				 cout << "can not open " << filename2 << endl;
				 return -1;
			 	}

			const char* window1_img = "original";
			const char* window2_img = "(circles + lines)Hough";
			namedWindow(window1_img	, CV_WINDOW_AUTOSIZE);
			namedWindow(window2_img	, CV_WINDOW_AUTOSIZE);

			const char* window1_2_img = "original 2";
			const char* window2_2_img = "(circles + lines)Hough 2";
			namedWindow(window1_2_img	, CV_WINDOW_AUTOSIZE);
			namedWindow(window2_2_img	, CV_WINDOW_AUTOSIZE);


			const char* track1_img = "circlesHough minThereshold";
			createTrackbar( track1_img, window2_img,
						&lowThresholdCircles, max_lowThresholdCircles);

			const char* track2_img = "linearHough minThereshold";
			createTrackbar( track2_img, window2_img,
						&lowThresholdLinear, max_lowThresholdLinear);

			int nCirclesTriangles, nLinesTriangles;
			int nCirclesCircles, nLinesCircles;
			while(1){
				Mat show, show2;

				src.copyTo(show);
				src2.copyTo(show2);

				#ifdef HOUGH_SIMPLES
					vector<Vec3f> lines, lines2;
				#else
					vector<Vec4i> lines, lines2;
				#endif

				vector<Vec3f> circles, circles2;

				getCirclesLines(src, lines, circles);
				drawLines(show, lines);
				drawCircles(show, circles);

				getCirclesLines(src2, lines2, circles2);
				drawLines(show2, lines2);
				drawCircles(show2, circles2);

				imshow( window1_img, src );
				imshow( window2_img, show );

				imshow( window1_2_img, src2 );
				imshow( window2_2_img, show2 );

				int c = cvWaitKey(20);

				if((char)c==27 )// char 27 == esc
						{
						imwrite( save_circles_show, show);
						imwrite( save_triangles_show, show2);
						makeContagem(lines, circles, nLinesTriangles,
								nCirclesTriangles);
						makeContagem(lines2, circles2, nLinesCircles,
								nCirclesCircles);


						cout << "A media de linhas encontradas nos triângulos é : "<<
									nLinesTriangles<< endl;
						cout << "A media de círculos encontrados nos triângulos é : "<<
									nCirclesTriangles<< endl;
						cout << "A media de linhas encontradas nos círculos é : "<<
									nLinesCircles<< endl;
						cout << "A media de círculos encontrados nos círculos é : "<<
								nCirclesCircles<< endl;
						break;
						}

				}
		#else
			//MODO DO ITEM 3: RODA VÍDEO E MANTÉM CONTAGEM
			//DO NÚMERO DE LINHAS E DE CÍRCULOS DETECTADOS
			VideoCapture video(0);
			if ( !video.isOpened())
			  {
			  cout  << "Could not open webcam " <<endl;
			  return -1;
			  }//testa se o vídeo foi aberto com sucesso

			const char* window1 = "original";
			const char* window2 = "(circles + lines)Hough";
			namedWindow(window1	, CV_WINDOW_AUTOSIZE);
			namedWindow(window2	, CV_WINDOW_AUTOSIZE);

			const char* track1 = "circlesHough minThereshold";
			createTrackbar( track1, window2,
						&lowThresholdCircles, max_lowThresholdCircles);

			const char* track2 = "linearHough minThereshold";
						createTrackbar( track2, window2,
									&lowThresholdLinear, max_lowThresholdLinear);

			Mat frame, show;

			int contagem = 0;
			int *nLines, *nCircles;
			nLines = new int[10];
			nCircles = new int[10];


			while(1) //aperte 'o' para fazer a contagem.
				//termina em 10 contagens
				{
				video >> frame;
				if (frame.empty()) break;

				frame.copyTo(show);

				const char* filename =
				"/home/juarez/Copy/UnB/2-2013/PVC/Projeto2/images/quest3C-src.jpg";

				const char* filenameSave =
				"/home/juarez/Copy/UnB/2-2013/PVC/Projeto2/images/quest3C-show.jpg";

				vector<Vec4i> lines;
				vector<Vec3f> circles;
				getCirclesLines(frame, lines, circles);
				drawLines(show, lines);
				drawCircles(show, circles);

				imshow( window1, frame );
				imshow( window2, show );

				int wait_c = cvWaitKey(30);

				if((char)wait_c==27 )// char 27 == esc
						break;

				if((char)wait_c == 111)//o
					{
					makeContagem(lines, circles, nLines[contagem],
							nCircles[contagem]);
					contagem++;
					if(contagem == 10)
						{
						cout << "A media de linhas encontradas é : "<<
								media(nLines, 10)<< endl;
						cout << "A media de círculos encontrados é : "<<
								media(nCircles, 10)<< endl;
						imwrite( filename, frame);
						imwrite( filenameSave, show);
						break;
						}
					}

				}
			video.release();//o vídeo já seria liberado
			//coloco isso aqui para manter uma didática

		#endif


	#endif

	 return 0;
	}

