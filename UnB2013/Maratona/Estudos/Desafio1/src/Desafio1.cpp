//============================================================================
// Name        : Desafio1.cpp
// Author      : Juarez A.S.F.
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int process(int n)
{
	cout << n<<"\t";
	if(n != 1)
	{
		if(n%2 == 0)
			return process(n/2) + 1;
		else
			return process(3*n + 1) + 1;
	}
	else
		return 1;
}

int main() {
	cout << process(22) << endl;
	return 0;
}
