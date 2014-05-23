#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //SET CLOCK
    this->clock = new QTimer(0);
    connect(this->clock, SIGNAL(timeout()), this, SLOT(process()));

    //INITIATE CAMERA
    videoInput = NULL;
    initVideo();

    //START CLOCK (PÓS CÂMERA SER INICIALIZADA)
    this->clock->start(50);
    //lança evento timeout() a cada 500 milisegundos


    //COLOTS TRACKBARS

    connect(this, SIGNAL(rangeChanged()), this, SLOT(findThresholdImg()));

    ui->ColorMinChannelOption->addItem("hue");
    ui->ColorMinChannelOption->addItem("saturation");
    ui->ColorMinChannelOption->addItem("value");

    ui->ColorMaxChannelOption->addItem("hue");
    ui->ColorMaxChannelOption->addItem("saturation");
    ui->ColorMaxChannelOption->addItem("value");

    //DEFINE COLOR BUTTOM
    /*
    Orange  0-22
    Yellow 22- 38
    Green 38-75
    Blue 75-130
    Violet 130-160
    Red 160-179*/
    ui->DefinedColorOption->addItem("Laranja");
    ui->DefinedColorOption->addItem("Amarelo");
    ui->DefinedColorOption->addItem("Verde");
    ui->DefinedColorOption->addItem("Azul");
    ui->DefinedColorOption->addItem("Roxo");
    ui->DefinedColorOption->addItem("Vermelho");

    minCorHSV[0] = 100;
    minCorHSV[1] = 0;
    minCorHSV[2] = 0;

    maxCorHSV[0] = 179;
    maxCorHSV[1] = 255;
    maxCorHSV[2] = 255;

    this->updateColorTrackBars();
    emit rangeChanged();

    //numero de falhas iniiais zerado
    //sera usado para controlar erros de abertura de camera
    numberOfFailure = 0;

    //BUTÃO PARA BORRA IMAGEM
    //orem : 3 5 7 9 11 13 21 31
    ui->SizeOfGaussian->addItem("3");//0
    ui->SizeOfGaussian->addItem("5");//1
    ui->SizeOfGaussian->addItem("7");
    ui->SizeOfGaussian->addItem("9");//3
    ui->SizeOfGaussian->addItem("11");
    ui->SizeOfGaussian->addItem("13");//5
    ui->SizeOfGaussian->addItem("21");
    ui->SizeOfGaussian->addItem("31");//7
    ui->SizeOfGaussian->addItem("51");
    ui->SizeOfGaussian->addItem("61");//9
    ui->SizeOfGaussian->addItem("71");
    ui->SizeOfGaussian->setCurrentIndex(7);

    pastHistoryMaxSize = 100;

    int RaioInicial = 30;
    Raio = RaioInicial;
    ui->raioValueLabel->setText(QString::number(RaioInicial));
    ui->raioSlider->setValue(RaioInicial);

    //variáveis para modo de rocord
    imageCounter = 0;
    ui->baseNameLineEdit->setText("./images/");
    frames_imprimidos = 0;
    frame_control = 0;

    control_storeInstantFuture = false;
    iteration_recording = 0;

    number_of_objects = 0;

    number_of_shots_to_take = 30;


}

Widget::~Widget()
{
    delete ui;
}

bool Widget::openVideo(int n){
    if(videoInput == NULL)
        videoInput = new VideoCapture(n);
    else
    {
        videoInput->release();
        videoInput->open(n);
    }

    if(!videoInput->isOpened()){
       stringstream msg;
       msg << "webcam " << n << " não pode ser aberta";
       reportBad(msg.str());
       return false;
    }

    if(videoInput->isOpened())
        return true;
    else
        return false;
   }

