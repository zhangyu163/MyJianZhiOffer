#include<iostream>
#include<string>
#include<vector>
#include"binarytree.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;
typedef struct MTreeNode
{
	int m_nValue;
	vector<MTreeNode*> m_vChild;
}MTreeNode, *pMTreeNode;

//针对搜索二叉树

bool IsExistenceInTree(const pBTreeNode pParent, const pBTreeNode pNode);
pBTreeNode FindCommonParent(pBTreeNode pRoot, pBTreeNode pNode1, pBTreeNode pNode2);


//针对普通二叉树
pBTreeNode FindCommonNode(const vector<pBTreeNode>& path1, const vector<pBTreeNode>& path2);
bool  GetNodePath(pBTreeNode pRoot, pBTreeNode pNode, vector<pBTreeNode>& path);
pBTreeNode GetCommonParent(pBTreeNode pRoot, pBTreeNode pNode1, pBTreeNode pNode2);



//针对非二叉树 
pMTreeNode FindCommonNode_MultiTree(const vector<pMTreeNode>& path1, const vector<pMTreeNode>& path2);
bool  GetNodePath_MultiTree(pBTreeNode pRoot, pBTreeNode pNode, vector<pBTreeNode>& path);
pMTreeNode GetCommonParent_MultiTree(pMTreeNode pRoot, pMTreeNode pNode1, pMTreeNode pNode2);

void Test(const string testName, const pBTreeNode pRoot, const pBTreeNode pNode1, 
		const pBTreeNode pNode2, const pBTreeNode pExpected);
void Test1();
void Test2();
void Test3();
//void Test4();

int main()
{
	Test1();
	Test2();
	Test3();
	return 0;
}

//针对搜索二叉树
bool IsExistenceInTree(const pBTreeNode pParent, const pBTreeNode pNode)
{
	if(nullptr == pParent || nullptr == pNode)
	{
		return false;
	}
	bool existence = false;
	pBTreeNode pCur = pParent;
	while(pCur)
	{
		if(pNode->m_nValue < pCur->m_nValue)
		{
			pCur =  pCur->m_pLeft;
		}else{
			if(pCur == pNode)
			{
				existence = true;
				break;
			}else{
				pCur =  pCur->m_pRight;
			}
		}
	}
	return existence;
}

pBTreeNode FindCommonParent(pBTreeNode pRoot, pBTreeNode pNode1, pBTreeNode pNode2)
{
	if(nullptr == pRoot || pNode1 == pNode2 || nullptr == pNode1 || nullptr == pNode2)
	{
		return nullptr;
	}else if(nullptr == pRoot->m_pLeft && nullptr == pRoot->m_pRight)
	{
		return nullptr;
	}
	int valueCur;
	int value1;
	int value2;
	pBTreeNode pCur = pRoot;
	pBTreeNode pParent = nullptr;
	while(pCur)
	{
		valueCur = pCur->m_nValue;
		value1 = pNode1->m_nValue;
		value2 = pNode2->m_nValue;
		if(value1 < valueCur && value2 < valueCur)
		{
			pCur = pCur->m_pLeft;
		}else if(value1 >= valueCur && value2 >= valueCur){
			if(pCur == pNode1 || pCur == pNode2)
			{
				pParent = pCur;
				break;
			}else{
				pCur = pCur->m_pRight;
			}
		}else{
			pParent = pCur;
			break;
		}
	}
	if(nullptr == pParent)
	{
		return nullptr;
	}else{
		bool existence1 = IsExistenceInTree(pParent, pNode1);
		bool existence2 = IsExistenceInTree(pParent, pNode2);
		if(existence1 && existence2)
		{
			return pParent;
		}else{
			return nullptr;
		}

	}
}

//针对普通二叉树

pBTreeNode FindCommonNode(const vector<pBTreeNode>& path1, const vector<pBTreeNode>& path2)
{
	vector<pBTreeNode>::const_iterator it1 = path1.begin();
	vector<pBTreeNode>::const_iterator it2 = path2.begin();
	pBTreeNode pCommon = nullptr;
	while((it1 != path1.end()) && (it2 != path2.end()) && (*it1 == *it2))
	{
		pCommon = *it1;
		++it1;
		++it2;
	}
	return pCommon;
}

bool GetNodePath(pBTreeNode pRoot, pBTreeNode pNode, vector<pBTreeNode>& path)
{
	bool found = false;
	if(nullptr == pRoot || nullptr == pNode)
	{
		return found;
	}
	path.push_back(pRoot);
	if(pRoot == pNode)
	{
		found = true;
		return found;
	}
	found = GetNodePath(pRoot->m_pLeft, pNode, path);
	if(!found)
	{
		found = GetNodePath(pRoot->m_pRight, pNode, path);
	}
	if(!found)
	{
		path.pop_back();
	}
	return found;
}

