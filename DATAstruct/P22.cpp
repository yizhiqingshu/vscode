#include <iostream>
#include <list>

using namespace std;

int maxdigit(int data[], int n)//�����������Ǽ�λ
{
	int d = 1;
	int p = 10;
	for(int i=0; i<n; ++i)
	{
		while(data[i] >= p)
		{
			p *= 10;
			++d;
		}
	}
	return d;
}


void radixsort(int data[], int n)
{
	int digits = maxdigit(data, n);
	list<int> lists[10];//����ʮ������
	int d, j, k, factor;
	for(d=1,factor=1; d<=digits; factor*=10,d++)
	{
		for(j=0; j<n; j++)//1.��������������Ƶ�������
		{
			///factor����ȡ��λ��ʮλ�ȣ�%10,ȡģ����ȥ����λ,Ȼ���data[j]�ŵ���Ӧ������
			lists[ (data[j]/factor) % 10].push_back(data[j]); 
		}
		for(j=k=0; j<10; j++)//2.��˳�������������ŵ�ԭ������
		{
			while(!lists[j].empty())//����������ʱ����һֱȡ
			{
				data[k++] = lists[j].front();//k++�����
				lists[j].pop_front();//ȥ���������Ҫɾ�������
			}
		}
		for(int m=0; m<10; m++)
			cout<< data[m] << " " ;
		cout<< endl;
	}
}

int main()
{
	cout<< "hello" <<endl;


	int data[10] = {179, 208, 306, 93, 859, 984, 55, 9, 271, 33};
	radixsort(data, 10);

	cout<< "�����" << endl;
	for(int i=0; i<10; i++)
		cout<< data[i] << " " ;

	cout<< endl;


	system("pause");
	return 0;
}