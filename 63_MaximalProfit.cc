#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::max;

int MaxDiff(const vector<int>& prices);
void Test(const string testName, const vector<int>& prices, const int expected);
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

int MaxDiff(const vector<int>& prices)
{
	if(prices.size() < 2)
	{
		return 0;
	}
	int minValue = prices[0] <= prices[1] ? prices[0]: prices[1];
	int temp;
	int maxOfI = prices[1] - prices[0];
	int i;
	for(i = 2; i < prices.size(); ++i)
	{
		temp = prices[i] - minValue;
		maxOfI = max(maxOfI, temp);
		if(prices[i] < minValue)
		{
			minValue = prices[i];
		}
	}
	return maxOfI;
}

void Test(const string testName, const vector<int>& prices, const int expected)
{
	cout << "********" << testName << "********" << endl;
	int result = MaxDiff(prices);
	if(expected == result)
	{
		cout << "passed!" << endl;
	}else{
		cout << "failed!" << endl;
	}
}

void Test1()
{
	vector<int> prices;
	Test("test1 for null", prices, 0);
	
	prices.push_back(1);
	Test("test1 for 1 element", prices, 0);
}

void Test2()
{
	vector<int> prices = {2, 1};
	Test("test2 for null", prices, -1);
	
	prices.push_back(3);
	prices.push_back(1);
	prices.push_back(5);
	Test("testr2 for 1 element", prices, 4);
}

void Test3()
{
	vector<int> prices = {9, 11, 8, 5, 7, 12, 16, 14};
	Test("test3 for ", prices, 11);
	
	vector<int>().swap(prices);
	for(auto x: {4, 4, 4, 4, 4})
	{
		prices.push_back(x);
	}
	Test("test3 for ", prices, 0);

	vector<int>().swap(prices);
	for(auto x: {5, 4, 3, 2, 1})
	{
		prices.push_back(x);
	}
	Test("test3 for ", prices, -1);
}

