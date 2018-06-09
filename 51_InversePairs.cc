#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
#include<cstring>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::sort;
using std::stringstream;
using std::less;
using std::greater;
using std::memset;

int GuibingSort(int* a, int length);
int Merge(int* a, int start, int mid, int end, int* copy);
int GuibingSortCore(int* a, int start, int end, int* copy);

int main()
{
	int a[] = {1, 2, 1, 2, 1};
	int pairsCount = GuibingSort(a, sizeof(a) / sizeof(int));
	for(int x: a)
	{
		cout << x << "  ";
	}
	cout << endl;
	cout << "the pair count is:" << pairsCount << endl;
	return 0;
}

int GuibingSort(int* a, int length)
{
	if(nullptr == a || length <= 0)
	{
		return 0;
	}
	int start = 0;
	int end = length - 1;
	int* copy = new int[length];
	memset((char*)copy, 0, sizeof(int) * length);
	int count = GuibingSortCore(a, start, end, copy);
	delete[] copy;
	copy = nullptr;
	return count;
}

int Merge(int* a, int start, int mid, int end, int* copy)
{
	int i = mid;
	int j = end;
	int k = end;
	int count = 0;
	while(i >= start && j >= mid + 1)
	{
		if(a[i] > a[j])
		{
			count += (j - mid);
			copy[k--] = a[i--];
		}else{
			copy[k--] = a[j--];
		}
	}
	while(i >= start)
	{
		copy[k--] = a[i--];
	}
	while(j >= mid + 1)
	{
		copy[k--] = a[j--];
	}
	for(k = 0; k <= end; ++k)
	{
		a[k] = copy[k];
	}
	return count;
}
int GuibingSortCore(int* a, int start, int end, int* copy)
{
	if(start == end)
	{
		return 0;
	}
	int mid = ((end - start) >> 1) + start;
	int left = GuibingSortCore(a, start, mid, copy);
	int right = GuibingSortCore(a, mid + 1, end, copy);
	int zujian = Merge(a, start, mid, end, copy);
	return left + right + zujian;
}

