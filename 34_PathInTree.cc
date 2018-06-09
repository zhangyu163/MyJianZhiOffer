#include<vector>
#include<string>
#include"binarytree.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

void FindPath(const pBTreeNode pRoot, const int expectedSum);
void FindPath(const pBTreeNode& pRoot, vector<int>& path, const int expectedSum, int& currentSum);
void Test(const string testName, const pBTreeNode pRoot, const int expectedSum);
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

void FindPath(const pBTreeNode pRoot, const int expectedSum)
{
	if(nullptr == pRoot)
	{
		return;
	}
	vector<int> path;
	int currentSum = 0;
	FindPath(pRoot, path, expectedSum, currentSum);
}

void FindPath(const pBTreeNode& pRoot, vector<int>& path, const int expectedSum, int& currentSum)
{
	if(nullptr == pRoot)
	{
		return;
	}
	bool isLeaf = false;
	if(nullptr == pRoot->m_pLeft && nullptr == pRoot->m_pRight)
	{
		isLeaf = true;
	}
	path.push_back(pRoot->m_nValue);
	currentSum += pRoot->m_nValue;
	if(isLeaf && currentSum == expectedSum)
	{
		vector<int>::const_iterator iter = path.begin();
		while(iter != path.end())
		{
			cout << "\t" << *iter;
			++iter;
		}
		cout << endl;
	}
	if(pRoot->m_pLeft)
	{
		FindPath(pRoot->m_pLeft, path, expectedSum, currentSum);
	}
	if(pRoot->m_pRight)
	{
		FindPath(pRoot->m_pRight, path, expectedSum, currentSum);
	}
	currentSum -= pRoot->m_nValue;
	path.pop_back();
}

void Test(const string testName, const pBTreeNode pRoot, const int expectedSum)
{
	cout << "*********" << testName << "*********" << endl;
	FindPath(pRoot, expectedSum);
}

void Test1()
{
//Test("test for null tree!", nullptr, 0);
}
void Test2()
{
	pBTreeNode p1 = CreateBTreeNode(1);
	pBTreeNode p2 = CreateBTreeNode(2);
	pBTreeNode p3 = CreateBTreeNode(4);
	pBTreeNode p4 = CreateBTreeNode(0);
	pBTreeNode p5 = CreateBTreeNode(0);
	pBTreeNode p6 = CreateBTreeNode(2);
	pBTreeNode p7 = CreateBTreeNode(0);

	ConnectBTreeNode(p1, p2, p3);
	ConnectBTreeNode(p2, p4, p5);
	ConnectBTreeNode(p5, nullptr, p6);
	ConnectBTreeNode(p4, nullptr, p7);
	Test("test for 1 2 0", p1, 5);
	DestroyBTree(&p1);

}
void Test3()
{

}
