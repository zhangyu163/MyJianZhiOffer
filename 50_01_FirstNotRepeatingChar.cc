#include<iostream>
#include<vector>
#include<string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

char FirstNotRepeatingChar(const string& str);
void Test(const string testName, const string str, const char expected, const bool InputValid);
void Test1();
void Test2();
void Test3();
void Test4();
void Test5();

bool g_InputInvalid = false;

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	return 0;
}

char FirstNotRepeatingChar(const string& str)
{
	if(str.empty())
	{
		g_InputInvalid = true;
		return 0;
	}
	vector<int> timesOfChar(128, 0);
	for(auto x: str)
	{
		++timesOfChar[int(x)];
	}
	for(auto x: str)
	{
		if(1 == timesOfChar[int(x)])
		{
			g_InputInvalid = false;
			return x;
		}
	}
	g_InputInvalid = false;
	return 0;
}

void Test(const string testName, const string str, const char expected, const bool InputValid)
{
	cout << "*******" << testName << "*******" << endl;
	char res = FirstNotRepeatingChar(str);
	if(g_InputInvalid == InputValid && expected == res)
	{
		cout << "passed" << endl;
	}else{
		cout << "failed" << endl;
	}
}

void Test1()
{
	string str;
	Test("test1 for null", str, 0, true);
}

void Test2()
{
	string str("a");
	Test("test2 for null", str, 'a', false);
}

void Test3()
{
	string str("aaaaaaaaaaa");
	Test("test3 for null", str, char(0), false);
}

void Test4()
{
	string str("bbbba");
	Test("test4 for null", str, 'a', false);
}

void Test5()
{
	string str("dbcfe");
	Test("test5 for null", str, 'd', false);
}
