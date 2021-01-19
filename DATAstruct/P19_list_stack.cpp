#include <iostream>
//#include "LinkedStack.h"

using namespace std;
template<class T> class LinkedStack;


template<class T> 
class ChainNode
{
	friend class LinkedStack<T>;
private:
	ChainNode(const T& theData, ChainNode *n = 0):data(theData), link(n){}
	T data;
	ChainNode<T> *link;
};


template<class T>
class LinkedStack
{
public:
	LinkedStack():top(0) {}
	~LinkedStack(){ MakeEmpty(); }
	bool IsEmpty() const;
	T& Top() const;
	void Push(const T& e);
	void Pop();


	void MakeEmpty();
private:
	ChainNode<T> *top;
};


/******????******/
/*******************/
/*******************/

template<class T>
void LinkedStack<T>::MakeEmpty()
{
	while(!IsEmpty())
		Pop();
}


template<class T>
bool LinkedStack<T>::IsEmpty() const
{
	return top == 0;
}


template<class T>
T& LinkedStack<T>::Top() const
{
	if(this-> IsEmpty())
		throw "stack is empty";
	return top->data;
}


template<class T>
void LinkedStack<T>::Push(const T &e)
{
	top = new ChainNode<T>(e, top);
}


template<class T>
void LinkedStack<T>::Pop()
{
	if(this->IsEmpty())
		throw "stack is empty. cannot delete.";
	ChainNode<T> *delNode = top;
	top = top->link;
	delete delNode;   //?????new
}

int main()
{
	// cout << "������ʽջ������ " << endl;

	LinkedStack<int> s;
	s.Push(10);
	cout<< s.Top() << endl;
	s.Push(20);
	s.Push(30);


	s.Pop();
	cout<< s.Top() << endl;
	return 0;
}