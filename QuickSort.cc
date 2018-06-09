#include<iostream>
#include<vector>

using namespace std;

int Partion(vector<int>& a, int low, int high)
{
	int k = high;
	int mid = a[low];
	int i;
	for(i = high; i > low; --i)
	{
		if(a[i] > mid)
		{
			if(i == k)
			{
				--k;
				continue;
			}
			int temp = a[i];
			a[i] = a[k];
			a[k] = temp;
			--k;
		}
	}
	int tmp = a[low];
	a[low] = a[k];
	a[k] = tmp;
	for(i = 0; i< a.size(); ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return k;
}

void QuickSort(vector<int>& vec, int low, int high)
{
	if(vec.empty() || low < 0 || high < low)
	{
		return;
	}
	if(low == high)
	{
		return;
	}
	int pivot = Partion(vec, low, high);
	QuickSort(vec, low, pivot - 1);
	QuickSort(vec, pivot + 1, high);

}

int main()
{
	vector<int> vec= {9, 1, 8 , 3, 7, 2, 4, 5};
	QuickSort(vec, 0, vec.size() - 1);
	int i;
	for(i = 0; i< vec.size(); ++i)
	{
		cout << vec[i] << endl;
	}
	return 0;
}
