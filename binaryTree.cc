/*
  Binary Tree in c++
 */
#include<iostream>
#include <vector>
using namespace std;

const int NCHILD=2;

struct node{
	int element;
	node* lchild;
	node* rchild;
};

class BinaryTree
{
private:
	node* Tree; // Root Node of the Tree
	int maxLevel;
	int curLevel;
	bool isLeafNode(node*);
	bool isHasSpace(node*);
	int setInsertNode(node* curNode,int level,int found);	

public:
	node* curInsertNode;
	BinaryTree(int element, int mLevel);
	node* getRoot();
	void insert(int element);
	int search(int element);
	vector<node*>  getChildren(node *curNode);
	void printInOrder();
	void printPreOrder();
	void printTree(node *curTree);
	void printPostOrder();
	void printBreadthFirst();
	void deleteANode();
		
};

BinaryTree::BinaryTree(int element, int mLevel)	
{
	Tree = new node;
	Tree->element = element;
	cout<<"\nInitializing Tree with root  "<<element;
 	Tree->lchild = NULL;
	Tree->rchild = NULL;

	/*
	  Initialize Tree Depth Parameters
	 */
	maxLevel= mLevel;
	curLevel=0;
}

vector<node*> BinaryTree::getChildren(node* curNode)
{
	/*
	 */
	vector<node*> childList;
	if(curNode->lchild!=NULL)
		childList.push_back(curNode->lchild);
	if(curNode->rchild!=NULL)
		childList.push_back(curNode->rchild);
	return childList;
}

bool BinaryTree::isHasSpace(node* curNode)
{
	vector<node*> childList = getChildren(curNode);
	if(childList.size()<2)
		return true;
	return false;			
}

bool BinaryTree::isLeafNode(node* curNode)
{
	 vector<node*> childList = getChildren(curNode);
	if(childList.size()==0)
		return true;
	return false;	
}
node* BinaryTree:: getRoot()
{
	return Tree;
}

void BinaryTree::printTree(node* curNode)
{
	/*
	  Pretty Print a Binary Tree !!
	 */
	if(isLeafNode(curNode))
	{
		cout<<"\n"<<curNode->element;
		return;
	}

	else
	{
		cout<<"\n"<<curNode->element;
		vector<node*> childList = getChildren(curNode);

		for(int i=0;i<childList.size();i++)
		{
			 printTree(childList[i]);
		}		
	}		
	
}

int BinaryTree::setInsertNode(node* curNode,int level=1,int found=0)
{
	
	//cout<<"\n"<<curNode->element<<endl;	
	if(isHasSpace(curNode)&&level<=(maxLevel-1))
	{
		if(found==0)
		{
			cout<<"\nLevel ::"<<level<<"  "<<curNode->element;
			curInsertNode = curNode;
			found=1;
			return found;
		}
	}
	else
	{			
		vector<node*> childList = getChildren(curNode);
		for(int i=0;i<childList.size();i++)
		{
			found = setInsertNode(childList[i],level+1,found);
		}
		return found;

	}
}

void BinaryTree::insert(int element)
{
    /*
	  A Depth first insert mechanism !
	 */
	//curInsertNode=NULL;
	int flag = setInsertNode(Tree);
	node* curNode = curInsertNode;
	cout<<"\nInserting at "<<curNode->element;
	if(curNode->lchild!=NULL && curNode->rchild!=NULL)
	{
		cout<<"Tree Full !! Cannot Insert !! Delete some elements";
		return;
	}	
	else		
	{
		node* temp = new node;
		temp->element = element;
		temp->lchild=NULL;
		temp->rchild=NULL;
		
		if(isLeafNode(curNode))
		{
			cout<<"\nIs Leaf Node  "<<curNode->element;
			curNode->lchild = temp;	 // Insert at left Child
			cout<<"\nInserting element" <<temp->element;
		}
		else
		{
			curNode->rchild = temp; // Insert at Right Child
			cout<<"\nInserting element" <<temp->element;
		}
		return;
	}	
}

int main()
{
	cout<<"Implementing a Binary Tree";
	BinaryTree tree(5,3);
	tree.insert(10);
	tree.insert(20);
	tree.insert(30);
	tree.insert(40);
	tree.insert(50);
	tree.insert(60);
	tree.insert(70);
	node* root = tree.getRoot();
	cout<<"\nPrinting Tree\n\n";
	tree.printTree(root);
	cout<<"\n";
	return 0;
}
	
