#include"binarytree.h"
#include<string>

using std::string;

bool IsTree1HaveTree2(const pBTreeNode& pRoot1, const pBTreeNode& pRoot2);
bool HasSubtree(const pBTreeNode& pRoot1, const pBTreeNode& pRoot2);
bool IsEqual(const double db1, const double db2);
void Test(const string testName, const pBTreeNode pRoot1, const pBTreeNode pRoot2, const bool expected);
void Test1();

int main()
{
	Test1();
	return 0;
}

bool IsEqual(const double db1, const double db2)
{
	if((db1 - db2 > -0.0000001) && (db1 - db2 < 0.0000001))
	{
		return true;
	}else{
		return false;
	}
}

bool IsTree1HaveTree2(const pBTreeNode& pRoot1, const pBTreeNode& pRoot2)
{
	if(nullptr == pRoot2)
	{
		return true;
	}
	if(nullptr == pRoot1)
	{
		return false;
	}
	if(IsEqual(pRoot1->m_dbValue, pRoot2->m_dbValue))
	{
		return IsTree1HaveTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) && 
			IsTree1HaveTree2(pRoot1->m_pRight, pRoot2->m_pRight);
	}else{
		return false;
	}
}

bool HasSubtree(const pBTreeNode& pRoot1, const pBTreeNode& pRoot2)
{	
	if(nullptr == pRoot1 || nullptr == pRoot2)
	{
		return false;
	}
	bool result = false;
	if(IsEqual(pRoot1->m_dbValue, pRoot2->m_dbValue))
	{
		result = IsTree1HaveTree2(pRoot1, pRoot2);
	}
	if(!result)
	{
		result = HasSubtree(pRoot1->m_pLeft, pRoot2) || HasSubtree(pRoot1->m_pRight, pRoot2);
	}
	return result;
}

void Test(const string testName, const pBTreeNode pRoot1, const pBTreeNode pRoot2, const bool expected)
{
	cout << "*******" << testName << "********" << endl;
	cout << "the first Ttree is: " << endl;
	PrintBTree(pRoot1, 1);
	cout << "the second Ttree is: " << endl;
	PrintBTree(pRoot2, 1);
	const bool result = HasSubtree(pRoot1, pRoot2);
	if(expected == result)
	{
		cout << "passed!" << endl;
	}else{
		cout << "failed" << endl;
	}
}

void Test1()
{
	Test("test1 for nullptr and nullptr", nullptr, nullptr, false);
	
	pBTreeNode p1 = CreateBTreeNode(8.0);
	Test("test1 for p1 and nullptr", p1, nullptr, false);
	Test("test1 for nullptr and p1", nullptr, p1, false);
	
	pBTreeNode p2 = CreateBTreeNode(8.0);
	pBTreeNode p3 = CreateBTreeNode(7.0);
	//ConnectBTreeNode(p1, p2, p3);
	pBTreeNode p21 = CreateBTreeNode(7.0);
	//Test("test1 for 8-8-7 and 8", p1, p21, true);
	
	pBTreeNode p4 = CreateBTreeNode(9.0);
	pBTreeNode p5 = CreateBTreeNode(3.0);
	pBTreeNode p6 = CreateBTreeNode(4.0);
	pBTreeNode p7 = CreateBTreeNode(7.0);
	//ConnectBTreeNode(p2, p4, p5);
	//ConnectBTreeNode(p5, p6, p7);
	ConnectBTreeNode(p1, p2, nullptr);
	ConnectBTreeNode(p2, p3,nullptr);
	ConnectBTreeNode(p3, p4,  nullptr);
	ConnectBTreeNode(p4, p5, nullptr);
	ConnectBTreeNode(p5, p6, nullptr);
	ConnectBTreeNode(p6, p7, nullptr);
	
	//pBTreeNode p21 = CreateBTreeNode(8.0);
	pBTreeNode p22 = CreateBTreeNode(9.0);
	pBTreeNode p23 = CreateBTreeNode(3.0);
	//ConnectBTreeNode(p21, p22, p23);
	ConnectBTreeNode(p21, p22, nullptr);
	ConnectBTreeNode(p22, p23, nullptr);
	Test("test1 for 8-8-7-9-2-4-7 and 8-9-2", p1, p21, true);
	DestroyBTree(&p1);
	DestroyBTree(&p21);
}
