#include<iostream>
#include<list>
using std::list;
using std::cout;
using std::endl;
/*
 主要原理就是首先将个位排序，放入列表数组中（push_back），在将数据存入数组中 把列表中的数据初始化10个列表
 将十位作同样处理，放入列表中
 先遇到哪个数据把哪个数据放入对应的列表中
 Init data
  123 234 2 6 765 456 5 543 968 142 
  baseSort data
  2 142 123 543 234 765 5 6 456 968 
  2 5 6 123 234 142 543 456 765 968 
  2 5 6 123 142 234 456 543 765 968 
  2 5 6 123 142 234 456 543 765 968 

 */
int MAX_size(int *data,int n)
{
    int d = 1;//定义一个位数
    int p = 10;//
    for(int i=0; i<n; i++ )
    {
        while(data[i] >= p)
        {
            p *= 10;
            ++d;
        }
    }
    return d;
}
void baseSort(int data[],int n)
{
    int digits = MAX_size(data,n);
    list<int> lists[10];
    int d,j,k,factor;
    for(d=1,factor=1;d<=digits;factor*=10,d++)
    {
        for(j=0; j<n ;j++)
        {
            lists[(data[j]/factor)%10].push_back(data[j]);//分别取出个位、十位、百位的数据存入列表Lists中
        }
        for(j=k=0;j<10;j++)
        {
            while(!lists[j].empty())
            {
                data[k++] = lists[j].front();
                lists[j].pop_front();
            }
        }
        for(int m=0;m<10;m++)
        cout<<data[m]<<" ";
        cout<<endl;
    }
}
int main()
{
    int data[10] = {123,234,2,6,765,456,5,543,968,142};
    for(int i=0;i<10;i++)
        cout<<data[i]<<" ";
    cout<<"Init data"<<endl;
    cout<<"baseSort data"<<endl;
    baseSort(data,10);
    for(int i=0;i<10;i++)
        cout<< data[i]<<" ";
    cout<<endl;
    return 0;
}
