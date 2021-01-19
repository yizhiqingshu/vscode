#include<iostream>

using namespace std;
template<class T>
void QuickSort(T *a,const int left,const int right);
int main(){
    int x[] = {1, 4, 20, 6, 8, 3, 5, 10, 9, 2, 100};
    QuickSort(x, 0, 9);
    for (int i = 0; i < 10;i++)
        cout << x[i]<<endl;
        return 0;
}
template<class T>
void QuickSort(T *a,const int left,const int right){
    if(left<right){
        //选枢纽进行划分
        int i=left;
        int j=right+1;//
        int pivot=a[left];
    do{
    do i++;while(a[i]<pivot);
    do j--; while(a[j]>pivot);
    if(i<j) swap(a[i],a[j]);
}
    while(i<j);
    swap(a[left], a[j]);

    QuickSort(a, left, j - 1);
    QuickSort(a, j + 1, right);
    }
}