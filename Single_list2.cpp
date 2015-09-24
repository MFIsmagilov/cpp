// ConsoleApplication10.cpp: определяет точку входа для консольного приложения.
//
// Single_node2.cpp: определяет точку входа для консольного приложения.
//
#include <iostream>

using namespace std;

struct Single_node2
{
   float val;
   Single_node2* next;
};

struct Single_list2
{
	Single_node2* head;
	Single_node2* tail;
	Single_node2* current;
	Single_list2();
	Single_list2(float);
	~Single_list2();
	bool is_empty(); 
	void add_front(float );
	void add_rear(float ); 
	float remove_front(); 
	bool find(float ); 
	float get_nth(int); 
	int size(); 
	void print(); 
	void reset_current(); 
	bool increment_current(); 
	float get_current(); 
	bool current_is_tail(); 
	bool insert_after_current(float );
};

Single_list2 :: Single_list2()
{
	head = new Single_node2();
	tail = new Single_node2();
	head=tail;

	tail->next=head;
	current=head;
}

Single_list2 :: Single_list2(float element)
{
	head = new Single_node2();
	tail = new Single_node2();

	head->val=element;
	tail->next=head;
	current=head;
}

Single_list2::~Single_list2()
{
while(head!=tail)
	{
		Single_node2* fhead= head;
		head=head->next;
		delete fhead;
	}
}

bool Single_list2:: is_empty()
{
	return head == tail;
}

void Single_list2::add_front(float element)
{
	Single_node2* toAdd = new Single_node2();
	toAdd->val=element;
	toAdd->next=head;
	if (is_empty())
		{
			head = toAdd;
			tail->next = head;
		}
	else
		{
			head=toAdd;
		}
}

void Single_list2::add_rear(float element)
{
	Single_node2* toAdd = new Single_node2();
	toAdd->val = element;
	toAdd->next = tail;
	if (is_empty())
		{
			add_front(element);
		}
	else
		{
			tail->next->next = toAdd;
			toAdd->next=tail;
			tail->next=toAdd;
		}
}


float Single_list2::remove_front()
{
	float val=head->val;
	Single_node2* qhead = head;
	head=qhead->next;
	delete qhead;
	return val;
}

bool Single_list2:: find(float element)
{
	Single_node2 *fhead = head;
	while(fhead!=tail)
		{
			if(fhead->val!=element)
				return true;
			fhead=fhead->next;
		}
	return false;
}

float Single_list2::get_nth(int i)
{	Single_node2 *fhead=head;
	int k=0;
	 while(k<i)
		 {
			 fhead=fhead->next;
			 k++;
		 }
	return fhead->val;
}

int  Single_list2::size()
{	int k=0; 
	Single_node2 *fhead=head;
	while(fhead!=tail)
		{
			fhead=fhead->next;
			k++;
		}
	return k;
}

void Single_list2::print()
{	int n=size();
	for(int i=0; i<n; i++)
			cout<<get_nth(i)<<" ";
	cout<<endl;
}

void Single_list2::reset_current()
{
	current = head;
}

bool Single_list2::increment_current()
{
	if(current_is_tail()==false)
		{
			current=current->next;
			return true;
		 }
	else
		return false;
}

float Single_list2::get_current(){

		return current->val;
} 

bool Single_list2::current_is_tail(){

	if(current == tail)
		return true;
	else
		return false;
}

bool Single_list2::insert_after_current(float element)
{
	Single_node2 *knot = new Single_node2();
	Single_node2 *fcurrent = current;
	knot->val=element;
	knot->next = fcurrent->next;
	fcurrent->next = knot;
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Single_list2 list;

	for (float f=0.0;f<0.5;f+=0.1)
	{
		list.add_front(f);
		list.add_rear(f);
		list.print();
	}
	while (!list.is_empty())
	{
		list.print();
		list.remove_front();
		
	}
	return 0;
}

