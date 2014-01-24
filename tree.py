# Binary Tree API basics for Python 
import sys
import os
import ipdb

class Node(object):

    def __init__(self,element,lchild=None,rchild=None):
        self.element = element
        self.lchild = lchild
        self.rchild = rchild;    


class BinaryTree(object):
    """
    Api Methods for a Simple Binary Tree
    """
    level = 5    
    
    def __init__(self,element=None,level=5):
        """
        Initialize a Tree
        """
        self.maxLevel = level
        self.INSERT_FLAG = False
        self.DEPTH_LIST =[]
        self.depthLinkedDict = {}
        if element==None:
            self.root = None

        else:
            newNode = Node(element,None,None)
            self.root=newNode

    def createTreefromArray(self,array):
        """
        Create a Binary Tree from a Sorted list
        """    
        if len(array)==1:
            return Node(array[0])
        
        if len(array)==2:
            newNode = Node(array[0])
            newNode.lchild = Node(array[1])
            return newNode

        hLen = len(array)/2
        middle = len(array)/2
        middleElement = array[middle]        
        fHalf = array[0:middle]
        sHalf = array[middle+1:-1] + [array[-1]]

        curNode = Node(middleElement)
        lNode = self.createTreefromArray(fHalf)
        rNode = self.createTreefromArray(sHalf)
        curNode.lchild = lNode
        curNode.rchild = rNode

        return curNode        

    def _hasSpace(self,node):
        """
        """
        childList = self._getChildren(node)
        if len(childList)<2:
            return True
        return False    

    def insert(self,element,root,level=1):
        self.INSERT_FLAG=False
        self.insertElement(element,root)
        if self.INSERT_FLAG is False:
            print "Cant Insert !! Tree Full"

    def createDepthLinkedLists(self,root,level=1):
        """
        Create a Linked List of elements at various depths !!
        """

        if not self.depthLinkedDict.get(level):            
            self.depthLinkedDict[level] =[root.element]
        else:
            self.depthLinkedDict[level].append(root.element)
            
        if not self._getChildren(root):
            return        

        childList = self._getChildren(root)
        for eachChild in childList:
            self.createDepthLinkedLists(eachChild,level+1)        
        

    def insertElement(self,element,root,level=1):
        """
        Insert elements in a Tree until a tree is full !!
        """            
        if self._hasSpace(root) and self.INSERT_FLAG==False and level<self.maxLevel:
            newNode = Node(element)
            if root.lchild is None:
                root.lchild=newNode
            else:
                root.rchild = newNode
            self.INSERT_FLAG = True

        else:
            childList = self._getChildren(root)
            for eachChild in childList:
                self.insertElement(element,eachChild,level+1)

        return           

    def checkBalanced(self,node,level=1):
        """
        Check if a Tree is Balanced !!
        """        
        if not self._getChildren(node):
            self.DEPTH_LIST.append(level)
            return 

        else:
            childList = self._getChildren(node)
            for each in childList:
                self.checkBalanced(each,level+1)                   

    def _deQueue(self,l):
        element = l[0]
        if len(l)==1:
            return element,[]        
        l = l[1:-1] + [l[-1]]
        return element,l

    def breadthFirstPrint(self,root):
        """
        Do a breadth First printing of the whole Tree !!!
        """
        queue = []
        queue.append(root)

        while queue:
            curElement,queue = self._deQueue(queue)
            print curElement.element
            if curElement.lchild!=None:
                queue.append(curElement.lchild)

            if curElement.rchild!=None:
                queue.append(curElement.rchild)      
        

    def prettyPrint(self):
        """
        Pretty Print a Tree
        """        

    def postOrderPrint(self,root):
        """
        Traverse a Tree in Post Order Retrieval form !!
        """
        if not self._getChildren(root):
            print root.element

        else:
            childList = self._getChildren(root)
            self.postOrderPrint(childList[0])
            if childList[1] is not None:
                self.postOrderPrint(childList[1])           
            print root.element    

    def inOrderPrint(self,root):
        """
        Prints a Tree in InOrder Format !!
        """                  
        if not self._getChildren(root):
            print root.element

        else:
            childList = self._getChildren(root)
            self.inOrderPrint(childList[0])
            print root.element
            if childList[1] is not None:
                self.inOrderPrint(childList[1])           


    def deleteNode(self,element):
        """
        delete Nodes from a Tree
        """
        a=1

    def _getChildren(self,root):
        childList = []
        if root.lchild:
            childList.append(root.lchild)

        if root.rchild:
            childList.append(root.rchild)
        return childList        

    def printTree(self,root):
        """
        Print Elements of a Tree !!
        """ 
        print root.element
        childList = self._getChildren(root)

        for eachChild in childList:
            self.printTree(eachChild)
            
        return
        
    def printRoot(self):
        """
        """
        print self.root.element

if __name__=="__main__":
    import ipdb
    print "Hello"
    obj = BinaryTree(5,3)
    tree = obj.root
    obj.insert(10,tree)
    obj.insert(20,tree)
    obj.insert(30,tree)
    obj.insert(40,tree)
    obj.insert(50,tree)
    obj.insert(60,tree)
    obj.insert(70,tree)
    print "Printing Tree"
    obj.printTree(tree)

    print "Trying to Create New Tree"
    ntree= obj.createTreefromArray([1,2,3,4,5,6,7])
    obj.printTree(ntree)
    obj.checkBalanced(ntree)    
    print obj.DEPTH_LIST
    print obj.inOrderPrint(ntree)
    print obj.postOrderPrint(ntree)
    print obj.breadthFirstPrint(ntree)

    # 
    obj.createDepthLinkedLists(ntree)
    print obj.depthLinkedDict
    
        
    
