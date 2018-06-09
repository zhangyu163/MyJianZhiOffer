#include<iostream>
#include<string>
#include<iterator>
#include<typeinfo>
using std::cout;
using std::endl;
using std::string;

bool Match(const string& str, const string& pattern);
bool MatchCore(const string& str, string::const_iterator itOfStr, const string& pattern, 
		string::const_iterator itOfPattern);

void Test(const char* testName, const string& str, const string& pattern, bool expected);
void Test1();
int main()
{
	Test1();
	return 0;
}

bool Match(const string& str, const string& pattern)
{
	if(0 == str.size() || 0 == pattern.size())
	{
		return false;
	}
	string::const_iterator itOfStr = str.begin();
	string::const_iterator itOfPattern = pattern.begin();
	return MatchCore(str, itOfStr, pattern, itOfPattern);
}

bool MatchCore(const string& str, string::const_iterator itOfStr, const string& pattern, 
		string::const_iterator itOfPattern)
{
	if(str.end() == itOfStr && pattern.end() == itOfPattern)
	{
		return true;
	}
	if(itOfStr != str.end() && pattern.end() == itOfPattern)
	{
		return false;
	}
	if(itOfStr == str.end() && itOfPattern != pattern.end())
	{
		return false;
	}
	if(*(itOfPattern + 1) == '*')
	{
		if(*itOfPattern == *itOfStr || '.' == *itOfPattern)
		{
			return MatchCore(str, itOfStr, pattern, itOfPattern + 2) ||
				MatchCore(str, itOfStr + 1, pattern, itOfPattern + 2) ||
				MatchCore(str, itOfStr + 1, pattern, itOfPattern);
		}else{
			return MatchCore(str, itOfStr, pattern, itOfPattern + 2);
		}
	}else{
		if(*itOfStr == *itOfPattern || '.' == *itOfPattern)
		{
			return MatchCore(str, itOfStr + 1, pattern, itOfPattern + 1);
		}else{
			return false;
		}
	}
}

void Test(const char* testName, string& str, string& pattern, bool expected)
{
	cout << "*******" << testName << "******" << endl;
	bool result = Match(str, pattern);
	if(result == expected)
	{
		cout << "passed!" << endl;
	}else{
		cout << "failed!" << endl;
	}
}

void Test1()
{
	string str("aa");
	string pattern("a*");
	Test("test1 for aaa and a.a:", str, pattern, true);
}
