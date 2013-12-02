
#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/imgproc/imgproc.hpp>  // Gaussian Blur
#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O
#include <iostream>
#include <sstream>

#ifndef MY_MATH_HPP
#define MY_MATH_HPP

using namespace std;
using namespace cv;

long sumMat(Mat target)
{
	//soma os elementos de uma imagem PB
	int i, j;
	int soma = 0;

	for(int i = 0; i < target.rows; i++)
		for(int j = 0; j < target.cols; j++)
			soma += target.at<schar>(i, j);

	return soma;
}


Mat ScanImageMultiply(Mat& I, const uchar* const table)
{
	//similar ao LUT mas multiplica em vez de atribuir o valor
    // accept only char type matrices
    CV_Assert(I.depth() != sizeof(uchar));

    int channels = I.channels();

    int nRows = I.rows;
    int nCols = I.cols * channels;

    if (I.isContinuous())
    {
        nCols *= nRows;
        nRows = 1;
    }

    int i,j;
    uchar* p;
    for( i = 0; i < nRows; ++i)
    {
        p = I.ptr<uchar>(i);
        for ( j = 0; j < nCols; ++j)
        {
            p[j] *= table[p[j]];
        }
    }
    return I;
}

void makeShadowGreen(Mat &I, Mat &mask)
{  /*pinta a máscara PB sobre a imagem colorida RGB de verde
	não realiza verificação, CUIDADO!*/
	MatIterator_<uchar> itMask, endMask;
	MatIterator_<Vec3b> it, end;	         

	itMask = mask.begin<uchar>();
	endMask = mask.end<uchar>();
	it = I.begin<Vec3b>();
	end = I.end<Vec3b>();
    
            for( ; it != end && itMask != endMask; ++it, ++itMask)
            {
				if(*itMask == 0)
					{
					(*it)[0] = 0;//azul
					(*it)[1] = 255;//verde
					(*it)[2] = 0;//vermelho
					}
			}
    
}

void makeCarBlue(Mat &I, Mat &mask)
{  //recebe imagem colorda e máscara, pinta a máscara sobre a imagem de azul
	//não realiza verificação de formato: CUIDADO COM A ORDEM DOS ARGUMENTOS
	MatIterator_<uchar> itMask, endMask;
	MatIterator_<Vec3b> it, end;	         

	itMask = mask.begin<uchar>();
	endMask = mask.end<uchar>();
	it = I.begin<Vec3b>();
	end = I.end<Vec3b>();
    
            for( ; it != end && itMask != endMask; ++it, ++itMask)
            {
				if(*itMask == 0)
					{
					(*it)[0] = 255;//azul
					(*it)[1] = 0;//verde
					(*it)[2] = 0;//vermelho
					}
			}   
}
Mat MySubstract(Mat &A, Mat &B)
{/*fazemos a subtração A-B de modo peculiar
	-se a mudança não for significativa pintamos de branco
	-se a mudança for positica(ficar mais claro), pintamos de claro
	-se a mudança for negativa(escurecer) pintamos de escuro

	o caso de interesse é o segundo;
		-a sombra(e infelizmente os parabrisas) escurem os pixels
		ao caminharem*/

	Mat S;
	S.create(0,0, CV_8UC1);
	if(A.empty() || B.empty())
		{
		cout << "absSubtract: A ou B!" <<endl;
		return S;
		}
	int rows = A.rows;
	int cols = A.cols;
	int aux;

	S.create(rows, cols, CV_8UC1);

	MatIterator_<uchar> itA, endA;
	MatIterator_<uchar> itB, endB;
	MatIterator_<uchar> itS, endS;

	itA = A.begin<uchar>();
	endA = A.end<uchar>();
	
	itB = B.begin<uchar>();
	endB = B.end<uchar>();
	
	itS  = S.begin<uchar>();
	endS = S.end<uchar>();

	int tolerancia = 22;
    //DEFINE A MARGEM DE TOLERANCIA

    for( ; itA != endA && itB != endB && itS != endS; ++itA, ++itB, ++itS)
            {
				aux = (int)(*itA) - (int)(*itB);
				if(aux > tolerancia)//no caso do frame ter clareado
					(*itS) = (uchar) (aux * 0.4);//fica escuro
				if(aux < -1*tolerancia)//no caso de ter escurecido
					(*itS) = (uchar)(-1*(aux)*0.4 + 150);//fica claro
				if(aux>=-1*tolerancia && aux <= tolerancia)//no caso de n ter mudado o suficiente
					(*itS) = 255;
			}
	
	return S;
	
}

