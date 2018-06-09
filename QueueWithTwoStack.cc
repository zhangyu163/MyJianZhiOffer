#include<iostream>
#include<stack>

using std::cout;
using std::endl;
using std::stack;

template<typename T>
class CQueue
{
	public:
		void AppendTail(const T& node);
		T& DeleteHead();
	private:
		stack<T> stack1;
		stack<T> stack2;
};

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

template<typename T>
void CQueue<T>::AppendTail(const T& node)
{
	(this->stack1).push(node);
}

template<typename T>
T& CQueue<T>::DeleteHead()
{
	if((this->stack2).empty())
	{
		while(!stack1.empty())
		{
			T& temp = stack1.top();
			stack2.push(temp);
			stack1.pop();
		}
	}
	if(!stack2.empty())
	{
		T& temp = stack2.top();
		stack2.pop();
		cout << temp << endl;
		return temp;
	}else{
		cout << "the que is empty()" << endl;
	}
}

void Test1()
{
	CQueue<int> que;
	cout << "test1 for continuous delete and insert" << endl;
	que.AppendTail(1);
	que.AppendTail(2);
	que.AppendTail(3);
	que.AppendTail(4);
	que.AppendTail(5);
	que.DeleteHead();
	que.DeleteHead();
	que.DeleteHead();
	que.DeleteHead();
	que.DeleteHead();
	cout << "test1 for more another delete" << endl;
	que.DeleteHead();
}
void Test2()
{
	CQueue<int> que;
	cout << "test2 for no insert but to delete" << endl;
	que.DeleteHead();
	que.DeleteHead();
	que.DeleteHead();
}

void Test3()
{
	CQueue<int> que;
	cout << "test3 for cross insert and  delete" << endl;
	que.AppendTail(1);
	que.DeleteHead();
	que.AppendTail(2);
	que.AppendTail(3);
	que.DeleteHead();
	que.AppendTail(4);
	que.AppendTail(5);
	que.AppendTail(6);
	que.DeleteHead();
	que.DeleteHead();
}
