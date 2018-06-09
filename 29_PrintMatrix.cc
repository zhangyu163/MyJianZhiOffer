#include<iostream>
#include<vector>
#include<string>

using std::vector;
using std::endl;
using std::cout;
using std::string;

void PrintMatrixInCircle(const vector<vector<int> >& numbers, 
		const int rows, const int columns, const int start);

void PrintMatrixClockWisely(const vector<vector<int> >& numbers, 
		const int rows, const int columns);

void PrintMatrixOrigin(const vector<vector<int> >& numbers);
void Test(const string testName, const vector<vector<int> >& numbers, const int rows, const int columns);
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

void PrintMatrixInCircle(const vector<vector<int> >& numbers, 
		const int rows, const int columns, const int start)
{
	const int endColumn = columns - 1 - start;
	const int endRow = rows - 1 - start;
	int i;
	for(i = start; i <= endColumn; ++i)
	{
		cout << numbers[start][i] << "  ";
	}
	for(i = start + 1; i <= endRow; ++i)
	{
		cout << numbers[i][endColumn] << "  ";
	}
	if(endRow > start)
	{
		for(i = endColumn - 1; i >= start; --i)
		{
			cout << numbers[endRow][i] << "  ";
		}
	}
	if(start < endColumn)
	{
		for(i = endRow - 1; i > start; --i)
		{
			cout << numbers[i][start] << "  ";
		}
	}
	cout << endl << endl;
}

void PrintMatrixClockWisely(const vector<vector<int> >& numbers, 
		const int rows, const int columns)
{
	if(numbers.empty() || rows < 1 || columns < 1)
	{
		return;
	}
	int start = 0;
	while(start * 2 < rows && start * 2 < columns)
	{
		PrintMatrixInCircle(numbers, rows, columns, start);
		++start;
	}
}
void PrintMatrixOrigin(const vector<vector<int> >& numbers)
{
	if(numbers.empty())
	{
		return;
	}
	for(vector<int>  array: numbers)
	{
		for(int num: array)
		{
			cout << num << "\t";
		}
		cout << endl;
	}
}

void Test(const string testName, const vector<vector<int> >& numbers, const int rows, const int columns)
{
	cout << "********" << testName << endl;
	cout << "the original vecotr is: " << endl;
	PrintMatrixOrigin(numbers);
	cout << "after processing the vector is: " << endl;
	PrintMatrixClockWisely(numbers, rows, columns);
	cout << endl << endl;
}
void Test1()
{
	vector<vector<int> > numbers;
	Test("test1 for null matrix", numbers, numbers.size(), 0);
	vector<int> temp;
	temp.push_back(1);
	numbers.push_back(temp);
	Test("test1 for 1 elemnts", numbers, numbers.size(), numbers.front().size());

}

void Test2()
{
	vector<vector<int> > numbers;
	vector<int> temp;
	for(auto i: {1, 2, 3, 4, 5})
	{
		temp.push_back(i);
	}
	numbers.push_back(temp);
	Test("test2 for 1 row", numbers, numbers.size(), numbers.front().size());
	numbers.clear();
	temp.clear();
	for(auto i: {1, 2, 3, 4, 5})
	{
		temp.push_back(i);
		numbers.push_back(temp);
		temp.clear();
	}
	Test("test2 for 1 column", numbers, numbers.size(), numbers.front().size());
}

void Test3()
{
	vector<vector<int> > numbers;
	vector<int> temp;
	int count = 0;
	for(auto i: {1, 2, 3, 4})
	{
		for(auto x: {1, 2, 3, 4})
		{
			++count;
			temp.push_back(count);
		}
		numbers.push_back(temp);
		temp.clear();
	}
	Test("test3 for 4X4", numbers, numbers.size(), numbers.front().size());
	numbers.clear();
	
	count = 0;
	for(auto i: {1, 2, 3, 4, 5})
	{
		for(auto x: {1, 2, 3, 4, 5})
		{
			++count;
			temp.push_back(count);
		}
		numbers.push_back(temp);
		temp.clear();
	}
	Test("test3 for 5X5", numbers, numbers.size(), numbers.front().size());
	numbers.clear();
	
	count = 0;
	for(auto i: {1, 2, 3, 4, 5})
	{
		for(auto x: {1, 2, 3, 4, 5, 6})
		{
			++count;
			temp.push_back(count);
		}
		numbers.push_back(temp);
		temp.clear();
	}
	Test("test3 for 5X6", numbers, numbers.size(), numbers.front().size());
	numbers.clear();
	
	count = 0;
	for(auto i: {1, 2})
	{
		for(auto x: {1, 2, 3})
		{
			++count;
			temp.push_back(count);
		}
		numbers.push_back(temp);
		temp.clear();
	}
	Test("test3 for 2X3", numbers, numbers.size(), numbers.front().size());
	numbers.clear();

}
