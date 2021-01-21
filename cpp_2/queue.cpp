#include<iostream>

template<class T>
class Queue
{
public:
	Queue();
	~Queue();

	bool isEmpty() const;
	const T& getFront() const;
	void enqueue(const T& x);
	T dequeue();
	void makeEmpty();

private:
	struct ListNode
	{
		T element;
		ListNode *next;

		ListNode(const T& theElement, ListNode *n = 0):element(theElement), next(n){}

	};

	ListNode *front;
	ListNode *back;
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
	return front->element;
}


template<class T>
void Queue<T>::enqueue(const T& x)
{
	if(isEmpty())
		back = front = new ListNode(x);
	else
		//1.
		//back->next = new ListNode(x);
		//back = back->next;

		//2. 
		back = back->next = new ListNode(x);
}


template<class T>
T Queue<T>::dequeue()
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