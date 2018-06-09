#include<queue>
#include<iostream>

using std::cout;
using std::endl;
using std::queue;

template<typename T> 
class CStack
{
	public:
		CStack()
		{

		}
		CStack(const CStack& stack1)
		{

		}
		~CStack()
		{

		}
		void append(const T& data);
		T deleteTail(int i);
	private:
		queue<T> queue1;
		queue<T> queue2;
};

template<typename T>
void CStack<T>::append(const T& data)
{
	queue1.push(data);
}

template<typename T>
T CStack<T>::deleteTail(int i)
{
	cout << i << endl;
	while(queue1.size() > 1)
	{
		T& temp = queue1.front();
		queue1.pop();
		queue2.push(temp);
	}
	if(1 == queue1.size())
	{
		T& temp = queue1.front();
		queue1.pop();
		while(!queue2.empty())
		{
			T& temp2 = queue2.front();
			queue1.push(temp2);
			queue2.pop();
		}
		return temp;
	}else{
		return 0;
	}

}

void Test1()
{
	CStack<int> cs;
	cs.append(1);
	cs.append(2);
	cs.append(3);
	cout << cs.deleteTail(1) << "    " << cs.deleteTail(2) << "   ****  "
		<< cs.deleteTail(3) << endl;
	//cout << cs.deleteTail() << endl;
	//cout << cs.deleteTail() << endl;
}


int main()
{
	Test1();
	return 0;
}
