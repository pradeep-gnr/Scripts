#include "linkedList.h"
#include<iostream>
using namespace std;

int LinkedList::getLength()
{
	/*
	  Returns the Size of a Linked List !!
	 */
	if(isListEmpty())
		return 0;		

	node* temp = head;
	int len=0;
	while(temp!=NULL)
	{
		len+=1;
		temp=temp->next;
	}
	return len;
}

void LinkedList::printAddress()
{
	/*
	  Helper function to perform sanity checks on Addresses !
	 */
	cout<<"HEAD "<<head;
	cout<<"TAIL "<<tail;
}


LinkedList::LinkedList(int element=0)
{
	head = new node;
	
	if(element!=0)
	{
		head->element = element;
		cout<<head->element;
		head->next = NULL;
		tail=head;
	}
	else
	{
		head=NULL;
		tail=NULL;
	}
}

void LinkedList::addElementAt(int index, int value)
{
	/*
	  Add an element in a Linked List at a given location !
	 */
	int len =getLength();
	if(index>len+1)
	{
		cout<<"\nList size is "<<len;
		cout<<"Cannot Insert at "<<index<<" th position";
		return;
	}
	int ind=1;
	node *temp=head;
	int prev_index = index-1;
	int jumps=0;

	
	while(jumps<prev_index-1)
	{
		temp=temp->next;
		jumps+=1;
	}
		
	if(temp->next!=NULL)
	{
		node* new_node = new node;
		new_node->element = value;
		node* backup = temp->next;
		temp->next = new_node;
		new_node->next = backup;
	}
	
	else
	{
		node* new_node = new node;
		new_node->element = value;
		temp->next = new_node;
		new_node->next = NULL;		
	}
	
}

void LinkedList:: addElement(int element)	
{
	cout<<"\nAdding "<<element;
	node *temp = new node;
	temp->element = element;	
	temp->next = NULL;
	//cout<<tail->element;
	tail->next = temp;
	tail=tail->next;
}

void LinkedList::printList()
{
	/*
	 * Print all elements of a Linked List !!
	 */
	node *temp = head;
	while(temp!=NULL)
	{
		cout<<"\n"<<temp->element;
		temp=temp->next;
	}
}

bool LinkedList::isListEmpty()
{
	if(head==NULL)
		return true;
	else
		return false;
				 
}

void LinkedList::deleteElement(int n)
{	
	/*
	  Search for an element and delete it !
	 */
	node *first = head;
	node *second;
	second = first;
	
	if(isListEmpty())
	{
		cout<<"List is Empty";
		return;
	}

	while(second!=NULL)
	{
		if(first==second)
		{
			if(second->element==n)
			{
				node* temp = first;
				first = first->next;
				second = first;
				cout<<"\nDeleting "<<temp->element;
				delete temp;
				head = first;
			}

			else
			{
				second = first->next;
			}
		}
		
		else
		{
			if(second->element==n)
			{
				node *temp = second;
				second=second->next;
				first->next = second;
				cout<<"\nDeleting :"<<temp->element;
				delete temp;
			}
			else
			{
			first=first->next;
			second=second->next;
			}
		}		
	}
}	

void LinkedList::deleteNthElement(int N)
{
	/*
	  Delete an element at the Nth Position !
	 */
	if(!isListEmpty())
	{
		
	}	
}

