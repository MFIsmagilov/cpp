// hash_table.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct cell{
	char* data;
	int key;
	cell* next;
};

class Hash_table{
	cell** table;
	int table_size;
	char* not_found;
	int hash(int key);
public:
	Hash_table(int size, char* not_found);
	~Hash_table();
	bool add(char* data, int key);
	void remove(int key);
	char* find(int key);
	void print();
};

Hash_table::Hash_table(int size, char* not_found1)
{
not_found= not_found1;
table_size = size;

table = new cell* [table_size];
for(int i=0; i<size ; i++)
	{
		table[i]=NULL;
	}
}

Hash_table::~Hash_table()
{
	for(int i=0; i<table_size; i++)
	{
		cell* phead = table[i];
		while(phead!=NULL)
		{
			cell* qhead = phead;
			phead = phead->next;
			delete  qhead;
		}
	delete phead;
	}
}

int Hash_table::hash(int key)	
{
	return key%table_size;
}

bool Hash_table::add(char* data, int key)
{
	int index = hash(key);
	cell* toAdd = new cell();
	toAdd->data = data;
	toAdd->key = key;

	cell* phead = table[index];
	while(phead!=NULL && phead->key != key)
	{
		phead = phead->next;
	}
	if(phead != NULL)
		return false;
	else
	{
		toAdd->next = table[index];
		table[index] = toAdd;
		return true;
}
}

void Hash_table::remove(int key)
{
int index = hash(key);
cell* phead = table[index];
int k=0;
	while(phead != NULL)
	{
		phead = phead->next;
		k++;
	}

if(k>1)
	{
		cell* phead = table[index];
 		while(phead != NULL && phead->next->key != key)
		{
			phead = phead->next;
		}

		if(phead != NULL)
		{
			cell* qhead = phead->next;
			phead->next = phead->next->next;
			delete qhead;
		}
	}
else
if(k == 1)
	{
		delete table[index];
		table[index] = NULL;
	}
}


char* Hash_table::find(int key)
{
	int index = hash(key);
	cell* phead = table[index];
	while(phead != NULL)
	{
		if(phead->key == key)
			return phead->data;
		else
			phead = phead->next;
	}
return not_found;
}

void Hash_table::print()
{
	for(int i=0; i<table_size; i++)
	{
		cell* phead = table[i];
		if(phead!= NULL)
		{
			cout<<i<<":";
			while(phead!=NULL)
			{
				cout<<"["<<phead->data<<","<<phead->key<<"]"<<" ";
				phead = phead->next;
			}
			cout<<endl;
		}
	} 
}


int _tmain(int argc, _TCHAR* argv[])
{
	Hash_table hash(5,"not_found");
	hash.add("abc",99);
	hash.add("abc",199);
	hash.add("abc", 100);
	hash.add("def", 100);
	hash.add("ghi", 101);

	hash.print();
	cout<<endl;
	cout<<hash.find(99)<<endl<<hash.find(100)<<endl<<hash.find(101)<<endl<<hash.find(66)<<endl;
	cout<<endl;
	hash.remove(99);
	hash.remove(100);
	hash.remove(101);
	hash.remove(199);
	
	hash.print();

	for(int i=0; i<25; i++)
		hash.add("xyz",i);
	hash.print();
	hash.remove(12);
	cout<<endl;
	hash.print();
	return 0;
}

