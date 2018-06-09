#include<iostream>
#include"listnode.h"

using std::cout;
using std::endl;

pListNode MeetinNode(const pListNode& pHead);
pListNode EntryNodeOfLoop(const pListNode& pHead);
void Test(const char* testName, const pListNode pHead, const pListNode pExpected);
void Test1();

int main()
{
	Test1();
	return 0;
}
pListNode MeetinNode(const pListNode& pHead)
{
	if(nullptr == pHead)
	{
		return nullptr;
	}
	pListNode pFast = pHead;
	pListNode pSlow = pHead;
	while(pFast->m_pNext)
	{
		pFast = pFast->m_pNext;
		pSlow = pSlow->m_pNext;
		if(pFast->m_pNext)
		{
			pFast = pFast->m_pNext;
		}else{
			return nullptr;
		}
		if(pFast == pSlow)
		{
			return pFast;
		}
	}
	return nullptr;
}

pListNode EntryNodeOfLoop(const pListNode& pHead)
{
	if(nullptr == pHead)
	{
		return nullptr;
	}
	pListNode pMeetingNode = MeetinNode(pHead);
	if(nullptr == pMeetingNode)
	{
		return nullptr;
	}
	int lengthOfLoop = 1;
	pListNode pCurNode = pMeetingNode->m_pNext;
	while(pCurNode != pMeetingNode)
	{
		++lengthOfLoop;
		pCurNode = pCurNode->m_pNext;
	}
	pListNode pEntryNodeOfLoop = pHead;
	pCurNode = pHead;
	int i;
	for(i = 0; i < lengthOfLoop; ++i)
	{
		pCurNode = pCurNode->m_pNext;
	}
	while(pCurNode != pEntryNodeOfLoop)
	{
		pCurNode = pCurNode->m_pNext;
		pEntryNodeOfLoop = pEntryNodeOfLoop->m_pNext;
	}
	return pEntryNodeOfLoop;
}

void Test(const char* testName, const pListNode pHead, const pListNode pExpected)
{
	cout << "*******" << testName << endl;
	const pListNode pEntryNodeOfLoop = EntryNodeOfLoop(pHead);
	if(pExpected == pEntryNodeOfLoop)
	{
		cout << "passed!" << endl;
	}else{
		cout << "failed" << endl;
	}
}

void Test1()
{
	/*Test("test1 for nullptr", nullptr, nullptr);*/
	
	//Test("test1 for 1 no loop", p1, nullptr);
	
	/*ConnectListNode(p1, p1);
	Test("test1 for 1 have loop", p1, p1);*/
	
	pListNode p1 = CreateListNode(1);
	pListNode p2 = CreateListNode(2);
	pListNode p3 = CreateListNode(3);
	pListNode p4 = CreateListNode(4);
	pListNode p5 = CreateListNode(5);
	pListNode p6 = CreateListNode(6);
	ConnectListNode(p1, p2);
	ConnectListNode(p2, p3);
	ConnectListNode(p3, p4);
	ConnectListNode(p4, p5);
	ConnectListNode(p5, p6);
	ConnectListNode(p6, p1);
	Test("test1 for 6 have no loop", p1, p1);
	
	//Connect(p1, p2);
	//ConnectListNode(p2, p1);
	//Test("test1 for 2 have loop in 2th", p1, p1);

	//DestroyList(p1);
}

