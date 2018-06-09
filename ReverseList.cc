//#include <iostream>
#include "listnode.h"

using std::cout;
using std::endl;

pListNode ReverseList(const pListNode& pHead);
pListNode ReverseList_Recursively(const pListNode& pHead);
pListNode Test(const char* testName, const pListNode pHead);
void Test1();

int main()
{
	Test1();
	return 0;
}

pListNode ReverseList(const pListNode& pHead)
{
	if(nullptr == pHead)
	{
		return nullptr;
	}
	pListNode pReverseListHead = nullptr;
	pListNode pPreNode = nullptr;
	pListNode pCurNode = pHead;
	pListNode pNextNode = nullptr;
	while(pCurNode)
	{
		pNextNode = pCurNode->m_pNext;
		if(nullptr == pNextNode)
		{
			pReverseListHead = pCurNode;
		}
		pCurNode->m_pNext =  pPreNode;
		pPreNode = pCurNode;
		pCurNode = pNextNode;
	}
	return pReverseListHead;
}

pListNode Test(const char* testName, const pListNode pHead)
{
	cout << testName << endl;
	cout << "before is: " << endl;
	PrintList(pHead);
	pListNode pReverseListHead = ReverseList_Recursively(pHead);
	cout << "after is: " << endl;
	PrintList(pReverseListHead);
	return pReverseListHead;
}

pListNode ReverseList_Recursively(const pListNode& pHead)
{
	if(nullptr == pHead)
	{
		return nullptr;
	}
	if(nullptr == pHead->m_pNext)
	{
		return pHead;
	}
	pListNode pCurNode = pHead;
	pListNode pNextNode = pCurNode->m_pNext;
	pListNode pReverseListHead = ReverseList_Recursively(pNextNode);
	pCurNode->m_pNext->m_pNext = pCurNode;
	pCurNode->m_pNext = nullptr;
	return pReverseListHead;
}

void Test1()
{
	Test("test1 for nullptr", nullptr);
	pListNode p1 = CreateListNode(1);
	Test("test1 for 1 node", p1);
	pListNode p2 = CreateListNode(2);
	pListNode p3 = CreateListNode(3);
	pListNode p4 = CreateListNode(4);
	ConnectListNode(p1, p2);
	ConnectListNode(p2, p3);
	ConnectListNode(p3, p4);
	pListNode pReverseListHead = Test("test1 for 4 node", p1);
	DestroyList(pReverseListHead);
}
