#include<iostream>
#include<vector>
#include<string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

/*void Swap(vector<int>::iterator& a, vector<int>::iterator& b);
bool IsQualifier8Quen(const vector<int>& num);
void Permutation(vector<int>& num, vector<int>::iterator it, int& count);
void Print8Queuen();
void Test(const string testName, vector<int>& num);
void Test1();*/

void PrintQueuenMatrix(const vector<vector<int> >& queueMatrix);
void Queuen(vector<vector<int> >& queueMatrix, int i, int& count);
bool IsCorrect(const vector<vector<int> >& queueMatrix, const int i, const int j);
void Test();

int main()
{
	//Test1();
	//Print8Queuen();
	Test();
	return 0;
}

bool IsCorrect(const vector<vector<int> >& queueMatrix, const int i, const int j)
{
	int s, t;
	for(s = i, t = 0; t < 8; ++t)
	{
		if(queueMatrix[s][t] && t != j)
			return false;
	}
	for(s = 0, t = j; s < 8; ++s)
	{
		if(queueMatrix[s][t] && s != i)
			return false;
	}
	for(s = i - 1, t = j - 1 ; s >= 0 && t >= 0; --s, --t)
	{
		if(queueMatrix[s][t])
			return false;
	}
	for(s = i +  1, t = j + 1 ; s < 8 && t < 8; ++s, ++t)
	{
		if(queueMatrix[s][t])
			return false;
	}
	for(s = i - 1, t = j + 1 ; s >= 0 && t < 8; --s, ++t)
	{
		if(queueMatrix[s][t])
			return false;
	}
	for(s = i + 1, t = j - 1 ; s < 8 && t >= 0; ++s, --t)
	{
		if(queueMatrix[s][t])
			return false;
	}
	return true;
}

void PrintQueuenMatrix(const vector<vector<int> >& queueMatrix)
{
	for(auto arr: queueMatrix)
	{
		for(auto x: arr)
		{
			if(x)
			{
				cout << "  " << "#";
			}else{
				cout << "  " << x;
			}
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
}

void Queuen(vector<vector<int> >& queueMatrix, int i, int& count)
{
	if(8 == i)
	{
		++count;
		PrintQueuenMatrix(queueMatrix);
		return;
	}
	int j;
	for(j = 0; j < 8; ++j)
	{
		if(IsCorrect(queueMatrix, i, j))
		{
			queueMatrix[i][j] = 1;
			Queuen(queueMatrix, i + 1, count);
			queueMatrix[i][j] = 0;
		}
	}
}

void Test()
{
	vector<vector<int> > queueMatrix;
	vector<int> temp = {0, 0, 0, 0, 0, 0, 0, 0};
	for(auto i: {0, 1, 2, 3, 4, 5, 6, 7})
	{
		queueMatrix.push_back(temp);
	}
	int count = 0;
	Queuen(queueMatrix, 0, count);
	cout << count << endl;
}
/*void Swap(vector<int>::iterator& a, vector<int>::iterator& b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Permutation(vector<int>& num, vector<int>::iterator it, int& count)
{
	if(num.empty())
	{
		return;
	}
	if(num.end() == it)
	{
		if(IsQualifier8Quen(num))
		{
			++count;
			for(auto x: num)
			{
				cout << x << "  ";
			}
			cout << endl;
		}
	}
	vector<int>::iterator itCur;
	for(itCur = it; itCur != num.end(); ++itCur)
	{
		Swap(itCur, it);
		Permutation(num, it + 1, count);
		Swap(itCur, it);
	}
}

bool IsQualifier8Quen(const vector<int>& num)
{
	vector<int>::const_iterator itOfi;
	vector<int>::const_iterator itOfj;
	for(itOfi = num.begin(); itOfi != num.end() - 1; ++itOfi)
	{
		for(itOfj = itOfi + 1; itOfj != num.end(); ++itOfj)
		{
			if(itOfi - itOfj == *itOfi - *itOfj || 
					itOfj - itOfi == *itOfi - *itOfj)
			{
				return false;
			}
		}
	}
	return true;
}

void Print8Queuen()
{
	vector<int> num;
	for(int x: {0, 1, 2, 3, 4, 5, 6, 7})
	{
		num.push_back(x);
	}
	int count = 0;
	Permutation(num, num.begin(), count);
	cout << "the count is: " << count << endl;
}

void Test(const string testName, vector<int>& num)
{
	cout << "********" << testName << "*******" << endl;
	//Permutation(num, num.begin(), );
}

void Test1()
{
	vector<int> num;
	Test("test for null", num);
	num.push_back(0);
	Test("test for 1 node", num);
	num.clear();
	num.push_back(0);
	num.push_back(1);
	num.push_back(2);
	Test("test for 3 node", num);
}*/
