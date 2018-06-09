#ifndef _LISTNODE_H_
#define _LISTNODE_H_ 

#include<iostream>
using std::cout;
using std::endl;

typedef struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
} ListNode, *pListNode;

pListNode CreateListNode(int n);
void ConnectListNode(const pListNode& pa, const pListNode& pb);
void DestroyList(pListNode& pHead);
void PrintList(const pListNode& pHead);

pListNode CreateListNode(int n)
{
	pListNode pNew = new ListNode;
	pNew->m_nValue = n;
	pNew->m_pNext = nullptr;
	return pNew;
}

void ConnectListNode(const pListNode& pa, const pListNode& pb)
{
	pa->m_pNext = pb;
}

void DestroyList(pListNode& pHead)
{
	pListNode temp = nullptr;
	while(pHead)
	{
		temp = pHead;
		pHead = temp->m_pNext;
		delete temp;
		temp = nullptr;
	}
	return;
}

void PrintList(const pListNode& pHead)
{
	if(nullptr == pHead)
	{
		cout << "The list is empty." << endl;
		return;
	}
	pListNode pNode = pHead;
	while(pNode)
	{
		cout << pNode->m_nValue << "\t";
		pNode = pNode->m_pNext;
	}
	cout << endl;
}

#endif