void Widget::initVideo(){
    bool sucesso;
    for(int i = 0; i < 10; i++)
    {
        sucesso = openVideo(i);
        if(sucesso)
            ui->selectVideoComboBox->addItem(QString("Câmera") + QString::number(i));
    }
    for(int i = 0; i < 10; i++)
    {
        sucesso = openVideo(i);
        if(sucesso)
            break;
    }
    if(sucesso == false)
    {
        reportBad("Nenhum vídeo de 0 à 10 pode ser inicializado!");
        this->clock->stop();
    }
}


void Widget::report(const string text){
    ui->logText->setTextColor(QColor("blue"));
    ui->logText->append(QString(text.c_str()));
}



void Widget::reportGood(const string text){
    ui->logText->setTextColor(QColor("green"));
    ui->logText->append(QString(text.c_str()));
}
void Widget::reportBad(const string text){
    ui->logText->setTextColor(QColor("red"));
    ui->logText->append(QString(text.c_str()));
}

void Widget::on_ColorMinChannelSlider_valueChanged(int value)
{
    ui->ColorMinValue->setText(QString::number(value));
    switch(ui->ColorMinChannelOption->currentIndex()){

        case 0:
                minCorHSV[0] = value;
                break;
        case 1:
                minCorHSV[1] = value;
                break;
        case 2:
                minCorHSV[2] = value;
                break;
        default:
                errorMsg("Opção para cor não definida");
                break;
    }

     emit rangeChanged();

}

void Widget::on_ColorMaxChannelSlider_valueChanged(int value)
{
    ui->ColorMaxValue->setText(QString::number(value));

    switch(ui->ColorMaxChannelOption->currentIndex()){

        case 0:
                maxCorHSV[0] = value;
                break;
        case 1:
                maxCorHSV[1] = value;
                break;
        case 2:
                maxCorHSV[2] = value;
                break;
        default:
                errorMsg("Opção para cor não definida");
                break;
    }

    emit rangeChanged();

}

void Widget::on_ColorMinChannelOption_currentIndexChanged(int index)
{
    QSlider *target = ui->ColorMinChannelSlider;
    int valueToChangeTo;

    switch(index){
        case 0:
            valueToChangeTo = minCorHSV[0];
            target->setRange(0, 179);
            break;
        case 1:
            valueToChangeTo = minCorHSV[1];
            target->setRange(0, 255);
            break;
        case 2:
            valueToChangeTo = minCorHSV[2];
            target->setRange(0, 255);
            break;
        default:
            errorMsg("Caso não definido!");
            break;
        }

    target->setValue(valueToChangeTo);
}

void Widget::on_ColorMaxChannelOption_currentIndexChanged(int index)
{
        QSlider *target = ui->ColorMaxChannelSlider;
        int valueToChangeTo;

        switch(index){
            case 0:
                valueToChangeTo = maxCorHSV[0];
                target->setRange(0, 179);
                break;
            case 1:
                valueToChangeTo = maxCorHSV[1];
                target->setRange(0, 255);
                break;
            case 2:
                valueToChangeTo = maxCorHSV[2];
                target->setRange(0, 255);
                break;
            default:
                errorMsg("Caso não definido!");
                break;
            }

        target->setValue(valueToChangeTo);

}

