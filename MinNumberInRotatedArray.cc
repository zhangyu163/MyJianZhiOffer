#include<iostream>
#include<vector>

using namespace std;

int MinInOrder(vector<int>& vec);
int Min(vector<int>& vec)
{
	if(vec.empty())
	{
		throw exception();
	}
	int index1 = 0;
	int index2 = vec.size() - 1;
	int mid = index1;
	while(vec[index1] >= vec[index2])
	{
		if(index2 == index1 + 1)
		{
			mid = index2;
			break;
		}
		mid = (index1 + index2) >> 1;
		if(vec[mid] == vec[index1] && vec[mid] == vec[index2])
		{
			return MinInOrder(vec);
		}
		if(vec[mid] >= vec[index1])
		{
			index1 = mid;
		}else{
			index2 = mid;
		}
	}
	return vec[mid];
}

int MinInOrder(vector<int>& vec)
{

	int minValue = vec[0];
	int i;
	for(i = 1; i < vec.size(); ++i)
	{
		if(minValue > vec[i])
		{
			minValue = vec[i];
		}
	}
	return minValue;
}

int main()
{
	//ector<int> vec = {1, 1, 1, 1, 0, 1};
	vector<int> vec;
	cout << Min(vec) << endl;
	return 0;
}
