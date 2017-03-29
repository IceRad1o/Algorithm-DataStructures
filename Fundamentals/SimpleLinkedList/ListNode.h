#pragma once
#ifndef LISTNODE_H
#define LISTNODE_H
template<typename NODETYPE>class List;

template<typename NODETYPE>
class ListNode
{
	frend class List<NODETYPE>;
public:
	ListNode(const NODETYPE &);//constructor
	NODETYPE getData() const;
private:
	NODETYPE data;
	ListNode <NODETYPE> *nextPtr;
};

template<typename NODETYPE>
ListNode<NODETYPE>::ListNode(const NODETYPE &info)
	:data(info), nextptr(0)
{

}
template<typename NODETYPE>
NODETYPE ListNode<NODETYPE>::getData() const
{
	return data;
}


#endif // !LISTNODE_H

