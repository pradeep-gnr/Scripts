// Stack as a Linked List
#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
  int value;
  node *next;
};


class MyStack
{
private:
  node *stack;

public:
  int a;
  // Declare all Member functions and 
  MyStack(int);
  void Initialize(int);
  void push(int);
  void pop();
  void flush();
  void top();
  void printAll();
};

MyStack::MyStack(int element)
{
  // Initialize Stack
  MyStack::Initialize(element);
}

void MyStack::Initialize(int element)
{
  if (element!=-1)
    {
      node *temp = new node;
      temp->value = element;
      temp->next = NULL;
      MyStack::stack = temp;
      }  
  else
    {
      /*
	Condition to Simulate empty Stack !!
      */
      MyStack::stack = NULL;
    }

}

void MyStack::push(int element)
{  
  node *temp = new node;
  temp->value = element;
  
  if(MyStack::stack!=NULL)
    {
    temp->next = MyStack::stack;
    MyStack::stack = temp;
    }

    else
      {
	temp->next = NULL;
	MyStack::stack=temp;        
      }  
}

void MyStack::printAll()
{
  node *temp = MyStack::stack;
  while(temp!=NULL)
    {
    cout<<"\n"<<temp->value;
   temp=temp->next;
    }
}

void MyStack::top()
{
  cout<<"The Top Element is "<<MyStack::stack->value<<"\n";  
}

void MyStack::pop()
{
  node *temp = MyStack::stack;    
  if(temp==NULL)
    {
      cout<<"Stack Empty\n";
      return;
    }


    if(temp->next!=NULL)
     {
     MyStack::stack = temp->next;  
     cout<<"\nPopping :" <<temp->value;
     free(temp);
     }

  else
    {
      cout<<"\nThis is the last element in stack";
    cout<<"\nPopping :" <<temp->value;
    MyStack::stack = NULL;  
    } 
}

void MyStack::flush()
{
  // Empty Stack !!
  node *temp = MyStack::stack;
  if(temp==NULL)
    {
      cout<<"Stack is Empty\n";
      return;
    }
  else
    {
      node *tmpNode, *curNode;
      curNode=temp;
      while(curNode!=NULL)
	{
	  tmpNode = curNode;
	  curNode = tmpNode->next;
	  cout<<"Popping :" <<tmpNode->value;
	  free(tmpNode);
	}
    }

}
  int main()
  {
    cout<<"Sample Stack Implemetation Program\n";
    MyStack stack(5);
    stack.top();
    stack.push(4);
    stack.push(10);
    stack.push(100);
    stack.printAll();
    stack.pop();
    stack.printAll();
    stack.pop();
    stack.printAll();
    stack.pop();
    stack.printAll();
    stack.pop();
    stack.pop();

    cout<<"\n";
    return 0;
  }
