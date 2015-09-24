// e.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
int main()
{
	int x = 1;
	double eps = 0.001;
	double lastSum = 1;
	double result = 1;
	cout<<exp(x)<<endl;
	int n = 1;
	for(; abs(lastSum) >= eps;)
	{
		lastSum = lastSum * x / n++;
		result += lastSum;
	}

	cout<<result<<endl;
	return 0;
}

