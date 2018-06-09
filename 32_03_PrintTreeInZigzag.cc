#include<queue>
#include<string>
#include<stack>
#include"binarytree.h"

using std::queue;
using std::string;
using std::stack;

void PrintBTreeInZigzag(const pBTreeNode pRoot);
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

void PrintBTreeInZigzag(const pBTreeNode pRoot)
{
	if(nullptr == pRoot)
	{
		return;
	}
	/*stack<pBTreeNode> stackOdd;
	stack<pBTreeNode> stackEven;
	int toBePirint = 1;
	int nextLevel = 0;
	int level = 1;
	pBTreeNode pTemp = nullptr;
	stackOdd.push(pRoot);
	while(!stackOdd.empty() || !stackEven.empty())
	{
		if(level & 0x1)
		{
			pTemp = stackOdd.top();
			stackOdd.pop();
			cout << "\t" << pTemp->m_nValue;
			if(pTemp->m_pLeft)
			{
				stackEven.push(pTemp->m_pLeft);
			}
			if(pTemp->m_pRight)
			{
				stackEven.push(pTemp->m_pRight);
			}
			if(stackOdd.empty())
			{
				cout << endl;
				++level;
			}
		}else{
			pTemp = stackEven.top();
			stackEven.pop();
			cout << "\t" << pTemp->m_nValue;
			if(pTemp->m_pRight)
			{
				stackOdd.push(pTemp->m_pRight);
			}
			if(pTemp->m_pLeft)
			{
				stackOdd.push(pTemp->m_pLeft);
			}
			if(stackEven.empty())
			{
				cout << endl;
				++level;
			}
		}
	}*/
	stack<pBTreeNode> levels[2];
	int current = 0;
	int next = 1;
	levels[current].push(pRoot);
	while(!levels[current].empty() || !levels[next].empty())
	{
		pBTreeNode pTemp = levels[current].top();
		levels[current].pop();
		cout << "\t" << pTemp->m_nValue;
		if(current)
		{
			if(pTemp->m_pRight)
			{
				levels[next].push(pTemp->m_pRight);
			}
			if(pTemp->m_pLeft)
			{
				levels[next].push(pTemp->m_pLeft);
			}
		}else{
			if(pTemp->m_pLeft)
			{
				levels[next].push(pTemp->m_pLeft);
			}
			if(pTemp->m_pRight)
			{
				levels[next].push(pTemp->m_pRight);
			}
		}
		if(levels[current].empty())
		{
			current = 1 - current;
			next = 1 - next;
			cout << endl;
		}
	}
}

void Test(const string testName, const pBTreeNode pRoot)
{
	cout << "******" << testName << "********" << endl;
	PrintBTreeInZigzag(pRoot);
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
	pBTreeNode p8 = CreateBTreeNode(8);
	pBTreeNode p9 = CreateBTreeNode(9);
	pBTreeNode p10 = CreateBTreeNode(10);
	pBTreeNode p11 = CreateBTreeNode(11);
	pBTreeNode p12 = CreateBTreeNode(12);
	pBTreeNode p13 = CreateBTreeNode(13);
	pBTreeNode p14 = CreateBTreeNode(14);
	pBTreeNode p15 = CreateBTreeNode(15);
	ConnectBTreeNode(p1, p2, p3);
	ConnectBTreeNode(p2, p4, p5);
	ConnectBTreeNode(p3, p6, p7);
	ConnectBTreeNode(p4, p8, p9);
	ConnectBTreeNode(p5, p10, p11);
	ConnectBTreeNode(p6, p12, p13);
	ConnectBTreeNode(p7, p14, p15);
	Test("test1 for both left and right subtree", p1);
	DestroyBTree(&p1);
}
