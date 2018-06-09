#include<iostream>
#include<string>
#include<algorithm>

using std::cout;
using std::endl;
using std::string;
using std::pow;

int CountNumbersOfDigit(const int digit);
int DigitAtIndex(int index, int digit);
int DigitAtIndex(int index);
void Test(const string testName, int index, const int expected);
void Test1();
void Test2();

int main()
{
	Test1();
	Test2();
	return 0;
}

int CountNumbersOfDigit(const int digit)
{
	if(1 == digit)
	{
		return 10;
	}
	return 9 * pow(10, digit - 1);
}

int DigitAtIndex(int index, int digit)
{
	int beginNumber;
	if(1 == digit)
	{
		beginNumber = 0;
	}else{
		beginNumber = pow(10, digit - 1);
	}
	int shang = index / digit;
	int number = beginNumber + shang;
	int indexFromRight = digit - index % digit;
	for(int i = 1; i < indexFromRight; ++i)
	{
		number = number / 10;
	}
	return number % 10;
}

int DigitAtIndex(int index)
{
	if(index < 0)
	{
		return -1;
	}
	int digit = 1;
	int numbersOfDigit;
	while(true)
	{
		numbersOfDigit = CountNumbersOfDigit(digit);
		if(index < numbersOfDigit)
		{
			return DigitAtIndex(index, digit);
		}
		index -= digit * numbersOfDigit;
		++digit;
	}
	return -1;
}
void Test(const string testName, int index, const int expected)
{
	cout << "*******" << testName << endl;
	int result = DigitAtIndex(index);
	if(expected == result)
	{
		cout << "the reuslt is: " << result << endl;
		cout << "passed" << endl;
	}else{
		cout << "the reuslt is: " << result << endl;
		cout << "failed" << endl;
	}

}

void Test1()
{
	Test("test1 for null", 0, 0);
}

void Test2()
{
	Test("test1 for 1th", 1, 1);
	Test("test1 for 2th", 2, 2);
	Test("test1 for 10th", 10, 1);
	Test("test1 for 90th", 90, 5);
	Test("test1 for 1000th", 1000, 3);
	Test("test1 for 1001th", 1001, 7);
	Test("test1 for 1002th", 1002, 0);

}
