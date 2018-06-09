#include<iostream>

using std::cout;
using std::endl;

long long Fibonacci(unsigned n)
{
	int result[2] = {0, 1};
	if(n < 2)
		return result[n];
	int fibN;
	int fibMinusOne = result[0];
	int fibMinusTwo = result[1];
	int i;
	for(i = 2; i <= n; ++i)
	{
		fibN = fibMinusOne + fibMinusTwo;
		fibMinusTwo = fibMinusOne;
		fibMinusOne = fibN;
	}
	return fibN;
}

long long TiaoTaiJie(int n)
{

}
int main()
{
	long long res = Fibonacci(10);
	cout << res << endl;
	return 0;
}
