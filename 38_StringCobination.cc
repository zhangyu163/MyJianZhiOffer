#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;

void Combination(const string& str, string::const_iterator it, 
		const int i, string& result);
void Combination(const string& str);
void Test(const string testName, const string str);
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

void Combination(const string& str, string::const_iterator it, 
		const int m, string& result)
{
	if(0 == m)
	{
		cout << result << endl;
		return;
	}
	if(str.end() == it)
	{
		return;
	}
	result.push_back(*it);
	Combination(str, it + 1, m - 1, result);
	result.pop_back();
	Combination(str, it + 1, m, result);
}

void Combination(const string& str)
{
	if(str.empty())
	{
		return;
	}else if(1 == str.size())
	{
		cout << str << endl;
		return;
	}
	int i;
	string result;
	string::const_iterator it = str.begin();
	for(i = 1; i <= str.size(); ++i)
	{
		Combination(str, it, i, result);
	}
}

void Test(const string testName, const string str)
{
	cout << "*******" << testName << endl;
	Combination(str);
}

void Test1()
{
	const string str;
	Test("test1 for null", str);
}

void Test2()
{
	string str;
	str.push_back('a');
	Test("test1 for 1 node", str);
}

void Test3()
{
	string str("abcd");
	Test("test3 for \"abc\"", str);
}
