/*************************************************************************
    > File Name: binarytree.h
    > Author: zhangyu
    > Mail: hebzhangyu@163.com 
    > Created Time: Tue 29 May 2018 07:28:21 AM PDT
 ************************************************************************/

#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_ 

#include<iostream>
#include<queue>

using std::cout;
using std::endl;
using std::queue;

typedef struct BinaryTreeNode
{
	int               m_nValue;
	BinaryTreeNode*   m_pLeft;
	BinaryTreeNode*   m_pRight;
}BTreeNode, *pBTreeNode;

pBTreeNode CreateBTreeNode(const double n);
void ConnectBTreeNode(pBTreeNode pParent, pBTreeNode pLeft, pBTreeNode pRight);
void DestroyBTree(pBTreeNode* ppRoot);
void PrintTBree(const pBTreeNode& pRoot, int floor);

pBTreeNode CreateBTreeNode(const double n)
{
	pBTreeNode pNew = new BTreeNode;
	pNew->m_nValue = n;
	pNew->m_pLeft = nullptr;
	pNew->m_pRight = nullptr;
	return pNew;
}
void ConnectBTreeNode(pBTreeNode pParent, pBTreeNode pLeft, pBTreeNode pRight)
{
	if(nullptr == pParent)
	{
		return;
	}
	pParent->m_pLeft = pLeft;
	pParent->m_pRight = pRight;
}

void DestroyBTree(pBTreeNode* ppRoot)
{
	if(nullptr == ppRoot || nullptr == *ppRoot)
	{
		return;
	}
	DestroyBTree(&((*ppRoot)->m_pLeft));
	DestroyBTree(&((*ppRoot)->m_pRight));
	delete *ppRoot;
	*ppRoot = nullptr;
}

void PrintBTree(const pBTreeNode& pRoot, int floor)
{
	if(nullptr == pRoot)
	{
		return;
	}
	cout << "the floor " << floor << "th: ";
	cout << pRoot->m_nValue << endl;
	PrintBTree(pRoot->m_pLeft, floor + 1);
	PrintBTree(pRoot->m_pRight, floor + 1);
}

#endif

