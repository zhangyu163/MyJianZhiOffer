#include<iostream>
#include<string>
#include<algorithm>
#include"listnode.h"

using std::cout;
using std::endl;
using std::string;
using std::max;

pListNode FindFirstCommonNodeInLists(const pListNode pHead1, const pListNode pHead2);
int GetListLength(const pListNode pHead);
void Test(const string testName, const pListNode pHead1, const pListNode pHead2, 
		const pListNode expected);
void Test1();
void Test2();
void Test3();
void Test4();
void Test5();

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	return 0;
}

pListNode FindFirstCommonNodeInLists(const pListNode pHead1, const pListNode pHead2)
{
	if(nullptr == pHead1 || nullptr == pHead2)
	{
		return nullptr;
	}
	pListNode pCur1 = pHead1;
	pListNode pCur2 = pHead2;
	int length1 = GetListLength(pHead1);
	int length2 = GetListLength(pHead2);
	int lenDiff;
	if(length1 >= length2)
	{
		lenDiff = length1 - length2;
		while(lenDiff--)
		{
			pCur1 = pCur1->m_pNext;
		}
	}else{
		lenDiff = length2 - length1;
		while(lenDiff)
		{
			pCur2 = pCur2->m_pNext;
		}
	}
	while(pCur1)
	{
		if(pCur1 == pCur2)
		{
			break;
		}
		pCur1 = pCur1->m_pNext;
		pCur2 = pCur2->m_pNext;
	}
	return pCur1;
}

int GetListLength(const pListNode pHead)
{
	int count = 0;
	pListNode pCur = pHead;
	while(pCur)
	{
		++count;
		pCur = pCur->m_pNext;
	}
	return count;
}

void Test(const string testName, const pListNode pHead1, const pListNode pHead2, 
		const pListNode expected)
{
	cout << "****" << testName << "****" << endl;
	pListNode pCommonNode = FindFirstCommonNodeInLists(pHead1, pHead2);
	if(expected == pCommonNode)
	{
		cout << "passed!" << endl;
	}else{
		cout << "failed!" << endl;
	}
}

void Test1()
{
	Test("test1 for null", nullptr, nullptr, nullptr);
}

void Test2()
{
	pListNode p11 = CreateListNode(1);
	Test("test2 for null", p11, nullptr, nullptr);
	Test("test2 for null", nullptr, p11, nullptr);
	DestroyList(p11);
}

void Test3()
{
	pListNode p11 = CreateListNode(1);
	pListNode p21 = CreateListNode(4);
	Test("test3 for null", p11, p21, nullptr);
	DestroyList(p11);
	DestroyList(p21);
}
void Test4()
{
	pListNode p11 = CreateListNode(1);
	pListNode p12 = CreateListNode(2);
	pListNode p21 = CreateListNode(4);
	Test("test4 for null", p11, p21, nullptr);
	DestroyList(p11);
	DestroyList(p21);
}

void Test5()
{
	pListNode p11 = CreateListNode(1);
	pListNode p12 = CreateListNode(2);
	pListNode p13 = CreateListNode(3);
	pListNode p14 = CreateListNode(6);
	pListNode p15 = CreateListNode(7);
	//istNode p21 = p11;
	pListNode p21 = CreateListNode(4);
	pListNode p22 = CreateListNode(5);
	ConnectListNode(p11, p12);
	ConnectListNode(p12, p13);
	ConnectListNode(p13, p14);
	ConnectListNode(p14, p15);
	ConnectListNode(p21, p22);
	//ConnectListNode(p22, p15);
	Test("test5 for null", p11, p21, nullptr);
	DestroyList(p11);
	DestroyList(p21);
}
