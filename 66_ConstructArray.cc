#include<iostream>
#include<vector>
#include<string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

template<typename T>
void ConstructArray(const vector<T>& numbers, vector<T>& res);
template<typename T>
void Test(const string testName, const vector<T>& numbers);
void Test1();
//void Test2();

int main()
{
	Test1();
	return 0;
}

template<typename T>
void ConstructArray(const vector<T>& numbers, vector<T>& res)
{
	if(numbers.size() <= 1)
	{
		return;
	}
	int i;
	int n = numbers.size();
	int temp = 1;
	res.push_back(1);
	for(i = 1; i < n; ++i)
	{
		res[i] = res[i - 1] * numbers[i - 1];
		res.push_back(res[i]);
	}
	for(i = n - 2; i >= 0; --i)
	{
		temp *= numbers[i + 1];
		res[i] = res[i] * temp;
	}
}

template<typename T>
void Test(const string testName, const vector<T>& numbers)
{
	cout << "******" << testName << "******" << endl;
	vector<T> res(0, numbers.size());
	//res.clear();
	ConstructArray(numbers, res);
	for(auto x: res)
	{
		cout << x << "  ";
	}
	cout << endl;
}

void Test1()
{
	//vector<int> numbers = {1, 2, 3, 4, 5};
	vector<int> numbers = {5, 4, 3, 2, 1};
	//vector<int> numbers = {1};
	Test("test1 for 12345", numbers);
}
