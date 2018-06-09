#include<iostream>

using std::cout;
using std::endl;

typedef struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
} listNode, *plistNode;

void DeleteNode(plistNode* ppHead, plistNode pToBeDeleted);
void PrintList(const plistNode pHead);
void Test(const char* testName, plistNode* ppHead, plistNode pToBeDeleted);
void Test1();

int main()
{
	Test1();
	return 0;
}

void DeleteNode(plistNode *ppHead, plistNode pToBeDeleted)
{
	if(nullptr == ppHead || nullptr == pToBeDeleted)
	{
		return;
	}
	plistNode pNext;
	if(pToBeDeleted->m_pNext != nullptr)
	{
		pNext = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNext->m_nValue;
		pToBeDeleted->m_pNext = pNext->m_pNext;
		delete pNext;
		pNext = nullptr;
	}else if(pToBeDeleted == *ppHead)
	{
		delete *ppHead;
		pToBeDeleted = nullptr;
		*ppHead = nullptr;
	}else{
		pNext = *ppHead;
		while(pNext->m_pNext != pToBeDeleted)
		{
			pNext = pNext->m_pNext;
		}
		pNext->m_pNext = nullptr;
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}

void PrintList(const plistNode pHead)
{
	if(nullptr == pHead)
	{
		cout << "null list!" << endl;
	}
	plistNode pcur = pHead;
	while(pcur)
	{
		cout << pcur->m_nValue << "  ";
		pcur = pcur->m_pNext;
	}
	cout << endl;
}

void Test(const char* testName, plistNode* ppHead, plistNode pToBeDeleted)
{
	cout << "------" << testName << "--------"<< endl;
	DeleteNode(ppHead, pToBeDeleted);
	PrintList(*ppHead);
}

void Test1()
{
	plistNode pa = new listNode;
	plistNode pb = new listNode;
	plistNode pc = new listNode;
	plistNode pd = new listNode;
	plistNode pe = new listNode;
	pa->m_nValue = 1;
	pa->m_pNext = pb;
	pb->m_nValue = 2;
	pb->m_pNext = pc;
	pc->m_nValue = 3;
	pc->m_pNext = pd;
	pd->m_nValue = 4;
	pd->m_pNext = pe;
	pe->m_nValue = 5;
	pe->m_pNext = nullptr;
	plistNode p = nullptr;
	plistNode* ppHead = nullptr;
	plistNode pToBeDeleted = nullptr;
	cout << "before delete" << endl;
	PrintList(pa);
	cout << "after delelte" << endl;
	Test("test1 for ppHead = nullptr", ppHead, nullptr);
	//DeleteNode(nullptr, pToBeDeleted);
}


