#include<iostream>
using namespace std;

void BubbleSort(int list[],int n);//冒泡排序
int main(){
    int a[]={2,5,8,9,4,1,20,15,6,9};
    BubbleSort(a,10);
    for(int k=0;k<10;k++)
    cout<<a[k]<<" ";
    return 0;
}
void BubbleSort(int list[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++)
        if(list[j]>list[j+1])
        std::swap(list[j],list[j+1]);
    }
}