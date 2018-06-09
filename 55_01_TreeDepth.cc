#include<string>
#include<iostream>
#include<vector>
#include"binarytree.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;

int TreeDepth(const pBTreeNode pRoot);

void Test(const string testName, const pBTreeNode pRoot, const int expected);
void Test1();
void Test2();
void Test3();
void Test4();


int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	return 0;
}

int TreeDepth(const pBTreeNode pRoot)
{
	if(nullptr == pRoot)
	{
		return 0;
	}
	int leftDepth = TreeDepth(pRoot->m_pLeft);
	int RightDepth = TreeDepth(pRoot->m_pRight);
	int maxDepth = leftDepth >= RightDepth ? leftDepth : RightDepth;
	return maxDepth + 1;
}

void Test(const string testName, const pBTreeNode pRoot, const int expected)
{
	cout << "********" << testName << "********" << endl;
	int treeDepth = TreeDepth(pRoot);
	if(expected == treeDepth)
	{
		cout << "passed! " << endl;
	}else{
		cout << "failed" << endl;
	}
}

void Test1()
{
	Test("test1 for null", nullptr , 0);
}

void Test2()
{
	pBTreeNode p1 = CreateBTreeNode(5);
	Test("test2 for 1 node", p1, 1);
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
	ConnectBTreeNode(p3, p6, p7);

	Test("test3 for 1 node pass", p1, 3);
	DestroyBTree(&p1);
}

void Test4()
{
	pBTreeNode p1 = CreateBTreeNode(5);
	pBTreeNode p2 = CreateBTreeNode(4);
	pBTreeNode p3 = CreateBTreeNode(3);
	pBTreeNode p4 = CreateBTreeNode(2);
	pBTreeNode p5 = CreateBTreeNode(1);
	//pBTreeNode p6 = CreateBTreeNode(6);
	//pBTreeNode p7 = CreateBTreeNode(8);
	/*ConnectBTreeNode(p1, p2, nullptr);
	ConnectBTreeNode(p2, p3, nullptr);
	ConnectBTreeNode(p3, p4, nullptr);
	ConnectBTreeNode(p4, p5, nullptr);*/
	
	ConnectBTreeNode(p5, nullptr, p4);
	ConnectBTreeNode(p4, nullptr, p3);
	ConnectBTreeNode(p3, nullptr, p2);
	ConnectBTreeNode(p2, nullptr, p1);


	Test("test4 for 1 node pass", p5, 5);
	DestroyBTree(&p5);
}
