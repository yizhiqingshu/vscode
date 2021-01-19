#include<iostream>
#include"13p.h"
using namespace std;
int main(){
    Queue <char> q(3);
    q.Push('a');
    q.Push('b');
    q.Push('c');
    cout<<q.Front()<<q.Rear()<<endl;
    q.Push('d');
    cout<<q.Front()<<q.Rear()<<endl;
    return 0;
}