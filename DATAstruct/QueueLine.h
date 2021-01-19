#ifndef QUEUELINE_H
#define QUEUELINE_H


template<class T>
class Queue
{
public:
	Queue();
	~Queue();//!!!!!!���ڴ�ȫ����գ���ֹ�ڴ�й©������������

	bool isEmpty() const;
	const T& getFront() const;//�Ӷ���ȡ���ݣ���ɾ��
	void enqueue(const T& x);//���
	T dequeue();//����,ɾ������
	void makeEmpty();

private:
	struct ListNode//Queue��Ƕ�׵�һ���ṹ��,Ҳ��д����
	{
		T element;
		ListNode *next;

		ListNode(const T& theElement, ListNode *n = 0):element(theElement), next(n){}

	};

	ListNode *front;
	ListNode *back;
};


/******����ʵ��******/
/*******************/
/*******************/

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
		back = front = new ListNode(x);//ָ��Ĭ��Ϊ0
	else
		//1.
		//back->next = new ListNode(x);
		//back = back->next;

		//2. 
		back = back->next = new ListNode(x);//******Ϊʲô��1ʱ������Ժ����getfront�����������
}


template<class T>
T Queue<T>::dequeue()
{
	T frontItem = getFront();

	ListNode *old = front;
	front = front->next;

	delete old; //��Ӧ���ʱ��new
	return frontItem;
}

#endif
