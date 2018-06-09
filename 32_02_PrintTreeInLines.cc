#include<queue>
#include<string>
#include"binarytree.h"

using std::queue;
using std::string;

void PrintBTreeInLines(const pBTreeNode pRoot);
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

void PrintBTreeInLines(const pBTreeNode pRoot)
{
	if(nullptr == pRoot)
	{
		return;
	}
	queue<pBTreeNode> queueBTreeNode;
	queueBTreeNode.push(pRoot);
	pBTreeNode pCurBTreeNode = nullptr;
	int countOfNextFloor = 0;
	int countToBePrint = 1;
	while(!queueBTreeNode.empty())
	{
		pCurBTreeNode = queueBTreeNode.front();
		queueBTreeNode.pop();
		cout << "\t" << pCurBTreeNode->m_nValue;
		--countToBePrint;
		if(pCurBTreeNode->m_pLeft)
		{
			queueBTreeNode.push(pCurBTreeNode->m_pLeft);
			++countOfNextFloor;
		}
		if(pCurBTreeNode->m_pRight)
		{
			queueBTreeNode.push(pCurBTreeNode->m_pRight);
			++countOfNextFloor;
		}
		if(0 == countToBePrint)
		{
			cout << endl;
			countToBePrint = countOfNextFloor;
			countOfNextFloor = 0;
		}
	}
}

void Test(const string testName, const pBTreeNode pRoot)
{
	cout << "******" << testName << "********" << endl;
	PrintBTreeInLines(pRoot);
	//cout << endl;
}
void Test1()
{
	Test("test1 for nullptr", nullptr);
	
	pBTreeNode p1 = CreateBTreeNode(1);
	Test("test1 for 1 node", p1);
	delete p1;
	p1 = nullptr;
}

void Test2()
{
	pBTreeNode p1 = CreateBTreeNode(1);
	pBTreeNode p2 = CreateBTreeNode(2);
	pBTreeNode p3 = CreateBTreeNode(3);
	pBTreeNode p4 = CreateBTreeNode(4);
	pBTreeNode p5 = CreateBTreeNode(5);
	ConnectBTreeNode(p1, nullptr, p2);
	ConnectBTreeNode(p2, p3, nullptr);
	ConnectBTreeNode(p3, p4, nullptr);
	ConnectBTreeNode(p4, nullptr, p5);
	Test("test1 for only leftsubtree", p1);
	DestroyBTree(&p1);
	
	p1 = CreateBTreeNode(1);
	p2 = CreateBTreeNode(2);
	p3 = CreateBTreeNode(3);
	p4 = CreateBTreeNode(4);
	p5 = CreateBTreeNode(5);
	ConnectBTreeNode(p1, nullptr, p2);
	ConnectBTreeNode(p2, nullptr, p3);
	ConnectBTreeNode(p3, nullptr, p4);
	ConnectBTreeNode(p4, nullptr, p5);
	Test("test1 for only rightsubtree", p1);
	DestroyBTree(&p1);
}

void Test3()
{
	pBTreeNode p1 = CreateBTreeNode(1);
	pBTreeNode p2 = CreateBTreeNode(2);
	pBTreeNode p3 = CreateBTreeNode(3);
	pBTreeNode p4 = CreateBTreeNode(4);
	pBTreeNode p5 = CreateBTreeNode(5);
	pBTreeNode p6 = CreateBTreeNode(6);
	pBTreeNode p7 = CreateBTreeNode(7);
	ConnectBTreeNode(p1, p2, p3);
	ConnectBTreeNode(p2, p4, p5);
	ConnectBTreeNode(p3, p6, p7);
	Test("test1 for only leftsubtree", p1);
	DestroyBTree(&p1);
}
