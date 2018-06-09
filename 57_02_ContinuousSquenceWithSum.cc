#include<iostream>
#include<string>
#include<vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;

void FindContinuousSequence(const int sum);
void PrinContinuousSequence(const int start, const int end);
void Test(const string testName, const int sum);
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

void FindContinuousSequence(const int sum)
{
	if(sum < 3)
	{
		return;
	}
	int start = 1;
	int end = 2;
	int curSum = start + end;
	int mid = (sum + 1) >> 1;
	while(start < mid)
	{
		if(sum == curSum)
		{
			PrinContinuousSequence(start, end);
		}else if(sum < curSum){
			curSum -= start;
			++start;
			continue;
		}
		++end;
		curSum += end;
	}
}

void PrinContinuousSequence(const int start, const int end)
{
	int i = start;
	while(i <= end)
	{
		cout << "  " << i;
		if(0 == i % 22)
		{
			cout << endl;
		}
		++i;
	}
	cout << endl;
}

void Test(const string testName, const int sum)
{
	cout << "*******" << testName << "********" << endl;
	FindContinuousSequence(sum);
}

void Test1()
{
	Test("test1 for 1", 1);
	cout << endl;
	Test("test1 for 2", 2);
	cout << endl << endl;
}
void Test2()
{
	Test("test2 for 3", 3);
	cout << endl;
	Test("test2 for 4", 4);
	cout << endl << endl;
}

void Test3()
{
	Test("test3 for 9", 9);
	cout << endl;
	Test("test3 for 11", 11);
	cout << endl << endl;
}

void Test4()
{
	Test("test2 for 15", 15);
	cout << endl;
	Test("test2 for 72", 72);
	cout << endl << endl;
}
