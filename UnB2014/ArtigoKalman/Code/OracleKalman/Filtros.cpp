#include "Filtros.h"

Filtros::Filtros()
    {
    }

void Filtros::Erosion( Mat src, Mat dst, int size)
{
	//função de erosão retirada dos tutoriais do OpenCv
	//qnt maior size maior a erosão
  int erosion_type = 0;
  int erosion_elem = 0;//0,1,2 : ver abaixo
  int erosion_size = size;//ate 21 : quanto mais alto mas borrado

  if( erosion_elem == 0 ){ erosion_type = MORPH_RECT; }
  else if( erosion_elem == 1 ){ erosion_type = MORPH_CROSS; }
  else if( erosion_elem == 2) { erosion_type = MORPH_ELLIPSE; }

  Mat element = getStructuringElement( erosion_type,
                       Size( 2*erosion_size + 1, 2*erosion_size+1 ),
                       Point( erosion_size, erosion_size ) );

  /// Apply the erosion operation
  erode( src, dst, element );
}

void Filtros::Dilation( Mat src, Mat dst, int size)
{//função de dilatação retirada dos tutoriais do OpenCn
//quando maior o size, maior a dilatação
  int dilation_type = 0;
  int dilation_elem = 0;//0,1,2 : ver abaixo
  int dilation_size = size;//ate 21 : quanto mais alto mas borrado

  if( dilation_elem == 0 ){ dilation_type = MORPH_RECT; }
  else if( dilation_elem == 1 ){ dilation_type = MORPH_CROSS; }
  else if( dilation_elem == 2) { dilation_type = MORPH_ELLIPSE; }

  Mat element = getStructuringElement( dilation_type,
                       Size( 2*dilation_size + 1, 2*dilation_size+1 ),
                       Point( dilation_size, dilation_size ) );
  /// Apply the dilation operation
  dilate( src, dst, element );
}
