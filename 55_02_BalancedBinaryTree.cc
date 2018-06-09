#include<string>
#include<iostream>
#include<vector>
#include"binarytree.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;

int TreeDepth(pBTreeNode pRoot);
bool IsBalancedBinaryTree(pBTreeNode pRoot);
bool IsBalancedBinaryTree_Postraversal(pBTreeNode pRoot, int& depth);
bool IsBalancedBinaryTree_Postraversal(pBTreeNode pRoot);

void Test(const string testName, const pBTreeNode pRoot, const bool expected);
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

int TreeDepth(pBTreeNode pRoot)
{
	if(nullptr == pRoot)
	{
		return 0;
	}
	int leftLen = TreeDepth(pRoot->m_pLeft);
	int rightLen = TreeDepth(pRoot->m_pRight);
	return leftLen >= rightLen ? (leftLen + 1) : (rightLen + 1);
}
bool IsBalancedBinaryTree(pBTreeNode pRoot)
{
	if(nullptr == pRoot)
	{
		return true;
	}
	int leftLen = TreeDepth(pRoot->m_pLeft);
	int rightLen = TreeDepth(pRoot->m_pRight);
	int diff = leftLen - rightLen;
	if(diff > 1 || diff < -1)
	{
		return false;
	}
	return IsBalancedBinaryTree(pRoot->m_pLeft) && IsBalancedBinaryTree(pRoot->m_pRight);
}

bool IsBalancedBinaryTree_Postraversal(pBTreeNode pRoot)
{
	if(nullptr == pRoot)
	{
		return true;
	}
	int depth = 0;
	return IsBalancedBinaryTree_Postraversal(pRoot, depth);
}

bool IsBalancedBinaryTree_Postraversal(pBTreeNode pRoot, int& depth)
{
	if(nullptr == pRoot)
	{
		depth = 0;
		return true;
	}
	int leftLen = 0;
	int rightLen = 0;
	if(IsBalancedBinaryTree_Postraversal(pRoot->m_pLeft, leftLen) && 
		IsBalancedBinaryTree_Postraversal(pRoot->m_pRight, rightLen))
	{
		int diff = leftLen - rightLen;
		depth = leftLen > rightLen ? (leftLen + 1) : (rightLen + 1);
		if(diff < -1 || diff > 1)
		{
			return false;
		}else{
			return true;
		}
	}
	return false;
}

void Test(const string testName, const pBTreeNode pRoot, const bool expected)
{
	cout << "********" << testName << "********" << endl;
	bool isBalanced = IsBalancedBinaryTree_Postraversal(pRoot);
	if(expected == isBalanced)
	{
		cout << "passed! " << endl;
	}else{
		cout << "failed" << endl;
	}
}

void Test1()
{
	Test("test1 for null", nullptr , true);
}

void Test2()
{
	pBTreeNode p1 = CreateBTreeNode(5);
	Test("test2 for 1 node", p1, true);
	DestroyBTree(&p1);
}

void Test3()
{
	pBTreeNode p1 = CreateBTreeNode(5);
	pBTreeNode p2 = CreateBTreeNode(3);
	pBTreeNode p3 = CreateBTreeNode(7);
	pBTreeNode p4 = CreateBTreeNode(2);
	pBTreeNode p5 = CreateBTreeNode(4);
	pBTreeNode p6 = CreateBTreeNode(6);
	pBTreeNode p7 = CreateBTreeNode(8);
	ConnectBTreeNode(p1, p2, p3);
	ConnectBTreeNode(p2, p4, p5);
	ConnectBTreeNode(p3, nullptr, p6);
	ConnectBTreeNode(p5, p7, nullptr);

	Test("test3 for 1 node pass", p1, true);
	DestroyBTree(&p1);
}

void Test4()
{
	pBTreeNode p1 = CreateBTreeNode(5);
	pBTreeNode p2 = CreateBTreeNode(4);
	pBTreeNode p3 = CreateBTreeNode(3);
	pBTreeNode p4 = CreateBTreeNode(2);
	pBTreeNode p5 = CreateBTreeNode(1);
	pBTreeNode p6 = CreateBTreeNode(6);
	//pBTreeNode p7 = CreateBTreeNode(8);
	/*ConnectBTreeNode(p1, p2, nullptr);
	ConnectBTreeNode(p2, p3, nullptr);
	ConnectBTreeNode(p3, p4, nullptr);
	ConnectBTreeNode(p4, p5, nullptr);*/
	
	ConnectBTreeNode(p1, p2, p3);
	ConnectBTreeNode(p2, p4, p5);
	ConnectBTreeNode(p5, p6, nullptr);


	Test("test4 for 1 node pass", p1, false);
	DestroyBTree(&p1);
}

void Test5()
{
	pBTreeNode p1 = CreateBTreeNode(5);
	pBTreeNode p2 = CreateBTreeNode(4);
	pBTreeNode p3 = CreateBTreeNode(3);
	pBTreeNode p4 = CreateBTreeNode(2);
	pBTreeNode p5 = CreateBTreeNode(1);
	//pBTreeNode p6 = CreateBTreeNode(6);
	//pBTreeNode p7 = CreateBTreeNode(8);
	ConnectBTreeNode(p1, p2, nullptr);
	ConnectBTreeNode(p2, p3, nullptr);
	ConnectBTreeNode(p3, p4, nullptr);
	ConnectBTreeNode(p4, p5, nullptr);


	Test("test5 for 1 node pass", p1, false);
	DestroyBTree(&p1);
}
