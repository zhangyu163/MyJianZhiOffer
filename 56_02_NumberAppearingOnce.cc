#include<iostream>
#include<vector>
#include<string>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::exception;

int FindNumsAppearOnce(const vector<int>& data);
void Test(const string testName, const vector<int>& arr, const int expected);
void Test1();
void Test2();
void Test3();
void Test4();

int main()
{
	//Test1();
	//Test2();
	Test3();
	//Test4();

	return 0;
}

int FindNumsAppearOnce(const vector<int>& data)
{
	if(data.size() < 1 || (data.size() > 1 && data.size() < 4))
	{
		throw exception();
	}
	vector<int> bitSum(32, 0);
	for(int num: data)
	{
		for(auto j = bitSum.end() -1; j >= bitSum.begin(); --j)
		{
			*j += num & 0x1;
			num = num >> 1;
		}
	}
	int result = 0;
	for(auto num: bitSum)
	{
		result = result  << 1;
		result += num % 3;
	}
	return result;
}

void Test(const string testName, const vector<int>& arr, const int expected)
{
	cout << "*******" << testName << "*******" << endl;
	int result = FindNumsAppearOnce(arr);
	if(result == expected)
	{
		cout << "passed!" << endl;
	}else{
		cout << "failed!" << endl;
	}

}
void Test1()
{
	vector<int> arr;
	Test("test1 for null", arr, 0);
}

void Test2()
{
	vector<int> arr = {1};
	Test("test2for null", arr, 1);
}

void Test3()
{
	vector<int> arr = {0, -1, -1, -1};
	Test("test3 for null", arr, 0);
	
	vector<int>().swap(arr);
	for(auto x: {-1, -1, -1, 0})
	{
		arr.push_back(x);
	}
	Test("test3 for null", arr, 0);
	
	vector<int>().swap(arr);
	for(auto x: {-1, -1, 0, -1})
	{
		arr.push_back(x);
	}
	Test("test3 for null", arr, 0);
	
	vector<int>().swap(arr);
	arr.push_back(1);
	arr.push_back(1);
	Test("test3 for null", arr, 0);
}

void Test4()
{
	vector<int> arr = {1, 2, -3, -3, 2, 2, -3};
	Test("test4 for ", arr, 1);
	cout << endl;

	vector<int>().swap(arr);
	for(int x: {3, 3, 2, 2, 2, 3, 6, -4, 6, 6})
	{
		arr.push_back(x);
	}
	Test("test4 for ", arr, -4);
	cout << endl;
	
	vector<int>().swap(arr);
	for(int x: {-3, 2, 6, 2, 2, 6, 6})
	{
		arr.push_back(x);
	}
	Test("test4 for ", arr, -3);
	cout << endl;
}