void Widget::on_DefinedColorOption_currentIndexChanged(int index)
{
        switch(index){
            case 0://laranja 0-22
                minCorHSV[0] = 0;
                minCorHSV[1] = 70;
                minCorHSV[2] = 0;

                maxCorHSV[0] = 22;
                maxCorHSV[1] = 255;
                maxCorHSV[1] = 255;

                break;
            case 1://amarelo 22-38
                minCorHSV[0] = 22;
                minCorHSV[1] = 70;
                minCorHSV[2] = 0;

                maxCorHSV[0] = 38;
                maxCorHSV[1] = 255;
                maxCorHSV[1] = 255;

                break;

            case 2: // verde 38-75
                minCorHSV[0] = 38;
                minCorHSV[1] = 0;
                minCorHSV[2] = 0;

                maxCorHSV[0] = 75;
                maxCorHSV[1] = 255;
                maxCorHSV[1] = 255;

                break;
            case 3://azul 75-130
                minCorHSV[0] = 75;
                minCorHSV[1] = 70;
                minCorHSV[2] = 0;

                maxCorHSV[0] = 130;
                maxCorHSV[1] = 255;
                maxCorHSV[1] = 255;

                break;

            case 4:// violeta 130-160
                minCorHSV[0] = 130;
                minCorHSV[1] = 70;
                minCorHSV[2] = 0;

                maxCorHSV[0] = 160;
                maxCorHSV[1] = 255;
                maxCorHSV[1] = 255;

                break;
            case 5:// vermelho 160-179
                minCorHSV[0] = 160;
                minCorHSV[1] = 70;
                minCorHSV[2] = 0;

                maxCorHSV[0] = 179;
                maxCorHSV[1] = 255;
                maxCorHSV[1] = 255;

                break;

            case 6:
                errorMsg("Opção Indefinida!");
                break;

            }

        this->updateColorTrackBars();
        emit rangeChanged();

}

void Widget::updateColorTrackBars()
    {
        QSlider *target = ui->ColorMaxChannelSlider;
        int index = ui->ColorMaxChannelOption->currentIndex();
        int valueToChangeTo;

        switch(index){
            case 0:
                valueToChangeTo = maxCorHSV[0];
                target->setRange(0, 179);
                break;
            case 1:
                valueToChangeTo = maxCorHSV[1];
                target->setRange(0, 255);
                break;
            case 2:
                valueToChangeTo = maxCorHSV[2];
                target->setRange(0, 255);
                break;
            default:
                errorMsg("Caso não definido!");
                break;
            }

        target->setValue(valueToChangeTo);

        target = ui->ColorMinChannelSlider;
        index = ui->ColorMinChannelOption->currentIndex();

        switch(index){
            case 0:
                valueToChangeTo = minCorHSV[0];
                target->setRange(0, 179);
                break;
            case 1:
                valueToChangeTo = minCorHSV[1];
                target->setRange(0, 255);
                break;
            case 2:
                valueToChangeTo = minCorHSV[2];
                target->setRange(0, 255);
                break;
            default:
                errorMsg("Caso não definido!");
                break;
            }

        target->setValue(valueToChangeTo);


    }

void Widget::errorMsg(string msg){
    QMessageBox msgBox;
    msgBox.setText(QString(msg.c_str()));
    msgBox.exec();
}

void Widget::findThresholdImg(){

    if(!currentFrame.empty())
    {
    Mat HSV_Input;
    cvtColor(currentFrame, HSV_Input, CV_BGR2HSV);

    Scalar colorMin(minCorHSV[0], minCorHSV[1], minCorHSV[2]);
    Scalar colorMax(maxCorHSV[0], maxCorHSV[1], maxCorHSV[2]);


    Mat BinaryImg =
                ColorDetection::GetThresholdedImage(
                     HSV_Input, colorMin,colorMax);

    Cv2QtImage::setLabelImage(ui->currentSegmentationImg, BinaryImg);
    }
}

void Widget::addColorToTracking(vector<Scalar> &range){

    Mat HSV_Input;
    if(currentFrame.empty())
        {
        errorMsg("O video ainda nao foi inicializado!");
        return;
        }
    cvtColor(currentFrame, HSV_Input, CV_BGR2HSV);

    Mat BinaryImg =
                ColorDetection::GetThresholdedImage(
                HSV_Input, range[0],range[1]);
    bool inutil;
    Point initialPos = ColorDetection::FindCenter(BinaryImg, 0, inutil);


    Scalar color = (range[0] + range[1])*0.5;

    ObjectToDetect *newTarget = new ObjectToDetect(range, color, initialPos);

    targets.push_back(newTarget);

   QString targetName = QString("Objeto ") + QString::number(newTarget->name);

   QString reportMsg = targetName + QString(" criado!\n");
   /*reportMsg.append(QString("\t from (%1, %2, %3) to (%4, %5, %6)").arg(QString::number(range[0][0]),
           QString::number(range[0][1]), QString::number(range[0][2]), QString::number(range[1][0]),
           QString::number(range[1][1]), QString::number(range[1][2])));
   */
   reportMsg.append(QString("\t from %1 to %2").arg(QString2String::Scalar2QString(range[0]),QString2String::Scalar2QString(range[1]) ));

    report(reportMsg.toStdString());

    ui->trackedColorsList->addItem(targetName);

    //adiciona espaço no vetor de sucessos
    detectionSucess.resize(detectionSucess.size()+1);
    objectsCenter.resize(objectsCenter.size()+1);
    pastHistory.resize(pastHistory.size() + 1);
}