pBTreeNode GetCommonParent(pBTreeNode pRoot, pBTreeNode pNode1, pBTreeNode pNode2)
{
	if(nullptr == pRoot || nullptr == pNode1 || nullptr == pNode2)
	{
		return nullptr;
	}
	vector<pBTreeNode> path1;
	vector<pBTreeNode> path2;
	GetNodePath(pRoot, pNode1, path1);
	GetNodePath(pRoot, pNode2, path2);
	if(path1.empty() || path2.empty())
	{
		return nullptr;
	}else{
		return FindCommonNode(path1, path2);
	}
}
//针对非二叉树

pMTreeNode FindCommonNode_MultiTree(const vector<pMTreeNode>& path1, const vector<pMTreeNode>& path2)
{
	vector<pMTreeNode>::const_iterator it1 = path1.begin();
	vector<pMTreeNode>::const_iterator it2 = path2.begin();
	pMTreeNode pCommon = nullptr;
	while((it1 != path1.end()) && (it2 != path2.end()) && (*it1 == *it2))
	{
		pCommon = *it1;
		++it1;
		++it2;
	}
	return pCommon;
}

bool  GetNodePath_MultiTree(pMTreeNode pRoot, pMTreeNode pNode, vector<pMTreeNode>& path)
{
	bool found = false;
	if(nullptr == pRoot || nullptr == pNode)
	{
		return found;
	}
	path.push_back(pRoot);
	if(pRoot == pNode)
	{
		found = true;
		return found;
	}
	vector<pMTreeNode>::const_iterator it = pRoot->m_vChild.begin();
	while(!found && it != pRoot->m_vChild.end())
	{
		found = GetNodePath_MultiTree(*it, pNode, path);
		++it;
	}
	if(!found)
	{
		path.pop_back();
	}
	return found;
}

pMTreeNode GetCommonParent_MultiTree(pMTreeNode pRoot, pMTreeNode pNode1, pMTreeNode pNode2)
{
	if(nullptr == pRoot || nullptr == pNode1 || nullptr == pNode2)
	{
		return nullptr;
	}
	vector<pMTreeNode> path1;
	vector<pMTreeNode> path2;
	GetNodePath_MultiTree(pRoot, pNode1, path1);
	GetNodePath_MultiTree(pRoot, pNode2, path2);
	if(path1.empty() || path2.empty())
	{
		return nullptr;
	}else{
		return FindCommonNode_MultiTree(path1, path2);
	}
}



//测试部分
void Test(const string testName, const pBTreeNode pRoot, const pBTreeNode pNode1, 
		const pBTreeNode pNode2, const pBTreeNode pExpected)
{
	cout << "******  " << testName << "  ******" << endl;
	pBTreeNode pResult = GetCommonParent(pRoot, pNode1, pNode2);
	if(pExpected == pResult)
	{
		cout << "   passed!" << endl;
	}else{
		cout << "   failed!" <<endl;
	}
}


void Test1()
{
	Test("test1 for null", nullptr, nullptr, nullptr, nullptr);
	cout << endl;
	pBTreeNode p1 = CreateBTreeNode(1);
	Test("test1 for 1 node", p1, p1, nullptr, nullptr);
	cout << endl;
	DestroyBTree(&p1);
}
void Test2()
{
	pBTreeNode p1 = CreateBTreeNode(1);
	pBTreeNode p2 = CreateBTreeNode(2);
	pBTreeNode p3 = CreateBTreeNode(3);
	pBTreeNode p4 = CreateBTreeNode(4);
	pBTreeNode p5 = CreateBTreeNode(5);
	pBTreeNode p6 = CreateBTreeNode(6);
	pBTreeNode p7 = CreateBTreeNode(7);
	ConnectBTreeNode(p1, nullptr, p2);
	ConnectBTreeNode(p2, nullptr, p3);
	ConnectBTreeNode(p3, nullptr, p4);
	ConnectBTreeNode(p4, nullptr, p5);
	Test("test2", p1, p3, nullptr, nullptr);
	cout << endl;
	Test("test2", p1, p4, p5, p4);
	cout << endl;
	Test("test2", p1, p3, p5, p3);
	cout << endl;
	Test("test2", p1, p7, p4, nullptr);
	cout << endl;
	DestroyBTree(&p1);
}

void Test3()
{
	pBTreeNode p1 = CreateBTreeNode(10);
	pBTreeNode p2 = CreateBTreeNode(6);
	pBTreeNode p3 = CreateBTreeNode(14);
	pBTreeNode p4 = CreateBTreeNode(4);
	pBTreeNode p5 = CreateBTreeNode(8);
	pBTreeNode p6 = CreateBTreeNode(12);
	pBTreeNode p7 = CreateBTreeNode(16);
	pBTreeNode p8 = CreateBTreeNode(9);
	ConnectBTreeNode(p1, p2, p3);
	ConnectBTreeNode(p2, p4, p5);
	ConnectBTreeNode(p3, p6, p7);
	ConnectBTreeNode(p5, nullptr, p8);
	Test("test3 for 1 node", p1, p6, p8, p1);
	cout << endl;
	DestroyBTree(&p1);

}
