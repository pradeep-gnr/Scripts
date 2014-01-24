#include<iostream>

struct node
{
	int element;
	node *next;	
};

class LinkedList
{
private:
	node *head;
	node *tail;
	int size ;

public:
	LinkedList(int);
	void createList(int element);	
	void addElement(int element);
	void addElementAt(int element,int value);
	void deleteElement(int element);
	void deleteNthElement(int N);
	void printAddress();
	bool isListEmpty();
	void printList();
	int getLength();
	void removeDuplicates();

};
