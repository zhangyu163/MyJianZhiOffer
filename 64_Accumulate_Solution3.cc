#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::max;

typedef int (*pfun)(int n);

void Test(const string testName, const int expected);
void Test1();
void Test2();

int main()
{
	Test1();
	Test2();
	return 0;
}

int Sum_terminator(int n)
{
	return 0;
}

int Sum_solution3(int n)
{
	pfun f[2] = {Sum_terminator, Sum_solution3};
	return n + f[!!n](n - 1);
}

void Test(const string testName, const int n, const int expected)
{
	cout << "********" << testName << "********" << endl;
	//int result = Temp::GetSum();
	int result = Sum_solution3(n);
	if(expected == result)
	{
		cout << "passed!" << endl;
	}else{
		cout << "failed!" << endl;
	}
}

void Test1()
{
	//Temp *a = new Temp[100];
	//delete[] a;
	Test("test1 for null", 100, 5050);	
}

void Test2()
{
	//Temp *a = new Temp[10];
	Test("test1 for null", 10, 55);	
}

void Test3()
{
}

