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
    cirleListNode *link;//指向下一个节点
    cirleListNode(T element);//复制构造函数
    cirleListNode(){}//默认构造函数
};
template<typename T>
class cirleList
{
    friend class cirleListIterator<T>;
public:
    cirleList(){First = new cirleListNode<T>;First ->link=First;} //初始化
    void Insert(T);//插入函数
    void Delete(T);//删除函数
private:
    cirleListNode<T> *First;
};
template<typename T>
class cirleListIterator
{
    public:
        cirleListIterator(const cirleList<T>& L):list(L),current(L.First->link){}//循环列表迭代器
        bool NotNull();//判断当前节点是否为空
        bool NextNotnull();//判断下一个节点是否为空
        T* first();//输出列表首位的节点
        T* Next();//
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
    cirleListNode<T> * Previous = First; //新建两个节点，保存Current的前一个数据
    cirleListNode<T> *current;
    for(current = First;(current != First)&&(current->data != k);)
    {
        Previous = current;
        current = current->link;
    }
    if(current != First)//循环结束，判断当前节点是否为头节点
    {
        Previous ->link = current ->link;//当前节点的前一个节点的下一个节点指向当前节点的下一个节点
        delete current;//删除当前节点
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
    //测试数据
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
