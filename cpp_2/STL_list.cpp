#include<iostream>
#include<list>
using std::list;
using std::cout;
using std::endl;
void PrintList(const list<int> &Out)
{
    list<int>::const_iterator iter;
    for(iter=Out.begin();iter != Out.end();++iter)
    {
        cout<<*iter<<endl;
    }
}

int main()
{
    list<int> a,b;
    a.push_front(1);
    a.push_front(2);
    PrintList(a);
    b.insert(b.begin(),5,10);
    list<int>::iterator iter = a.begin();
    a.insert(iter,4);
    a.insert(a.end(),4,5);
    a.insert(a.begin(),b.begin(),b.end());
    PrintList(a);
    PrintList(b);
    return 0;
}