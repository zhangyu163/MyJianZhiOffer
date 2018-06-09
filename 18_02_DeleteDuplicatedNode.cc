#include<iostream>

using std::cout;
using std::endl;

typedef struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
} listNode, *plistNode;

void PrintList(const plistNode pHead);
void DeleteDuplicatedNode(plistNode* ppHead);
void Test(const char* testName, plistNode pHead);
void Test1();

int main()
{
	Test1();
	return 0;
}

void DeleteDuplicatedNode(plistNode* ppHead)
{
	if(nullptr == ppHead || nullptr == *ppHead)
	{
		return;
	}
	plistNode pPreNode = nullptr;
	plistNode pCurNode = nullptr;
	plistNode pNextNode = nullptr;
	pCurNode = *ppHead;
	while(pCurNode)
	{
		pNextNode = pCurNode->m_pNext;
		if(pNextNode != nullptr && pNextNode->m_nValue != pCurNode->m_nValue)
		{
			pPreNode = pCurNode;
			pCurNode = pNextNode;
		}else if(pNextNode != nullptr)
		{
			int value = pCurNode->m_nValue;
			plistNode pToDel = pCurNode;
			while(pToDel && pToDel->m_nValue == value)
			{
				pNextNode = pToDel->m_pNext;
				delete pToDel;
				pToDel = pNextNode;
			}
			pCurNode = pToDel;
			if(nullptr == pPreNode)
			{
				*ppHead = pCurNode;
			}else{
				pPreNode->m_pNext = pCurNode;
			}
		}else{
			break;
		}
	}
}

void Test(const char* testName, plistNode pHead)
{
	cout << testName << endl;
	cout << "before" << endl;
	PrintList(pHead);
	cout << "after" << endl;
	DeleteDuplicatedNode(&pHead);
	PrintList(pHead);
}

void PrintList(const plistNode pHead)
{
	if(pHead)
	{
		plistNode pCur = pHead;
		while(pCur)
		{
			cout << pCur->m_nValue << "\t" << endl;
			pCur = pCur->m_pNext;
		}
	}
}

void Test1()
{
	plistNode pa = new listNode;
	plistNode pb = new listNode;
	plistNode pc = new listNode;
	plistNode pd = new listNode;
	plistNode pe = new listNode;
	plistNode pf = new listNode;
	plistNode pg = new listNode;
	plistNode ph = new listNode;
	pa->m_nValue = 1;
	pa->m_pNext = pb;
	pb->m_nValue = 2;
	pb->m_pNext = pc;
	pc->m_nValue = 3;
	pc->m_pNext = pd;
	pd->m_nValue = 4;
	pd->m_pNext = pe;
	pe->m_nValue = 5;
	pe->m_pNext = pf;
	pf->m_nValue = 6;
	pf->m_pNext = pg;
	pg->m_nValue = 7;
	pg->m_pNext = ph;
	ph->m_nValue = 8;
	ph->m_pNext = nullptr;
	plistNode pHead;
	pHead = pa;
	Test("test1 for :" , pHead);
}
