#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using std::cout;
using std::endl;
using std::string;
using std::vector;

unsigned int ComputeCountWithSumS(unsigned int n, unsigned int s);
float PrintProbability(unsigned int n, unsigned int s);

void Test(const string testName, const unsigned int n, const unsigned int s, const float expected);
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
	/*unsigned int curSum = 0;
	unsigned int res = 0;
	res = ComputeCountWithSumS(3, 8);
	cout << res <<endl;*/
	
	return 0;
}

unsigned int ComputeCountWithSumS(unsigned int n, unsigned int s)
{
	if(1 == n &&(1 == s || 2 == s || 3 == s || 4 == s || 5 == s || 6 == s))
	{
		return 1;
	}else if(1 == n){
		return 0;
	}
	int res = ComputeCountWithSumS(n - 1, s - 1) + ComputeCountWithSumS(n - 1, s - 2) 
		+ ComputeCountWithSumS(n - 1, s - 3) + ComputeCountWithSumS(n - 1, s - 4)
		+ ComputeCountWithSumS(n - 1, s - 5) + ComputeCountWithSumS(n - 1, s - 6);
	return res;
}

float PrintProbability(unsigned int n, unsigned int s)
{
	if(n <= 0 || s <= 0 || s < n || s > 6 *n)
	{
		return 0.0;
	}
	unsigned int countOfS = 0;
	unsigned int curSum = 0;
	countOfS = ComputeCountWithSumS(n, s);
	float probabilityOfS = static_cast<float>(countOfS) / pow(6, n);
	return probabilityOfS;
	//cout << "the probability of s is: " << probabilityOfS << endl;
}

void Test(const string testName, const unsigned int n, const unsigned int s, const float expected)
{
	cout << "********" << testName << "***********" << endl;
	float probabilityOfS = PrintProbability(n, s);

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

