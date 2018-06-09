#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::sort;
using std::stringstream;

bool Compare(const string& str1, const string& str2);
void PrintMinNumber(const vector<int>& numbers);
void Test(const string testName, const vector<int>& numbers);
void Test1();
void Test2();

int main()
{
	Test1();
	Test2();
	return 0;
}

bool Compare(const string& str1, const string& str2)
{
	string c_str1(str1);
	string c_str2(str2);
	c_str1.append(str2);
	c_str2.append(str1);
	if(c_str1.compare(c_str2) >= 0)
	{
		return false;
	}else{
		return true;
	}
	//return c_str1.compare(c_str2);
}

void PrintMinNumber(const vector<int>& numbers)
{
	if(numbers.empty())
	{
		return;
	}else if(1 == numbers.size())
	{
		cout << numbers.front() << endl;
	}
	vector<string> strArray;
	string temp;
	stringstream tempStream;
	for(auto x: numbers)
	{
		tempStream << x;
		tempStream >> temp;
		strArray.push_back(temp);
		tempStream.clear();
	}
	sort(strArray.begin(), strArray.end(), Compare);
	cout << "the result is: ";
	for(string x: strArray)
	{
		cout << x;
	}
	cout << endl;
}

void Test(const string testName, const vector<int>& numbers)
{
	cout << "*****" << testName << "*****" << endl;
	if(!numbers.empty())
	{
		cout << "the original array is: ";
		for(int x: numbers)
		{
			cout << " " << x;
		}
		cout << endl;
	}
	PrintMinNumber(numbers);
}

void Test1()
{
	vector<int> numbers;
	Test("test1 for null", numbers);
	numbers.push_back(234);
	Test("test1 for 1 number", numbers);
}

void Test2()
{
	vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(11);
	numbers.push_back(11);
	Test("test2 for 2 number", numbers);
	numbers.clear();
	numbers.push_back(3);
	numbers.push_back(5);
	numbers.push_back(1);
	numbers.push_back(4);
	numbers.push_back(2);
	Test("test2 for 3 number", numbers);
}
