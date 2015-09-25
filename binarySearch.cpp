
#include "stdafx.h"
#include <iostream>

using namespace std;

bool binary_search(int* first,int* last, int elem)
{
	int* f = first;
	int* l = last;
	int* midl;
	while (f < l)
	{
		midl=f+(l-f)/2;
		if (*midl == elem) 
			return 1;
		else
			if (elem > *midl)
				f = midl+1;
			else
				l = midl;
	}
	return 0;
}


int rek_binary_search(int* first, int* last, int elem)
{
	int *mid;
	while(first != last)
	{
		mid = first + (last - first) / 2;

		if (*mid == elem)
			return 1;
		else
			if (*mid>elem)
				return rek_binary_search(first, mid, elem);
			else
				return rek_binary_search(mid+1, last, elem);
	}
	return 0;
}

int main()
{
	int const n=10;
	int a[10]={11,23,35,49,53,67,77,88,93,100};
	cout<<binary_search(a,a+n,77)<<endl;
	cout<<endl;
	cout<<rek_binary_search(a,a+n,77)<<endl;
	return 0;
}