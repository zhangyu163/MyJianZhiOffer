#include<iostream>

using std::cout;
using std::endl;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode* m_pParent;
};

BinaryTreeNode* ConstructBinaryTreeNode(int value);
void DestroyBinaryTree(BinaryTreeNode* root);
BinaryTreeNode* GetNext(BinaryTreeNode* pNode);

void Test(const char* testName, BinaryTreeNode* pFind, BinaryTreeNode* expected);
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

BinaryTreeNode* ConstructBinaryTreeNode(int value)
{
	BinaryTreeNode* pNew = new BinaryTreeNode();
	pNew->m_nValue = value;
	pNew->m_pParent = pNew->m_pLeft = pNew->m_pRight = nullptr;
}
void ConnectTreeNode(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
	if(pParent)
	{
		if(pLeft)
		{
			pParent->m_pLeft = pLeft;
			pLeft->m_pParent = pParent;
		}
		if(pRight)
		{
			pParent->m_pRight = pRight;
			pRight->m_pParent = pParent;
		}
	}
}

void DestroyBinaryTree(BinaryTreeNode* root)
{
	if(nullptr == root)
	{
		return;
	}else{
		DestroyBinaryTree(root->m_pLeft);
		DestroyBinaryTree(root->m_pRight);
		delete root;
		root = nullptr;
	}
}

BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
	if(nullptr == pNode)
	{
		return nullptr;
	}
	BinaryTreeNode* pNext = nullptr;
	BinaryTreeNode* pCur = pNode;
	BinaryTreeNode* pParent = nullptr;
	if(pCur->m_pRight)
	{
		pCur = pCur->m_pRight;
		while(pCur->m_pLeft)
		{
			pCur = pCur->m_pLeft;
		}
		pNext = pCur;
	}else{
		pParent = pCur->m_pParent;
		while(pParent && pCur == pParent->m_pRight)
		{
			pCur = pCur->m_pParent;
			pParent = pParent->m_pParent;
		}
		pNext = pParent;
	}
	return pNext;
}

void Test(const char* testName, BinaryTreeNode* pFind, BinaryTreeNode* expected)
{
	if(!testName)
	{
		cout << "please input testName!" << endl;
		return;
	}else{
		cout << "************" <<  testName << "***********"<< endl;
	}
	BinaryTreeNode* p = GetNext(pFind);
	if(expected == p)
	{
		cout << "passed" << endl;
	}else{
		cout << "failed" << endl;
	}
}

//the tree is null
void Test1()
{
	BinaryTreeNode* p = nullptr;
	Test("Test1 for nullptr", p, nullptr);
	DestroyBinaryTree(p);
}

//the tree only have left or right subtree 
void Test2()
{
	BinaryTreeNode* p[4] = {nullptr};
	p[0] = ConstructBinaryTreeNode(0);
	p[1] = ConstructBinaryTreeNode(1);
	p[2] = ConstructBinaryTreeNode(2);
	p[3] = ConstructBinaryTreeNode(3);
	ConnectTreeNode(p[0], p[1], nullptr);
	ConnectTreeNode(p[1], p[2], nullptr);
	ConnectTreeNode(p[2], p[3], nullptr);
	Test("test2 for only have left subtree", p[0], nullptr);
	Test("test2 for only have left subtree", p[1], p[0]);
	Test("test2 for only have left subtree", p[3], p[2]);
	DestroyBinaryTree(p[0]);
}

void Test3()
{
	BinaryTreeNode* p[7] = {nullptr};
	p[0] = ConstructBinaryTreeNode(0);
	p[1] = ConstructBinaryTreeNode(1);
	p[2] = ConstructBinaryTreeNode(2);
	p[3] = ConstructBinaryTreeNode(3);
	p[4] = ConstructBinaryTreeNode(4);
	p[5] = ConstructBinaryTreeNode(5);
	p[6] = ConstructBinaryTreeNode(6);
	ConnectTreeNode(p[0], p[1], p[4]);
	ConnectTreeNode(p[1], p[2], p[3]);
	ConnectTreeNode(p[3], nullptr, p[5]);
	ConnectTreeNode(p[4], p[6], nullptr);
	Test("test for both left and right", p[2], p[1]);
	Test("test for both left and right", p[5], p[1]);
	Test("test for both left and right", p[0], p[3]);
	DestroyBinaryTree(p[0]);
}


