// Array.cpp: определяет точку входа для консольного приложения.
//

// SparseArray.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct cell {
	int col;
	cell* right;
	float data;
};

class Sparse_Array{

private:
	cell* head;
	float default_value;
public:
	Sparse_Array(float);
	~Sparse_Array();
	float& operator[] (int col);
	void print();
};

Sparse_Array::Sparse_Array(float val)
{
	head = new cell();
	head->col = -1;
	head->right = NULL;
	default_value = val;
}
Sparse_Array::~Sparse_Array()
{
while(head!=NULL)
	{
		cell* fhead= head;
		head=head->right;
		delete fhead;
	}
delete head;
}

float& Sparse_Array:: operator [] (int col)
{
	cell* qhead = head;

while(qhead->right!=NULL && qhead->right->col<=col)
{
	qhead = qhead->right;
}

if(qhead->col != col)
	{
		cell* toAdd = new cell();
		toAdd->col = col;
		toAdd->data = default_value;

		toAdd->right = qhead->right;
		qhead->right = toAdd;
		return toAdd->data;	
	}
else
	{
		return qhead->data;
	}
}

void Sparse_Array::print()
{
cell* qhead = head->right;
while(qhead!=NULL)
{		
	cout<<"["<<qhead->col<<","<<qhead->data<<"] ";
	qhead = qhead->right;
}
cout<<endl;
}





int _tmain(int argc, _TCHAR* argv[])
{
	Sparse_Array A(-1);
	A[15] = 1.5;    
	A[1001] = 8;
	cout<<A[73] + A[15]<<endl;

	A[522]= 85;
	A[9999]=53;
	A[25]=6;
	A.print();

	return 0;
}

