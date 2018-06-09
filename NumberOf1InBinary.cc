#include<iostream>

using namespace std;

int NumberOf1InBinary_1(const int& n);	
int NumberOf1InBinary_2(const int& n);	
void Test(const char* testName, const int& n, const int& expected);
void Test1();
void Test2();
int main()
{
	Test1();
	Test2();
	return 0;
}
int NumberOf1InBinary_1(const int& n)
{
	int count = 0;
	int flag = 1;
	while(flag)
	{
		if(n & flag)
		{
			++count;
		}
		flag = flag << 1;
	}
	return count;
}

int NumberOf1InBinary_2(const int& n)
{
	int count = 0;
	int num = n;
	while(num)
	{
		num = (num - 1) & num;
		++count;
	}
	return count;
}
void Test(const char* testName, const int& n, const int& expected)
{
	cout << "********" << testName << "*********" << endl;
	cout << "NumberOf1InBinary_1: " << endl; 
	if(NumberOf1InBinary_1(n) == expected)
	{
		cout << "passed" << endl;
	}else{
		cout << "failed" << endl;
	}
	cout << "NumberOf1InBinary_2: " << endl; 
	if(NumberOf1InBinary_2(n) == expected)
	{
		cout << "passed" << endl;
	}else{
		cout << "failed" << endl;
	}
}
void Test1()
{
	Test("test1 for negative and zero number: ", 0xFFFFFFFF, 32);
	Test("test1 for negative and zero number: ", 0x80000000, 1);
}
void Test2()
{
	Test("test2 for positive number: ", 1, 1);
	Test("test2 for positive number: ", 563, 5);
}
