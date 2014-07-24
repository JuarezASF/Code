#include "AvalonCustomizer.h"

AvalonCustomizer::AvalonCustomizer()
{
}

void AvalonCustomizer::setPlano(Mat &novo){
    novo.copyTo(plano);
}

void AvalonCustomizer::setMoldura(Mat &novo){
    novo.copyTo(plano);
}
void AvalonCustomizer::setPersonagem(Mat &novo){
    novo.copyTo(personagem);
}
void AvalonCustomizer::setVerso(Mat &novo){
    novo.copyTo(verso);
}
void AvalonCustomizer::setNome(string novo){
    nome = novo;
    cout << "Nome setado para '" + nome + "'"<< endl;
}
