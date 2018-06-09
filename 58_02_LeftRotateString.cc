#include<iostream>
#include<string>
#include<vector>
#include<cstring>
using std::cout;
using std::endl;
using std::string;

void LeftRotateString(string& str, const int k);
void LeftRotateString(string& str, string::iterator start, string::iterator end);
void Test(const string testName, string& str, const int k, const string& expected);
void Test1();
void Test2();
void Test3();
void Test4();
void Test5();
void Test6();
void Test7();
void Test8();
void Test9();

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	Test8();
	Test9();
	return 0;
}

void LeftRotateString(string& str, const int k)
{
	if(str.empty() || k <= 0)
	{
		return;
	}
	string::iterator start = str.begin();
	string::iterator mid = start;
	string::iterator end = str.end();
	int shiftLen = k % str.size();
	while(shiftLen)
	{
		++mid;
		--shiftLen;
	}
	LeftRotateString(str, start, mid);
	LeftRotateString(str, mid, end);
	LeftRotateString(str, start, end);
}

void LeftRotateString(string& str, string::iterator start, string::iterator end)
{
	if(start == end)
	{
		return;
	}
	char temp;
	--end;
	while(start != end)
	{
		temp = *start;
		*start = *end;
		*end = temp;
		++start;
		if(start == end)
		{
			break;
		}
		--end;
	}
}

void Test(const string testName, string& str, const int k, const string& expected)
{
	cout << "*****" << testName << "*****" << endl;
	LeftRotateString(str, k);
	if(0 == str.compare(expected))
	{
		cout << "passed" << endl;
	}else{
		cout << "failed" << ". The result is str" << str << endl;
	}
}
void Test1()
{
	string str;
	string expected;
	Test("test1 for null", str, -2, expected);
}

void Test2()
{
	string str("abcd");
	string expected("abcd");
	Test("test2 for 'abcd-0' ", str, 0, expected);
}

void Test3()
{
	string str("abcd");
	string expected("bcda");
	Test("test3 for 'abcd-1' ", str, 1, expected);
}

void Test4()
{
	string str("abcd");
	string expected("cdab");
	Test("test4 for 'abcd-2' ", str, 2, expected);
}

void Test5()
{
	string str("abcd");
	string expected("dabc");
	Test("test5 for 'abcd-3' ", str, 3, expected);
}

void Test6()
{
	string str("abcd");
	string expected("abcd");
	Test("test6 for 'abcd-4' ", str, 4, expected);
}

void Test7()
{
	string str("abcd");
	string expected("bcda");
	Test("test7 for 'abcd-5' ", str, 5, expected);
}

void Test8()
{
	string str("abcdefg");
	string expected("bcdefga");
	Test("test8 for 'abcd-1' ", str, 1, expected);
}

void Test9()
{
	string str("abcdefg");
	string expected("efgabcd");
	Test("test9 for 'abcd-4' ", str, 4, expected);
}
