#include<iostream>
#include<string>
#include<cstring>

using std::string;
using std::cout;
using std::endl;
using std::to_string;
using std::memset;

int GetTranslationCount(const int number);
int GetTranslationCount(const string& numberInString);
void Test(const string testName, const int number, const int expectedCount);
void Test1();
void Test2();

int main()
{
	Test1();
	Test2();
	return 0;
}

int GetTranslationCount(const int number)
{
	if(number < 0)
	{
		return 0;
	}
	string numberInString = to_string(number);
	return GetTranslationCount(numberInString);
}

int GetTranslationCount(const string& numberInString)
{
	int lengthOfNumStr = numberInString.length();
	int i;
	int count = 0;
	int* counts = new int[lengthOfNumStr];
	memset(counts, 0, lengthOfNumStr);
	for(i = lengthOfNumStr - 1; i >= 0; --i)
	{
		count = 0;
		if(i < lengthOfNumStr - 1)
		{
			int temp = (numberInString[i] - '0') * 10 + (numberInString[i + 1] - '0');
			if(temp >= 10 && temp <= 25)
			{
				count = 1;
			}
		}else{
			counts[i] = 1;
			continue;
		}
		if(i < lengthOfNumStr - 2)
		{
			counts[i] = counts[i + 1] + count * counts[i + 2];
		}else{
			counts[i] = counts[i + 1] + count;
		}
	}
	count = counts[0];
	delete[] counts;
	return count;
}

void Test(const string testName, const int number, const int expectedCount)
{
	cout << "*******" << testName << "******" << endl;
	int count = GetTranslationCount(number);
	if(expectedCount == count)
	{
		cout << "passed!" << endl;
	}else{
		cout << "failed!" << endl;
	}
}
void Test1()
{
	int number;
	number = 10;
	Test("test1 for negative number: ", number, 2);
	number = 125;
	Test("test1 for negative number: ", number, 3);
}
void Test2()
{
	int number;
	number = 126;
	Test("test1 for negative number: ", number, 2);
	number = 100;
	Test("test1 for negative number: ", number, 2);
	number = 101;
	Test("test1 for negative number: ", number, 2);

}
