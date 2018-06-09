#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::max;


class A;
A* Array[2];

class A
{
	public:
		virtual int Sum(int n)
		{
			return 0;
		}
};

class B: public A
{
	public:
		virtual int Sum(int n)
		{
			return Array[!!n]->Sum(n - 1) + n;
		}
};

class Temp
{
	public:
		Temp()
		{
			++N;
			Sum += N;
		}

		static void Reset()
		{
		    N = 0;
			Sum = 0;
		}

		static int GetSum()
		{
			return Sum;
		}

	private:
		static int N;
		static int Sum;
};

int Temp::N = 0;
int Temp::Sum = 0;

void Test(const string testName, const int expected);
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

int Sum_solution2(int n)
{
	A a;
	B b;
	Array[0] = &a;
	Array[1] = &b;
	int value = b.Sum(n);
	return value;
}

void Test(const string testName, const int n, const int expected)
{
	cout << "********" << testName << "********" << endl;
	//int result = Temp::GetSum();
	int result = Sum_solution2(n);
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

