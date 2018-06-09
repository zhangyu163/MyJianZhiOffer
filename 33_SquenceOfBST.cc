#include<iostream>
#include<vector>
#include<string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

bool VerifySquenceOfBST(const vector<int>& arr, vector<int>::const_iterator itLeft,
		vector<int>::const_iterator itRight);
void Test(const string testName, const vector<int>& arr, const bool expected);
void Test1();
void Test2();
void Test3();

int main()
{
	//Test1();
	Test2();
	Test3();
	return 0;
}

bool VerifySquenceOfBST(const vector<int>& arr, vector<int>::const_iterator itLeft,
		vector<int>::const_iterator itRight)
{
	if(arr.empty() || itLeft > itRight)
	{
		return false;
	}
	if(1 == arr.size() || itLeft == itRight)
	{
		return true;
	}
	vector<int>::const_iterator itCurrent = itLeft;
	vector<int>::const_iterator itRoot = itRight - 1;
	const int rootValue = *itRoot;
	while(itCurrent < itRight && *itCurrent < rootValue)
	{
		++itCurrent;
	}
	bool left = true;
	if(itCurrent > itLeft)
	{
		left = VerifySquenceOfBST(arr, itLeft, itCurrent);
	}
	vector<int>::const_iterator itCurrent_2 = itCurrent;
	while(itCurrent_2 < itRoot && *itCurrent_2 > rootValue)
	{
		++itCurrent_2;
	}
	bool right = true;
	if(itCurrent_2 == itRoot)
	{
		right = VerifySquenceOfBST(arr, itCurrent, itRoot);
	}else{
		right = false;
	}
	return left && right;
}
void Test(const string testName, const vector<int>& arr, const bool expected)
{
	cout << "********" << testName << "********" << endl;
	const bool result = VerifySquenceOfBST(arr, arr.begin(), arr.end());
	if(expected == result)
	{
		cout << "passed" << endl;
	}else{
		cout << "failed" << endl;
	}
}

void Test1()
{
	vector<int> arr;
	Test("test1 for null", arr, false);
	arr.push_back(1);
	Test("test1 for 1 element", arr, true);
}

void Test2()
{
	vector<int> arr;
	for(int x: {5, 4, 3, 2, 1})
	{
		arr.push_back(x);
	}
	Test("test2 for 5-7-6-9-11-10-8", arr, true);
}

void Test3()
{
	vector<int> arr;
	for(int x: {1, 2, 3, 4, 5, 6})
	{
		arr.push_back(x);
	}
	Test("test2 for 7-4-6-5", arr, true);

}
