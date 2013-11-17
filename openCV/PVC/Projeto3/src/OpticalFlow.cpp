#include "../headers/OpticalFlow.h"

using namespace cv;
using namespace std;

static TermCriteria termcrit(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS, 20, 0.03);
static Size  winSize(31,31);
/*essas últimas duas linahs definem o tamanho da imagem a ser utilizado
 * esses parametros são passados como argumento da função que calcula
 * o fluxo óptico.
 * eles não são necessários, isto é, a função tem valores default para eles
 * */

void drawNormalizedArrows(Mat &img, vector<Point2f> &P,
		vector<Point2f> &V)
{
    double l_max = -10;
    for (size_t i = 0; i < V.size(); i++)
        {
    	//descobre o maior módulo
        float dx = V[i].x;
        float dy = V[i].y;

        double l = sqrt(dx*dx + dy*dy);

        if(l>l_max) l_max = l;
        }



    for (size_t i = 0; i < V.size(); i++)
    {
    	float dx = V[i].x;
    	float dy = V[i].y;
        double l = sqrt(dx*dx + dy*dy);
        //'l' é módulo da velocidade
        if (l > 0)
        {
            double spinSize = 5.0 * l/l_max;

            //dezenha o traço da flecha
            CvPoint p2 = cvPoint(P[i].x + (int)(dx), P[i].y + (int)(dy));
            line(img, P[i], p2, CV_RGB(0,255,0), 1, CV_AA);

            //dezenha a cabeça da flexa
            double angle;                                                                           // Draws the spin of the arrow
            angle = atan2( (double) P[i].y - p2.y, (double) P[i].x - p2.x );

            CvPoint p;
            p.x = (int) (p2.x + spinSize * cos(angle + 3.1416 / 4));
            p.y = (int) (p2.y + spinSize * sin(angle + 3.1416 / 4));
            line(img, p, p2, CV_RGB(0,255,0), 1, CV_AA, 0 );

            p.x = (int) (p2.x + spinSize * cos(angle - 3.1416 / 4));
            p.y = (int) (p2.y + spinSize * sin(angle - 3.1416 / 4));
            line( img, p, p2, CV_RGB(0,255,0), 1, CV_AA, 0 );

        }
   }

}

float maxElement(vector<float> data){
	float max = -100000;
	for(size_t i = 0; i < data.size(); i++)
		if(data[i] > max)
			max =data[i];

	return max;
}

void opticFlowCalculate(Mat &previous, Mat &current)
{
    //contagem máxima de pontos a seguir

    Mat gray, prevGray;
    vector<Point2f> pointsToTrack, pointsFounded, V;

    //pontos que serão usados para calcular o fluxo ótico
    //points[0] pontos da imagem anterior
    //points[1] ponto na nova imagem

     if(current.empty() || previous.empty()){
    	 	return;
     	 }


     /*Como estamos trabalhando com brilho, passamos para PB*/
     cvtColor(current, gray, CV_BGR2GRAY);
     cvtColor(previous, prevGray, CV_BGR2GRAY);

     int dy, dx;
     dy = 20;
     dx = 20;
     for (int y = 0; y < gray.rows; y+=gray.rows/dy)
    	 {
    	 for (int x = 0; x < gray.cols; x+=gray.cols/dx)
    	 	 {
             Point2f p(x, y);
             pointsToTrack.push_back(p);
          	 }
          }

	vector<uchar> status;
	//status guarda para guarda ponto do vetor points[0]
	//se a operação de detectar foi bem sucedida ou não
    vector<float> err;
    //estima erro para cada ponto achado?? not sure what it means

    calcOpticalFlowPyrLK(prevGray, gray, pointsToTrack, pointsFounded, status, err, winSize,
                                 3, termcrit, 0, 0.001);

    /*acha o vetor velocidade*/
    size_t i, k;

    float maxError = maxElement(err);

    for( i = k = 0; i < pointsFounded.size(); i++ )
    	{
       	//se o ponto falhou não será computado!
    	if( !status[i] )
    		continue;
    	if( err[i] > 1.0*maxError )
    	    		continue;
    	Point2f vel = (pointsFounded[i] - pointsToTrack[i]);
    	V.push_back(vel);
    	pointsFounded[k] = pointsFounded[i];
    	pointsToTrack[k++] = pointsToTrack[i];
    	}
    	pointsToTrack.resize(k);
    	pointsFounded.resize(k);

    	drawNormalizedArrows(current, pointsToTrack, V);

    return ;
}
