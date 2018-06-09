#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::min;

int minUgly(const int a, const int b, const int c);
int GetUglyNumber(const int index);
int GetUglyNumber_solution2(const int index);
int IsUgly(const int number);
void Test(const string testName, const int index, const int expected);
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

int minUgly(const int a, const int b, const int c)
{
	int minaandb = a <= b ? a : b;
	int minabc = minaandb <= c ? minaandb : c;
	return minabc;
}

int IsUgly(const int number)
{
	int numbercopy = number;
	while(0 == numbercopy % 2)
	{
		numbercopy /= 2;
	}
	while(0 == numbercopy % 3)
	{
		numbercopy /= 3;
	}
	while(0 == numbercopy % 5)
	{
		numbercopy /= 5;
	}
	if(1 == numbercopy)
	{
		return true;
	}else{
		return false;
	}
}
int GetUglyNumber(const int index)
{
	if(index <= 0)
	{
		return 0;
	}
	int number = 0;
	int countUgly = 0;
	while(countUgly < index)
	{
		++number;
		if(IsUgly(number))
		{
			++countUgly;
		}
	}
	return number;
}

int GetUglyNumber_solution2(const int index)
{
	if(index <= 0)
	{
		return 0;
	}
	int uglybase_2 = 1;
	int uglybase_3 = 1;
	int uglybase_5 = 1;
	int tempUgly = 0;
	int count = 1;
	int index2 = 0;
	int index3 = 0;
	int index5 = 0;
	vector<int> uglyArray;
	uglyArray.push_back(1);
	while(count <= index)
	{
		++count;
		while(uglybase_2 * 2 <= uglyArray.back())
		{
			uglybase_2 = uglyArray[index2];
			++index2;
		}
		while(uglybase_3 * 3 <= uglyArray.back())
		{
			uglybase_3 = uglyArray[index3];
			++index3;
		}
		while(uglybase_5 * 5 <= uglyArray.back())
		{
			uglybase_5 = uglyArray[index5];
			++index5;
		}
		tempUgly = minUgly(uglybase_2 * 2, uglybase_3 * 3, uglybase_5 * 5);
		uglyArray.push_back(tempUgly);
	}
	return uglyArray[index - 1];
}

void Test(const string testName, const int index, const int expected)
{
	cout << "*******" << testName << "********" << endl;
	//int result1 = GetUglyNumber(index);
	int result2 = GetUglyNumber_solution2(index);
	/*if(result1 == expected)
	{
		cout << "solution1 is passed" << endl;
	}else{
		cout << "solution1 is failed" << endl;
	}*/
	if(result2 == expected)
	{
		cout << "solution2 is passed" << endl;
	}else{
		cout << "solution2 is failed" << endl;
	}
	cout << endl;
	cout << endl;
}

void Test1()
{
	Test("test1 for 0", 0, 0);
}

void Test2()
{
	Test("test2 for 1", 1, 1);
	Test("test2 for 2", 2, 2);
	Test("test2 for 3", 3, 3);
	Test("test2 for 4", 4, 4);
	Test("test2 for 5", 5, 5);
	Test("test2 for 9", 9, 10);
	Test("test2 for 10", 10, 12);
}

void Test3()
{
	Test("test3 for 1500", 1500, 859963392);
}
