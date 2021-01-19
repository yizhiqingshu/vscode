#include<iostream>

using namespace std;//折半查找

int BinarySearch_I(int *a,const int x,const int n);
int BinarySearch_R(int *a,const int x,const int left,const int right);

int main(){
    int array[]={1,2,3,4,5,6,7,8,9,10,11};
    int result=BinarySearch_R(array,2,0,10);
    cout<<result<<endl;
    return 0;
}
int BinarySearch_I(int *a,const int x,const int n)
{
    int left=0,right=n-1;
    while(left<=right){
        int middle=(left+right)/2;
        if(x<a[middle]) right=middle-1;
        else if(x>a[middle]) left=middle+1;
        else return middle;

    }
    return -1;
}
int BinarySearch_R(int *a,const int x,const int left,const int right)
{
    if(left<=right)
    {
        int middle=(left+right)/2;
        if(x<a[middle]) return BinarySearch_R(a,x,left,middle-1);
        else if(x>a[middle]) return BinarySearch_R(a,x,middle+1,right);
        return middle;
    }
    return -1;
}