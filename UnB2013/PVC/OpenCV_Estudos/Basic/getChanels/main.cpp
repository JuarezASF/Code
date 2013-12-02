#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <sstream>

using namespace std;
using namespace cv;

Mat get_chanell(Mat &O, int channel);
Mat sum_images(Mat &A, Mat &B);

int main( int argc, char* argv[])
/**
 * main
 * 
 * rotina para testar os conceitos aprendidos de opencv e c++
 * pega uma imagem e a divide em seus canais RGB e nas possíveis
 * combinaçoes entre esses canais.
 * mostra as imagens ao final
 * 
 * uso o método 'safe mode' para caminhar pelas matrizes
 * me pareceu o mais fácil para se usar com matrizes rgb
 * 
 * também só trabalho com rgb. Não sei como o código 
 * age sobre grayscale. Provavelmete dê um pal cabuloso
 * */
{

//----------------------------------------
//----TESTANDO ARGUMENTS------------------
//----------------------------------------
    if (argc < 2)
    {
        cout << "Not enough parameters" << endl 
        << "entre com o arquivo a ser lido" <<endl;
        return -1;
    }
//----------------------------------------
//----ABRINDO IMAGENS---------------------
//----------------------------------------
    Mat I;
    //I para a original e J para a modificada
    
    //DEFINIMOS ABRIR EM GRAY_SCALE OU RGB
    if( argc == 3 && !strcmp(argv[3],"G") ) 
        I = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
    else//RGB POR DEFAULT
        I = imread(argv[1], CV_LOAD_IMAGE_COLOR);

    if (!I.data)
    {
        cout << "The image" << argv[1] << " could not be loaded." << endl;
        return -1;
    }



//----------------------------------------
//----ROTINA PROPRIAMENTE-----------------
//----------------------------------------
    Mat Red, Blue, Green, RB, RG, BG;
    
    Blue = get_chanell(I, 0);
    Red = get_chanell(I, 2);
    Green = get_chanell(I, 1);
    RB = sum_images(Red, Blue);
    RG = sum_images(Red, Green);
    BG = sum_images(Blue,Green);
    
 
		//imprimindo resultados
	namedWindow("imagem original"	, CV_WINDOW_AUTOSIZE);
	namedWindow("canal azul"		, CV_WINDOW_AUTOSIZE);
	namedWindow("canal vermelho"	, CV_WINDOW_AUTOSIZE);
	namedWindow("canal verde"		, CV_WINDOW_AUTOSIZE);
	namedWindow("canal R+B"		, CV_WINDOW_AUTOSIZE);
	namedWindow("canal R+G"		, CV_WINDOW_AUTOSIZE);
	namedWindow("canal G+B"		, CV_WINDOW_AUTOSIZE);
				
	imshow( "imagem original"   , I );//imagem original
	imshow( "canal azul"  		, Blue );
	imshow( "canal vermelho"  	, Red );
	imshow( "canal verde"  		, Green );
	imshow( "canal R+B"  		, RB );
	imshow( "canal R+G"  		, RG );
	imshow( "canal G+B"  		, BG );
	 
	waitKey(0);		
		
	imwrite( "./red.jpg", 	Red 	);
	imwrite( "./blue.jpg", 	Blue 	);
	imwrite( "./green.jpg", Green 	);
	imwrite( "./RG.jpg", 	RG 		);
	imwrite( "./RB.jpg", 	RB 		);
	imwrite( "./GB.jpg",	BG 		);
	
    return 0;
}

Mat get_chanell(Mat &O, int channel)
/**
 * get_chanells
 * deve receber uma imagem RGB
 * retorna o canal escolhido
 * 0: blue
 * 1: green
 * 2: red
 * caso nenhum acima: retorna uma matriz de 0's
 * */
	{
		
	if(channel > 3 || channel < 0)
		{
		cout << "get_channel deve receber x \\in {0,1,2}" <<endl;	
		}
		
	Mat canal(O.rows, O.cols, CV_8UC3);
	MatIterator_<Vec3b> it, end, Oit, Oend;
	
	it  = canal.begin<Vec3b>();	
	end = canal.end<Vec3b>();
	
	Oit  = O.begin<Vec3b>();	
	Oend = O.end<Vec3b>();
	
	switch(channel)
	{
	case 0: 
		for( ; it != end; ++it, ++Oit)
			(*it)[0] = (*Oit)[0];//azul		
		break;
	case 1: 
		for( ; it != end; ++it, ++Oit)
			(*it)[1] = (*Oit)[1];//verde
		break;
	case 2: 
		for( ; it != end; ++it, ++Oit)
			(*it)[2] = (*Oit)[2];//vermelho
		break;
	default :
		break;
	}
	return canal;	
		
	}
	
Mat sum_images(Mat &A, Mat &B)
/**
 * sum_images
 * deve reeber duas matrizes RGB de igual tamanho
 * retorna a soma pixel a pixel delas
 * 
 * caso as matrizes sejam iguais retorna um Mat não inicializado
 * não sei como se comporta caso A e B não tenham sido iniializados
 * */
{
	Mat newMat;
	if(A.rows == B.rows && A.cols == B.cols)
		{
		int colunas = A.cols;
		int linhas  = A.rows;
		
		newMat = Mat::zeros(linhas, colunas, CV_8UC3);
		MatIterator_<Vec3b> it, end, Ait, Aend, Bit, Bend;
		
		it  = newMat.begin<Vec3b>();	
		end = newMat.end<Vec3b>();
		
		Ait  = A.begin<Vec3b>();	
		Aend = A.end<Vec3b>();
		
		Bit  = B.begin<Vec3b>();	
		Bend = B.end<Vec3b>();
		
		for(  ; it != end; ++it, ++Ait, ++Bit)
            {
             (*it)[0] = (*Ait)[0] + (*Bit)[0];
             (*it)[1] = (*Ait)[1] + (*Bit)[1];
             (*it)[2] = (*Ait)[2] + (*Bit)[2];
            }
		}
	else
		cout << "sum_images recebeu imagens de \
		tamanho diferentes!" << endl;
	
	return newMat;

}
