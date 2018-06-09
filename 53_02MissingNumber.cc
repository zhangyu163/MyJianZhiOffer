#include<string>
#include<iostream>
#include<vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;

int FindMissingNumberCore(const vector<int>& data, vector<int>::const_iterator start, 
		vector<int>::const_iterator end);
int FindMissingNumber(const vector<int>& data);
void Test(const string testName, const vector<int>& data, const int expected);
void Test1();
void Test2();
void Test3();
void Test4();


int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	return 0;
}

int FindMissingNumberCore(const vector<int>& data, vector<int>::const_iterator start, 
		vector<int>::const_iterator end)
{
	if(start == end)
	{
		return -1;
	}
	vector<int>::const_iterator mid;
	mid = ((end - start) >> 1) + start;
	int pos = mid - data.begin();
	if(*mid != pos)
	{
		if(mid == data.begin())
		{
			return pos;
		}else if(*(mid -1) == pos - 1)
		{
			return pos;
		}else{
			end = mid;
		}
	}else{
		start = mid + 1;
	}
	return FindMissingNumberCore(data, start, end);
}

int FindMissingNumber(const vector<int>& data)
{
	if(data.empty())
	{
		return -1;
	}
	int missingNumber = -1;
	vector<int>::const_iterator start = data.begin();
	vector<int>::const_iterator end = data.end();
	missingNumber = FindMissingNumberCore(data, start, end);
	return missingNumber;
}

void Test(const string testName, const vector<int>& data, const int expected)
{
	cout << "********" << testName << "********" << endl;
	int result = FindMissingNumber(data);
	if(expected == result)
	{
		cout << "passed" << endl;
	}else{
		cout << "failed" << endl;
	}
}

void Test1()
{
	vector<int> data;
	Test("test1 for null", data, -1);
}

void Test2()
{
	vector<int> data = {0};
	Test("test2 for 1 node pass", data, -1);
	data.clear();
	data = {1};
	Test("test2 for 1 node pass", data, 0);
}

void Test3()
{
	vector<int> data = {1, 2, 3, 4, 5};
	Test("test3 for 5 node pass", data, 0);
	data.clear();
	vector<int>().swap(data);
	data = {0, 1, 2, 4};
	Test("test3 for 4 node pass", data, 3);
}

void Test4()
{
	vector<int> data = {0, 1, 2, 3, 5};
	Test("test4 for 5 node pass", data, 4);
}