void Widget::on_addTotrackingButtom_clicked()
{
    Scalar minColor(minCorHSV[0], minCorHSV[1], minCorHSV[2]);
    Scalar maxColor(maxCorHSV[0], maxCorHSV[1], maxCorHSV[2]);

    if( maxColor[0] < minColor[0] || maxColor[1] < minColor[1] || maxColor[2] < minColor[2] )
    {
        errorMsg(string("Range inválido! Escolha novamente"));
    }
    else{
    vector<Scalar> range;
    range.push_back(minColor);
    range.push_back(maxColor);

    addColorToTracking(range);
    number_of_objects++;

    }

}


void Widget::on_trackedColorsList_currentIndexChanged(int index)
{
    if(targets.size() > 1){
    ObjectToDetect *target = targets[index];
    Scalar minCor = (target->colorRange)[0];
    Scalar maxCor = (target->colorRange)[1];

    minCorHSV[0] = minCor[0]; minCorHSV[1] = minCor[1]; minCorHSV[2] = minCor[2];
    maxCorHSV[0] = maxCor[0]; maxCorHSV[1] = maxCor[1]; maxCorHSV[2] = maxCor[2];

    updateColorTrackBars();
    }
}


void Widget::on_deleteButtom_clicked()
{
    unsigned int index = ui->trackedColorsList->currentIndex();
    if(index > targets.size())
        errorMsg("Valor Inválido!");
    targets.erase(targets.begin()+index);
    ui->trackedColorsList->removeItem(index);
    pastHistory.erase(pastHistory.begin()+index);
    number_of_objects --;
}

void Widget::pauseVideo(){
    this->clock->stop();
    reportBad("O video esta sendo pausado");
}

void Widget::on_BorrarButtom_clicked()
{
    if(CONTROL_FILTER_GAUSSIAN == true)
        CONTROL_FILTER_GAUSSIAN =false;
    else
        CONTROL_FILTER_GAUSSIAN = true;

}

void Widget::on_SizeOfGaussian_currentIndexChanged(int )
{
    //ordem : 3 5 7 9 11 13 21 31
    SizeGaussFilter = ui->SizeOfGaussian->currentText().toInt();
}

void Widget::on_futureButtom_stateChanged(int)
{
    CONTROL_SEE_FUTURE = ui->futureButtom->isChecked();
}

void Widget::on_pastButtom_stateChanged(int)
{
    CONTROL_SEE_PAST = ui->pastButtom->isChecked();
}

vector<Point> Widget::findTargets(Mat &RGB_Input){
    vector<Point> centers;
    Mat HSV_Input;
    cvtColor(RGB_Input, HSV_Input, CV_BGR2HSV);

    for(unsigned int i = 0; i < targets.size(); i++){
        Scalar colorMin = targets[i]->colorRange[0];
        Scalar colorMax = targets[i]->colorRange[1];

        Mat BinaryImg =
            ColorDetection::GetThresholdedImage(
                        HSV_Input, colorMin,colorMax);

        //filtragem de ruidos
        Filtros::Erosion(BinaryImg, BinaryImg, 3);
        Filtros::Erosion(BinaryImg, BinaryImg, 3);
        Filtros::Dilation(BinaryImg, BinaryImg, 3);

        int ColorDetectionThreshold = 20;

        bool sucessoAtual;

        Point currentCenter =
                   ColorDetection::FindCenter(BinaryImg,
                                           ColorDetectionThreshold,
                                           sucessoAtual);
        detectionSucess[i] = sucessoAtual;

        centers.push_back(currentCenter);
        }

    return centers;
}

