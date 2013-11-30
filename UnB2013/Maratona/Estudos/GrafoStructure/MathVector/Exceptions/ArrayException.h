/*
 * ArrayException.h
 *
 *  Created on: Nov 6, 2013
 *      Author: juarez
 */

#ifndef ARRAYEXCEPTION_H_
#define ARRAYEXCEPTION_H_

#include <string>

class ArrayException{

private:
    std::string m_strError;

public:
    ArrayException(std::string strError)
			: m_strError(strError){}

    std::string GetError(){
    	return m_strError;
    }
};


#endif /* ARRAYEXCEPTION_H_ */
