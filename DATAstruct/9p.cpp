#include<iostream>
using namespace std;
template<class T>
void InsertionSort(T *list,int n);
int main(){
    int x[]={1,3,5,7,9,2,4,6,8,10};
    InsertionSort(x,10);
    for(int i=0;i<10;i++)
    cout<<*(x+i);
    return 0;
}
template<class T>
void InsertionSort(T *list,int n){
    int in,out;
    //out=0已经出去
    for(out=1;out<n;++out){

        int temp=list[out];
        in=out;
        while(in>0&&list[in-1]>=temp){
            list[in]=list[in-1];
            --in;
        }
        list[in]=temp;
    }
}
