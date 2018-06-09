#include<iostream>
#include"listnode.h"

using std::cout;
using std::endl;

pListNode MergeSortedLists(pListNode& pHead1, pListNode& pHead2);
pListNode MergeSortedLists_Recursively(pListNode& pHead1, pListNode& pHead2);
void Test(const char* testName, pListNode pHead1, pListNode pHead2);
void Test1();

int main()
{
	Test1();
	return 0;
}

pListNode MergeSortedLists(pListNode& pHead1, pListNode& pHead2)
{
	if(nullptr == pHead1)
	{
		return pHead2;
	}else if(nullptr == pHead2)
	{
		return pHead1;
	}
	pListNode pCurNode1 = pHead1;
	pListNode pCurNode2 = pHead2;
	pListNode pMergeHead = nullptr;
	pListNode pCurOfMerge = nullptr;
	if(pCurNode1->m_nValue <= pCurNode2->m_nValue)
	{
		pMergeHead = pHead1;
		pCurNode1 = pHead1->m_pNext;
	}else{
		pMergeHead = pHead2;
		pCurNode2 = pHead2->m_pNext;
	}
	pCurOfMerge = pMergeHead;
	while(pCurNode1 && pCurNode2)
	{
		if(pCurNode1->m_nValue <= pCurNode2->m_nValue)
		{
			pCurOfMerge->m_pNext = pCurNode1;
			pCurOfMerge = pCurNode1;
			pCurNode1 = pCurNode1->m_pNext;
			pCurOfMerge->m_pNext = nullptr;
		}else{
			pCurOfMerge->m_pNext = pCurNode2;
			pCurOfMerge = pCurNode2;
			pCurNode2 = pCurNode2->m_pNext;
			pCurOfMerge->m_pNext = nullptr;
		}
	}
	if(pCurNode1)
	{
		pCurOfMerge->m_pNext = pCurNode1;
	}else{
		pCurOfMerge->m_pNext = pCurNode2;
	}
	return pMergeHead;
}

pListNode MergeSortedLists_Recursively(pListNode& pHead1, pListNode& pHead2)
{
	if(nullptr == pHead1)
	{
		return pHead2;
	}else if(nullptr == pHead2)
	{
		return pHead1;
	}
	pListNode pMergeHead = nullptr;
	if(pHead1->m_nValue <= pHead2->m_nValue)
	{
		pMergeHead = pHead1;
		pMergeHead->m_pNext = MergeSortedLists_Recursively(pHead1->m_pNext, pHead2);
	}else{
		pMergeHead = pHead2;
		pMergeHead->m_pNext = MergeSortedLists_Recursively(pHead1, pHead2->m_pNext);
	}
	return pMergeHead;
}

void Test(const char* testName, pListNode pHead1, pListNode pHead2)
{
	cout << "*****" << testName << endl;
	cout << "list1:";
	PrintList(pHead1);
	cout << "list2:";
	PrintList(pHead2);
	pListNode pMergeHead = MergeSortedLists_Recursively(pHead1, pHead2);
	cout << "merged list is: ";
	PrintList(pMergeHead);
}

void Test1()
{
	pListNode p2 = CreateListNode(2);
	Test("test1 for nullptr pHead1", nullptr, p2);

	pListNode p1 = CreateListNode(1);
	Test("test1 for nullptr pHead2", p1, nullptr);

	Test("test1 for 1 and 2", p1, p2);

	pListNode p3 = CreateListNode(2);
	pListNode p4 = CreateListNode(3);
	pListNode p5 = CreateListNode(3);
	pListNode p6 = CreateListNode(3);
	pListNode p7 = CreateListNode(7);
	ConnectListNode(p1, p3);
	ConnectListNode(p3, p5);
	ConnectListNode(p5, p7);
	ConnectListNode(p2, p4);
	ConnectListNode(p4, p6);
	Test("test1 for 1357and246", p1, p2);
}
