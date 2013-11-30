/*
 * NodeAlreadyExists.h
 *
 *  Created on: 30/11/2013
 *      Author: juarez408
 */

#ifndef NODEALREADYEXISTS_H_
#define NODEALREADYEXISTS_H_


#include <string>

class NodeAlreadyExistsException{

private:
    std::string m_strError;

public:
    NodeAlreadyExistsException(std::string strError = "No já existente")
			: m_strError(strError){}

    std::string what(){
    	return m_strError;
    }
};



#endif /* NODEALREADYEXISTS_H_ */
