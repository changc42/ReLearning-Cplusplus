#include<iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

class linked_list
{
	public:
	node *head, *tail;
	
	linked_list(){
		head = NULL;
		tail = NULL;
	}
	
	void add_node(int n)
	{
		node* tmp = new node;
		tmp->data = n;
		tmp->next = NULL;
		
		if(head==NULL)
		{
			head = tmp;
			tail = tmp;
		}
		else
		{
			tail->next = tmp;
			tail = tmp;
		}
	}
	
	void print(){
		node* tmp;
		tmp = head;
		
		while(tmp!=NULL){
			cout << tmp->data << endl;
			tmp = tmp->next;
		}
	}
};

int main()
{
	linked_list list1;
	list1.add_node(22);
	list1.add_node(54);
	list1.print();
	
	return 0;
}