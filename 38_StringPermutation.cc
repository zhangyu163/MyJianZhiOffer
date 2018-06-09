#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;

void StringPermutation(string& str, string::iterator itbegin);
void Test(const string testName, string& str);
void Test1();
void Test2();
void Test3();
void Test4();

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	return 0;
}

void StringPermutation(string& str, string::iterator itbegin)
{
	if(str.end() == itbegin)
	{
		cout << str << endl;
		return;
	}
	string::iterator itCur;
	char ch;
	char* itTemp = &ch;
	for(itCur = itbegin; itCur != str.end(); ++itCur)
	{
		*itTemp = *itCur;
		*itCur = *itbegin;
		*itbegin = *itTemp;
		StringPermutation(str, itbegin + 1);
		*itTemp = *itCur;
		*itCur = *itbegin;
		*itbegin = *itTemp;
	}
}

void Test(const string testName, string& str)
{
	cout << "******" << testName << "*******" << endl;
	if(!str.empty())
	{
		cout << "orinal string is: " << str << endl;
		StringPermutation(str, str.begin());
		cout << "finish string is: " << str << endl;
		cout << endl << endl;
	}
}

void Test1()
{
	string str;
	Test("test1 for null str", str);
}

void Test2()
{
	string str;
	str.push_back('a');
	Test("test2 for 1 node", str);
}

void Test3()
{
	string str;
	for(auto x: {'a', 'b'})
	{
		str.push_back(x);
	}
	Test("test3 for ab node", str);
}

void Test4()
{
	string str;
	for(auto x: {'a', 'b', 'c', 'd'})
	{
		str.push_back(x);
	}
	Test("test4 for abcd node", str);
}
