#include<iostream>

using std::endl;
using std::cout;

typedef struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
} ListNode, *pListNode;

pListNode CreateListNode(int n);
void ConnectListNode(const pListNode& pa, const pListNode& pb);
void DestroyList(pListNode& pHead);
const pListNode FindKthFromTail(const pListNode& pHead, const int& k);
void Test(const char* testName, const pListNode& pHead, const int& k, const pListNode& expected);
void Test1();
int main()
{
	Test1();
	return 0;
}

const pListNode FindKthFromTail(const pListNode&  pHead, const int& k)
{
	if(nullptr == pHead || k <= 0)
	{
		return nullptr;
	}
	pListNode pAheadNode = pHead;
	pListNode pBehindNode = nullptr;
	int i;
	for(i = 0; i < k - 1; ++i)
	{
		if(pAheadNode->m_pNext)
		{
			pAheadNode = pAheadNode->m_pNext;
		}else{
			return nullptr;
		}
	}
	pBehindNode = pHead;
	while(pAheadNode->m_pNext)
	{
		pAheadNode = pAheadNode->m_pNext;
		pBehindNode = pBehindNode->m_pNext;
	}
	return pBehindNode;
}

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
	}
	return;
}

void Test(const char* testName, const pListNode& pHead, const int& k, const pListNode& expected)
{
	cout << "*********" << testName << endl;
	pListNode pResult = FindKthFromTail(pHead, k);
	if(pResult == expected)
	{
		cout << "passed" << endl;
	}else{
		cout << "failed" << endl;
	}
}
void Test1()
{
	pListNode pa = CreateListNode(1);
	pListNode pb = CreateListNode(2);
	pListNode pc = CreateListNode(3);
	pListNode pd = CreateListNode(4);
	pListNode pe = CreateListNode(5);
	pListNode pf = CreateListNode(6);
	pListNode pg = CreateListNode(7);
	pListNode ph = CreateListNode(8);
	/*ConnectListNode(pa, pb);
	ConnectListNode(pb, pc);
	ConnectListNode(pc, pd);
	ConnectListNode(pd, pe);
	ConnectListNode(pe, pf);
	ConnectListNode(pf, pg);
	ConnectListNode(pg, ph);*/
	Test("test1 for 1,2,3,4,5,6, 7, 8at 1", pa, 1, pa);
	Test("test1 for 1,2,3,4,5,6, 7, 8at 2", pa, 3, nullptr);
	/*Test("test1 for 1,2,3,4,5,6, 7, 8at 3", nullptr, 3, nullptr);
	Test("test1 for 1,2,3,4,5,6, 7, 8at 8", nullptr, 10, nullptr);*/
	DestroyList(pa);
}
