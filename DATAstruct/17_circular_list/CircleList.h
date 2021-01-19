#ifndef CIRCLELIST_H
#define CIRCLELIST_H

#include <iostream>


template<class T> class List;
template<class T> class ListIterator;

template<class T>
class ListNode
{
friend  class List<T>;
friend class ListIterator<T>;

private:
	T data;
	ListNode *link;
	ListNode(T element);//ֻ������Ԫ�������� //�в����Ĺ��캯��
	ListNode(){}//�޲����Ĺ��캯��
};


template<class T>
class List
{
	friend class ListIterator<T>;
public:
	//List(){ first = 0;}
	List(){ first = new ListNode<T>; first->link = first; } //*******����ͷ�ṹ��
	void Insert(T);
	void Delete(T);
private:
	ListNode<T> *first;
};


template<class T>
class ListIterator
{
public:
	ListIterator(const List<T>& L):list(L), current(L.first->link){}  //******��Ҫ����{}
	bool NotNull();//��ǰ�ڵ��Ƿ��
	bool NextNotNull();//��ǰ�ڵ����һ�ڵ��Ƿ��
	T* First();
	T* Next();
private:
	const List<T> &list;
	ListNode<T>* current;

};

template<class T>
ListNode<T>::ListNode(T element)
{
	data = element;
	link = 0;
}


/******���룺�Ӻ���******/
template<class T>
void List<T>::Insert(T k)
{
	ListNode<T> *newnode = new ListNode<T>(k); //k�Ǵ���ڽڵ��������
	newnode->link = first->link;
	first->link = newnode;
}


template<class T>
void List<T>::Delete(T k)
{
	
	ListNode<T> *previous = first;
	ListNode<T> *current;
	for(current = first; (current!=first) && (current->data != k);)
	{
		previous =current;
		current = current->link;
	}
	if(current != first)
	{
		previous->link = current->link;
		delete current;
	}
	else
		std::cout << "û�����ֵ" << std::endl;

}



template<class T>
bool ListIterator<T>::NotNull()
{
	if(current != list.first) 
		return true;
	else
		return false;
}


template<class T>
bool ListIterator<T> ::NextNotNull()
{
	if(current->link != list.first)
		return true;
	else
		return false;
}


template<class T>
T* ListIterator<T>::First()
{
	if(current != list.first)
		return &current->data;//****���ؽڵ������� ��ָ��
	else
		return 0;
}


template<class T>
T* ListIterator<T>::Next()
{
	current = current->link;
	if(current == list.first)
		current = current->link;
	return &current->data;
}


#endif