
#include<iostream>
#include<string>
#include<cstdlib>
#include"binarytree.h"

using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::istream;
using std::string;
using std::atoi;

bool ReadStream(istream& stream, int* number);
void Serialize(const pBTreeNode pRoot, ostream& stream);
void Deserialize(pBTreeNode* pRoot, istream& stream);
void TestSerialize(const string testName, pBTreeNode pRoot);
void TestDeserialize(const string testName, pBTreeNode* pRoot);

int main()
{

	return 0;
}

bool ReadStream(istream& stream, int* number)
{
	if(stream.eof())
	{
		return false;
	}
	char buffer[32] = {0};
	char ch;
	stream >> ch;
	int i = 0;
	while(!stream.eof() && ch != ',')
	{
		buffer[i++] = ch;
		stream >> ch;
	}
	bool isNumeric = false;
	if(i > 0 && buffer[0] != '$')
	{
		*number = atoi(buffer);
		isNumeric = true;
	}
	return isNumeric;
}
void Serialize(const pBTreeNode pRoot, ostream& stream)
{
	if(nullptr == pRoot)
	{
		stream << "$,";
		return;
	}
	stream << "\t" << pRoot->m_nValue;
	Serialize(pRoot->m_pLeft, stream);
	Serialize(pRoot->m_pRight, stream);
}

void Deserialize(pBTreeNode* pRoot, istream& stream)
{
	if(nullptr == pRoot)
	{
		return;
	}
	int number;
	if(ReadStream(stream, &number))
	{
		*pRoot = new BTreeNode;
		(*pRoot)->m_nValue = number;
		(*pRoot)->m_pLeft = nullptr;
		(*pRoot)->m_pRight = nullptr;
		Deserialize(&((*pRoot)->m_pLeft), stream);
		Deserialize(&((*pRoot)->m_pRight), stream);
	}
}

void TestSerialize(const string testName, pBTreeNode pRoot)
{
	cout << "********" << testName << "********" << endl;
	Serialize(pRoot, cout);
}

void TestDeserialize(const string testName, pBTreeNode* pRoot)
{
	cout << "********" << testName << "********" << endl;
	Deserialize(pRoot, cin);
}
