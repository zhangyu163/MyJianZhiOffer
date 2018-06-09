#include<iostream>
#include<deque>

using namespace std;

int GetDigitBitSum(const int& number);
bool Check(const int& threshold, const int& row, const int& col);
int MovingCountCore(const int& threshold, const int& rows, const int& cols, 
		int row, int col, deque<deque<bool> >& visited);
int MovingCount(const int& threshold, const int& rows, const int& cols);

void Test(const char* testName, const int& threshold, const int& rows, const int& cols,
		const int& expected);
void Test1();
void Test2();

int main()
{
	Test1();
	Test2();
	return 0;
}
int GetDigitBitSum(const int& number)
{
	int sum = 0;
	int num = number;
	while(num)
	{
		sum += num % 10;
		num /= 10;
	}
	return sum;
}

bool Check(const int& threshold, const int& row, const int& col)
{
	int x = row;
	int y = col;
	bool pass = false;
	if(GetDigitBitSum(x) + GetDigitBitSum(y) <= threshold)
	{
		pass = true;
	}
	return pass;
}

int MovingCountCore(const int& threshold, const int& rows, const int& cols, 
		int row, int col, deque<deque<bool> >& visited)
{
	int count = 0;
	if(row >= 0 && row < rows && col >= 0 && col < cols && Check(threshold, row, col) 
			&& !visited[row][col])
	{
		visited[row][col] = true;
		count = 1 +  MovingCountCore(threshold, rows, cols, row - 1, col, visited)
			+ MovingCountCore(threshold, rows, cols, row + 1, col, visited)
			+ MovingCountCore(threshold, rows, cols, row, col - 1, visited)
			+ MovingCountCore(threshold, rows, cols, row, col + 1, visited);
	}
	return count;
}

int MovingCount(const int& threshold, const int& rows, const int& cols)
{
	if(threshold < 0 || rows < 1 || cols < 1)
	{
		return 0;
	}
	int i;
	int count = 0;
	deque<deque<bool>> visited;
	deque<bool> tmp;
	for(i = 0; i < cols; ++i)
	{
		tmp.push_back(false);
	}
	for(i = 0; i < rows; ++i)
	{
		visited.push_back(tmp);
	}
	count = MovingCountCore(threshold, rows, cols, 0, 0, visited);
	return count;
}

void Test(const char* testName, const int& threshold, const int& rows, const int& cols,
		const int& expected)
{
	int res;
	cout << "******" << testName << "******" << endl;
	if(res = MovingCount(threshold, rows, cols), res == expected)
	{
		cout << "passed: the compute count is: ";
	}else{
		cout << "failed: the compute count is: ";
	}
	cout << res << endl;
}

void Test1()
{
	int threshold = -1;
	Test("test1 for the -1 threshold: ", threshold, 1, 1, 0);
	threshold = 0;
	Test("test1 for the 0 threshold: ", threshold, 2, 2, 1);
	threshold = 2;
	Test("test1 for the 2 threshold: ", threshold, 0, 0, 0);
	threshold = 2;
	Test("test1 for the 2-2 threshold: ", threshold, 1, 1, 1);
}

void Test2()
{
	int threshold = 15;
	Test("test2 for the 15 threshold: ", threshold, 20, 20, 359);
	threshold = 10;
	Test("test2 for the 10 threshold: ", threshold, 1, 100, 29);
	threshold = 10;
	Test("test2 for the 10 threshold: ", threshold, 1, 10, 10);

}
