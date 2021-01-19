#include<iostream>
#include<string>
#include<list>
template <class T> class List;
template <class T> class ListIterator;
template<class T>
class ListNode
{
    friend class List<T>;
    friend class ListIterator<T>;
    private:
    T date;
    ListNode *link;
    ListNode (T);
};
template<class T>
ListNode<T>::ListNode(T element)
{
    date = element;
    link = 0;
}
template<class T>
class List
{
    public:
    friend class ListIterator<T>;
    List(){First = 0;}
    void Insert(T);
    void Show();
    void Delete(T k);
    void Invert();
    void Concatenate(List<T>);
    private:
    ListNode<T> * First;
};

template<class T>
void List<T>::Insert(T k)
{
    ListNode<T>* newNode = new ListNode<T>(k);
    newNode->link = First;
    First = newNode;
}
template<class T>
void List<T>::Delete(T k)
{
    ListNode<T> * previous = 0;
    ListNode<T> * current;
    for(current = First;current && current->date!= k;previous = current,current = current->link)
    ;
        if(current)
        {
            if(previous)previous ->link = current ->link;
            else First = First->link;
            delete current;
        }

}
template<class T>
void List<T>::Invert()
{
    ListNode<T> *p=First,*q=0;
    while (p)
    {
        ListNode<T>* r = q;q=p;
        p = p->link;
        q->link = r;
    }
    First = q;    
}
template<class T>
void List<T>::Concatenate(List<T> k)
{   
    if(!First){First = k.First; return ;}
    if(k.First)
    {
        ListNode<T>* p;
        for(p=First;p->link;p=p->link);
        p->link = k.First;
    }
}
template<class T>
void List<T>::Show()
{
    for(ListNode<T>*currentNode = First;currentNode;currentNode = currentNode->link)
    {
    std::cout<<currentNode->date;
    if(currentNode->link) std::cout<<"->";
    }
    std::cout<<std::endl;
}

template<class T>
class ListIterator
{
    public:
    ListIterator(const List<T>& i):list(i),current(i.First){};
    bool NotNull();
    bool NextNotNull();
    T * First();
    T * Next();

    private:
    const List<T> &list;
    ListNode<T> * current;
};
template<class T>
bool ListIterator<T>::NotNull()
{
    if(current)return true;
    else return false;
}
template<class T>
bool ListIterator<T>::NextNotNull()
{
    if(current && current ->link)return true;
    else return false;
}
template<class T>
T* ListIterator<T>::First()
{
    if(list.First) return &list.First->date;
    else return 0;
}
template<class T>
T* ListIterator<T>::Next()
{
    if(current){current= current->link;return &current->date;}
    else return 0;
}

int main()
{
    List<int> initList;
    initList.Insert(3);
    initList.Insert(4);
    initList.Show();
    initList.Invert();
    initList.Show();
    List<std::string> initList1,list2;
    initList1.Insert("chuan");
    list2.Insert("hello ");
    initList1.Concatenate(list2);
    initList1.Show();

    ListIterator<int> li(initList);
    if(li.NotNull())
    {
        std::cout<<*li.First();
        while (li.NextNotNull())
        {
            std::cout<<"->"<<*li.Next();
        }
        std::cout<<std::endl;
        
    }

    std::list<int> ListIntegers;
    ListIntegers.push_front(1);
    ListIntegers.push_front(2);
    ListIntegers.push_back(3);

    std::list<int>::iterator i = ListIntegers.begin();
    while (i!= ListIntegers.end() )
    {
        std::cout<<*i<<"->";
        ++i;
    }
    std::cout<<std::endl;
    

    return 0;
}

