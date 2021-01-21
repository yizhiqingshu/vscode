#include<iostream>
using std::cout;
using std::endl;
template<class T> class DbList;
template<class T>
class DbListNode
{
    friend class DbList<T>;
    public:
    DbListNode(){}
    DbListNode(T data):data(data){}
    T data;
    DbListNode *llink,*rlink;
};
template<class T>
class DbList
{
    public:
        DbList()
        {
        First = new DbListNode<T>;
        First->llink= First ->rlink=First;
        }
    void Insert(DbListNode<T>*L,DbListNode<T>*R);
    void Delete(DbListNode<T>* );
    DbListNode<T>* First;
};

template<class T>
void DbList<T>::Insert(DbListNode<T>*L,DbListNode<T>*R)
{
    L->llink = R;
    L->rlink = R->rlink;
    R->rlink ->llink = L;
    R->rlink = L;
}
template<class T>
void DbList<T>::Delete(DbListNode<T>* k)
{
    if(k==First)
    std::cerr<<"the first node is not permitted";
    else 
    {
        k->llink->rlink = k->rlink;
        k->rlink->llink = k->llink;
        delete k;
    }
}
int main()
{
    DbList<int> a;
    DbListNode<int> *b,*c,*d,*e;
    b = new DbListNode<int>(1);
    c = new DbListNode<int>(2);
    d = new DbListNode<int>(3);
    e = new DbListNode<int>(4);

    a.Insert(b,a.First);
    a.Insert(c,a.First);
    a.Insert(d,a.First);
    a.Insert(e,a.First);
    a.Delete(e);
    cout<<a.First->rlink->data<<endl;
    cout<<a.First->rlink->rlink->data<<endl;
    cout<<a.First->rlink->rlink->rlink->data<<endl;
    cout<<a.First->rlink->rlink->rlink->rlink->data<<endl;
    return 0;
}
