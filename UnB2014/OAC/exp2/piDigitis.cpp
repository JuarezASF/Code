#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

/**
    IMPLEMENTA ALGORITMO SPIGOT PARA CALCULAR DÍGITOS DE PI
    ESTÁ FUNCIONANDO!!!
    FALTA COLOCAR EM MODO SILENCIOSO, O PROGRAMA DÁ INÚMERAS INFORMAÇÕES INÚTEIS
*/

int findNecessarySize(int n){/*
    if(n%3 == 0)
        return (10*n/3);
    else
        return (10*(n - n%3 + 3)/3);
*/
    return (10*n/3 + 1);

}

vector<int> reduce(unsigned int n, unsigned int q){
    //n = p*q + r
    //return (p, r)
    int r = n%q;
    int p = (n - r)/q;
    vector<int> reduced(2);
    reduced[0] = p;
    reduced[1] = r;

    return reduced;
}

void printVector(vector<int> piDigits){
    for(unsigned int i = 0; i < piDigits.size(); i++)
                 cout << piDigits[i] << " ";
    cout << "\n";

}

int main()
{
    unsigned int n = 0;
    cout << "Entre com o numero de digitos a calcular: " << endl;
    cin >> n;
    unsigned int tamanho = findNecessarySize(n);
    cout << "numero de digitos necessarios = " << tamanho << endl;

    vector<int> array(tamanho);
    //step 1: Initialize
    for(unsigned int i = 0; i < array.size(); i++)
        array[i] = 2;

    vector<int> piDigits;
    vector<int> preDigits;

    for(unsigned int counter = 0; counter < n + 1; counter++){
        //step 2: mutiplique por 10
        for(unsigned int i = 0; i < array.size(); i++)
            array[i] *= 10;

        //step3: colocar em forma regular

        //do último até o segundo elemento do vetor, normaliza
        for(unsigned int i = array.size() - 1; i > 0; i--){
            //a primeira linha da tabela é (j-1)/(2j-1)
            unsigned int indice = i + 1;
            vector<int> reduced = reduce(array[i], 2*(indice)-1);
            array[i] = reduced[1];//resto da divisão
            int carry = reduced[0]*(indice-1);
            array[i-1] += carry;
        }

        vector<int> reduced = reduce(array[0], 10);
        array[0] = reduced[1];//resto da divisão


    //step 4: ajuste dos pré-digitos
        int q = reduced[0];
        if(q == 9)
                preDigits.push_back(q);
        else if(q == 10){
            q = 0;
            for(unsigned int k = 0; k < preDigits.size(); k++)
                {
                if(preDigits[k] + 1 == 10)
                    preDigits[k] = 0;
                else
                    preDigits[k] += 1;
                piDigits.push_back(preDigits[k]);
            }
            preDigits.resize(0);
            preDigits.push_back(q);
           }
        else {//release the held predigits as true digits and hold q
            for(unsigned int k = 0; k < preDigits.size(); k++)
                piDigits.push_back(preDigits[k]);
            preDigits.resize(0);
            preDigits.push_back(q); //hold q
        }

    }//fim for counter = 0:n

    cout << "Os digitos de pi calculados sao:" <<endl;
    printVector(piDigits);

    system("pause");

    return 0;
}

