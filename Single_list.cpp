// sn.cpp: определяет точку входа для консольного приложения.
//
// single_list.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;



struct Single_node
{
	Single_node *next;
	int val;
};

struct Single_list
{
	Single_node *head;
	Single_node *tail;
	Single_list();
	Single_list(int);
	~Single_list();
	bool is_empty();
	void add_front(int k);
	int remove_front();
	bool find(int);
	int get_nth(int);
	int size();
};

Single_list::Single_list()
{
	head=new Single_node();
	tail=new Single_node();
	tail=head;
}

Single_list::Single_list(int element)
{
	head=new Single_node();
	tail=new Single_node();
	head->val=element;
	head->next=tail;
}

Single_list::~Single_list()
{
while(head!=tail)
	{
		Single_node* fhead= head;
		head=head->next;
		delete fhead;
	}
}

void Single_list::add_front(int element)
{
	Single_node* toAdd = new Single_node();
	toAdd->val = element;
	toAdd->next = head;
	head=toAdd;
}

int Single_list::remove_front()
{
Single_node* qhead = head;
	int val=qhead->val;
	head=qhead->next;
	delete qhead;
	return val;
}

bool Single_list::is_empty()
{
	return head == tail;
}

bool Single_list:: find(int element)
{
Single_node *fhead = head;
while(fhead!=tail)
		{
			if(fhead->val==element)
				return true;
			else
			fhead=fhead->next;
		}
	return false;	
}


int Single_list::get_nth(int i)
{
	Single_node *fhead=head;
	int k=0;
	 while(k<i)
		 {
			 fhead=fhead->next;
			 k++;
		 }
	return fhead->val;
}


int  Single_list::size()
{
	int k=0;
		Single_node *fhead=head;
			while(fhead!=tail)
				{
					fhead=fhead->next;
					k++;
				}
			return k;
}


void print_slist(Single_list &list)
{
	int n=list.size();
	for(int i=0; i<n; i++)
			cout<<list.get_nth(i)<<" ";
	cout<<endl;
}


int _tmain(int argc, _TCHAR* argv[])
{
	Single_list list;
	 for(int i=0; i<5; i++)
	 {
		 list.add_front(i);
		 print_slist(list);
	 }
	  while(!list.is_empty())
	 {
		print_slist(list);
		list.remove_front();
	 }
	 return 0;
}

