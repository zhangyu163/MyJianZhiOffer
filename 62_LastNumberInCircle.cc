#include<iostream>
#include<list>
#include<string>

using std::cout;
using std::endl;
using std::string;
using std::list;

int LastRemaining(int n, int m);
int LastRemaining_solution2(int n, int m);
void Test(const string testName, const int n, const int m, const int expected);
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

int LastRemaining(int n, int m)
{
	if(n < 1 || m < 1)
	{
		return -1;
	}
	list<int> numbers;
	list<int>::const_iterator itCur;
	list<int>::const_iterator itNext;
	int i;
	for(i = 0; i < n; ++i)
	{
		numbers.push_back(i);
	}
	itCur = numbers.begin();
	while(numbers.size() > 1)
	{

		for(i = 1; i < m; ++i)
		{
			++itCur;
			if(numbers.end() == itCur)
			{
				itCur = numbers.begin();
			}
		}
		itNext = ++itCur;
		if(numbers.end() == itNext)
		{
			itNext = numbers.begin();
		}
		--itCur;
		numbers.erase(itCur);
		itCur = itNext;
	}
	return *itCur;
}

int LastRemaining_solution2(int n, int m)
{
	if(n < 1 || m < 1)
	{
		return -1;
	}
	int a = 0;
	int b = 0;
	int i;
	for(i = 2; i <= n; ++i)
	{
		b = (a + m) % i;
		a = b;
	}
	return b;
}

void Test(const string testName, const int n, const int m, const int expected)
{
	cout << "*****" << testName << "******" << endl;
	int res = LastRemaining_solution2(n, m);
	if(res == expected)
	{
		cout << "passed!" << endl;
	}else{
		cout << "failed!" << endl;
	}
}

void Test1()
{
	int n = -1;
	int m = 2;
	Test("test1 for n = -1, m = 2", n, m, -1);
	
	n = 1;
	m = 1;
	Test("test1 for n = 1, m = 1", n, m, 0);
	
	n = 1;
	m = 2;
	Test("test1 for n = 1, m = 2", n, m, 0);
}

void Test2()
{
	int n = 2;
	int m = 1;
	Test("test2 for n = 2, m = 1", n, m, 1);
	
	n = 2;
	m = 2;
	Test("test2 for n = 1, m = 1", n, m, 0);
}

void Test3()
{
	int n = 5;
	int m = 2;
	Test("test3 for n = 2, m = 1", n, m, 2);
	
	n = 6;
	m = 7;
	Test("test3 for n = 1, m = 1", n, m, 4);
}
