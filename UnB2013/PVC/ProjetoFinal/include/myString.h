/*
 * myString.h
 *
 *  Created on: 24/11/2013
 *      Author: juarez408
 */

#ifndef MYSTRING_H_
#define MYSTRING_H_


#include <iostream>
#include <sstream>
#include <string>

template <typename T>
inline std::string ToString(T tX)
{
    std::ostringstream oStream;
    oStream << tX;
    return oStream.str();
}

/*exemple de uso:
 *
 * int main()
{
    string sFour(ToString(7));
    string sSixPointSeven(ToString(6.7));
    string sA(ToString('A'));
    cout << sFour << endl;
    cout << sSixPointSeven << endl;
    cout << sA << endl;
}
 * */

template <typename T>
inline bool FromString(const std::string& sString, T &tX)
{
    std::istringstream iStream(sString);
    return (iStream >> tX) ? true : false;
}
/*
 * exemplo de uso:
 * int main()
{
    double dX;
    if (FromString("3.4", dX))
        cout << dX << endl;
    if (FromString("ABC", dX))
        cout << dX << endl;
}
 * */


#endif /* MYSTRING_H_ */
