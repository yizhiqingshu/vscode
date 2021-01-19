#include<iostream>

using namespace std;

int SequentialSearch(int *a,const int n,const int x);//顺序查找
int main(){
    int a[]={1,2,4,5,34,24,67,6,7,8};
    cout<<SequentialSearch(a,10,2);
    
    return 0;
}
int SequentialSearch(int *a,const int n,const int x){
    int i;
    for(i=0;i<n;i++){
        if(a[i]==x)
        return i;
    }
    if(i==n)
    return -1;

}