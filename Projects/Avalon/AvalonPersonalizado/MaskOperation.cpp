#include "MaskOperation.h"

MaskOperation::MaskOperation()
{
}

Mat MaskOperation::mergeEspecial(Mat &A, Mat &B, Scalar cor){

    if(A.empty() || B.empty())
        return Mat(0, 0, 0);

    int rows = std::min(A.rows, B.rows);
    int cols = std::min(A.cols, B.cols);
    Size tamanho(rows, cols);
    resize(A, A, tamanho);
    resize(B, B, tamanho);

    cout << "Tamanho dimensionado para (" << tamanho.width << ", " << tamanho.height <<") "<< endl;

    Mat C;
    A.copyTo(C);

    MatIterator_<Vec3b> itB, endB;
    MatIterator_<Vec3b> itC, endC;

    itB = B.begin<Vec3b>();
    endB = B.end<Vec3b>();

    itC  = C.begin<Vec3b>();
    endC = C.end<Vec3b>();

               for( ; itB != endB && itC != endC; ++itB, itC++)
               {
                   Scalar cor_atual((*itB)[0], (*itB)[1], (*itB)[2]);
                   if(cor_atual == cor)
                       continue;
                   else{
                       (*itC)[0] = (*itB)[0];
                       (*itC)[1] = (*itB)[1];
                       (*itC)[2] = (*itB)[2];
                   }
               }

    return C;
}