vector<Point> Widget::findKalmanCenters(vector<Point> dataInput){
    vector<Point> kalmanCenters;
    if(dataInput.empty()){
        errorMsg("Nao ha objetos a serem detectados!");
        return kalmanCenters;
    }
    kalmanCenters.resize(dataInput.size());
    KalmanFilter *KF;

    for(unsigned int i = 0; i < targets.size(); i++){
        KF = targets[i]->KF;

        //apenas conversao de estruturas usadas
        Mat_<float> measurement(2,1);
        measurement(0) = dataInput[i].x;
        measurement(1) = dataInput[i].y;

        Mat estimated;
        Mat prediction = KF->predict();
        if(detectionSucess[i] == true)
            {
            //caso a detecção tenha sido um sucesso jogamos a nova medida no filtro
            //ao chamar correct já estamos adicionando a nova medida ao filtro
            estimated = KF->correct(measurement);
            }
        else{
            /*caso a medição tenha falhada realimentamos o filtro com a própria
            predição anterior*/
            Mat_<float> predictedMeasurement(2,1);
            predictedMeasurement(0) = prediction.at<float>(0);
            predictedMeasurement(1) = prediction.at<float>(1);
            estimated = KF->correct(predictedMeasurement);
            KF->errorCovPre.copyTo(KF->errorCovPost);
            //copiar a covPre para covPos [dica de um usuário de algum fórum]
            }
        Point statePt(estimated.at<float>(0),estimated.at<float>(1));

        kalmanCenters[i] = statePt;
        /*existe o centro medido pela previsão e o centro que o filtro de kalman
        acredita ser o real. O centro de kalman é uma ponderação das medidas e do modelo
        com conhecimento prévio de um erro aleatório*/
    }

    return kalmanCenters;
}

void Widget::drawDetectionResult(Mat &outputFrame, vector<Point> &centers){
    float crossSize = 10;

    //procura cores para desenhar
    vector<Scalar> colorsToPaint;
    for(unsigned int i = 0; i < centers.size(); i++)
             colorsToPaint.push_back(targets[i]->colorPaint);


    Draw::Crosses(outputFrame, centers, colorsToPaint, crossSize, detectionSucess);
}

void Widget::drawKalmanResult(Mat &outputFrame, vector<Point> &kalmanCenters){
    vector<Vec3f> kalmanCircles;
    vector<Scalar> colorsToPaint;

    float radiusKalmanCircles = Raio;
    //raio é uma variável global definida na interface em tempo de execução

    if(kalmanCenters.size() != targets.size())
        reportBad("O numero de elementos a desenhar e diferente do numero de alvos procurados!");

    //gera circulos a serem desenhados
    for(unsigned int i = 0; i < kalmanCenters.size(); i++){
            Vec3f currentCircle(kalmanCenters[i].x, kalmanCenters[i].y,
                  radiusKalmanCircles);
            kalmanCircles.push_back(currentCircle);

            colorsToPaint.push_back(targets[i]->colorPaint);
    }

    Draw::Circles(outputFrame, kalmanCircles, colorsToPaint);
}

void Widget::on_raioSlider_valueChanged(int value)
{
    Raio = value;
    ui->raioValueLabel->setText(QString::number(value));
}

