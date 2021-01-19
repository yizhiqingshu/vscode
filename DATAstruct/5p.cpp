#include<iostream>

using namespace std;
int BinarySearch(int *a,const int n,const int x);//二分查找
int BinSearch(int *a,const int n,const int x);
int main(){
    int x[]={1,2,3,4,5,6,7,8,9,10};
    int Result;
    Result=BinSearch(x,10,4);
    cout<<Result<<endl;
    return 0;
}
int BinSearch(int *a,const int n,const int x){
    int left=0,right=n-1;
    while(left<=right){
        int middle=(left+right)/2;
        if(x>a[middle]) left=middle+1;
        else if(x<a[middle]) right=middle-1;
        else return middle;
    }
    return -1;
}
int BinarySearch(int *a,const int n,const int x){
    int low,high,mid;
    low=0,high=n-1;
    while(low<=high){
        mid=(low+high)/2;
        if(a[mid]==x)
        return mid;
        else if(a[mid]<x)
         low =mid+1;
        else if(a[mid]>x)
        low=mid-1;
    
    }
    return -1;
}