#include<iostream>
#include<vector>
#include<set>

/*using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::multiset;*/
using namespace std;

typedef vector<int>::iterator iterator;
typedef multiset<int, greater<int> >::iterator iteratorOfMultiset;

//iterator Partion(vector<int>& num, iterator start, iterator end);
//void FindKLeastNumbers(vector<int>& num, vector<int>& output, const int k);
void FindKLeastNumbers_Volume(vector<int>& num, vector<int>& output, const int k);
void Test(const string testName, vector<int>& num);
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

/*iterator Partion(vector<int>& num, iterator start, iterator end)
{
	if(start == end)
	{
		return start;
	}
	--end;
	int base = *start;
	while(start < end)
	{
		while(start < end && *end >= base)
		{
			--end;
		}
		*start = *end;
		while(start < end && *start <= base)
		{
			++start;
		}
		*end = *start;
	}
	*start = base;
	return start;
}*/

/*void FindKLeastNumbers(vector<int>& num, vector<int>& ouput, const int k)
{
	if(num.empty() || k <= 0 || k > num.size())
	{
		return;
	}
	iterator start = num.begin();
	iterator end = num.end();

	iterator itOfpivot = Partion(num, start, end);
	int pivot = itOfpivot - num.begin();
	while(pivot != k - 1)
	{
		if(pivot < k - 1)
		{
			start = itOfpivot + 1;
			itOfpivot = Partion(num, start, end);
		}else{
			end = itOfpivot;
			itOfpivot = Partion(num, start, end);
		}
		pivot = itOfpivot - num.begin();
	}
	for(iterator it = num.begin(); it <= itOfpivot; ++it)
	{
		ouput.push_back(*it);
	}
}*/

void FindKLeastNumbers_Volume(vector<int>& num, vector<int>& output, const int k)
{
	if(num.empty() || k <= 0 || k > num.size())
	{
		return;
	}
	multiset<int, greater<int> > leastNumbersSet;
	leastNumbersSet.clear();
	for(auto x: num)
	{
		if(leastNumbersSet.size() < k)
		{
			leastNumbersSet.insert(x);
		}else{
			iteratorOfMultiset itMaxofSet = leastNumbersSet.begin();
			if(*itMaxofSet > x)
			{
				leastNumbersSet.erase(itMaxofSet);
				leastNumbersSet.insert(x);
			}
		}
	}
	for(auto x: leastNumbersSet)
	{
		output.push_back(x);
	}
}

void Test(const string testName, vector<int>& num, const int k)
{
	cout << "*****" << testName << "******" << endl;
	for(auto x: num)
	{
		cout << "\t" << x;
	}
	cout << endl;
	vector<int> output;
	FindKLeastNumbers_Volume(num, output, k);
	cout << "the k least is : ";
	for(auto x: output)
	{
		cout << "\t" << x;
	}
	cout << endl;
}
void Test1()
{
	vector<int> num;
	Test("test1 for null", num, 1);
	num.push_back(1);
	Test("test1 for 1 node", num, 1);
	num.clear();
	num.push_back(1);
	num.push_back(2);
	Test("test1 for 2 node", num, 2);
}
void Test2()
{
	vector<int> num;
	for(auto x: {4, 5, 1, 6, 2, 7, 3, 2})
	{
		num.push_back(x);
	}
	Test("test1 for 8 node", num, 4);
}
void Test3()
{
	vector<int> num;
	for(auto x: {4, 5, 1, 6, 2, 7, 3, 8})
	{
		num.push_back(x);
	}
	Test("test1 for 8 node", num, 7);
}
