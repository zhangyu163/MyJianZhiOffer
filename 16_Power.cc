#include<iostream>
#include<cmath>
using std::cout;
using std::endl;
using std::equal;
using std::fabs;
double PowerCore(const double& base, const int& exponent);
double Power(const double& base, const int& exponent);
void Test(const char* testName, const double& base, const int& exponent, const double& expected);
void Test1();
void Test2();

bool globalInvalidInput = false;

int main()
{
	Test1();
	return 0;
}
double PowerCore(const double& base, const int& exponent)
{
	if(0 == exponent)
	{
		return 1;
	}
	double result = 1.0;
	double base_op = base;
	int exp_op = exponent;
	while(exp_op)
	{
		if(exp_op & 1)
		{
			result *= base_op;
		}
		base_op *= base_op;
		exp_op = exp_op >> 1;
	}
	return result;
}

double PowerCore_cursive(const double& base, const int& exponent)
{
	if(0 == exponent)
	{
		return 1.0;
	}
	if(1 == exponent)
	{
		return base;
	}
	int result = 1.0;
	int exp_op = exponent;
	if(exponent & 1)
	{
		result *= base;
	}
	result = PowerCore_cursive(base, exp_op >> 1) * PowerCore_cursive(base, exp_op >> 1) * result;
	return result;
}

double Power(const double& base, const int& exponent)
{
	int absExponent;
	if(exponent <= 0)
	{
		if(fabs(base - 0.0) < 1e-6)
		{
			globalInvalidInput = true;
			return 0.0;
		}
		absExponent = -exponent;
	}else{
		absExponent = exponent;
	}
	double result = PowerCore_cursive(base, absExponent);
	if(exponent < 0)
	{
		result = 1.0 / result;
	}
	return result;
}

void Test(const char* testName, const double& base, const int& exponent, const double& expected)
{
	cout << "----------" << testName << "------------" << endl;
	const double result = Power(base, exponent);
	if(fabs(result - expected) < 0.00001)
	{
		cout << "passed" << endl;
	}else{
		cout << "failed" << endl;
	}
}
void Test1()
{
	Test("test for 0.0", 0, 2, 0);
	Test("test for 1.0", 1.0, 0, 1.0);
	Test("test1 for 3", 3.0, 3, 27.0);
	Test("test1 for -8.0", -8.0, -2, 1.0 / 64);
	Test("test1 for 2", 2.0, -2, 1.0 / 4);
}
