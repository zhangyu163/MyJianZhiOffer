#include<iostream>
#include<vector>

using namespace std;

bool CheckNum(const vector<char>& num1, const vector<char>& num2);
vector<int> BigIntMultiply(const vector<char>& num1, const vector<char>& num2);
void Test();

int main()
{
	Test();
	return 0;
}

bool CheckNum(const vector<char>& num1, const vector<char>& num2)
{
	int i;
	for(i = 0; i < num1.size(); ++i)
	{
		if(num1[i] < '0' && num1[i] > '9')
		{
			cout << "the first number is invalid input!" << endl;
			return false;
		}
	}

	for(i = 0; i < num2.size(); ++i)
	{
		if(num2[i] < '0' && num2[i] > '9')
		{
			cout << "the second number is invalid input!" << endl;
			return false;
		}
	}
	return true;
}
vector<int> BigIntMultiply(const vector<char>& num1, const vector<char>& num2)
{
	vector<int> result;
	int lengthOfResult = num1.size() + num2.size() + 1;
	int indexOfNum1;
	int indexOfNum2;
	for(int i = lengthOfResult - 1; i >= 0; --i)
	{
		result.push_back(0);
	}
	for(indexOfNum2 = num2.size() - 1; indexOfNum2 >=  0; --indexOfNum2)
	{
		for(indexOfNum1 = num1.size() - 1; indexOfNum1 >= 0; --indexOfNum1)
		{
			result[indexOfNum1 + indexOfNum2 + 2] += (num1[indexOfNum1] - '0') * (num2[indexOfNum2] - '0');
		}
	}
	int indexOfResult;
	int nTakeOver = 0;
	for(indexOfResult = num1.size() + num2.size(); indexOfResult > 0; --indexOfResult)
	{
		result[indexOfResult] = result[indexOfResult] + nTakeOver;
		int temp = result[indexOfResult];
		result[indexOfResult] = result[indexOfResult] % 10;
		nTakeOver = temp / 10;
	}
	return result;
}
/*vector<char> BigIntMultiply(const vector<char>& num1, const vector<char>& num2)
{
	vector<char> tempResult;
	vector<char> finalResult;
	if(!CheckNum)
	{
		finalResult.push_back('E');
		return finalResult;
	}
	int lengthOfNum1 = num1.size();
	int lengthOfNum2 = num2.size();
	int lengthOfTempResult = lengthOfNum1 + 1;
	int lengthOfFinalResult = lengthOfNum1 + lengthOfNum2;
	int indexOfNum1;
	int indexOfNum2;
	int i;
	int indexOfTempResult;
	int indexOfFinalResult;
	int nTakeOver = 0;
	int nSum;
	int offsetOfFinalResult = 0;
	for(i = 0; i < lengthOfFinalResult; ++i)
	{
		finalResult.push_back('0');
	}
	for(i = 0; i < lengthOfTempResult; ++i)
	{
		tempResult.push_back('0');
	}
	for(indexOfNum2 = lengthOfNum2 - 1; indexOfNum2 >= 0; --indexOfNum2)
	{
		nTakeOver = 0;
		indexOfTempResult = lengthOfTempResult - 1;
		for(indexOfNum1 = lengthOfNum1 - 1; indexOfNum1 >= 0; --indexOfNum1)
		{
			nSum = (num1[indexOfNum1] - '0') * (num2[indexOfNum2] - '0') + nTakeOver;
			nTakeOver = nSum / 10;
			nSum = nSum % 10;
			tempResult[indexOfTempResult--] = nSum + '0';
		}
		tempResult[indexOfTempResult] = nTakeOver + '0';
		indexOfTempResult = lengthOfTempResult - 1;
		nTakeOver = 0;
		for(indexOfFinalResult = lengthOfFinalResult - offsetOfFinalResult- 1;
				indexOfFinalResult >= lengthOfFinalResult - lengthOfNum1 - offsetOfFinalResult; 
				--indexOfFinalResult)
		{
			nSum = (finalResult[indexOfFinalResult] - '0') + 
				(tempResult[indexOfTempResult--] - '0') + nTakeOver;
			nTakeOver = nSum / 10;
			nSum = nSum % 10;
			finalResult[indexOfFinalResult] = nSum + '0';
		}
		finalResult[indexOfFinalResult] = (finalResult[indexOfFinalResult] - '0') + 
			(tempResult[0] - '0') + nTakeOver + '0';
		++offsetOfFinalResult;
	}
	return finalResult;
}*/

void Test()
{
	vector<char> num1;
	vector<char> num2;
	char temp;
	while(cin >> temp, temp != '#')
	{
		num1.push_back(temp);
	}
	while(cin >> temp, temp != '#')
	{
		num2.push_back(temp);
	}
	for(auto it = num1.begin(); it != num1.end(); ++it)
	{
		cout << *it;
	}
	cout << endl;
	for(auto it = num2.begin(); it != num2.end(); ++it)
	{
		cout << *it;
	}
	cout << endl;
	vector<int> result;
	result = BigIntMultiply(num1, num2);
	for(auto it = result.begin(); it != result.end(); ++it)
	{
		cout << *it;
	}
	cout << endl;
	
}
