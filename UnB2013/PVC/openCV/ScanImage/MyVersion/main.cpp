#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <sstream>

using namespace std;
using namespace cv;

int main( int argc, char* argv[])
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
    Mat I, J;
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
    uchar table[256];
    Mat lookUpTable(1, 256, CV_8U);
    uchar* p;
    int divideWith = 120;
    
    while(divideWith)
    {	
		//definido tabela lookup

		for (int i = 0; i < 256; ++i)
		   table[i] = (uchar)(divideWith * (i/divideWith));

		p = lookUpTable.data;
		
		for( int i = 0; i < 256; ++i)
			p[i] = table[i];

		//MODELO EFICIENTE UTILIZANDO FUNÇÃO DEFINIDA NO OPENCV
			LUT(I, lookUpTable, J);

		//imprimindo resultados
		namedWindow("imagem original", CV_WINDOW_AUTOSIZE);
		namedWindow("imagem modificada", CV_WINDOW_AUTOSIZE);
		
		imshow( "imagem original"  , I );//imagem original
		imshow( "imagem modificada", J );//imagem modificada
		
		waitKey(100);
		
		cout << "Entre com o número inteiro a dividir a escala de cores" <<endl
			<< "Entre com zero par terminar" << endl;
		cin >> divideWith;
		
		while(divideWith < 0 || divideWith >256)
			{ 
			cout << "O número deve estar entre 0 e 25(inclusive)" << endl;
			cin >> divideWith;
			}
	}
	
    return 0;
}
