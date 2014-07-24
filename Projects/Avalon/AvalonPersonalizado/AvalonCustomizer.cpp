#include "AvalonCustomizer.h"

AvalonCustomizer::AvalonCustomizer()
{
    for(int i = 0; i < 5; i++)
        set[i] = false;
}

void AvalonCustomizer::setPlano(Mat &novo){
    set[0] = true;
    novo.copyTo(plano);
}

void AvalonCustomizer::setMoldura(Mat &novo){
    set[1] = true;
    novo.copyTo(moldura);
}
void AvalonCustomizer::setPersonagem(Mat &novo){
    set[2] = true;
    novo.copyTo(personagem);
}
void AvalonCustomizer::setVerso(Mat &novo){
    set[3] = true;
    novo.copyTo(verso);
}
void AvalonCustomizer::setNome(string novo){
    set[4] = true;
    nome = novo;
    cout << "Nome setado para '" + nome + "'"<< endl;
}

Mat AvalonCustomizer::getCard()
{
    Mat card(0,0,0);
    if(set[0] && set[2]){
        card = MaskOperation::mergeEspecial(plano, personagem, Scalar(255, 255, 255));
        if(set[1])
            card = MaskOperation::mergeEspecial(card, moldura, Scalar(255, 255, 255));

        if(set[4])
            putText( card, nome, Point2d(50, 50), FONT_HERSHEY_COMPLEX,
                     3.0, Scalar(255, 255, 255), 10);
    }

     return card;
}
