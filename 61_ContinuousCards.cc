#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::sort;

bool compare(int a, int b);
bool IsContinuous(vector<int>& number);

void Test(const string testName, vector<int>& number, const bool expected);
void Test1();
void Test2();
void Test3();
void Test4();
void Test5();
void Test6();
void Test7();

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	return 0;
}

bool compare(int a, int b)
{
	return a <= b;
}

bool IsContinuous(vector<int>& number)
{
	if(number.size() != 5)
	{
		return false;
	}
	sort(number.begin(), number.end(), compare);
	/*for(auto x: number)
	{
		cout << x << "  ";
	}
	cout << endl;*/ 
	int numberOfZero = 0;
	int numberOfGap = 0;
	for(auto x: number)
	{
		if(x)
		{
			break;
		}
		++numberOfZero;
	}
	int small = numberOfZero;
	int big = small + 1;
	while(big < number.size())
	{
		if(number[big] == number[small])
		{
			return false;
		}
		numberOfGap += number[big] - number[small] - 1;
		small = big;
		++big;
	}
	return numberOfZero >= numberOfGap ? true: false;
}

void Test(const string testName, vector<int>& number, const bool expected)
{
	cout << "*******" << testName << "*******" << endl;
	int res = IsContinuous(number);
	if(expected == res)
	{
		cout << "passed!" << endl;
	}else{
		cout << "failed!" << endl;
	}
}

void Test1()
{
	vector<int> number;
	Test("test1 for null", number, false);
	number.push_back(1);
	Test("test1 for 1 node", number, false);
}

void Test2()
{
	vector<int> number = {1, 0, 0, 0, 0};
	Test("Test2 for 1 node", number, true);
}

void Test3()
{
	vector<int> number = {0, 0, 1, 0, 1};
	Test("test3 for 1 node", number, false);
}

void Test4()
{
	vector<int> number = {0, 3, 0, 4, 3};
	Test("test4 for 1 node", number, false);
}

void Test5()
{
	vector<int> number = {4, 3, 1, 0, 0};
	Test("test5 for 1 node", number, true);
}

void Test6()
{
	vector<int> number = {8, 6, 7, 9, 0};
	Test("test6 for 1 node", number, true);
}

void Test7()
{
	vector<int> number = {8, 6, 7, 5, 9};
	Test("test7 for 1 node", number, true);
}
