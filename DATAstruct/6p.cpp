#include<iostream>
using namespace std;
long jiecheng(int n){
    if(n==0)
    return 1;
    else 
    return n*jiecheng(n-1);
}
long diedai(int n){
    int result=1;
    for(int i=n;i>0;i--)
    result=result*i;
    return result;
}
int main()
{
    cout<<jiecheng(5)<<endl;
    for(int num=0;num<10;num++){
    cout<<num<<"!="<<jiecheng(num)<<endl;
    cout<<num<<"!="<<diedai(num)<<endl;}
    return 0;
}