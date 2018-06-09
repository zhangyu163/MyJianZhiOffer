#include<iostream>
#include<vector>
#include<deque>
#include<string>

using std::cout;
using std::endl;
using std::string;
using std::deque;
using std::vector;

vector<int> MaxInWindow(const vector<int>& num, unsigned int size);
void Test(const string testName, const vector<int>& num, unsigned int size, const vector<int>& expected);
void Test1();
void Test2();
void Test3();
void Test4();
void Test5();
void Test6();

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	
	return 0;
}

vector<int> MaxInWindow(const vector<int>& num, unsigned int size)
{
	vector<int> maxInWindow;
	if(num.size() >= size && size >= 1)
	{
		deque<int> index;
		unsigned int i;
		for(i = 0; i < size; ++i)
		{
			if(!index.empty() && num[i] >= num[index.front()])
			{
				index.pop_back();
			}
			index.push_back(i);
		}
		for(i = size; i < num.size(); ++i)
		{
			maxInWindow.push_back(num[index.front()]);
			while(!index.empty() && num[i] >= num[index.back()])
			{
				index.pop_back();
			}
			if(!index.empty() && i - index.front() >= size)
			{
				index.pop_front();
			}
			index.push_back(i);
		}
		maxInWindow.push_back(num[index.front()]);
	}
	return maxInWindow;
}

void Test(const string testName, const vector<int>& num, unsigned int size, const vector<int>& expected)
{
	cout << "********" << testName << "***********" << endl;
	vector<int> maxInWindow = MaxInWindow(num, size);
	int i, j;
	for(i = 0, j = 0; i < maxInWindow.size(), j < expected.size(); ++i, ++j)
	{
		if(maxInWindow[i] != expected[j])
		{
			break;
		}
	}
	if(i == maxInWindow.size() && j == expected.size())
	{
		cout << "passed!" << endl;
	}else{
		cout << "failed" << endl;
	}
	cout << endl << endl;
}

void Test1()
{
	vector<int> num;
	vector<int> expected;
	Test("test1 for null", num, 2, expected);
}

void Test2()
{
	vector<int> num = {1};
	vector<int> expected;
	Test("test2 for 1", num, 0, expected);
	expected.push_back(1);
	Test("test2 for 1", num, 1, expected);
}

void Test3()
{
	vector<int> num = {1, 2};
	vector<int> expected = {1, 2};
	Test("test3 for 1", num, 1, expected);
	vector<int>().swap(num);
	vector<int>().swap(expected);
	num.assign({2, 3, 4, 2, 6, 2, 5, 1});
	expected.assign({4, 4, 6, 6, 6, 5});
	Test("test3 for 1", num, 3, expected);
}

void Test4()
{
	vector<int> num;
	vector<int> expected;
	num.assign({1, 3, -1, -3, 5, 3, 6, 7});
	expected.assign({3, 3, 5, 5, 6, 7});
	Test("test4 for 1", num, 3, expected);
	
	vector<int>().swap(num);
	vector<int>().swap(expected);
	num.assign({1, 3, 7, 9, 11, 13, 15});
	expected.assign({7, 9, 11, 13, 15});
	Test("test4 for 1", num, 4, expected);
}

void Test5()
{
	vector<int> num;
	vector<int> expected;
	num.assign({16, 14, 12, 10, 8, 6, 4});
	expected.assign({16, 14, 12});
	Test("test5 for 1", num, 5, expected);
	
	vector<int>().swap(num);
	vector<int>().swap(expected);
	num.assign({1, 3, 7, 9});
	expected.assign({9});
	Test("test5 for 1", num, 4, expected);
}

void Test6()
{
	vector<int> num;
	vector<int> expected;
	num.assign({16, 14, 12, 10, 8});
	Test("test6 for 1", num, 6, expected);
	
}
