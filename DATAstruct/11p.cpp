#include<iostream>
#include<bits\stdc++.h>
using namespace std;

template<class T>
void MergeSortTemp(T *data, int start, int end, T *temp)
{
	int len = end - start + 1;
	int mid = (end - start) / 2 + start;
	if (len == 0) {
		return ;
	}
	if (len == 1) {
		return ;
	}
	MergeSortTemp(data, start, mid, temp);
	MergeSortTemp(data, mid + 1, end, temp);
	int i = start;
	int j = mid + 1;
	int k = 0;
	while(i <= mid && j <= end)
	{
		if(data[i] < data[j])
		{
			temp[k++] = data[j++];
		}else
		{
			temp[k++] = data[i++];
		}
	}
	while(i <= mid)
	{
		temp[k++] = data[i++];
	}
	while(j <= end)
	{
		temp[k++] = data[j++];
	}
	for(int i = 0; i < k; i++)
	{
		data[start + i] = temp[i];
	}
}
/*归并排序*/
template<class T>
void MergeSort(T *data, T len)
{
	T temp[len];
	MergeSortTemp(data, 0, len - 1, temp);
}

int main()
{
    int a[11]={1,5,12,24,31,23,25,6,7,8,9};
    int b[11]={};
    MergeSortTemp(a,0,10,b);
    for(int i=0;i<10;i++)
    cout<<b[i]<<endl;
    return 0;
}