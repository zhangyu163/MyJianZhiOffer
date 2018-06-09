#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;


int AddTwoNumbers(int num1, int num2);
void Test(const string testName, int num1, int num2, const int expected);
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

int AddTwoNumbers(int num1, int num2)
{
	int carry = 0;
	int sum = 0;
	do{
		sum = num1 ^ num2;
		carry = (num1 & num2) << 1;
		num1 = sum;
		num2 = carry;
	}while(num2 != 0);
	return sum;
}

void Test(const string testName, int num1, int num2, const int expected)
{
	cout << "*****  " << testName << "   *******" << endl;
	int result = AddTwoNumbers(num1, num2);
	if(expected == result)
	{
		cout << "passed!" << endl;
	}else{
		cout << "failed!" << endl;
	}
}

void Test1()
{
	Test("test1 for two negative", -2, -3, -5);
	Test("test1 for 1 negative", -2, 0, -2);
	Test("test1 for two zero", 0, 0, 0);
}

void Test2()
{
	Test("test2 for two positive", 2, 4, 6);
	Test("test2 for 1 positive", 0, 3, 3);
	Test("test2 for two zero", 1, 5, 6);
}

void Test3()
{
	Test("test3 for two positive", -1, 2, 1);
	Test("test3 for 1 positive", -40, 45, 5);
	Test("test3 for two zero", 1000000, 5, 1000005);
}
