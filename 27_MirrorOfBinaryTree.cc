#include<string>
#include<stack>
#include"binarytree.h"

using std::string;
using std::stack;

void MirrorOfBinaryTree(const pBTreeNode& pRoot);
void MirrorOfBinaryTreeIteratively(const pBTreeNode& pRoot);
void Test(const string testName, const pBTreeNode pRoot);
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

void MirrorOfBinaryTree(const pBTreeNode& pRoot)
{
	if(nullptr == pRoot)
	{
		return;
	}
	pBTreeNode pLeft = pRoot->m_pLeft;
	pBTreeNode pRight = pRoot->m_pRight;
	pRoot->m_pLeft = pRight;
	pRoot->m_pRight = pLeft;
	if(pRoot->m_pLeft)
	{
		MirrorOfBinaryTree(pRoot->m_pLeft);
	}
	if(pRoot->m_pRight)
	{
		MirrorOfBinaryTree(pRoot->m_pRight);
	}
}

void MirrorOfBinaryTreeIteratively(const pBTreeNode& pRoot)
{
	if(nullptr == pRoot)
	{
		return;
	}
	stack<pBTreeNode> stackBTreeNode;
	stackBTreeNode.push(pRoot);
	pBTreeNode pCurBTreeNode = nullptr;
	pBTreeNode pTempBTreeNode = nullptr;
	while(!stackBTreeNode.empty())
	{
		pCurBTreeNode = stackBTreeNode.top();
		stackBTreeNode.pop();
		if(pCurBTreeNode)
		{
			pTempBTreeNode = pCurBTreeNode->m_pLeft;
			pCurBTreeNode->m_pLeft = pCurBTreeNode->m_pRight;
			pCurBTreeNode->m_pRight = pTempBTreeNode;
		}
		if(pCurBTreeNode->m_pLeft)
		{
			stackBTreeNode.push(pCurBTreeNode->m_pLeft);
		}
		if(pCurBTreeNode->m_pRight)
		{
			stackBTreeNode.push(pCurBTreeNode->m_pRight);
		}
	}
}

void Test(const string testName, const pBTreeNode pRoot)
{
	cout << "********" << testName << "*********" << endl;
	cout << "-------the original tree is: " << endl;
	PrintBTree(pRoot, 1);
	MirrorOfBinaryTreeIteratively(pRoot);
	cout << "-------the Mirror tree is: " << endl;
	PrintBTree(pRoot, 1);
}

void Test1()
{
	Test("test1 for nullptr", nullptr);
	pBTreeNode p1 = CreateBTreeNode(1.0);
	Test("test1 for p1", p1);
	DestroyBTree(&p1);
}

void Test2()
{
	pBTreeNode p1 = CreateBTreeNode(1.0);
	pBTreeNode p2 = CreateBTreeNode(2.0);
	pBTreeNode p3 = CreateBTreeNode(3.0);
	pBTreeNode p4 = CreateBTreeNode(4.0);
	pBTreeNode p5 = CreateBTreeNode(5.0);
	pBTreeNode p6 = CreateBTreeNode(6.0);
	pBTreeNode p7 = CreateBTreeNode(7.0);
	ConnectBTreeNode(p1, p2, p3);
	ConnectBTreeNode(p2, p4, p5);
	ConnectBTreeNode(p3, p6, p7);
	Test("test1 for 1-7", p1);
	DestroyBTree(&p1);
	p1 = CreateBTreeNode(1.0);
	p2 = CreateBTreeNode(2.0);
	p3 = CreateBTreeNode(3.0);
	p4 = CreateBTreeNode(4.0);
	p5 = CreateBTreeNode(5.0);
	p6 = CreateBTreeNode(6.0);
	p7 = CreateBTreeNode(7.0);
	ConnectBTreeNode(p1, p2, p3);
	ConnectBTreeNode(p2, p4, p5);
	ConnectBTreeNode(p3, p6, p7);
	pBTreeNode p8 = CreateBTreeNode(8.0);
	ConnectBTreeNode(p4, p8, nullptr);
	Test("test1 for 1-8", p1);
	DestroyBTree(&p1);
}

void Test3()
{
	pBTreeNode p1 = CreateBTreeNode(1.0);
	pBTreeNode p2 = CreateBTreeNode(2.0);
	pBTreeNode p3 = CreateBTreeNode(3.0);
	pBTreeNode p4 = CreateBTreeNode(4.0);
	pBTreeNode p5 = CreateBTreeNode(5.0);
	pBTreeNode p6 = CreateBTreeNode(6.0);
	ConnectBTreeNode(p1, p2, nullptr);
	ConnectBTreeNode(p2, p3, nullptr);
	ConnectBTreeNode(p3, p4, nullptr);
	ConnectBTreeNode(p4, p5, nullptr);
	ConnectBTreeNode(p5, p6, nullptr);
	Test("test1 only left tree for 1-6", p1);
	ConnectBTreeNode(p1, nullptr, p2);
	ConnectBTreeNode(p2, nullptr, p3);
	ConnectBTreeNode(p3, nullptr, p4);
	ConnectBTreeNode(p4, nullptr, p5);
	ConnectBTreeNode(p5, nullptr, p6);
	Test("test1 only right tree for 1-6", p1);
	DestroyBTree(&p1);
	cout << "p1 address: " << p1 << endl;
}
