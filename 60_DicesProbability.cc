#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::memset;
using std::pow;

//第三套解决方案-----迭代

void ComputeProbability_solution3(unsigned int n, unsigned int s);
float PrintProbability_solutoin3(unsigned int n, unsigned int s);

//第二套解决方案-----递归
void ComputeProbability(unsigned int n, unsigned int s, unsigned int& curSum, unsigned int& count);
float PrintProbability(unsigned int n, unsigned int s);
float PrintProbability_solutoin2(unsigned int n, unsigned int s);
//第一套解决方案-----递归
void ComputeCount(unsigned int n, unsigned int floor, unsigned int sum, unsigned int* count);
void ComputeCount(unsigned int n, unsigned int* count);
float PrintProbability_solutoin2(unsigned int n, unsigned int s);

void Test(const string testName, const unsigned int n, const unsigned int s, const float expected);
void Test1();
void Test2();
void Test3();
void Test4();

int main()
{
	/*Test1();
	Test2();
	Test3();
	Test4();*/
	unsigned int curSum = 0;
	unsigned int res = 0;
	for(unsigned int x = 0; x < 20; ++x)
	{
		ComputeProbability_solution3(3, x);
	}
	//cout << res <<endl;
	
	return 0;
}

void ComputeProbability(unsigned int n, unsigned int s, unsigned int& curSum, unsigned int& count)
{
	if(n == 0)
	{
		return;
	}
	int i;
	for(i = 1; i < 7; ++i)
	{
		curSum += i;
		ComputeProbability(n - 1, s, curSum, count);
		if(s == curSum && n == 1)
		{
			++count;
			//return;
		}
		curSum -= i;
	}
}

void ComputeProbability_solution3(unsigned int n, unsigned int s)
{
	if(n < 1 || s < n || s > 6 * n)
	{
		return;
	}
	unsigned int* count1 = new unsigned int[6*n + 1];
	memset(count1, 0, sizeof(int) * (6 * n + 1));
	int i;
	int j;
	int k;
	int sum;
	for(i = 1; i < 7; ++i)
	{
		count1[i] = 1;
	}
	for(i = 2; i <= n; ++i)
	{
		for(j = 6 * i; j >= i; --j)
		{
			count1[j] = 0;
			for(k = 1; k <= 6 && k < j; ++k )
			{
				count1[j] += count1[j -k];
			}
		}
		count1[i - 1] = 0;
	}
	cout << "result is: " << count1[s] << endl;
	delete[] count1;
}

float PrintProbability_solutoin3(unsigned int n, unsigned int s)
{
	if(n <= 0 || s <= 0 || s < n || s > 6 *n)
	{
		return 0.0;
	}
	unsigned int countOfS = 0;
	unsigned int curSum = 0;
	float probabilityOfS = static_cast<float>(countOfS) / pow(6, n);
	return probabilityOfS;

}


float PrintProbability(unsigned int n, unsigned int s)
{
	if(n <= 0 || s <= 0 || s < n || s > 6 *n)
	{
		return 0.0;
	}
	unsigned int countOfS = 0;
	unsigned int curSum = 0;
	ComputeProbability(n, s, curSum, countOfS);
	float probabilityOfS = static_cast<float>(countOfS) / pow(6, n);
	return probabilityOfS;
	//cout << "the probability of s is: " << probabilityOfS << endl;
}

void ComputeCount(unsigned int n, unsigned int* count)
{
	int i;
	ComputeCount(n, n , 0, count);
}

void ComputeCount(unsigned int n, unsigned int floor, unsigned int sum, unsigned int* count)
{
	int i;
	if(floor == 0)
	{
		count[sum - n] += 1;
	}else{
		for(i = 1; i < 7; ++i)
		{	
			sum = sum + i;
			ComputeCount(n, floor - 1, sum, count);
			sum = sum - i;
		}
	}
}

float PrintProbability_solutoin2(unsigned int n, unsigned int s)
{
	float probabilityOfS = 0.0;
	if(n < 1 || s < n || s > 6 * n)
	{
		return probabilityOfS;
	}
	unsigned int* count = new unsigned int[5*n + 1];
	memset(count, 0, sizeof(int)*(5*n + 1));
	ComputeCount(n, count);
	probabilityOfS = static_cast<float>(count[s - n]) / pow(6, n);
	delete[] count;
	return probabilityOfS;
}

void Test(const string testName, const unsigned int n, const unsigned int s, const float expected)
{
	cout << "********" << testName << "***********" << endl;
	float probabilityOfS = PrintProbability_solutoin2(n, s);

	if(expected - probabilityOfS > -0.001 && expected - probabilityOfS < 0.001)
	{
		cout << "passed!" << endl;
	}else{
		cout << "failed" << endl;
	}
	cout << endl << endl;
}

void Test1()
{
	unsigned int n = 0;
	unsigned int s = 6;
	float expected = 0;
	Test("test1 for n=0, s= 0", n, s, expected);
	
	n = 1;
	s = 7;
	expected = 0;
	Test("test1 for n=1, s= 0", n, s, expected);
	
	n = 1;
	for(s: {1, 2, 3, 4, 5, 6})
	{
		expected = 0.16667;
		Test("test1 for n=1, s= 1,2,3,4,5,6", n, s, expected);
	}
}

void Test2()
{
	unsigned int n = 2;
	unsigned int s = 6;
	float expected = 0.13889;
	Test("test2 for n=2, s= 6", n, s, expected);

}

void Test3()
{
}

void Test4()
{
}