vector<vector<Point> > Widget::predictFuture(int futureSize){
    vector<vector<Point> > future;
    future.resize(targets.size());

    for(unsigned int i = 0; i < targets.size(); i++)
        {
        KalmanFilter *KF;
        KF = targets[i]->KF;

        KalmanFilter DelfusOracle = myMath::copyKF(*KF);
            /*para ver o futuro copiamos o estado do filtro atual e
              o realimentamos com suas próprias previsões um número fixo de vezes*/
        for(int j = 0; j < futureSize; j++)
                //CALCULA PONTOS DO FUTURO
            {

            Mat prediction = DelfusOracle.predict();
            Point predictPt(prediction.at<float>(0),prediction.at<float>(1));

            future[i].push_back(predictPt);

            Mat_<float> predictedMeasurement(2,1);
            predictedMeasurement(0) = prediction.at<float>(0);
            predictedMeasurement(1) = prediction.at<float>(1);

            DelfusOracle.correct(predictedMeasurement);

            DelfusOracle.errorCovPre.copyTo(DelfusOracle.errorCovPost);
                //copiamos covPre para covPost seguindo a dica de um fórum
                //o Vidal não gosta dessa dica, diz ele que isso engana o filtro
            }


        }//end for each color

    return future;
}

void Widget::drawFuturePrediction(Mat &outputFrame,vector<vector<Point> > &future){
    //DEZENHA PONTOS DO FUTURO
    for(unsigned int i = 0; i < targets.size(); i++){
        vector<Vec3f> kalmanFutureCircles;
        vector<Scalar> ColorsToPaintFuture;
        for(unsigned int n = 0; n < future[i].size(); n++)
            {
                int KalmanFutureRaio = 2;
                Vec3f currentCircle(future[i][n].x, future[i][n].y,
                      KalmanFutureRaio);
                kalmanFutureCircles.push_back(currentCircle);

                //ColorsToPaintFuture.push_back(targets[i]->colorPaint);
                ColorsToPaintFuture.push_back(Scalar(255, 255, 255));

            }
        Draw::Circles(outputFrame, kalmanFutureCircles, ColorsToPaintFuture);
    }
}

void Widget::predictFutureColisions(Mat &outputFrame,vector<vector<Point> > &future){
    /*para todas as posições futuras dos pontos, procura por colisões
      medimos a distância entre todas as partículas procurando por colisões */
             for(unsigned int i = 0; i < future.size(); i++)
             {//para todos os objetos
                for(unsigned int j = i+1; j < future.size(); j++)
                    //para todos os outros objetos
                    {
                    for(unsigned int n = 0; n < future[i].size(); n++){
                       //para todos os pontos de futuro
                        float distance =
                                pow(future[i][n].x - future[j][n].x, 2) +
                                pow(future[i][n].y - future[j][n].y, 2);
                        distance = sqrt(distance);

                        float sumRadius = 2*Raio;

                        if(distance < sumRadius)
                            {
                                float xColision =
                                        (future[i][n].x + future[j][n].x)*0.5;
                                float yColision =
                                        (future[i][n].y + future[j][n].y)*0.5;

                                Point colisionPoint(xColision, yColision);

                                Scalar xColor(0, 0, 0);

                                int xSize = 10;
                                Draw::Cross(outputFrame, colisionPoint, xColor, xSize);
                                if(CONTROL_RECORDING){
                                    float x = iteration_recording;
                                    float y = colisionPoint.x;
                                    float z = colisionPoint.y;
                                    QVector3D tripla(x,y,z);
                                    toRecord_colisionsPoints.push_back(tripla);
                                    }
                                break;
                                //se já achou uma colisão, passa para o próximo possível alvo
                            }
                    }
                    }
             }

        }


void Widget::addToPastHistory(vector<Point> &kalmanCenters){

    if(!pastHistory.empty())
        if(pastHistory[0].size() > pastHistoryMaxSize)
                for (unsigned int i = 0; i < pastHistory.size(); i++)
                    pastHistory[i].clear();

    for(unsigned int i = 0; i < pastHistory.size(); i++)
        pastHistory[i].push_back(kalmanCenters[i]);

}

