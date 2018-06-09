#include<iostream>
#include<vector>

using namespace std;
/*bool hasPathCore(const vector<vector<char> >& vec, int rows, int cols, int row, int col, 
		const vector<char>& strvec, int& pathLength, vector<vector<bool> > visited)
{
	if(pathLength == strvec.size())
	{
		return true;
	}
	bool hasPath = false;
	if(row >= 0 && row < rows && col >= 0 && col < cols && vec[row][col] == strvec[pathLength] &&
			!visited[row][col])
	{
		++pathLength;
		visited[row][col] = true;
		hasPath = hasPathCore(vec, rows, cols, row, col - 1, strvec, pathLength, visited) ||
			hasPathCore(vec, rows, cols, row, col + 1, strvec, pathLength, visited) ||
			hasPathCore(vec, rows, cols, row -1, col, strvec, pathLength, visited) ||
			hasPathCore(vec, rows, cols, row + 1, col, strvec, pathLength, visited);
		if(!hasPath)
		{
			--pathLength;
			visited[row][col] = false;
		}
	}
	return hasPath;
}
bool HasPath(const vector<vector<char> >& vec, int rows, int cols, const vector<char>& strvec)
{
	if(vec.empty() || rows < 1 || cols < 1 || strvec.empty())
	{
		return false;
	}
	vector<vector<bool> > visited;
	vector<bool> temp;
	int i;
	for(i = 0; i < cols; ++i)
	{
		temp.push_back(false);
	}
	for(i = 0; i < rows; ++i)
	{
		visited.push_back(temp);
	}
	int pathLength = 0;
	int j;
	for(i = 0; i < rows; ++i)
	{
		for(j = 0; j < cols; ++j)
		{
			if(hasPathCore(vec, rows, cols, i, j, strvec, pathLength, visited))
			{
				return true;
			}
		}
	}
	return false;
}

void Test1()
{
	vector<vector<char> > vec;
	vector<char> str, temp;
	str.push_back('e');
	bool res = HasPath(vec, 0, 0, str);
	cout << "test1: " << res << endl;
	temp = {'a', 'b', 'c', 'd'};
	vec.push_back(temp);
	res = HasPath(vec, vec.size(), vec[0].size(), str);
	cout << "test1: 2:::" << res << endl;
}

void Test2()
{
	vector<vector<char> > vec;
	vector<char> str, temp;
	str = {'b', 'f', 'c', 'e', 'd'};
	temp = {'a', 'b', 't', 'g'};
	vec.push_back(temp);
	temp.clear();
	temp = {'c', 'f', 'c', 's'};
	vec.push_back(temp);
	temp.clear();
	temp = {'j', 'd', 'e', 'h'};
	vec.push_back(temp);
	temp.clear();
	bool res = HasPath(vec, vec.size(), vec[0].size(), str);
	cout << "test3 for bfce:" << res << endl;
}
int main()
{
	Test2();
	return 0;
}*/ 

#include<deque>
#include<iostream>
using namespace std;

int main()
{
	deque<deque<bool> > visited;
	deque<bool> temp;
	int rows = 3;
	int cols = 4;
	int i;
	for(i = 0; i < cols; ++i)
	{
		temp.push_back(false);
	}
	for(i = 0; i < rows; ++i)
	{
		visited.push_back(temp);
	}
	visited[1][1] = true;
	for(i = 0; i < rows; ++i)
	{
		for(int j = 0; j < cols; ++j)
		{
			cout << visited.at(i).at(j) << "  ";
		}
		cout << endl;
	}
	return 0;
}
