#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;

typedef struct ComplexListNode
{
	int m_nValue;
	ComplexListNode* m_pNext;
	ComplexListNode* m_pSibling;
} ComplexListNode;

void CloneNodes(ComplexListNode* pHead);
void ConnectSiblingNodes(ComplexListNode* pHead);
ComplexListNode* ReconnectNodes(ComplexListNode* pHead);
ComplexListNode* Clone(ComplexListNode* pHead);
void PrintComplexList(const ComplexListNode* pHead);
void Destroy(ComplexListNode** pHead);
ComplexListNode* CreateNode(const int value);
void ConnectNodes(ComplexListNode* pNode1, ComplexListNode* pNode2);
void ConnectNodes_Sibling(ComplexListNode* pNode1, ComplexListNode* pNode2);
void Test(const string testName, const ComplexListNode* pHead);
void Test1();
void Test2();
void Test3();

int main()
{
	Test1();
	Test2();
	Test3();
	return 0;
}

void CloneNodes(ComplexListNode*  pHead)
{
	if(nullptr == pHead)
	{
		return;
	}
	ComplexListNode* pCurNode = pHead;
	ComplexListNode* pNext = nullptr;
	ComplexListNode* pNew = nullptr;
	while(pCurNode)
	{
		pNew = new ComplexListNode;
		pNew->m_nValue = pCurNode->m_nValue;
		pNew->m_pNext = nullptr;
		pNew->m_pSibling = nullptr;
		pNext = pCurNode->m_pNext;
		pCurNode->m_pNext = pNew;
		pNew->m_pNext = pNext;
		pCurNode = pNext;
	}
}

void ConnectSiblingNodes(ComplexListNode* pHead)
{
	if(nullptr == pHead)
	{
		return;
	}
	ComplexListNode* pCurNode = pHead;
	ComplexListNode* pNextNode = nullptr;
	while(pCurNode)
	{
		pNextNode = pCurNode->m_pNext;
		if(pCurNode->m_pSibling)
		{
			pNextNode->m_pSibling = pCurNode->m_pSibling->m_pNext;
		}
		if(pNextNode)
		{
			pCurNode = pNextNode->m_pNext;
		}else{
			break;
		}
	}
}

ComplexListNode* ReconnectNodes(ComplexListNode* pHead)
{
	ComplexListNode* pCurNode = pHead;
	ComplexListNode* pResultCurNode = nullptr;
	ComplexListNode* pNextNode = nullptr;
	ComplexListNode* pNextNextNode = nullptr;
	ComplexListNode* pResultHead = nullptr;
	while(pCurNode)
	{
		pNextNode = pCurNode->m_pNext;
		if(pNextNode)
		{
			pNextNextNode = pNextNode->m_pNext;
		}else{
			pNextNextNode = nullptr;
		}
		if(nullptr == pResultHead)
		{
			pResultHead = pNextNode;
			pResultCurNode = pResultHead;
		}
		pCurNode->m_pNext = pNextNextNode;
		pCurNode = pNextNextNode;
		if(pNextNextNode)
		{
			pResultCurNode->m_pNext = pNextNextNode->m_pNext;
			pResultCurNode = pNextNextNode->m_pNext;
		}
	}
	return pResultHead;
}

ComplexListNode* Clone(ComplexListNode* pHead)
{
	if(nullptr == pHead)
	{
		return nullptr;
	}
	CloneNodes(pHead);
	ConnectSiblingNodes(pHead);
	return ReconnectNodes(pHead);
}

void PrintComplexList(const ComplexListNode* pHead)
{
	if(nullptr == pHead)
	{
		return;
	}
	while(pHead)
	{
		cout << "\t" << pHead->m_nValue;
		pHead = pHead->m_pNext;
	}
	cout << endl;
}

void Destroy(ComplexListNode** pHead)
{
	if(nullptr == pHead || nullptr == *pHead)
	{
		return;
	}
	ComplexListNode* pCurNode = *pHead;
	ComplexListNode* pTemp = nullptr;
	while(pCurNode)
	{
		pTemp = pCurNode->m_pNext;
		delete pCurNode;
		pCurNode = pTemp;
	}
	*pHead = nullptr;
}

ComplexListNode* CreateNode(const int value)
{
	ComplexListNode* p = new ComplexListNode;
	p->m_nValue = value;
	p->m_pNext = nullptr;
	p->m_pSibling = nullptr;
	return p;
}

void ConnectNodes(ComplexListNode* pNode1, ComplexListNode* pNode2)
{
	if(pNode1)
	{
		pNode1->m_pNext = pNode2;
	}
}

void ConnectNodes_Sibling(ComplexListNode* pNode1, ComplexListNode* pNode2)
{
	if(pNode1)
	{
		pNode1->m_pSibling = pNode2;
	}
}

void Test(const string testName, const ComplexListNode* pHead)
{
	cout << "***********" << testName << "*********" << endl;
	cout << "the copy list is:" << endl;
	ComplexListNode* pResult = Clone(const_cast<ComplexListNode*>(pHead));
	PrintComplexList(pResult);
}
void Test1()
{
	Test("test1 for null list!", nullptr);
	cout << endl;
}
void Test2()
{
	ComplexListNode* p1 = CreateNode(1);
	Test("test1 for 1 node! but m_pSibling is null", p1);
	ConnectNodes_Sibling(p1, p1);
	Test("test1 for 1 node! but m_pSibling is own", p1);
	cout << endl;
	Destroy(&p1);
}
void Test3()
{
	ComplexListNode* p1 = CreateNode(1);
	ComplexListNode* p2 = CreateNode(2);
	ComplexListNode* p3 = CreateNode(3);
	ComplexListNode* p4 = CreateNode(4);
	ComplexListNode* p5 = CreateNode(5);
	ComplexListNode* p6 = CreateNode(6);
	ComplexListNode* p7 = CreateNode(7);
	ConnectNodes(p1, p2);
	ConnectNodes(p2, p3);
	ConnectNodes(p3, p4);
	ConnectNodes(p4, p5);
	ConnectNodes(p6, p7);
	Test("test1 for 1 node! but m_pSibling is null", p1);
	cout << endl;
	ConnectNodes_Sibling(p1, p3);
	ConnectNodes_Sibling(p3, p1);
	ConnectNodes_Sibling(p7, p2);
	Test("test1 for 1 node! but m_pSibling is own", p1);
	cout << endl;
	Destroy(&p1);

}
