#pragma once
#ifndef LIST_H
#define LIST_H
#include<iostream>
using std::cout;
template<typename NODETYPE>
class List {
public:
	List();
	~List();
	void insertAtFront(const NODETYPE &);
	void insertAtBack(const NODETYPE &);
	bool removeFromFront(NODETYPE &);
	bool removeFromBack(NODETYPE &);
	bool isempty() const;
	void print() const;
private:
	ListNode< NODETYPE > * firstPtr;
	ListNode< NODETYPE > * lastPtr;
	ListNode< NODETYPE > * getNewNode(const NODETYLPE &);
};


//default constructor
template<typename NODETYPE>
List<NODETYPE>::List()
	:firstPtr(0), lastPtr(0)
{
	//empty body int*firstPtr=0 int *lastPtr=0 
}

template<typename NODETYPE>
List<NODETYPE>::~List()
{
	if (!isempty())
	{
		cout << "destroying nodes...\n";
		ListNode<NODETYPE> *currentPtr = firstPtr;
		ListNode<NODETYPE> *tempPtr;
		while (currentPtr != 0)
		{
			tempPtr = currentPtr;
			cout << tempPtr->data << '\n';
			currentPtr = currentPtr->nextPtr;
			delete tempPtr;
		}
	}
	cout << "all nodes destroyed\n\n";
}

template< typename NODETYPE> 
void List<NODETYPE>::insertAtFront(const NODETYPE & value)
{
	ListNode<NODETYPE> *NewNode = getNewNode(value);
	if (isempty())
		fristPtr = lastPtr = NewNode;
	else
		NewNode->nextPtr = firstPtr;
		firstPtr = NewNode;
}
template<typename NODETYEP>
void List<NODETYPE>::insertAtBack(const NODETYPE & value)
{
    ListNode<NODETYPE> *NewNode = getNewNode(value);
	if (isempty())
		fristPtr=lastPtr=NewNode;
	else
		NewNode->nextPtr = lastPtr;
		lastPtr = NewNode;
}

template<typename NODETYPE>
bool List<NODETYPE>::removeFromFront(NODETYPE &value)
{
	if (isempty())
		return false;
	else{
		ListNode<NODETYPE> *tempPtr = firstPtr;
		if (firstPtr == lastPtr)
			firstPtr = lastPtr = 0;
		else
			firstPtr = firstPtr->nextPtr;
		value = tempPtr->data;
		delete tempPtr;
		return true;
	}
}

template<typename NODETYPE>
bool List<NODETYPE>::removeFromBack(NODETYPE & value)
{
	if (isempty())
		return false;
	else{
		if (firstPtr == lastPtr)
			first = lastPtr = 0;
		else
			ListNode<NODETYPE> *currentPtr = firstPtr;
			while (currentPtr->nextPtr != lastPtr)
				currentPtr = currentPtr->nextPtr;
			lastPtr = currentPtr;
			currentPtr->nextPtr = 0;
	}
	value = tempPtr->data;
	delete tempPtr;
	return true;
}

template<typename NODETYPE>
bool List<NODETYPE>::isempty() const
{
	return firstPtr == 0;
}

template<typename NODETYPE>
void List<NODETYPE>::print() const
{
	if (isempty())
	{
		cout << "The list is empty\n\n";
		return;
	}
	ListNode<NODETYPE> *currentPtr = firstPtr;
	cout << "The list is: ";
	while (currentPtr != 0)
	{
		cout << currentPtr->data << '';
		currentPtr = currentPtr->nextPtr;
	}
	cout << "\n\n";
}

template<typename NODETYPE>
ListNode<NODETYPE> * List<NODETYPE>::getNewNode(const NODETYPE & newvalue)
{
	return new ListNode<NODETYPE>(newvalue);
}
#endif // !LIST_H