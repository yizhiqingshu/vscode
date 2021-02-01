#include <iostream>

using namespace std;

template<class T>
class Heap
{
public:
    Heap(int mx=10);
    virtual ~Heap();

    bool IsEmpty();
    void Push(const T&);
    void Pop();
    const T& Top()const;

    void trickUp(int index);
    void trickDown(int index);
private:
    T* heapArray;
    int MAXsize;
    int currentSize;
};
template<class T>
Heap<T>::Heap(int mx)
{
    if(mx<1) throw "Heap is must be >=1";
    MAXsize = mx;
    currentSize = 0;
    heapArray = new T[MAXsize];

}
template<class T>
Heap<T>::~Heap()
{
    delete[] heapArray;
}
template<class T>
bool Heap<T>::IsEmpty()
{
    return currentSize == 0;
}
template<class T>
void Heap<T>::Push(const T& e)
{
    if(currentSize == MAXsize) throw "Heap is full";

    heapArray[currentSize] = e;
    trickUp(currentSize++);
}

template<class T>
void Heap<T>::Pop()
{
    heapArray[0] = heapArray[--currentSize];
    trickDown(0);
}
template<class T>
void Heap<T>::trickUp(int index)
{
    int parent = (index - 1)/2;
    T bottom = heapArray[index];
    while(index>0 && heapArray[parent]<bottom)
    {
        heapArray[index] = heapArray[parent];
        index = parent;
        parent = (parent-1)/2;
    }
    heapArray[index]=bottom;
}

template<class T>
void Heap<T>::trickDown(int index)
{
    int largeChild;
    T TOP = heapArray[index];
    while(index < currentSize/2)
    {
    int leftChild = 2*index + 1;
    int rightChild = leftChild + 1;
    if(rightChild < currentSize && heapArray[leftChild]<heapArray[rightChild])
    {
        largeChild = rightChild;
    }
    else largeChild = leftChild;
    if(TOP>=heapArray[largeChild])
        break;
    heapArray[index] = heapArray[largeChild];
    index = largeChild;
    }
    heapArray[index] = TOP;
}
template<class T>
const T& Heap<T>::Top()const
{
    return heapArray[0];
}
int main()
{
    Heap<int> a(100);
    int arr[]={17,1,23,42,52,3,2,98,100,321};
    for(int i=0;i<10;i++)
    {
        a.Push(arr[i]);
    }
    for(int i= 0;i<10;i++)
    {
        arr[i]=a.Top();
        a.Pop();
    }
    for(int i=0;i<10;i++)
    {
        std::cout<<arr[i]<<std::endl;
    }
    std::cout << "Hello world" << std::endl;
    return 0;
}

