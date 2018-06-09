#include<iostream>
#include<string>
#include"binarytree.h"

using std::cout;
using std::endl;
using std::string;

pBTreeNode Convert(pBTreeNode pRoot);
void ConvertNode_1(pBTreeNode pRoot, pBTreeNode* ppLastNodeInList);
void ConvertNode_2(pBTreeNode pRoot, pBTreeNode* ppLastNodeInList);
void PrintList(const pBTreeNode pHead);
void Destroy(pBTreeNode* pHead);
void Test(const string testName, pBTreeNode pRoot);
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

pBTreeNode Convert(pBTreeNode pRoot)
{
	if(nullptr == pRoot)
	{
		return nullptr;
	}
	pBTreeNode ppLastNodeInList = nullptr;
	ConvertNode_1(pRoot, &ppLastNodeInList);
	pBTreeNode pListHead = ppLastNodeInList;
	if(pListHead)
	{
		while(pListHead->m_pLeft != nullptr)
		{
			pListHead = pListHead->m_pLeft;
		}
	}
	return pListHead;
}
void ConvertNode_1(pBTreeNode pRoot, pBTreeNode* ppLastNodeInList)
{
	if(nullptr == pRoot)
	{
		return;
	}
	pBTreeNode pCurrent = pRoot;
	if(pCurrent->m_pLeft)
	{
		ConvertNode_1(pCurrent->m_pLeft, ppLastNodeInList);
	}
	if(*ppLastNodeInList)
	{
		(*ppLastNodeInList)->m_pRight = pCurrent;
	}
	pCurrent->m_pLeft = *ppLastNodeInList;
	*ppLastNodeInList = pCurrent;
	if(pCurrent->m_pRight)
	{
		ConvertNode_1(pCurrent->m_pRight, ppLastNodeInList);
	}
}

void ConvertNode_2(pBTreeNode pRoot, pBTreeNode* ppLastNodeInList)
{

}

void PrintList(const pBTreeNode pHead)
{
	if(nullptr == pHead)
	{
		return;
	}
	pBTreeNode pCur = pHead;
	while(pCur)
	{
		cout << "\t" << pCur->m_nValue;
		pCur = pCur->m_pRight;
	}
	cout << endl;
}
void Destroy(pBTreeNode* pHead)
{
	if(nullptr == pHead || nullptr == *pHead)
	{
		return;
	}
	pBTreeNode pCur = *pHead;
	pBTreeNode pNext = nullptr;
	while(pCur)
	{
		pNext = pCur->m_pRight;
		delete pCur;
		pCur = pNext;
	}
	*pHead = nullptr;
}

void Test(const string testName, pBTreeNode pRoot)
{
	cout << "*******" << testName << "******" << endl;
	pBTreeNode* ppLastNodeInList = nullptr;
	pBTreeNode result = Convert(pRoot);
	PrintList(result);
	cout << "converse:" << endl;
	if(result)
	{
		while(result->m_pRight)
		{
			result = result->m_pRight;
		}
		while(result)
		{
			cout << "\t" << result->m_nValue;
			result = result->m_pLeft;
		}
	}
	Destroy(&result);
}

void Test1()
{
	Test("test1 for null", nullptr);
	cout << endl;
	pBTreeNode p1 = CreateBTreeNode(1);
	Test("test1 for 1 node", p1);
	cout << endl;
}
void Test2()
{
	pBTreeNode p1 = CreateBTreeNode(1);
	pBTreeNode p2 = CreateBTreeNode(2);
	pBTreeNode p3 = CreateBTreeNode(3);
	pBTreeNode p4 = CreateBTreeNode(4);
	pBTreeNode p5 = CreateBTreeNode(5);
	ConnectBTreeNode(p1, p2, nullptr);
	ConnectBTreeNode(p2, p3, nullptr);
	ConnectBTreeNode(p3, p4, nullptr);
	ConnectBTreeNode(p4, p5, nullptr);
	Test("test1 for 1 node", p1);
	cout << endl;
}

void Test3()
{
	pBTreeNode p1 = CreateBTreeNode(10);
	pBTreeNode p2 = CreateBTreeNode(6);
	pBTreeNode p3 = CreateBTreeNode(14);
	pBTreeNode p4 = CreateBTreeNode(4);
	pBTreeNode p5 = CreateBTreeNode(8);
	pBTreeNode p6 = CreateBTreeNode(12);
	pBTreeNode p7 = CreateBTreeNode(16);
	ConnectBTreeNode(p1, p2, p3);
	ConnectBTreeNode(p2, p4, p5);
	ConnectBTreeNode(p3, p6, p7);
	Test("test1 for 1 node", p1);
	cout << endl;

}