void Widget::drawPastHistory(Mat &outputFrame){
    for(unsigned int n = 0; n < pastHistory.size(); n++)
            for (unsigned int i = 0; i < pastHistory[n].size() - 1; i++)
                    Draw::Line(outputFrame, pastHistory[n][i], pastHistory[n][i+1],
                            targets[n]->colorPaint);

}


void Widget::on_ClearPastButtom_clicked()
{
    for (unsigned int i = 0; i < pastHistory.size(); i++)
        pastHistory[i].clear();
}

void Widget::on_gnuplotButton_clicked()
{
    showGnuplot();
}


void Widget::showGnuplot(){
    Gnuplot gp;

    std::cout << "Press Ctrl-C to quit (closing gnuplot window doesn't quit)." << std::endl;

    gp << "set yrange [-1:1]\n";

    const int N = 1000;
    std::vector<double> pts(N);

    double theta = 0;
    while(1) {
        for(int i=0; i<N; i++) {
            double alpha = (double(i)/N-0.5) * 10;
            pts[i] = sin(alpha*8.0 + theta) * exp(-alpha*alpha/2.0);
        }

        gp << "plot '-' binary" << gp.binFmt1d(pts, "array") << "with lines notitle\n";
        gp.sendBinary1d(pts);
        gp.flush();

        theta += 0.2;
        myMath::mysleep(100);
    }
}

void Widget::on_selectVideoComboBox_currentIndexChanged(int index)
{
    openVideo(index);
}

void Widget::on_pushButton_clicked()
{
    ui->logText->clear();
}

void Widget::on_pushButton_2_clicked()
{
    CONTROL_RECORDING = true;

    toRecord_instantDetectionToRecord.clear();
    toRecord_instantKalmandEstimation.clear();

    for(unsigned int i = 0; i < number_of_objects; i++){
        toRecord_instantDetectionToRecord.push_back(vector<QVector3D>());
        toRecord_instantKalmandEstimation.push_back(vector<QVector3D>());
    }

    reportGood("Vamos começar a gravar!");
}

void Widget::recordStep(){
    QString file = ui->baseNameLineEdit->text();
    file = file + QString::number(imageCounter++) + ",png";

    const QPixmap *img = ui->OutputImg->pixmap();

    bool sucesso = img->save(file, "PNG");

    if(sucesso == true)
        {
        ui->recorTimeLabel->setText("Tomadas " + QString::number(imageCounter));
        }
    else
        reportBad("Imagem não pode ser salva!");
}

