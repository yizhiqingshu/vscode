#include <iostream>
// #include "MaxHeap.h"

using namespace std;

template<class T>
class MaxHeap
{
public:
	MaxHeap(int mx = 10);
	virtual ~MaxHeap();

	bool IsEmpty();
	void Push(const T&);
	void Pop();
	const T& Top() const;
private:
	T* heapArray;
	int maxSize;
	int currentSize;

	void trickleUp(int index);//????
	void trickleDown(int index);//????
};


////////??????////////

/**************************
name: MaxHeap
description? ????
**************************/
template<class T>
MaxHeap<T>::MaxHeap(int mx = 10)
{
	if(mx<1)
		throw "max size must be >= 1.";
	maxSize = mx;
	currentSize = 0;
	heapArray = new T[maxSize];
}


/**************************
name: ~MaxHeap
description? ????
**************************/
template<class T>
MaxHeap<T>::~MaxHeap()
{
	delete[] heapArray;
}


/**************************
name: IsEmpty
description???????? 
**************************/
template<class T>
bool MaxHeap<T>::IsEmpty()
{
	return currentSize == 0;
}


/**************************
name: Push
description??? 
**************************/
template<class T>
void MaxHeap<T>::Push(const T& e)
{
	if(currentSize == maxSize)
		throw "MaxHeap is full.";
	heapArray[currentSize] = e;//?????????????????
	//????/????
	trickleUp(currentSize++);
}


/**************************
name: Pop
description?????????? 
**************************/
template<class T>
void MaxHeap<T>::Pop()
{
	heapArray[0] = heapArray[--currentSize];//currentSize???????????currentSize????
	trickleDown(0);
}


/**************************
name: Top
description?????
**************************/
template<class T>
const T& MaxHeap<T>::Top() const
{
	return heapArray[0];
}


/**************************
name: trickleUp
description? ????/??
**************************/
template<class T>
void MaxHeap<T>::trickleUp(int index)
{
	int parent = (index-1) / 2;
	T bottom = heapArray[index];//?????????????
	while(index>0  && heapArray[parent]<bottom)
	{
		heapArray[index] = heapArray[parent];
		index = parent;
		parent = (parent-1) / 2;
	}
	heapArray[index] = bottom;
}


/**************************
name: trickleDown
description? ????
**************************/
template<class T>
void MaxHeap<T>::trickleDown(int index)
{
	int largerChild;
	T top = heapArray[index];//?????????heapArray[index]
	while(index < currentSize/2)//???????????
	{
		int leftChild = 2*index + 1;
		int rightChild = leftChild + 1;
		if(rightChild<currentSize && heapArray[leftChild]<heapArray[rightChild]) 
			largerChild = rightChild;
		else
			largerChild = leftChild;

		if(top >= heapArray[largerChild])
			break;
		heapArray[index] = heapArray[largerChild];
		index = largerChild;
	}
	heapArray[index] =  top;
}



int main()
{
	

	MaxHeap<int> h(100);
	cout<< h.IsEmpty() << endl;

	h.Push(20);
	h.Push(30);
	h.Push(15);
	cout<< h.Top() << endl;
	h.Push(90);
	h.Push(35);
	cout<< h.Top() << endl;
	h.Pop();
	cout<< h.Top() << endl;
	h.Pop();
	cout<< h.Top() << endl;

	system("pause");
	return 0;
}