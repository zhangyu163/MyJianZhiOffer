#include<string>
#include<iostream>
#include<vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;

int GetFirstNumberOfK(const vector<int>& data, const int k, vector<int>::const_iterator start,
		vector<int>::const_iterator end);

int GetLastNumberOfK(const vector<int>& data, const int k, vector<int>::const_iterator start,
		vector<int>::const_iterator end);

int GetNumberOfK(const vector<int>& data, const int k);
void Test(const string testName, const vector<int>& data, const int k, const int expected);
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

int GetNumberOfK(const vector<int>& data, const int k)
{
	if(data.empty())
	{
		return 0;
	}
	int countOfK = 0;
	vector<int>::const_iterator it1 = data.begin();
	vector<int>::const_iterator it2 = data.end();
	
	int firstK = GetFirstNumberOfK(data, k, it1, it2);

	int lastK = GetLastNumberOfK(data, k, it1, it2);
	if(firstK > -1 && lastK > -1)
	{
		countOfK = lastK - firstK + 1;
	}
	return countOfK;
}

int GetFirstNumberOfK(const vector<int>& data, const int k, vector<int>::const_iterator start,
		vector<int>::const_iterator end)
{
	if(start ==  end)
	{
		if(*start == k)
		{
			return start - data.begin();
		}
		return -1;
	}
	int pos = 0;
	vector<int>::const_iterator mid;
	mid = (end - start) / 2 + start;
	if(*mid == k)
	{
		if(mid > start && *(mid - 1) != k || data.begin() == mid)
		{
			pos = mid - data.begin();
			return pos;
		}else{
			end = mid;
		}
	}else if(*mid < k)
	{
		start = mid + 1;
	}else{
		end = mid;
	}
	return GetFirstNumberOfK(data, k, start, end);
}

int GetLastNumberOfK(const vector<int>& data, const int k, vector<int>::const_iterator start,
		vector<int>::const_iterator end)
{
	if(start == end)
	{
		if(start == data.end())
		{
			return -1;
		}
		if(*start == k)
		{
			return start - data.begin();
		}
		return -1;
	}
	int pos = 0;
	vector<int>::const_iterator mid;
	mid = (end - start) / 2 + start;
	if(*mid == k)
	{
		if(mid < data.end() - 2 && *(mid + 1) != k || (data.end() - 1) == mid)
		{
			return mid - data.begin();
		}else{
			start = mid + 1;
		}
	}else if(*mid < k)
	{
		start = mid + 1;
	}else{
		end = mid;
	}
	return GetLastNumberOfK(data, k, start, end);
}

void Test(const string testName, const vector<int>& data, const int k, const int expected)
{
	cout << "********" << testName << "********" << endl;
	int result = GetNumberOfK(data, k);
	if(expected == result)
	{
		cout << "passed" << endl;
	}else{
		cout << "failed" << endl;
	}
}

void Test1()
{
	vector<int> data;
	Test("test1 for null", data, 7, 0);
}

void Test2()
{
	vector<int> data = {1};
	Test("test2 for 1 node pass", data, 1, 1);
	Test("test2 for 1 node fail", data, 1, 0);
}

void Test3()
{
	vector<int> data = {1, 2, 3, 3, 3, 4, 5};
	Test("test3 for 1 node pass", data, 3, 3);
	Test("test3 for 1 node pass", data, 5, 1);
	Test("test3 for 1 node pass", data, 1, 1);
}

void Test4()
{
	vector<int> data = {1, 2, 2,  3, 4, 4, 4};
	Test("test4 for 1 node pass", data, 4, 3);
	Test("test4 for 1 node pass", data, 2, 2);
	data.clear();
	data = {3, 3, 3, 3};
	Test("test4 for 1 node pass", data, 3, 4);
}
