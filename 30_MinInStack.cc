#include<iostream>
#include<stack>
#include<string>
#include<cassert>

using std::cout;
using std::endl;
using std::stack;
using std::string;

template<typename T>
class StackWithMin
{
	public:
		void pop();
		void push(const T& value);
		const T& min() const;
	private:
		stack<T> m_data;
		stack<T> m_min;
};

template<typename T>
void StackWithMin<T>::push(const T& value)
{
	if(m_data.empty() || value < m_min.top())
	{
		m_data.push(value);
		m_min.push(value);
	}else{
		m_data.push(value);
		m_min.push(m_min.top());
	}
}

template<typename T>
void StackWithMin<T>::pop()
{
	assert(m_data.size() > 0 && m_min.size() > 0);
	m_data.pop();
	m_min.pop();
}

template<typename T>
const T& StackWithMin<T>::min() const 
{
	return m_min.top();
}

void Test();

int main()
{
	Test();
	return 0;
}

void Test()
{
	cout << "test for stack is null" << endl;
	StackWithMin<int>* pstack = new StackWithMin<int>;
	//cout << pstack->min() << endl << endl;
	
	cout << "test for stack has one element" << endl;
	pstack->push(3);
	cout << pstack->min() << endl;
	pstack->pop();
	//cout << pstack->min() << endl << endl;

	cout << "test for stack has 4 element" << endl;
	pstack->push(3);
	pstack->push(4);
	pstack->push(2);
	pstack->push(1);
	cout << pstack->min() << endl;
	cout << pstack->min() << endl;
	pstack->pop();
	cout << pstack->min() << endl;
	//pstack->pop();
	pstack->pop();
	cout << pstack->min() << endl;
	pstack->pop();
	pstack->pop();
	pstack->pop();

}
