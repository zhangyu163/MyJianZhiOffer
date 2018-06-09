#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

bool Increment(vector<char>& number);
void Print1ToMaxOfnDigitsRecursively(vector<char>& number, const int& length, int index);
void PrintNumber(const vector<char>& number);
void Print1ToMaxOfnDigits(const int& n);
void Test(const char* testName, const int& n, const char* expected);
void Test1();
void Test2();

int main()
{
	Test1();
	Test2();
	return 0;
}

bool Increment(vector<char>& number)
{
	bool isOverFlow = false;
	int nTakeOver = 0;
	int i = number.size() - 1;
	int numberSize = number.size();
	int nSum = 0;
	while(i >= 0)
	{
		nSum = number[i] - '0' + nTakeOver;
		if(numberSize - 1 == i)
		{
			++nSum;
		}
		if(nSum > 9)
		{
			if(0 == i)
			{
				isOverFlow = true;
				break;
			}
			nTakeOver = 1;
		}else{
			nTakeOver = 0;
		}
		number[i] = nSum % 10 + '0';
		--i;
	}
	return isOverFlow;
}
void PrintNumber(const vector<char>& number)
{
	bool isBegin0 = true;
	int i = 0;
	while(i < number.size())
	{
		if(number[i] != '0'&& isBegin0)
		{
			isBegin0 = false;
		}
		if(!isBegin0)
		{
			cout << number[i];
		}
		++i;
	}
	cout << "\t";
}
void Print1ToMaxOfnDigits(const int& n)
{
	if(n < 1)
	{
		return;
	}
	vector<char> number;
	int i;
	for(i = 0; i < n; ++i)
	{
		number.push_back('0');
	}
	for(i = 0; i < 10; ++i)
	{
		number[0] = i + '0';
		Print1ToMaxOfnDigitsRecursively(number, n, 0);
	}
}
void Print1ToMaxOfnDigitsRecursively(vector<char>& number, const int& length, int index)
{
	if(length == index + 1)
	{
		PrintNumber(number);
		return;
	}
	int i;
	for(i = 0; i < 10; ++i)
	{
		number[index + 1] = i + '0';
		Print1ToMaxOfnDigitsRecursively(number, length, index + 1);
	}
}
/*{
	if(n < 1)
	{
		return;
	}
	vector<char> number;
	int i = 0;
	while(i ^ n)
	{
		++i;
		number.push_back('0');
	}
	while(!Increment(number))
	{
		PrintNumber(number);
	}
}*/

void Test(const char* testName, const int& n)
{
	cout << "-----" << testName << "---------" << endl;
	Print1ToMaxOfnDigits(n);
	cout << endl;
}

void Test1()
{
	Test("test1 for -3:", -3);
	Test("test1 for -100", -100);
	Test("test1 for 0", 0);
}
void Test2()
{
	Test("test2 for 1", 1);
	Test("test1 for 2", 2);
	Test("test1 for 3", 3);
	//Test("test1 for ", 5);
}
