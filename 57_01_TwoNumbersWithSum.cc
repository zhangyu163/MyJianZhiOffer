#include<iostream>
#include<vector>
#include<string>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::exception;

bool FindNumbersWithSum(const vector<int>& data, vector<int>& pairNum, const int NumSum);

void Test(const string testName, const vector<int>& arr, const bool existence,
		const int expected);
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

bool FindNumbersWithSum(const vector<int>& data, vector<int>& pairNum, const int NumSum)
{
	pairNum[0] = 0;
	pairNum[1] = 0;
	if(data.size() < 2)
	{
		return false;
	}
	vector<int>::const_iterator left = data.begin();
	vector<int>::const_iterator right = data.end() - 1;
	vector<int>::const_iterator mid;
	int curSum;
	while(left < right)
	{
		curSum = *left + *right;
		if(NumSum == curSum)
		{
			pairNum[0] = *left;
			pairNum[1] = *right;
			return true;
		}else if(curSum > NumSum)
		{
			--right;
		}else{
			++left;
		}
	}
	return false;
}

void Test(const string testName, const vector<int>& arr, const bool existence,
		const int expected)
{
	cout << "*******" << testName << "*******" << endl;
	vector<int> pairsNum(2, 0);
	bool result = FindNumbersWithSum(arr, pairsNum, expected);
	if(existence == result)
	{
		if(result)
		{
			cout << "the existence is: " << pairsNum[0] << "+" << pairsNum[1] << endl;
		}else{
			cout << "not existence!" <<endl;
		}
		cout << "passed!" << endl;
	}else{
		cout << "failed!" << endl;
	}

}
void Test1()
{
	vector<int> arr;
	Test("test1 for null", arr, false, 0);
}

void Test2()
{
	vector<int> arr = {1};
	Test("test2for null", arr, false, 0);
}

void Test3()
{
	vector<int> arr = {-2, 3};
	Test("test3 for null", arr, true, 1);
	Test("test3 for null", arr, false, -2);
	Test("test3 for null", arr, false, 3);
	
	vector<int>().swap(arr);
	for(auto x: {3, 9})
	{
		arr.push_back(x);
	}
	Test("test3 for null", arr, true, 12);
	Test("test3 for null", arr, false, 0);
	Test("test3 for null", arr, false, 13);
	
	vector<int>().swap(arr);
	for(auto x: {4, 6})
	{
		arr.push_back(x);
	}
	Test("test3 for null", arr, false, -5);
	Test("test3 for null", arr, true, 10);
	
	vector<int>().swap(arr);
	arr.push_back(1);
	arr.push_back(1);
	Test("test3 for null", arr, true, 2);
	Test("test3 for null", arr, false, 1);
}

void Test4()
{
	vector<int> arr = {-5, -3, -2, -1};
	Test("test4 for ", arr, true, -6);
	Test("test4 for ", arr, true, -5);
	Test("test4 for ", arr, true, -4);
	Test("test4 for ", arr, true, -7);
	Test("test4 for ", arr, false, -2);
	cout << endl;

	vector<int>().swap(arr);
	for(int x: {-5, -3, -3, -1})
	{
		arr.push_back(x);
	}
	Test("test4 for ", arr, true, -4);
	Test("test4 for ", arr, true, -8);
	Test("test4 for ", arr, true, -6);
	cout << endl;
	
	vector<int>().swap(arr);
	for(int x: {-3, -2, 0, 4, 5, 7})
	{
		arr.push_back(x);
	}
	Test("test4 for ", arr, true, 2);
	Test("test4 for ", arr, true, 12);
	Test("test4 for ", arr, true, -5);
	Test("test4 for ", arr, false, 6);
	Test("test4 for ", arr, false, 0);
	cout << endl;
}
