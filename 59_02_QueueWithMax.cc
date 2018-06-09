#include<iostream>
#include<vector>
#include<deque>
#include<string>

using std::cout;
using std::endl;
using std::string;
using std::deque;
using std::vector;
using std::exception;


template<typename T>
class QueueWithMax
{
	public:

		QueueWithMax()
			: currentIndex(0)
		{

		}

		void push_back(T number)
		{
			InternalData temp = {number, currentIndex};
			while(!maximums.empty() && number >= maximums.back().number)
			{
				maximums.pop_back();
			}
			maximums.push_back(temp);
			data.push_back(temp);
			++currentIndex;
		}
		
		void pop_front()
		{
			if(data.empty())
			{
				throw exception();
			}
			if(maximums.front().index == data.front().index)
			{
				maximums.pop_front();
			}
			data.pop_front();
		}

		T max() const 
		{
			if(maximums.empty())
			{
				throw exception();
			}
			return maximums.front().number;
		}
	private:
		struct InternalData
		{
			T number;
			int index;
		};
		deque<InternalData> data;
		deque<InternalData> maximums;
		int currentIndex;
};

void Test1();

int main()
{
	Test1();
	
	return 0;
}

void Test1()
{
	QueueWithMax<int> que;
	//que.max();
	/*que.push_back(1);
	cout << que.max() << endl;
	que.push_back(-2);
	que.pop_front();
	cout << que.max() << endl;*/
	que.push_back(5);
	//que.pop_front();
	cout << que.max() << endl;
	que.push_back(-2);
	que.pop_front();
	cout << que.max() << endl;
	que.push_back(5);
	que.pop_front();
	cout << que.max() << endl;
	que.pop_front();
	que.push_back(3);
	cout << que.max() << endl;
}

