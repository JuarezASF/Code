/*
 * ProjetoFinal.cpp
 *
 *  Created on: 23/11/2013
 *      Author: juarez408
 */

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/background_segm.hpp>

#include <iostream>
#include <sstream>
#include <cassert>

using namespace std;
using namespace cv;

int main(){

	cout << "Este é o main do projeto!" << endl;
	cout << "aperte para sair!" << endl;
    int wait_c = cvWaitKey(0);
		if((char)wait_c == 27 )
			{// char == 27 : ESC key
			cout << "\n\n execução será encerrada!"<<endl;
			}


	return 0;
}
