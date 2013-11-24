/*
 * myMath.cpp
 *
 *  Created on: 24/11/2013
 *      Author: juarez408
 */

#include "myMath.h"

	double myMath::mod(Point &A){
		double mod = 0;
			mod = A.x*A.x + A.y*A.y;
		return sqrt(mod);
	}
