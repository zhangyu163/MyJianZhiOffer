#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

typedef bool (*pfunc)(int&);

void ReOrderArrayOddEven(vector<int>& vec, pfunc function);
void ReOrderArray(vector<int>& vec, pfunc function);
bool isEven(int& num);
void Test(const char* testName, vector<int>& vec, pfunc function, vector<int>& expectedVector);
void Test1();

int main()
{
	Test1();
	return 0;
}

bool isEven(int& num)
{
	return !(num & 0x1);
}
void ReOrderArrayOddEven(vector<int>& vec, pfunc function)
{
	if(0 == vec.size() || nullptr == function)
	{
		return;
	}
	ReOrderArray(vec, function);
}

void ReOrderArray(vector<int>& vec, pfunc function)
{
	if(vec.empty())
	{
		return;
	}else if(1 == vec.size())
	{
		return;
	}
	vector<int>::iterator itBegin = vec.begin();
	vector<int>::iterator itEnd = vec.end() - 1;
	while(itBegin < itEnd)
	{
		while(itBegin < itEnd && !function(*itBegin))
		{
			++itBegin;
		}
		while(itEnd > itBegin && function(*itEnd))
		{
			--itEnd;
		}
		if(itBegin < itEnd)
		{
			int temp = *itBegin;
			*itBegin = *itEnd;
			*itEnd = temp;
		}
	}
}
void Test(const char* testName, vector<int>& vec, pfunc function, vector<int>& expectedVector)
{
	cout << "******" << testName << endl;
	ReOrderArrayOddEven(vec, function);
	vector<int>::iterator itOrigin;
	vector<int>::iterator itExpected;
	for(itOrigin = vec.begin(), itExpected = expectedVector.begin(); 
			itOrigin != vec.end() && itExpected != expectedVector.end(); ++itOrigin, ++itExpected)
	{
		if(*itOrigin != *itExpected)
		{
			cout << "failed" << endl;
		}
	}
	cout << "passed" << endl;
}
void Test1()
{
	vector<int> vec;
	vector<int> expectedVector;
	for(int x: {2, 4, 6, 1, 3})
	{
		vec.push_back(x);
	}
	for(int x: {3, 1, 6, 4, 2})
	{
		expectedVector.push_back(x);
	}
	Test("test1 for 1 2 3 4 5", vec, isEven, expectedVector);
}
