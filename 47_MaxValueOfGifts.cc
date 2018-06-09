#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::max;

int GetMaxValueOfGifts_Solution1(const vector<vector<int> >& gift);
int GetMaxValueOfGifts_Solution2(const vector<vector<int> >& gift);
void Test(const string testName, const vector<vector<int> >& gift, const int expected);
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
	return 0;
}

int GetMaxValueOfGifts_Solution1(const vector<vector<int> > gift)
{
	if(gift.empty())
	{
		return 0;
	}
	vector<vector<int> > maxValue;
	vector<int> temp;
	for(auto i = gift[0].begin(); i != gift[0].end(); ++i)
	{
		temp.push_back(0);
	}
	for(auto i = 0; i < gift.size(); ++i)
	{
		maxValue.push_back(temp);
	}
	int left;
	int up;
	int i, j;
	for(i = 0; i < maxValue.size(); ++i)
	{
		for(j = 0; j < maxValue.front().size(); ++j)
		{
			left = 0;
			up = 0;
			if(i > 0)
			{
				up = maxValue[i - 1][j];
			}
			if(j > 0)
			{
				left = maxValue[i][j - 1];
			}
			maxValue[i][j] = max(left, up) + gift[i][j];
		}
	}
	int maxGiftValue = maxValue[i - 1][j - 1];
	return maxGiftValue;
}

int GetMaxValueOfGifts_Solution2(const vector<vector<int> >& gift)
{
	if(gift.empty())
	{
		return 0;
	}
	vector<int> maxValue;
	for(int x = 0; x <  gift.front().size(); ++x)
	{
		maxValue.push_back(0);
	}
	int i, j;
	int left;
	int up;
	for(i = 0; i < gift.size(); ++i)
	{
		for(j = 0; j < gift.front().size(); ++j)
		{
			left = 0;
			up = 0;
			if(i > 0)
			{
				up = maxValue[j];
			}
			if(j > 0)
			{
				left = maxValue[j - 1];
			}
			maxValue[j] = max(up, left) + gift[i][j];
		}
	}
	int maxGiftValue = maxValue[j - 1];
	return maxGiftValue;
}

void Test(const string testName, const vector<vector<int> >& gift, const int expected)
{
	cout << "*****" << testName << "****" << endl;
	int maxValue = GetMaxValueOfGifts_Solution2(gift);
	if(expected == maxValue)
	{
		cout << "passed!" << endl;
	}else{
		cout << "failed!" << endl;
	}
}

void Test1()
{
	vector<vector<int> > gift;
	Test("test1 for null:", gift, 0);
	vector<int> temp = {2};
	gift.push_back(temp);
	Test("test1 for only 1 element:", gift, 2);
}

void Test2()
{
	vector<vector<int> > gift;
	vector<int> temp;
	for(auto x: {1, 1, 1, 1, 1})
	{
		temp.push_back(x);
	}
	gift.push_back(temp);
	Test("test1 for 1 row:", gift, 5);
	
	vector<vector<int> > gift2;
	vector<int> temp2;
	temp2.push_back(1);
	for(auto x: {1, 1, 1, 1})
	{
		gift2.push_back(temp2);
	}
	Test("test1 for 1 column:", gift2, 4);
}

void Test3()
{
	vector<vector<int> > gift;
	vector<int> temp;
	for(auto x: {1, 1, 1, 1, 1})
	{
		temp.push_back(x);
	}
	gift.push_back(temp);
	gift.push_back(temp);
	Test("test1 for 2 row:", gift, 6);
}

void Test4()
{
	vector<vector<int> > gift;
	vector<int> temp;
	for(auto x: {1, 10, 3, 8})
	{
		temp.push_back(x);
	}
	gift.push_back(temp);
	temp.clear();
	for(auto x: {12, 2, 9, 6})
	{
		temp.push_back(x);
	}
	gift.push_back(temp);
	temp.clear();
	for(auto x: {5, 7, 4, 11})
	{
		temp.push_back(x);
	}
	gift.push_back(temp);
	temp.clear();
	
	for(auto x: {3, 7, 16, 5})
	{
		temp.push_back(x);
	}
	gift.push_back(temp);
	temp.clear();

	Test("test1 for 4X4:", gift, 53);
}

void Test5()
{
	vector<vector<int> > gift;
	vector<int> temp;
	for(auto x: {1, 2, 3})
	{
		temp.push_back(x);
	}
	gift.push_back(temp);
	temp.clear();
	for(auto x: {4, 5, 6})
	{
		temp.push_back(x);
	}
	gift.push_back(temp);
	temp.clear();
	for(auto x: {7, 8, 9})
	{
		temp.push_back(x);
	}
	gift.push_back(temp);
	temp.clear();
	Test("test1 for 4X4:", gift, 29);
}
