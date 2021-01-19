#include<iostream>
using namespace std;

void SelectSort(int *list,const int n);//选择排序
int main(){
    int a[]={1,2,45,21,22,3,6,78,12,9};
    SelectSort(a,10);
    for(int i=0;i<10;i++)
    cout<<a[i]<<endl;
    return 0;
}
void SelectSort(int *list,const int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(list[j]<list[min])
            min=j;
        }
        std::swap(list[min],list[i]);
    }
}