/// Global variables
Mat src, erosion_dst, dilation_dst;
void Erosion( Mat src, Mat dst, int size)
{
	//função de erosão retirada dos tutoriais do OpenCv
	//qnt maior size maior a erosão
  int erosion_type = 0;
  int erosion_elem = 0;//0,1,2 : ver abaixo
  int erosion_size = size;//ate 21 : quanto mais alto mas borrado

  if( erosion_elem == 0 ){ erosion_type = MORPH_RECT; }
  else if( erosion_elem == 1 ){ erosion_type = MORPH_CROSS; }
  else if( erosion_elem == 2) { erosion_type = MORPH_ELLIPSE; }

  Mat element = getStructuringElement( erosion_type,
                       Size( 2*erosion_size + 1, 2*erosion_size+1 ),
                       Point( erosion_size, erosion_size ) );

  /// Apply the erosion operation
  erode( src, dst, element );
}

void Dilation( Mat src, Mat dst, int size)
{//função de dilatação retirada dos tutoriais do OpenCn
//quando maior o size, maior a dilatação
  int dilation_type = 0;
  int dilation_elem = 0;//0,1,2 : ver abaixo
  int dilation_size = size;//ate 21 : quanto mais alto mas borrado

  if( dilation_elem == 0 ){ dilation_type = MORPH_RECT; }
  else if( dilation_elem == 1 ){ dilation_type = MORPH_CROSS; }
  else if( dilation_elem == 2) { dilation_type = MORPH_ELLIPSE; }

  Mat element = getStructuringElement( dilation_type,
                       Size( 2*dilation_size + 1, 2*dilation_size+1 ),
                       Point( dilation_size, dilation_size ) );
  /// Apply the dilation operation
  dilate( src, dst, element );
}

void myFilter(Mat &I){
			//elimina ruídos
			//explicação dos parâmetros: 200000 de testes feitos
			//esse foi o que ficou mais maneiro
	        medianBlur ( I, I, 7);
            Dilation(I,I, 2);
            Erosion(I, I, 3);
                  }

 void shadowSubtract(Mat &I, Mat &mask)
{  
	/*recebe uma máscara I(Pb) e retira a máscara mask(tbm Pb)
	não realiza verificação de formato adequado: CUIDADO
	-mask contém a sombra a ser retirada de I
	*/
	MatIterator_<uchar> itMask, endMask;
	MatIterator_<uchar> it, end;

	itMask = mask.begin<uchar>();
	endMask = mask.end<uchar>();
	it = I.begin<uchar>();
	end = I.end<uchar>();
    
            for( ; it != end && itMask != endMask; ++it, ++itMask)
            {
				if(*itMask == 0)
					{
					*it = 255;//branco
					}
			}
    
}
/*FUNÇÕES RETIRADAS DO CÓDIGO. DEIXO AQUI PARA REFERẼNCIA FUTURA
//------------------------------------------------------------------
//--------------------HISTOGRAMAS-----------------------------------
//------------------------------------------------------------------
			Mat histImage, coloredHistograma, myHist;
			Mat PbFrameBlur;
			//medianBlur ( frame, PbFrameBlur, 91); 
			getGrayHist(frame, histImage, myHist);
			getColoredHist(colorFrame, coloredHistograma);
*/
#endif
