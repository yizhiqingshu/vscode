#include<iostream>

template<class T>
class Queue
{
public:
	Queue();
	~Queue();

	bool isEmpty() const;//判断队列是否为空
	const T& getFront() const;//返回队首元素
	void enqueue(const T& x);//插入元素到队首
	T dequeue();//删除队列的第一个元素
	void makeEmpty();//删除队列

private:
	struct ListNode
	{
		T element;
		ListNode *next;
		ListNode(const T& theElement, ListNode *n = 0):element(theElement), next(n){}
	};
	ListNode *front;//队首
	ListNode *back;//队尾
};


template<class T>
Queue<T>::Queue()
{
	front = back = 0;
}

template<class T>
Queue<T>::~Queue()
{
	makeEmpty();
}

template<class T>
void Queue<T>::makeEmpty()
{
	while(!isEmpty())
		dequeue();
}

template<class T>
bool Queue<T>::isEmpty() const
{
	return front == 0;
}


template<class T>
const T& Queue<T>::getFront() const
{
	if(isEmpty())
		throw "queue is empty.";
	return front->element;//返回队首元素
}

template<class T>
void Queue<T>::enqueue(const T& x)//向队首插入元素
{
	if(isEmpty())
		back = front = new ListNode(x);
	else
		back = back->next = new ListNode(x);
}

template<class T>
T Queue<T>::dequeue()//删除队首元素
{
	T frontItem = getFront();
	ListNode *old = front;
	front = front->next;
	delete old; 
	return frontItem;
}
int main()
{
    using std::cout;
    using std::endl;
    Queue<int> myQ;

	myQ.enqueue(10);
	myQ.enqueue(20);
	myQ.enqueue(30);

	cout<< myQ.getFront() << endl;
	myQ.dequeue();
	cout<< myQ.getFront() << endl;
	cout<< myQ.dequeue() << endl;
	cout<< myQ.getFront() << endl;
    return 0;
}
