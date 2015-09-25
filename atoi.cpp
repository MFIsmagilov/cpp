// atoi.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int strlen(char *a)
{
	int i=0;
	for(i=0; a[i]; i++);
	return i;
}

int atoi(char *a)
{
	int q=0;
	for(int i=0; a[i]; i++)
		q=q*10+(a[i]-'0');
	return q;
}

int atoi16(char *a)
{
	int sum=0;
	int i=0;
	for(i=0; a[i]; i++)
	{
		if(a[i]>='A' && a[i]<='F')
			sum=sum*16 + (a[i]-'A'+10);
		if(a[i]>='0' && a[i]<='9')
			sum=sum*16 + (a[i]-'0');
	}
	return sum;
}

int _tmain(int argc, _TCHAR* argv[])
{
	////	atoi  ///////////
	cout<<"atoi"<<endl;
	int const n=1000;
	char a[n]="32496";
	int q=strlen(a);
	cout<<" Char: ";
	for(int i=0; i<q; i++)
		cout<<a[i];
	cout<<endl;
	cout<<" int : ";
	cout<<atoi(a)<<endl;
	cout<<endl;
	//////////////////////////

	////	atoi16/////////// 
	cout<<"atoi16"<<endl;
	char b[n]="5BCD";
	int k=strlen(b);
	cout<<" Char :";
	for(int i=0; i<k; i++)
		cout<<b[i];
	cout<<endl;
	cout<<" int  :"<<atoi16(b)<<endl;
	cout<<" Char :";
	for(int i=0; i<k; i++)
		cout<<b[i];
	cout<<endl;
	return 0;
}


