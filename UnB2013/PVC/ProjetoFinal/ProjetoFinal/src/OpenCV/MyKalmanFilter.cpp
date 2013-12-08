/*
 * MyKalmanFilter.cpp
 *
 *  Created on: 24/11/2013
 *      Author: juarez408
 */

#include "MyKalmanFilter.h"

struct mouse_info_struct { int x,y; };
struct mouse_info_struct mouse_info = {-1,-1}, last_mouse;

vector<Point> mousev,kalmanv, future;


void on_mouse(int event, int x, int y, int flags, void* param) {
	//if (event == CV_EVENT_LBUTTONUP)
	{
		last_mouse = mouse_info;
		mouse_info.x = x;
		mouse_info.y = y;

//		cout << "got mouse " << x <<","<< y <<endl;
	}
}


void MyKalmanFilter::runDemo(){
    /*Esse exemplo foi retirado do site :
     * http://www.morethantechnical.com/2011/06/17/simple-kalman-filter-for-tracking-using-opencv-2-2-w-code/
     *
     * e modificado segundo a sugestão do usuário Anant, nos comentários do mesmo link,
     * para incluir no modelo a aceleração.
     *
     *outras modificações no exemplo foram feitas para tornar o código no meu
     *outras estilo de ptrogamação
     *
     * Ao incluir no modelo essa nova variável notou-se que o algoritmo se torna
     * muito mais rápido!
     *
     * autor : Juarez Aires Sampaio Filho
     * data : 23/11/2013 00h04
     *
    */

    Mat img(500, 500, CV_8UC3);

    KalmanFilter KF(6, 2, 0);
    //kalman filter com 4 variáveis de estado e 2 de medida

    Mat_<float> state(6, 1); /* (x, y, Vx, Vy, Ax, Ay) */
    //vairável para guardar estado

    Mat processNoise(6, 1, CV_32F);
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
        /*seta variaveis do modelo*/
        if (mouse_info.x < 0 || mouse_info.y < 0) {
            //captura o novo estado(espera 30 sec para atualização)
            imshow("mouse kalman", img);
            waitKey(30);
            continue;
        }

        //condições iniciais de posição
        KF.statePre.at<float>(0) = mouse_info.x;
        KF.statePre.at<float>(1) = mouse_info.y;
        //condições iniciais de velocidade
        KF.statePre.at<float>(2) = 0;
        KF.statePre.at<float>(3) = 0;
        //condições iniciais de aceleração
        KF.statePre.at<float>(4) = 0;
        KF.statePre.at<float>(5) = 0;

        //modelo
        /*A princípio o modelo poderia variar a cada iteração
         * nessa versão simplificada setamos o modelo inicialmente
         * e mantemos as matrizes constantes ao longo do processamento*/
        KF.transitionMatrix =
            *(
                Mat_<float>(6, 6) <</*		Sx	Sy	Vx	Vy	Ax		Ay	*/
                                    /*Sx*/	 1,	0,	1,	0,	0.5,	0,
                                    /*Sy*/	 0,	1,	0,	1,	0,		0.5,
                                    /*Vx*/	 0,	0,	1,	0,	1,		0,
                                    /*Vy*/	 0,	0,	0,	1,	0,		1,
                                    /*Ax*/	 0,	0,	0,	0,	1,		0,
                                    /*Ay*/	 0,	0,	0,	0,	0,		1
                            );
        //medidas??
        KF.measurementMatrix =
                *(
                Mat_<float>(2,6) <<
                            1, 0, 1, 0, 0.5, 0,
                            0, 1, 0, 1, 0, 0.5
                    );

        //erro no processo de medida??
        setIdentity(KF.processNoiseCov, Scalar::all(1e-4));

        //erro nas pedidas?
        setIdentity(KF.measurementNoiseCov, Scalar::all(1e-1));

        //erro a posteriori?
        setIdentity(KF.errorCovPost, Scalar::all(.1));

        //limpa a memória de pontos
        mousev.clear();
        kalmanv.clear();
        /*kalmanv e mousev são vector<Point> e guardam a memória
         * dos estados anteriores. Usamos ele para plotar a trajetória*/

        /*depois de setadas as condições iniciais e demais parâmetros,
         * rodamos o kalman Filter até que o usuário entre 'q' ou 'esc'*/
        for(;;)
        {
            //pega ponto predito
            Mat prediction = KF.predict();
            Point predictPt(prediction.at<float>(0),prediction.at<float>(1));

            //pega a medida atual e insere no histórico (mousec)
            measurement(0) = mouse_info.x;
            measurement(1) = mouse_info.y;
            Point measPt(measurement(0),measurement(1));
            mousev.push_back(measPt);

            //corrige com o novo ponto medido
            Mat estimated = KF.correct(measurement);
            Point statePt(estimated.at<float>(0),estimated.at<float>(1));

            //atualiza o novo estado calculado na memória
            kalmanv.push_back(statePt);


            // plot points
            // cada vez que rodamos limpamos
            img = Scalar::all(0);
            Draw::Cross(img,  statePt, Scalar(255,255,255), 5 );
            Draw::Cross(img,  measPt, Scalar(0,0,255), 5 );

            if(drawPast == true)
            {
                //dezenha todas as linhas anteriores
                for (unsigned int i = 0; i < mousev.size()-1; i++)
                    line(img, mousev[i], mousev[i+1], Scalar(255,255,0), 1);

                for (unsigned int i = 0; i < kalmanv.size()-1; i++)
                    Draw::dashedLine(img, kalmanv[i], kalmanv[i+1], Scalar(0, 255, 0));
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

    return;
}


void MyKalmanFilter::runDemo2(){
	/*
	 * esse demo tenta mostra o futuro e não o passado!
	*/

	double initialTime = (double)getTickCount();

    Mat img(500, 500, CV_8UC3);

    KalmanFilter KF(6, 2, 0);
    //kalman filter com 4 variáveis de estado e 2 de medida

    Mat_<float> state(6, 1); /* (x, y, Vx, Vy, Ax, Ay) */
    //vairável para guardar estado

    Mat processNoise(6, 1, CV_32F);
    //guarda o ruído

    Mat_<float> measurement(2,1);
    measurement.setTo(Scalar(0));
    //marca a medida inicial para (0,0);

    char code = (char)-1;
    //sinal de controle de parada

	namedWindow("mouse kalman");
	setMouseCallback("mouse kalman", on_mouse, 0);


	bool drawPast = false;
	bool drawFuture = false;

	int futureSize = 50;
    for(;;)
    {
    	/*seta variaveis do modelo*/
		if (mouse_info.x < 0 || mouse_info.y < 0) {
			//captura o novo estado(espera 30 sec para atualização)
			imshow("mouse kalman", img);
			waitKey(30);
			continue;
		}

		//condições iniciais de posição
        KF.statePre.at<float>(0) = mouse_info.x;
		KF.statePre.at<float>(1) = mouse_info.y;
		//condições iniciais de velocidade
		KF.statePre.at<float>(2) = 0;
		KF.statePre.at<float>(3) = 0;
		//condições iniciais de aceleração
		KF.statePre.at<float>(4) = 0;
		KF.statePre.at<float>(5) = 0;

		//modelo
		/*A princípio o modelo poderia variar a cada iteração
		 * nessa versão simplificada setamos o modelo inicialmente
		 * e mantemos as matrizes constantes ao longo do processamento*/
		KF.transitionMatrix =
			*(
				Mat_<float>(6, 6) <</*		Sx	Sy	Vx	Vy	Ax		Ay	*/
									/*Sx*/	 1,	0,	1,	0,	0.5,	0,
									/*Sy*/	 0,	1,	0,	1,	0,		0.5,
									/*Vx*/	 0,	0,	1,	0,	1,		0,
									/*Vy*/	 0,	0,	0,	1,	0,		1,
									/*Ax*/	 0,	0,	0,	0,	1,		0,
									/*Ay*/	 0,	0,	0,	0,	0,		1
							);
		//medidas??
        KF.measurementMatrix =
        		*(
        		Mat_<float>(2,6) <<
        					1, 0, 1, 0, 0.5, 0,
        					0, 1, 0, 1, 0, 0.5
        			);

        //erro no processo de medida??
        setIdentity(KF.processNoiseCov, Scalar::all(1e-4));

        //erro nas pedidas?
        setIdentity(KF.measurementNoiseCov, Scalar::all(1e-1));

        //erro a posteriori?
        setIdentity(KF.errorCovPost, Scalar::all(.1));

        //limpa a memória de pontos
		mousev.clear();
		kalmanv.clear();
		/*kalmanv e mousev são vector<Point> e guardam a memória
		 * dos estados anteriores. Usamos ele para plotar a trajetória*/

		/*depois de setadas as condições iniciais e demais parâmetros,
		 * rodamos o kalman Filter até que o usuário entre 'q' ou 'esc'*/
        for(;;)
        {
            //pega a medida atual e insere no histórico (mousec)
            measurement(0) = mouse_info.x;
			measurement(1) = mouse_info.y;
			Point measPt(measurement(0),measurement(1));
			mousev.push_back(measPt);

			future.clear();
			KalmanFilter DelfusOracle = myMath::copyKF(KF);
			for(int j = 0; j < futureSize; j++)
				/*calcula os pontos no futuro*/
				{
				Mat prediction = DelfusOracle.predict();
				Point predictPt(prediction.at<float>(0),prediction.at<float>(1));
				future.push_back(predictPt);

			    Mat_<float> predictedMeasurement(2,1);
				predictedMeasurement(0) = prediction.at<float>(0);
				predictedMeasurement(1) = prediction.at<float>(1);
				DelfusOracle.correct(predictedMeasurement);
				DelfusOracle.errorCovPre.copyTo(DelfusOracle.errorCovPost);
				}
			KF.predict();

			//corrige com o novo ponto medido
			Mat estimated = KF.correct(measurement);
			Point statePt(estimated.at<float>(0),estimated.at<float>(1));
			//coloca o novo estado na memória memória
			kalmanv.push_back(statePt);


            // plot points
			// cada vez que rodamos limpamos
            img = Scalar::all(0);
            Draw::Cross(img,  statePt, Scalar(255,255,255), 5 );
            Draw::Cross(img,  measPt, Scalar(0,0,255), 5 );

            if(drawPast == true)
            {
            	//dezenha todas as linhas anteriores
				for (unsigned int i = 0; i < mousev.size()-1; i++)
					Draw::Line(img, mousev[i], mousev[i+1], Scalar(255,255,0));
				for (unsigned int i = 0; i < kalmanv.size()-1; i++)
					Draw::dashedLine(img, kalmanv[i], kalmanv[i+1], Scalar(0, 255, 0));
            }

            if(drawFuture == true)
            {
            //dezenha todas as linhas do futuro
            for (unsigned int i = 0; i < future.size()-1; i++)
            	Draw::dashedLine(img, future[i], future[i+1], Scalar(0, 0, 255));
            }


            double currentTime = ((double)getTickCount() - initialTime)/getTickFrequency();
        	string sTime(ToString(currentTime));
        	string sPrintTime(string("time: ") + sTime + string("s"));
        	Draw::Text_in_a_Box(img, Point(0 ,20), sPrintTime,
        			Scalar(255, 255, 255), 0.5);


            imshow( "mouse kalman", img );

            code = (char)waitKey(100);
            if( code > 0 )
                break;
        }
        if( code == 27 || code == 'q' || code == 'Q' )
            break;
        if( code == 'p' || code == 'P' )
           drawPast = !drawPast;
        if( code == 'f' || code == 'F' )
           drawFuture = !drawFuture;

    }

    return;
}


void runDemo3(ProjetoFinal &mainWindow){
    /*
     * esse demo tenta mostra o futuro e não o passado!
    */

    double initialTime = (double)getTickCount();

    Mat img(500, 500, CV_8UC3);

    KalmanFilter KF(6, 2, 0);
    //kalman filter com 6 variáveis de estado e 2 de medida

    Mat_<float> state(6, 1); /* (x, y, Vx, Vy, Ax, Ay) */
    //vairável para guardar estado

    Mat processNoise(6, 1, CV_32F);
    //guarda o ruído

    Mat_<float> measurement(2,1);
    measurement.setTo(Scalar(0));
    //marca a medida inicial para (0,0);

    char code = (char)-1;
    //sinal de controle de parada

    namedWindow("mouse kalman");
    setMouseCallback("mouse kalman", on_mouse, 0);


    bool drawPast = false;
    bool drawFuture = false;

    int futureSize = 50;
    for(;;)
    {
        /*seta variaveis do modelo*/
        if (mouse_info.x < 0 || mouse_info.y < 0) {
            //captura o novo estado(espera 30 sec para atualização)
            imshow("mouse kalman", img);
            waitKey(30);
            continue;
        }

        //condições iniciais de posição
        KF.statePre.at<float>(0) = mouse_info.x;
        KF.statePre.at<float>(1) = mouse_info.y;
        //condições iniciais de velocidade
        KF.statePre.at<float>(2) = 0;
        KF.statePre.at<float>(3) = 0;
        //condições iniciais de aceleração
        KF.statePre.at<float>(4) = 0;
        KF.statePre.at<float>(5) = 0;

        //modelo
        /*A princípio o modelo poderia variar a cada iteração
         * nessa versão simplificada setamos o modelo inicialmente
         * e mantemos as matrizes constantes ao longo do processamento*/
        KF.transitionMatrix =
            *(
                Mat_<float>(6, 6) <</*		Sx	Sy	Vx	Vy	Ax		Ay	*/
                                    /*Sx*/	 1,	0,	1,	0,	0.5,	0,
                                    /*Sy*/	 0,	1,	0,	1,	0,		0.5,
                                    /*Vx*/	 0,	0,	1,	0,	1,		0,
                                    /*Vy*/	 0,	0,	0,	1,	0,		1,
                                    /*Ax*/	 0,	0,	0,	0,	1,		0,
                                    /*Ay*/	 0,	0,	0,	0,	0,		1
                            );
        //medidas??
        KF.measurementMatrix =
                *(
                Mat_<float>(2,6) <<
                            1, 0, 1, 0, 0.5, 0,
                            0, 1, 0, 1, 0, 0.5
                    );

        //erro no processo de medida??
        setIdentity(KF.processNoiseCov, Scalar::all(1e-4));

        //erro nas pedidas?
        setIdentity(KF.measurementNoiseCov, Scalar::all(1e-1));

        //erro a posteriori?
        setIdentity(KF.errorCovPost, Scalar::all(.1));

        //limpa a memória de pontos
        mousev.clear();
        kalmanv.clear();
        /*kalmanv e mousev são vector<Point> e guardam a memória
         * dos estados anteriores. Usamos ele para plotar a trajetória*/

        /*depois de setadas as condições iniciais e demais parâmetros,
         * rodamos o kalman Filter até que o usuário entre 'q' ou 'esc'*/
        for(;;)
        {
            //pega a medida atual e insere no histórico (mousec)
            measurement(0) = mouse_info.x;
            measurement(1) = mouse_info.y;
            Point measPt(measurement(0),measurement(1));
            mousev.push_back(measPt);

            future.clear();
            KalmanFilter DelfusOracle = myMath::copyKF(KF);
            for(int j = 0; j < futureSize; j++)
                /*calcula os pontos no futuro*/
                {
                Mat prediction = DelfusOracle.predict();
                Point predictPt(prediction.at<float>(0),prediction.at<float>(1));
                future.push_back(predictPt);

                Mat_<float> predictedMeasurement(2,1);
                predictedMeasurement(0) = prediction.at<float>(0);
                predictedMeasurement(1) = prediction.at<float>(1);
                DelfusOracle.correct(predictedMeasurement);
                DelfusOracle.errorCovPre.copyTo(DelfusOracle.errorCovPost);
                }

            KF.predict();
            //corrige com o novo ponto medido
            Mat estimated = KF.correct(measurement);
            Point statePt(estimated.at<float>(0),estimated.at<float>(1));
            //coloca o novo estado na memória memória
            kalmanv.push_back(statePt);


            // plot points
            // cada vez que rodamos limpamos
            img = Scalar::all(0);
            Draw::Cross(img,  statePt, Scalar(255,255,255), 5 );
            Draw::Cross(img,  measPt, Scalar(0,0,255), 5 );

            if(drawPast == true)
            {
                //dezenha todas as linhas anteriores
                for (unsigned int i = 0; i < mousev.size()-1; i++)
                    Draw::Line(img, mousev[i], mousev[i+1], Scalar(255,255,0));
                for (unsigned int i = 0; i < kalmanv.size()-1; i++)
                    Draw::dashedLine(img, kalmanv[i], kalmanv[i+1], Scalar(0, 255, 0));
            }

            if(drawFuture == true)
            {
            //dezenha todas as linhas do futuro
            for (unsigned int i = 0; i < future.size()-1; i++)
                Draw::dashedLine(img, future[i], future[i+1], Scalar(0, 0, 255));
            }


            double currentTime = ((double)getTickCount() - initialTime)/getTickFrequency();
            string sTime(ToString(currentTime));
            string sPrintTime(string("time: ") + sTime + string("s"));
            Draw::Text_in_a_Box(img, Point(0 ,20), sPrintTime,
                    Scalar(255, 255, 255), 0.5);


            imshow( "mouse kalman", img );
            mainWindow.setInputImg(img);

            code = (char)waitKey(100);

            drawPast = mainWindow.pastMode;
            drawFuture = mainWindow.futureMode;

            if( code > 0 )
                break;

        }

        if( code == 27 || code == 'q' || code == 'Q' )
            break;
    }

    return;
}


void runDemo4(ProjetoFinal &mainWindow){
    /*
     * esse demo tenta mostra o futuro e não o passado!
    */


    Mat img(500, 500, CV_8UC3);

    mainWindow.setInputImg(img);

    myTimer::wait(50);



    return;
}



