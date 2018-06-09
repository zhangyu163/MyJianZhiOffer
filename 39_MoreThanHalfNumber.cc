#include<vector>
#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

bool MoreThanHalfNum(const vector<int>& num, int& result);
void Test(const string testName, const vector<int>& num, 
		const int& HalfNum, const bool& expected);
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

bool MoreThanHalfNum(const vector<int>& num, int& result)
{
	if(num.empty())
	{
		result = 0;
		return false;
	}
	int times = 0;
	int HalfNum = num.front();
	vector<int>::const_iterator it = num.begin();
	while(it != num.end())
	{
		if(HalfNum == *it)
		{
			++times;
		}else{
			--times;
		}
		if(0 == times)
		{
			times = 1;
			HalfNum = *it;
		}
		++it;
	}
	times = 0;
	it = num.begin();
	while(it != num.end())
	{
		if(*it == HalfNum)
		{
			++times;
		}
		++it;
	}
	if(times > (num.size() >> 1))
	{
		result = HalfNum;
		return true;
	}else{
		result = 0;
		return false;
	}
}

void Test(const string testName, const vector<int>& num,
		const int& HalfNum, const bool& expected)
{
	cout << "*******" << testName << "********" << endl;
	int resultHalf = 0;
	bool resbool = MoreThanHalfNum(num, resultHalf);
	if(HalfNum == resultHalf && expected == resbool)
	{
		cout << "passed" << endl;
	}else{
		cout << "failed" << endl;
	}
}

void Test1()
{
	const vector<int> num;
	int HalfNum = 0;
	const bool expected = false;
	Test("test1 for null array", num, HalfNum, expected);
}
void Test2()
{
	vector<int> num;
	num.push_back(1);
	int HalfNum = 1;
	const bool expected = true;
	Test("test2 for 1 node", num, HalfNum, expected);
}
void Test3()
{
	vector<int> num;
	for(auto x: {1, 2, 3, 2, 2, 3, 5, 4, 2})
	{
		num.push_back(x);
	}
	int HalfNum = 0;
	const bool expected = false;
	Test("test2 for 1 node", num, HalfNum, expected);
}
