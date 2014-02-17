#include "TemplateMatchSensor.h"

TemplateMatchSensor::TemplateMatchSensor()
{
    initialized = false;
    position = Point(0,0);
    matchingAlgorithm = MatchSensorTechnique::SQDIFF;
    //caso default
}

Point TemplateMatchSensor::currentPosition(Mat frame){
    if(initialized == false )
        throw "Sensor de Matching deve ser Inicializado com template!!!";
    int matchingMat_cols = frame.cols - templateMat.cols + 1;
    int matchingMat_rows = frame.rows - templateMat.rows + 1;

    matchingMat.create(matchingMat_cols, matchingMat_rows, CV_32FC1);

    //faz o matching e a normalização
    matchTemplate(frame, templateMat, matchingMat, matchingAlgorithm);
    normalize(matchingMat, matchingMat, 0, 1, NORM_MINMAX, -1, Mat());

    //acha o melhor match[acha os valores de mínimios e máximo
    //e suas respectivas posições]
    double minVal, maxVal;
    Point minLoc, maxLoc;
    Point matchLoc;

    minMaxLoc(matchingMat, &minVal, &maxVal, &minLoc, &maxLoc, Mat());

    /// For SQDIFF and SQDIFF_NORMED, the best matches are lower
    ///values. For all the other methods, the higher the better
    //retirado de exemplo do openCV
    if( matchingAlgorithm  == MatchSensorTechnique::SQDIFF  ||
            matchingAlgorithm == MatchSensorTechnique::SQDIFF_NORMED)
      { matchLoc = minLoc; }
    else
      { matchLoc = maxLoc; }

    /*teremos em MatchLoc a canto esquerdo superior do template
        localizado. Como o objeto deve estar no centro, temos que
        fazer mais algumas contas*/

    position.x = matchLoc.x + templateMat.cols/2;
    position.y = matchLoc.y + templateMat.rows/2;


    return position;
}
Point TemplateMatchSensor::currentPosition(){
    if(initialized == false)
        throw "Sensor de Matching deve ser Inicializado com template!!!";

    return position;
}

void TemplateMatchSensor::setTemplateMat(Mat &tpl){
    tpl.copyTo(templateMat);
    if(!tpl.empty())
        initialized = true;
}

    void TemplateMatchSensor::setMatchAlgorithm(int type){
        if(type > 5 || type < 0)
            throw "Tipo de matching algoritmo inválido!!!";

        matchingAlgorithm = type;
    }

    int TemplateMatchSensor::getTplWidth(){
        return templateMat.cols;
    }

    int TemplateMatchSensor::getTplHeigh(){
        return templateMat.rows;
    }
