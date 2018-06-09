#include<iostream>
#include<vector>
#include<string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

int FirstBit1(const int globalXOR);
bool IsBitIndexSpecial(const int x, const int indexFirstBit1);
void FindNumsAppearOnce(const vector<int>& arr, int& num1, int& num2);

void Test(const string testName, const vector<int>& arr, const int expected1, const int expected2);
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

int FirstBit1(const int globalXOR)
{
	int cglobalXOR = globalXOR;
	int indexFirstBit1 = 0;
	while((cglobalXOR & 0x1 == 0) && indexFirstBit1 < 8 * sizeof(int))
	{
		++indexFirstBit1;
		cglobalXOR >> 1;
	}
	return indexFirstBit1;
}
bool IsBitIndexSpecial(const int x, const int indexFirstBit1)
{
	int dealX = x >> indexFirstBit1;
	return dealX & 0x1;
}

void FindNumsAppearOnce(const vector<int>& arr, int& num1, int& num2)
{
	num1 = 0;
	num2 = 0;
	if(arr.empty() || arr.size() < 2)
	{
		return;
	}
	int globalXOR = 0;
	for(auto x: arr)
	{
		globalXOR ^= x;
	}
	int indexFirstBit1 = FirstBit1(globalXOR);
	for(auto x: arr)
	{
		if(IsBitIndexSpecial(x, indexFirstBit1))
		{
			num1 ^= x;
		}else{
			num2 ^= x;
		}
	}
}

void Test(const string testName, const vector<int>& arr, const int expected1, const int expected2)
{
	cout << "*******" << testName << "*******" << endl;
	int number1, number2;
	FindNumsAppearOnce(arr, number1, number2);
	if((number1 == expected1 && number2 == expected2) || 
			(number1 == expected2 && number2 == expected1))
	{
		cout << "passed!" << endl;
	}else{
		cout << "failed!" << endl;
	}

}
void Test1()
{
	vector<int> arr;
	Test("test1 for null", arr, 0, 0);
}

void Test2()
{
	vector<int> arr = {1};
	Test("test2for null", arr, 0, 0);
}

void Test3()
{
	vector<int> arr = {0, 1};
	Test("test3 for null", arr, 0, 1);
	Test("test3 for null", arr, 1, 0);
	
	vector<int>().swap(arr);
	arr.push_back(1);
	arr.push_back(1);
	Test("test3 for null", arr, 0, 0);
}

void Test4()
{
	vector<int> arr = {1, 2, 3, 3, 2, 0};
	Test("test4 for ", arr, 0, 1);
	Test("test4 for ", arr, 1, 0);
	cout << endl;

	vector<int>().swap(arr);
	for(int x: {3, 3, 2, 2, 5, 1, 1, 4, 6, 6})
	{
		arr.push_back(x);
	}
	Test("test4 for ", arr, 5, 4);
	Test("test4 for ", arr, 4, 5);
	cout << endl;
	
	vector<int>().swap(arr);
	for(int x: {3, 3, 2, 2, 6, 6, -8, -9})
	{
		arr.push_back(x);
	}
	Test("test4 for ", arr, -8, -9);
	Test("test4 for ", arr, -9, -8);
	cout << endl;
}
