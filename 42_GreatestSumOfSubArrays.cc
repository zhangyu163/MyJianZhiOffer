#include<iostream>
#include<vector>
#include<string>

using std::cout;
using std::endl;
using std::string;
using std::vector;

bool GreatestSumOfSubArrays(const vector<int>& numbers, int& resSumOfGreat, vector<int>& pos);
void Test(const string testName, const vector<int>& numbers, const int expected);
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

bool GreatestSumOfSubArrays(const vector<int>& numbers, int& resSumOfGreat, vector<int>& pos)
{
	bool invalid = true;
	resSumOfGreat = 0x80000000;
	if(numbers.empty())
	{
		invalid = false;
		pos[0] = pos[1] = 0;
		resSumOfGreat = 0x80000000;
		return invalid;
	}
	int curSum = 0;
	int greateSum = numbers[0];
	vector<int>::const_iterator itOfNumbers = numbers.begin();
	pos[0] = pos[1] = 0;
	int posss;
	while(itOfNumbers != numbers.end())
	{
		if(curSum <= 0)
		{
			curSum = *itOfNumbers;
			posss = itOfNumbers - numbers.begin();
		}else{
			curSum += *itOfNumbers;
		}
		if(curSum > greateSum)
		{
			pos[0] = posss;
			pos[1] = itOfNumbers - numbers.begin();
			greateSum = curSum;
		}
		++itOfNumbers;
	}
	resSumOfGreat = greateSum;
	return invalid;
}

void Test(const string testName, const vector<int>& numbers, const int expected)
{
	cout << "******" << testName << "*******" << endl;
	if(!numbers.empty())
	{
		for(auto x: numbers)
		{
			cout << "\t" << x;
		}
		cout << endl;
	}
	vector<int> pos = {0, 0};
	int resSumOfGreat = 0;
	int valid = GreatestSumOfSubArrays(numbers, resSumOfGreat, pos);
	if(valid)
	{
		cout << "the GreatestSumOfSubArrays: ";
		for(auto i = pos[0]; i <= pos[1]; ++i)
		{
			cout << "\t" << numbers[i];
		}
		cout << endl;
	}
	if(expected == resSumOfGreat)
	{
		cout << "passed" << endl;
	}else{
		cout << "failed" << endl;
	}

}
void Test1()
{
	const vector<int> numbers;
	Test("test1 for null", numbers, 0x80000000);
}
void Test2()
{
	vector<int> numbers;
	for(auto x: {1, -2, 3, 10, -4, 7, 2, -5})
	{
		numbers.push_back(x);
	}
	Test("test2 for 18", numbers, 18);
}
void Test3()
{
	vector<int> numbers;
	for(auto x: {1,  -2, -3, -1, -4, -5,  -2, -5})
	{
		numbers.push_back(x);
	}
	Test("test3 for negative", numbers, 1);
}
