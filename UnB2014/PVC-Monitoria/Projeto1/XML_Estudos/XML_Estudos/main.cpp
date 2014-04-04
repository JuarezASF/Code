
#include <opencv2/core/core.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;


int main()
{
    string filename = "OlaMundo.xml";
    FileStorage fs(filename, FileStorage::WRITE);

    //pode ser FileStorage::APPEND, FileStorage::WRITE ou FileStorage::READ

    //For outputting any type of data structure we need first to specify its name.
    fs << "minhaString" << "Olá Mundo! Estou aprendendo XML";


    fs << "leIntXml" << 31;

    fs.release();

    FileStorage f_in(filename, FileStorage::READ);

    int leInt;
    string leString;

    f_in["leIntXml"] >> leInt;
    f_in["minhaString"] >> leString;

    cout << "A mensagem lida foi : " << leString << endl;
    cout << "O número lido foi : " << leInt << endl;





    return 0;
}

