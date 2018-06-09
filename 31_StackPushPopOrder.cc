#include<iostream>
#include<stack>
#include<vector>
#include<string>

using std::cout;
using std::endl;
using std::vector;
using std::stack;
using std::string;

bool IsPopOrder(const vector<int>& vecPush, const vector<int>& vecPop);
void Test(const string testName, const vector<int>& vecPush,
		const vector<int>& vecPop, const bool expected);
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

bool IsPopOrder(const vector<int>& vecPush, const vector<int>& vecPop)
{
	if(vecPush.empty() || vecPop.empty())
	{
		return false;
	}
	if(vecPush.size() != vecPop.size())
	{
		return false;
	}

	vector<int>::const_iterator itOfPush = vecPush.begin();
	vector<int>::const_iterator itOfPop = vecPop.begin();
	bool possible = false;
	stack<int>* pstack = new stack<int>;
	while(itOfPop != vecPop.end())
	{
		while(pstack->empty() || *itOfPop != pstack->top())
		{
			if(itOfPush != vecPush.end())
			{
				pstack->push(*itOfPush);
				++itOfPush;
			}else{
				break;
			}
		}
		if(pstack->top() != *itOfPop)
		{
			break;
		}
		++itOfPop;
		pstack->pop();
	}
	if(vecPop.end() == itOfPop)
	{
		possible = true;
	}
	if(pstack)
	{
		delete pstack;
	}
	return possible;
}

void Test(const string testName, const vector<int>& vecPush,
		const vector<int>& vecPop, const bool expected)
{
	cout << "********" << testName << "********" << endl;
	cout << "the push vector is: ";
	if(!vecPush.empty())
	{
		for(auto x: vecPush)
		{
			cout << x << "  ";
		}
		cout << endl;
	}
	
	cout << "the pop vector is: ";
	if(!vecPop.empty())
	{
		for(auto x: vecPop)
		{
			cout << x << "  ";
		}
		cout << endl;
	}
	bool result = IsPopOrder(vecPush, vecPop);
	if(expected == result)
	{
		cout << "passed" << endl;
	}else{
		cout << "failed" << endl;
	}
}

void Test1()
{
	vector<int> vecPop;
	vector<int> vecPush;
	Test("test1 for null and null", vecPop, vecPush, false);
	vecPush.push_back(1);
	Test("test1 for 1 and null", vecPop, vecPush, false);
	
	vecPush.clear();
	vecPop.push_back(1);
	Test("test1 for null and 1", vecPop, vecPush, false);

	vecPop.clear();
	vecPush.push_back(1);
	vecPop.push_back(1);
	Test("test1 for 1 and 1", vecPop, vecPush, true);

}

void Test2()
{
	vector<int> vecPop;
	vector<int> vecPush;
	for(auto x: {1, 2, 3, 4, 5})
	{
		vecPush.push_back(x);	
	}
	for(auto x: {4, 5, 3, 2, 1})
	{
		vecPop.push_back(x);
	}
	Test("test2 for 5e and 5e", vecPush, vecPop, true);


}
void Test3()
{
	vector<int> vecPush;
	vector<int> vecPop;
	for(auto x: {1, 2, 3, 4, 5})
	{
		vecPush.push_back(x);	
	}
	for(auto x: {4, 3, 5, 1, 2})
	{
		vecPop.push_back(x);
	}
	Test("test3 for 5e and 5e", vecPush, vecPop, false);

}
