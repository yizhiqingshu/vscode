#include<iostream>
#include<algorithm>
using namespace std;
/*快速排序  
从左边找一个标签，比标签大的放右边，比标签小的放左边
*/
template <class T>
void QuickSort(T* a,const int left,const int right)
{
    if(left<right)//左边的小于右边的
    {
    int i=left;
    int j=right+1;
    int pivot=a[left];
    do{
        do i++; while (a[i]<pivot); 
        do j--; while (a[j]>pivot);
        if(i<j)swap(a[i],a[j]); //交换a[i]和a[j]
    }    
        while (i<j);
        swap(a[left],a[j]);
        QuickSort(a,left,j-1);
        QuickSort(a,j+1,right);
        
    }
}
//归并排序
template<class T>
void GUIbiSort(T* a,T* b,const int l,const int m,const int n)
{
    int i1,i2,iResult;
    for(i1 = l,i2 = m+1,iResult=l;i1<=m&&i2<=n;iResult++)
    {
        if(a[i1]<=a[i2])
        {
            b[iResult]=a[i1];
            i1++;
        }
        else 
        {
            b[iResult]=a[i2];
            i2++;
        }
    }
    copy(a+i1,a+m+1,b+iResult);
    copy(a+i2,a+n+1,b+iResult);
}
template<class T>
void GUIbinPass(T* a,T* b,const int n,const int s)//a输入数组，b输出数组，n 数据个数，s 归并次数
{
    int i;
    for(i=1;i<n-2*s+1;i+=2*s)
    GUIbiSort(a,b,i,i+s-1,i+2*s-1);
    if((i+s-1)<n)
    GUIbiSort(a,b,i,i+s-1,n);
    else 
    copy(a+i,a+n+1,b+i);    
}
template <class T>
void GUIbingSort(T* a ,const int n)
{
    T *tempList = new int [n+1];
    for(int i=1;i<n;i*=2)
    {
        GUIbinPass(a,tempList,n,i);
        i*=2;
        GUIbinPass(a,tempList,n,i);       
    }
    delete []tempList;
}
int main()
{
    int b[]={0,1,56,23,25,26,99,100,101,102,105};
    //QuickSort(b,0,9);
    GUIbingSort(b,10);
    int i=0;
    for(;i<10;i++)
    {
        cout<<b[i]<<endl;
    }
    return 0;
}

