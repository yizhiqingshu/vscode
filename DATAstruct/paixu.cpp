#include <ctime>
#include <string>
#include <cstdlib>
#include <queue>
#include <pthread.h>
#include <csignal>
#include <windows.h>
#include <iostream>

using namespace std;

template<class T>
void Swap(T &a, T &b)
{
	T t = a;
	a = b;
	b = t;
}

/*冒泡排序*/
void BriSort(int data[], int len)
{
	bool flag = false;//实测加标志变量对于随机数排序时间变多了，对于交换变量是很多内容的结构体时加标志变量会缩短时间

	for(int i = 0; i < len - 1; i++)
	{
		flag = false;
		for(int j = 0; j < len - i - 1; j++)
		{
			if(data[j] < data[j + 1])
			{
				swap(data[j], data[j + 1]);
				flag = true;
			}
		}
		if(flag == false)//没有交换一次数据说明已经有序了
		{
			break;
		}
	}
}

/*插入排序*/
void InsertSort(int data[],int len)
{
	int begin = 1;
	int i = 0;
	while(begin < len)
	{
		int key = data[begin];//要插入的数据 [0:begin-1]的数据已经有序
		for(i = begin - 1; i >= 0; i--)
		{
			if(key <= data[i])//降序 找到要插入的位置
			{
				data[i + 1] = key;
				break;
			}
			data[i + 1] = data[i];//后移动一位
		}
		if(i < 0)//要插入的位置位最前面及数据比之前的数都大
			data[0] = key;
		begin++;
	}
}

/*选择排序*/
void selectionSort(int data[], int len)
{
	for(int i = 0; i < len; i++)
	{
		int max = i;//存放数组[i:len-1]中最大值的位置
		for(int j = i; j < len; j++)
		{
			if(data[j] > data[max])/*查找[i:len-1]最大值的坐标*/
			{
				max = j;
			}
		}
		swap(data[i], data[max]);//把[i:len-1]中最大值与data[i]交换
	}
}

/*希尔排序*/
void shellSort(int data[], int len)
{
	for(int gap = len/2; gap > 0; gap /= 2)//增量
	{
		for(int i = 0; i < gap; i++)/*i组 [i:len-i]增量gap进行插入排序*/
		{
			int begin = i + gap;//要插入的元素的位置
			while(begin < len - i)
			{
				int j = 0;
				int key = data[begin];
				for(j = begin - gap; j >= i; j -= gap)
				{
					if(key <= data[j])//满足插入条件
					{
						data[j + gap] = key;
						break;
					}
					data[j + gap] = data[j];//元素向后移动gap位
				}
				if(j < i)
					data[i] = key;
				begin += gap;
			}
		}
	}
}

/*归并排序*/
template<class T>
void MergeSortTemp(T data[], int start, int end, T temp[])
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

template<class T>
void MergeSort(T data[], T len)
{
	T temp[len];
	MergeSortTemp(data, 0, len - 1, temp);
}

/*堆排序*/
void adjustHeap(int * arrs, int p, int len){
    int curParent = arrs[p]; //父亲节点
    int child = 2 * p + 1;   //左孩子
    while(child < len){      //没有孩子
        if(child + 1 < len && arrs[child] < arrs[child+1]){//有右孩子并且右孩子值大于左孩子
            child++;    //较大孩子的下标
        }
        if(curParent < arrs[child]){
            arrs[p]=arrs[child];
            //没有将curParent赋值给孩子是因为还要迭代子树，
            //如果其孩子中有大的，会上移，curParent还要继续下移。
            p=child;
            child=2*p+1;
        }
        else
            break;
    }
    arrs[p]=curParent;
}

void heapSort(int * arrs, int len){
    //建立堆，从最底层的父节点开始
    for(int i = len/2 -1; i>=0; i--)
        adjustHeap(arrs, i, len);
    for(int i = len -1; i>=0; i--){
        int maxEle = arrs[0];
        arrs[0] = arrs[i];
        arrs[i] = maxEle;

        adjustHeap(arrs, 0, i);
    }
}

/*快速排序*/
template<class T>
void speedSortTemp(T data[], int start, int end)
{
	if(start >= end)
	{
		return ;
	}
	int i = start, j = end, x = data[start];
	while(i < j)
	{
		while(i < j && data[j] <= x)// 从右向左找第一个大于x的数
		{
			j--;
		}

		if(i < j)//找到了
		{
			data[i++] = data[j];
		}

		while(i < j && data[i] >= x )// 从左向右找第一个小于x的数
		{
			i++;
		}
		if(i < j)//找到了
		{
			data[j--] = data[i];
		}
	}
	data[i] = x;
	speedSortTemp(data, start, i - 1);
	speedSortTemp(data, i + 1, end);
}

template<class T>
void speedSort(T data[], int len)
{
	speedSortTemp(data, 0, len - 1);
}

#define MAX 20//数组大小
#define PRINT//打印排序前与排序后 宏
int main(void)
{
	time_t c_end, c_start;
	int data[MAX];
	int len = 0;
	/*数组随机数赋值*/
	srand((unsigned)time(NULL));
	for(int i = 0; i < MAX; i++)
	{
		data[i] = rand()%100;
	}
	len = sizeof(data) / sizeof(data[0]);

#ifdef PRINT
	for(int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
#endif

	c_start = clock();
	//BriSort(data, len);//冒泡排序 num:20000 time:1496ms O(n^2)
	//selectionSort(data, len);//选择排序 num:20000 time:557ms O(n^2)
	//InsertSort(data, len);//插入排序 num:20000 time:300ms O(n^2)

	//speedSort(data, len);//快速排序 num:20000 * 10 time:449ms O(n^logn)
	//MergeSort(data, len);//归并排序 num:20000 * 10 time:60ms O(n^Logn)
	//heapSort(data, len);//堆排序    num:20000 * 10 time:44ms O(n^logn)
	shellSort(data, len);//希尔排序 num:20000 * 10 time:35ms/50ms O(n^logn)
	c_end =clock();
	cout << difftime(c_end, c_start) << endl;//打印排序所需时间

#ifdef PRINT
	for(int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
#endif
	
	return 0;
}

