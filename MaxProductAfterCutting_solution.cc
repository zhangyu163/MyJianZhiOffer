#include<iostream>
#include<vector>
#include<algorithm>
using std::cout;
using std::endl;
using std::vector;

int MaxProductAfterCutting_Solution(const int& length)
{
	vector<int> product;
	if(length < 2)
	{
		return 0;
	}
	if(2 == length)
	{
		return 1;
	}
	if(3 == length)
	{
		return 2;
	}
	product.push_back(0);
	product.push_back(1);
	product.push_back(2);
	product.push_back(3);
	int max = 0;
	int i;
	int j;
	for(i = 4; i < length + 1; ++i)
	{
		max = 0;
		for(j = 1; j <= i / 2; ++j)
		{
			int muti = product[j] * product[i - j];
			if(muti > max)
			{
				max = muti;
			}
		}
		product.push_back(max);
	}
	max = product[length];
	return max;
}

int MaxProductAfterCutting_TanLan(const int& length)
{
	if(length < 2)
	{
		return 0;
	}else if(2 == length)
	{
		return 1;
	}else if(3 == length)
	{
		return 2;
	}
	int max = 0;
	int timesOfThree;
	timesOfThree = length / 3;
	if(1 == (length - timesOfThree * 3))
	{
		timesOfThree -= 1;
	}
	int timesOfTwo = (length - timesOfThree * 3) / 2;
	max = pow(3, timesOfThree) * pow(2, timesOfTwo);
	return max;
}

void Test(const char* testName, const int& length, const int& expected)
{
	cout << "*********" << testName << "*******"  << endl;
	int max = MaxProductAfterCutting_TanLan(length);
	if(expected == max)
	{
		cout << "passed" << endl;
	}else{
		cout << "failed" << endl;
	}
}
void Test1()
{
	int length = 1;
	Test("test1 for 1 len", length, 0);
	length = 2;
	Test("test1 for 2 len", length, 1);
	length = 3;
	Test("test1 for 3 len", length, 2);
	length = 4;
	Test("test1 for 4 len", length, 4);
	length = 9;
	Test("test1 for 9 len", length, 27);
	length = 50;
	Test("test1 for 50 len", length, 86093442);

}
int main()
{
	Test1();
	return 0;
}
