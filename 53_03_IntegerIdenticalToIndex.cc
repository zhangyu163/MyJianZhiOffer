#include<string>
#include<iostream>
#include<vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;

vector<int>::const_iterator GetNumberSameAsIndex(const vector<int>& data, 
		vector<int>::const_iterator start, vector<int>::const_iterator end);
int GetNumberSameAsIndex(const vector<int>& data);

int GetNumberSameAsIndex_Iteratively(const vector<int>& data);

void Test(const string testName, const vector<int>& data);
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

vector<int>::const_iterator GetNumberSameAsIndex(const vector<int>& data, 
		vector<int>::const_iterator start, vector<int>::const_iterator end)
{
	if(start == end)
	{
		return data.end();
	}
	vector<int>::const_iterator mid = ((end - start) >> 1) + start;
	int index = mid - data.begin();
	if(*mid == index)
	{
		return mid;
	}else if(*mid > index)
	{
		end = mid;
	}else{
		start = mid + 1;
	}
	return GetNumberSameAsIndex(data, start, end);
}

int GetNumberSameAsIndex(const vector<int>& data)
{
	if(data.empty())
	{
		return -1;
	}
	vector<int>::const_iterator start = data.begin();
	vector<int>::const_iterator end = data.end();
	auto result = GetNumberSameAsIndex(data, start, end);
	if(data.end() == result)
	{
		return -1;
	}else{
		return *result;
	}
}

int GetNumberSameAsIndex_Iteratively(const vector<int>& data)
{
	if(data.empty())
	{
		return -1;
	}
	vector<int>::const_iterator left = data.begin();
	vector<int>::const_iterator right = data.end();
	vector<int>::const_iterator mid;
	int index;
	while(left != right)
	{
		mid = ((right - left) >> 1) + left;
		index = mid - data.begin();
		if(*mid == index)
		{
			return index;
		}else if(*mid > index)
		{
			right = mid;
		}else{
			left = mid + 1;
		}
	}
	return -1;

}

void Test(const string testName, const vector<int>& data)
{
	cout << "********" << testName << "********" << endl;
	int result = GetNumberSameAsIndex_Iteratively(data);
	cout << "the result is: " << result << endl;
}

void Test1()
{
	vector<int> data;
	Test("test1 for null", data);
}

void Test2()
{
	vector<int> data = {1};
	Test("test2 for 1 node pass", data);
	data.clear();
	data.push_back(0);
	Test("test2 for 1 node pass", data);
}

void Test3()
{
	vector<int> data = {0, 1, 2, 3, 4};
	Test("test3 for 1 node pass", data);
	Test("test3 for 1 node pass", data);
}

void Test4()
{
	vector<int> data = {0, 2, 3, 5};
	Test("test4 for 1 node pass", data);
	data.clear();
	data = {-3, -1, 1, 3, 5};
	Test("test4 for 1 node pass", data);
	data = {-4, -3, -1, 3};
	Test("test4 for 1 node pass", data);
}
