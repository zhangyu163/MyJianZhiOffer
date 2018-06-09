#include<iostream>
#include<string>
#include<vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int LongestSubstringWithoutDup(const string& str, vector<int>& substrPos);
void Test(const string testName, const string& str, vector<int>& substrPos, const int expected);
void Test1();
void Test2();
void Test3();
void Test4();
void Test5();

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	return 0;
}

int LongestSubstringWithoutDup(const string& str, vector<int>& substrPos)
{
	if(str.empty())
	{
		return 0;
	}
	vector<int> pos(26, -1);
	string::const_iterator itOfStr;
	int maxSubLength = 1;
	int curSbuLength = 0;
	int tempPos = 0;
	for(int i = 0; i < str.size(); ++i)
	{
		++curSbuLength;
		if(i - pos[str[i] - 'a'] < curSbuLength)
		{
			curSbuLength = i - pos[str[i] - 'a'];
			tempPos = pos[str[i] - 'a'] + 1;
		}
		if(curSbuLength >= maxSubLength)
		{
			substrPos[1] = i;
			substrPos[0] = tempPos;
			maxSubLength = curSbuLength;
		}
		pos[str[i] - 'a'] = i;
	}
	return maxSubLength;
}

void Test(const string testName, const string& str, vector<int>& substrPos, const int expected)
{
	cout << "*******" << testName << "********" << endl;
	int longestLen = LongestSubstringWithoutDup(str, substrPos);
	if(expected == longestLen)
	{
		cout << "passed!" << endl;
	}else{
		cout << "failed!" << endl; 
	}
	if(!str.empty())
	{
		cout << "the longest substring is: ";
		for(int it  = substrPos[0]; it <= substrPos[1]; ++it)
		{
			cout << str[it];
		}
		cout << endl;
	}
}

void Test1()
{
	string str;
	vector<int> substrPos(2, 0);
	Test("test1 for null", str, substrPos, 0);
}
void Test2()
{
	string str("a");
	vector<int> substrPos(2, 0);
	Test("test1 for 1 element", str, substrPos, 1);
}

void Test3()
{
	string str("abcdaef");
	vector<int> substrPos(2, 0);
	Test("test1 for 9 element", str, substrPos, 6);
}

void Test4()
{
	string str("aaabbbccc");
	vector<int> substrPos(2, 0);
	Test("test1 for 9 element", str, substrPos, 2);
}

void Test5()
{
	string str("abcdcba");
	vector<int> substrPos(2, 0);
	Test("test1 for 9 element", str, substrPos, 4);
}
