#include<string>
#include<iostream>
#include<vector>
#include"binarytree.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;

pBTreeNode GetKthNodeInBST(const pBTreeNode pRoot, int k);
pBTreeNode GetKthNodeInBSTCore(const pBTreeNode pRoot, int& k);
void Test(const string testName, const pBTreeNode pRoot, int k, const pBTreeNode pExpected);
void Test1();
void Test2();
void Test3();
//void Test4();


int main()
{
	Test1();
	Test2();
	Test3();
	//Test4();
	return 0;
}

pBTreeNode GetKthNodeInBST(const pBTreeNode pRoot, int k)
{
	if(nullptr == pRoot || k <= 0)
	{
		return nullptr;
	}
	return GetKthNodeInBSTCore(pRoot, k);
}

pBTreeNode GetKthNodeInBSTCore(const pBTreeNode pRoot, int& k)
{
	if(nullptr == pRoot)
	{
		return nullptr;
	}
	pBTreeNode res = GetKthNodeInBSTCore(pRoot->m_pLeft, k);
	if(res == nullptr && 1 == k)
	{
		return pRoot;
	}else if(res)
	{
		return res;
	}
	--k;
	res = GetKthNodeInBSTCore(pRoot->m_pRight, k);
	return res;
}

void Test(const string testName, const pBTreeNode pRoot, int k, const pBTreeNode pExpected)
{
	cout << "********" << testName << "********" << endl;
	pBTreeNode res = GetKthNodeInBST(pRoot, k);
	if(pExpected == res)
	{
		cout << "passed! " << endl;
	}else{
		cout << "failed" << endl;
	}
}

void Test1()
{
	Test("test1 for null", nullptr , 1, nullptr);
}

void Test2()
{
	pBTreeNode p1 = CreateBTreeNode(5);
	Test("test2 for 1 node", p1, 1, p1);
	Test("test2 for 1 node", p1, 5, nullptr);
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

	Test("test3 for 1 node pass", p1, -1, nullptr);
	Test("test3 for 1 node pass", p1, 8, nullptr);
	Test("test3 for 1 node pass", p1, 1, p4);
	Test("test3 for 1 node pass", p1, 2, p2);
	Test("test3 for 1 node pass", p1, 3, p5);
	Test("test3 for 1 node pass", p1, 4, p1);
	Test("test3 for 1 node pass", p1, 5, p6);
	Test("test3 for 1 node pass", p1, 6, p3);
	Test("test3 for 1 node pass", p1, 7, p7);
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


	Test("test3 for 1 node pass", p5, -1, nullptr);
	Test("test3 for 1 node pass", p5, 1, p1);
	Test("test3 for 1 node pass", p5, 2, p2);
	Test("test3 for 1 node pass", p5, 3, p3);
	Test("test3 for 1 node pass", p5, 4, p4);
	Test("test3 for 1 node pass", p5, 5, p5);
	Test("test3 for 1 node pass", p5, 6, nullptr);
	Test("test3 for 1 node pass", p5, 0, nullptr);
	DestroyBTree(&p5);
}
