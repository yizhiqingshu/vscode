#include <iostream>
#include <list>

using namespace std;

void PrintListContents(const list<int>& listInput);

int main()
{
	list<int> a;

	a.push_front(4);
	a.push_front(3);

	list<int>::iterator iElementValueTwo;

	//iElementValueTwo = a.push_front(2); //�����������Ϊpushû�з���ֵ,��insert
	iElementValueTwo = a.insert(a.begin(), 2);
	a.push_front(1);
	a.push_front(0);

	PrintListContents(a);
	cout<< endl;

	//a.erase(iElementValueTwo);
	a.erase(a.begin(), iElementValueTwo);//ǰ�պ󿪣���a.begin()��iElementValueTwo֮���Ԫ�ض��ᱻɾ��
	PrintListContents(a);

	a.erase(iElementValueTwo, a.end());//�����ȫɾ��
	PrintListContents(a);

	return 0;
}

void PrintListContents(const list<int>& listInput)
{
	cout<< endl;
	cout<< "{ ";
	list<int>::const_iterator iter;
	for(iter=listInput.begin(); iter!=listInput.end(); ++iter)
		cout<< *iter << " ";
	cout<< "}" << endl;
}