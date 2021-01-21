#include<iostream>
using std::cout;
using std::endl;
template<typename T>class cirleList;
template<typename T>class cirleListIterator;
template<typename T>
class cirleListNode
{
    friend class cirleList<T>;
    friend class cirleListIterator<T>;
private:
    T data;
    cirleListNode *link;
    cirleListNode(T element);
    cirleListNode(){}
};
template<typename T>
class cirleList
{
    friend class cirleListIterator<T>;
public:
   // cirleList():First(new cirleListNode<T>),First(First->link){}
   cirleList(){First = new cirleListNode<T>;First->link=First;}
    void Insert(T);
    void Delete(T);
private:
    cirleListNode<T> *First;
};
template<typename T>
class cirleListIterator
{
    public:
        cirleListIterator(const cirleList<T>& L):list(L),current(L.First->link){}
        bool NotNull();
        bool NextNotnull();
        T* first();
        T* Next();
    private:
        const cirleList<T>& list;
        cirleListNode<T>* current;
};
template<typename T>
cirleListNode<T>::cirleListNode(T element)
{
    data = element;
    link = 0;
}
template<typename T>
void cirleList<T>::Insert(T k)
{
    cirleListNode<T>* newNode = new cirleListNode<T>(k);
    newNode ->link = First ->link;
    First ->link = newNode;
}
template<typename T>
void cirleList<T>::Delete(T k)
{
    cirleListNode<T> * Previous = First;
    cirleListNode<T> *current;
    for(current = First;(current != First)&&(current->data != k);)
    {
        Previous = current;
        current = current->link;
    }
    if(current != First)
    {
        Previous ->link = current ->link;
        delete current;
    }
}
template<typename T>
bool cirleListIterator<T>::NotNull()
{
    if(current != list.First)
        return true;
    else return false;
}
template<typename T>
bool cirleListIterator<T>::NextNotnull()
{
    if(current->link != list.First)
        return true;
    else return false;
}
template<typename T>
T* cirleListIterator<T>::first()
{
    if(current != list.First)
        return &current->data;
    else return 0;
}
template<typename T>
T* cirleListIterator<T>::Next()
{
    current = current ->link;
    if(current == list.First)
        current = current->link;
    return &current->data;
}
int main()
{
    cout<<"hello world"<<endl;
    cirleList<int> a;
    a.Insert(1);
    a.Insert(2);
    a.Insert(3);

    cirleListIterator<int> iter(a);
    cout<< *iter.first() << endl;
	cout<< *iter.Next() << endl;
	cout<< *iter.Next() << endl;
	cout<< *iter.Next() << endl;
	cout<< *iter.Next() << endl;
	cout<< *iter.Next() << endl;
	cout<< *iter.Next() << endl;
	cout<< *iter.Next() << endl;
	cout<< *iter.Next() << endl;
	cout<< *iter.Next() << endl;
	cout<< *iter.Next() << endl;
	cout<< *iter.Next() << endl;
    return 0;
}