void Widget::recordEnd(){
    CONTROL_RECORDING = false;
    frames_imprimidos = 0;
    frame_control = 0;
    imageCounter = 0;
    iteration_recording = 0; //reseta para a próxima gravação

    //salva dados dos futuros instantêneos

    //arruma os dados: temos para cada instante i, os pontos do futuro para as n partículas
    //queremos ter para cada uma das n partículas, todos os futuros

    vector<vector<QVector3D> > instantFuturePorObjeto;
    unsigned int n_de_objetos = instantFutureToRecord[0].size();

    //instantFutureToRecord[0].size() = n de objetos no instante 0 = n de objetos em qualquer instante
    for(unsigned int n = 0; n < n_de_objetos; n++)
        {//para todas as partículas, ler todos os instantes
        vector<QVector3D> objeto;
        for(unsigned int i = 0; i < instantFutureToRecord.size(); i++)//para cada instante
            for(unsigned int j = 0; j < instantFutureToRecord[i][n].size(); j++)//para cada instante previsto do futuro de um instante
                objeto.push_back(instantFutureToRecord[i][n][j]);
        instantFuturePorObjeto.push_back(objeto);
        }

    for(unsigned int n = 0; n < instantFuturePorObjeto.size(); n++){
        //para cada objeto
        QString file_name = QString(file_instanteFutureRecorded.c_str()) + "_" + QString::number(n) + ".data";
        QFile file(file_name);
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream out(&file);
        out << "# Dados do futuro instantaneo para o objeto " << n << "\n";
        out << "#Gerado por OracleKalman by JuarezASF UnB110032829 \n";
        out << "#data: " << QDate::currentDate().toString() << "\n";
        for(unsigned int i = 0; i < instantFuturePorObjeto[n].size(); i++){
            out << instantFuturePorObjeto[n][i].x() << "\t";
            out << instantFuturePorObjeto[n][i].y() << "\t";
            out << instantFuturePorObjeto[n][i].z() << "\n";
        }

        file.close();
    }

    //salva centros detectados
    for(unsigned int n = 0; n < number_of_objects; n++){
        //para cada objeto
        QString file_name = QString(file_centers.c_str()) + QString::number(n) + ".data";
        QFile file(file_name);
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream out(&file);
        out << "# Dados do instante tomado e centro detectado(x,y) para o objeto " << n << "\n";
        out << "#Gerado por OracleKalman by JuarezASF UnB110032829 \n";
        out << "#data: " << QDate::currentDate().toString() << "\n";
        for(unsigned int i = 0; i < toRecord_instantDetectionToRecord[n].size(); i++){
            out << toRecord_instantDetectionToRecord[n][i].x() << "\t";
            out << toRecord_instantDetectionToRecord[n][i].y() << "\t";
            out << toRecord_instantDetectionToRecord[n][i].z() << "\n";
        }

        file.close();
    }


    //salva centros estimados
    for(unsigned int n = 0; n < number_of_objects; n++){
        //para cada objeto
        QString file_name = QString(file_centers.c_str()) + "_kalman_" + QString::number(n) + ".data";
        QFile file(file_name);
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream out(&file);
        out << "# Dados do instante tomado e centro kalman estimado (x,y) para o objeto " << n << "\n";
        out << "#Gerado por OracleKalman by JuarezASF UnB110032829 \n";
        out << "#data: " << QDate::currentDate().toString() << "\n";
        for(unsigned int i = 0; i < toRecord_instantKalmandEstimation[n].size(); i++){
            out << toRecord_instantKalmandEstimation[n][i].x() << "\t";
            out << toRecord_instantKalmandEstimation[n][i].y() << "\t";
            out << toRecord_instantKalmandEstimation[n][i].z() << "\n";
        }

        file.close();
    }

    //salva centro de colisões
    {
        //para cada objeto
        QString file_name = QString(file_colisions.c_str());
        QFile file(file_name);
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream out(&file);
        out << "# Dados do instante tomado e pontos de colisões " <<"\n";
        out << "#Gerado por OracleKalman by JuarezASF UnB110032829 \n";
        out << "#data: " << QDate::currentDate().toString() << "\n";
        for(unsigned int i = 0; i < toRecord_colisionsPoints.size(); i++){
            out << toRecord_colisionsPoints[i].x() << "\t";
            out << toRecord_colisionsPoints[i].y() << "\t";
            out << toRecord_colisionsPoints[i].z() << "\n";

         }
        file.close();
    }


    //reseta para a próxima gravação
    instantFutureToRecord.clear();
    toRecord_colisionsPoints.clear();

    reportGood("Terminamos de Gravar");
}


void Widget::getInstantFutureToRecord(vector< vector< Point> > &future){
    vector<vector<QVector3D> > instantFuture;
    for(unsigned int n = 0; n < future.size(); n++){//n-esima objeto
        vector<QVector3D> n_esimo_objeto_instante_future;
        for(unsigned int i = 0; i < future[n].size(); i++)//i-esimo futuro do n-esimo objeto
            {
            float x = iteration_recording + i;
            float y = future[n][i].x;
            float z = future[n][i].y;
            QVector3D tripla(x,y,z);
            n_esimo_objeto_instante_future.push_back(tripla);
            }
        instantFuture.push_back(n_esimo_objeto_instante_future);
    }
    instantFutureToRecord.push_back(instantFuture);
}

void Widget::on_horizontalSlider_sliderMoved(int position)
{
    number_of_shots_to_take = position;
}
