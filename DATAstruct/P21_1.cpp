#include <iostream>
#include <list>

using namespace std;

void PrintListContents(const list<int>& listInput);

int main()
{


	list<int> a;
	list<int> b;
	list<int>::iterator iter;

	a.push_front(4);
	a.push_front(3);
	a.push_front(2);
	a.push_front(1);
	a.push_back(5);

	b.push_back(100);
	b.push_back(200);
	b.push_back(300);
	b.push_back(400);
	b.push_back(500);

	PrintListContents(b);

	iter = a.begin();
	++iter;

	//a.insert(a.begin(), 10);//�ڿ�ͷ��ǰ�����10
	a.insert(iter, 10);
	++iter;
	a.insert(a.end(), 4, 20);//�ں�˲����ĸ�20

	a.insert(a.begin(), b.begin(), b.end());//��b���嵽a���a.begin()��ʼ

	a.insert(iter, b.begin(), b.end());//!!!!!!ͨ��������ʵ���м����!!!!!!
	a.insert(iter, ++b.begin(), --b.end());//���������Խ��в���


	PrintListContents(a);

	return 0;
}


void PrintListContents(const list<int>& listInput)
{
	std::list<int>::const_iterator iter;
	for(iter = listInput.begin(); iter!=listInput.end(); ++iter)
		cout<< *iter << endl;
}