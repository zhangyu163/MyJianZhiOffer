#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::greater;
using std::less;
using std::exception;

template<typename T>
class DynamicArray
{
	public:
	void Insert(T num)
	{
		int size = maxHeap.size() + minHeap.size();
		if(size & 0x1)
		{
			if(maxHeap.size() && num < maxHeap[0])
			{
				maxHeap.push_back(num);
				push_heap(maxHeap.begin(), maxHeap.end(), less<T>());
				num = maxHeap[0];
				pop_heap(maxHeap.begin(), maxHeap.end(), less<T>());
				maxHeap.pop_back();
			}
			minHeap.push_back(num);
			push_heap(minHeap.begin(), minHeap.end(), greater<T>());
		}else{
			if(minHeap.size() && num > minHeap[0])
			{
				minHeap.push_back(num);
				push_heap(minHeap.begin(), minHeap.end(), greater<T>());
				num = minHeap[0];
				pop_heap(minHeap.begin(), minHeap.end(), greater<T>());
				minHeap.pop_back();
			}
			maxHeap.push_back(num);
			push_heap(maxHeap.begin(), maxHeap.end(), less<T>());
		}
	}

	T GetMedian() const
	{
		if(minHeap.empty() && maxHeap.empty())
		{
			throw exception();
		}
		int size = minHeap.size() + maxHeap.size();
		if(size & 0x1)
		{
			return maxHeap[0];
		}else{
			return (minHeap[0] + maxHeap[0]) >> 1;
		}
	}
	private:
		vector<T> minHeap;
		vector<T> maxHeap;
};

template<typename T>
void Test(const string testName, const vector<T>& num, const int expected);
void Test1();

int main()
{
	Test1();
	return 0;
}

template<typename T>
void Test(const string testName, const vector<T>& num, const int expected)
{
	cout << "*******" << testName << "******" << endl;
	DynamicArray<T> arr;
	for(auto x: num)
	{
		arr.Insert(x);
	}
	int mediannum = arr.GetMedian();
	if(expected == mediannum)
	{
		cout << "passed!" << endl;
	}else{
		cout << "failed!" << endl;
	}
}
void Test1()
{
	vector<int> num;
	/*for(auto x: {2, 2, 1, 4, 3, 5, 0, 4})
	{
		num.push_back(x);
	}*/
	Test("test1 for 5nodes", num, 2);
}
