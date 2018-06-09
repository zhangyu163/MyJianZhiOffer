#include<iostream>
#include<vector>
#include<queue>
#include<stack>

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};
using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::stack;

BinaryTreeNode* Construct(int* preorder, int* inorder, int length);
BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder,
		int* startInorder, int* endInorder);
void print(BinaryTreeNode* root);
void Test1();
void Test2();

int main()
{
	Test1();
	return 0;
}

BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
	if(nullptr == preorder || nullptr == inorder || length < 1)
	{
		return nullptr;
	}
	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder,
		int* startInorder, int* endInorder)
{
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = *startPreorder;
	root->m_pLeft = root->m_pRight = nullptr;
	if(startPreorder == endPreorder)
	{
		if(startInorder == endInorder && *startPreorder == *startInorder)
		{
			return root;
		}else{
			throw std::exception();
		}
	}
	int* rootInorder = startInorder;
	while(rootInorder <= endInorder && root->m_nValue != *rootInorder)
	{
		++rootInorder;
	}
	if(rootInorder == endInorder && *rootInorder != root->m_nValue)
	{
		throw std::exception();
	}
	int leftLength = rootInorder - startInorder;
	int*  leftPreorderEnd = startPreorder + leftLength;
	if(leftLength > 0)
	{
		root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd,
				startInorder, rootInorder - 1);
	}
	if(leftLength < endPreorder - startPreorder)
	{
		root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder,
				rootInorder + 1, endInorder);
	}
	return root;
}

void print(BinaryTreeNode* root)
{
	if(nullptr == root)
	{
		cout << "null tree" << endl;
	}
	stack<BinaryTreeNode*> queueNode;
	queueNode.push(root);
	BinaryTreeNode* pcur = nullptr;
	int i = 0;
	/*while(!queueNode.empty())
	{
		pcur = queueNode.top();
		if(pcur->m_pLeft)
		{
			queueNode.push(pcur->m_pLeft);
		}
		if(pcur->m_pRight)
		{
			queueNode.push(pcur->m_pRight);
		}
		queueNode.pop();
		cout << ++i << "ceng is: " << pcur->m_nValue << endl;
	}*/ 
	while(!queueNode.empty())
	{
		BinaryTreeNode* pcur = queueNode.top();
		if()
	}
}

void Test1()
{
	int pre[8] = {1, 2, 4, 7, 3, 5, 6, 8};
	int in[8] = {4, 7, 2, 1, 5, 3, 8, 6};
	BinaryTreeNode* root = Construct(pre, in, sizeof(pre) / sizeof(int));
	print(root);
}
