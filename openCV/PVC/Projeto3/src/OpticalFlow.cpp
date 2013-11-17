#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <iostream>
#include <ctype.h>

using namespace cv;
using namespace std;

static TermCriteria termcrit(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS, 20, 0.03);
static Size subPixWinSize(10,10), winSize(31,31);
/*essas últimas duas linahs definem o tamanho da imagem a ser utilizado
 * esses parametros são passados como argumento da função que calcula
 * o fluxo óptico.
 * eles não são necessários, isto é, a função tem valores default para eles
 * */

void opticFlowCalculate(Mat &previous, Mat &current)
{

    const int MAX_COUNT = 500;
    //contagem máxima de pontos a seguir

    Mat gray, prevGray;
    vector<Point2f> points[2];
    //pontos que serão usados para calcular o fluxo ótico
    //points[0] pontos da imagem anterior
    //points[1] ponto na nova imagem


     if(current.empty() )
        cout << "Isso não deveria acontecer!" << endl;

     /*Como estamos trabalhando com brilho, passamos para PB*/
     cvtColor(current, gray, CV_BGR2GRAY);
     cvtColor(previous, prevGray, CV_BGR2GRAY);

    /*define bons pontos para seguir,
     * no futuro não usarei isso. devemos procurar todos
     * os pontos em uma malhar regular*/
	goodFeaturesToTrack(prevGray, points[0], MAX_COUNT, 0.01, 10, Mat(), 3, 0, 0.04);
    cornerSubPix(prevGray, points[0], subPixWinSize, Size(-1,-1), termcrit);


	vector<uchar> status;
	//status guarda para guarda ponto do vetor points[0]
	//se a operação de detectar foi bem sucedida ou não
    vector<float> err;
    //estima erro para cada ponto achado?? not sure what it means

    calcOpticalFlowPyrLK(prevGray, gray, points[0], points[1], status, err, winSize,
                                 3, termcrit, 0, 0.001);

    /*pinta os pontos que foram achados*/
    size_t i;
    for( i = 0; i < points[1].size(); i++ )
    	{
    	if( !status[i] )
    		continue;
    	//se o ponto falhou não será pintado!
    	circle( current, points[1][i], 3, Scalar(0,255,0), -1, 8);
    	}

    /*Até essa etapa do trabalho temos os pontos de interesse em previous
     * achados em current
     *
     * a fazer:
     * 	- definir os pontos de interesse como todos os pontos de uma malha quadrada
     * 	- visualizar isso*/
}
