#include<string>
#include"binarytree.h"

using std::string;

bool isEqual(const double& db1, const double& db2);
bool isSymmetrical(const pBTreeNode pRoot);
bool isSymmetrical(const pBTreeNode pRoot1, const pBTreeNode pRoot2);
void Test(const string testName, const pBTreeNode& pRoot, const bool expected);
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

bool isSymmetrical(const pBTreeNode pRoot)
{
	return isSymmetrical(pRoot, pRoot);
}

bool isEqual(const double& db1, const double& db2)
{
	if(db1 - db2 > -0.0000001 && db1 - db2 < 0.0000001)
	{
		return true;
	}else{
		return false;
	}
}

bool isSymmetrical(const pBTreeNode pRoot1, const pBTreeNode pRoot2)
{
	if(nullptr == pRoot1 && nullptr == pRoot2)
	{
		return true;
	}else if(nullptr == pRoot1 && pRoot2)
	{
		return false;
	}else if(pRoot1 && nullptr == pRoot2)
	{
		return false;
	}
	if(isEqual(pRoot1->m_dbValue, pRoot2->m_dbValue))
	{
		return isSymmetrical(pRoot1->m_pLeft, pRoot2->m_pRight) && 
			isSymmetrical(pRoot1->m_pRight, pRoot2->m_pLeft);
	}else{
		return false;
	}
}

void Test(const string testName, const pBTreeNode& pRoot, const bool expected)
{
	cout << "*******" << testName << "*******" << endl;
	bool result = isSymmetrical(pRoot);
	PrintBTree(pRoot, 0);
	if(expected == result)
	{
		cout << "passed" << endl;
	}else{
		cout << "failed" << endl;
	}
}

void Test1()
{
	Test("test1 for nullptr", nullptr, true);
	pBTreeNode p1 = CreateBTreeNode(1);
	Test("test1 for 1 node", p1, true);
	DestroyBTree(&p1);
}
void Test2()
{
	pBTreeNode p1 = CreateBTreeNode(2);
	pBTreeNode p2 = CreateBTreeNode(2);
	ConnectBTreeNode(p1, p2, nullptr);
	Test("test2 for 2 node", p1, false);
	DestroyBTree(&p1);
	
	p1 = CreateBTreeNode(2);
	p2 = CreateBTreeNode(2);
	pBTreeNode p3 = CreateBTreeNode(2);
	pBTreeNode p4 = CreateBTreeNode(2);
	pBTreeNode p5 = CreateBTreeNode(2);
	pBTreeNode p6 = CreateBTreeNode(2);
	ConnectBTreeNode(p1, p2, p3);
	ConnectBTreeNode(p2, p4, p5);
	ConnectBTreeNode(p3, p6, nullptr);
	Test("test2 for 2 node", p1, false);
	DestroyBTree(&p1);
}
void Test3()
{
	pBTreeNode p1 = CreateBTreeNode(1);
	pBTreeNode p2 = CreateBTreeNode(2);
	pBTreeNode p3 = CreateBTreeNode(2);
	ConnectBTreeNode(p1, p2, p3);
	Test("test3 for 1-2-2", p1, true);
	DestroyBTree(&p1);
	
	p1 = CreateBTreeNode(8);
	p2 = CreateBTreeNode(6);
	p3 = CreateBTreeNode(6);
	pBTreeNode p4 = CreateBTreeNode(5);
	pBTreeNode p5 = CreateBTreeNode(7);
	pBTreeNode p6 = CreateBTreeNode(7);
	pBTreeNode p7 = CreateBTreeNode(5);
	ConnectBTreeNode(p1, p2, p3);
	ConnectBTreeNode(p2, p4, p5);
	ConnectBTreeNode(p3, p6, p7);
	Test("test2 for 8-6-6-5-7-7-5", p1, true);
	DestroyBTree(&p1);
}
