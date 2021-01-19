#ifndef LIST_H
#define LIST_H

#include <iostream>


template<class T> class List;
template<class T> class ListIterator;//*********������Ԫ��Ҫ����ǰ������

template<class T>
class ListNode
{
friend  class List<T>;
friend class ListIterator<T>;

private:
	T data;
	ListNode *link;
	ListNode(T element);//ֻ������Ԫ��������
};


template<class T>
class List
{
	friend class ListIterator<T>;
public:
	List(){ first = 0;}
	void Insert(T);
	void Delete(T);
	void Invert();
	void Concatenate(List<T>);
	void Show();//������
	

private:
	ListNode<T> *first;
};


template<class T>
class ListIterator
{
public:
	ListIterator(const List<T>& L):list(L), current(L.first){}  //*****��Ҫ����{}
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


/******���룺��ǰ��******/
template<class T>
void List<T>::Insert(T k)
{
	ListNode<T> *newnode = new ListNode<T>(k); //k�Ǵ���ڽڵ��������
	newnode->link = first;
	first = newnode;
}


template<class T>
void List<T>::Delete(T k)
{
	ListNode<T> *previous = 0;//��ɾ��ǰһ��
	ListNode<T> *current;
	for(current = first; current && current->data != k;)
	{
		previous =current;
		current = current->link;
	}
	if(current)//�ҵ���
	{
		if(previous)
			previous->link = current->link;
		else
			first = first->link;
		delete current;
	}
	else
		std::cout << "û�����ֵ" << std::endl;

}


template<class T>
void List<T>::Invert()
{
	ListNode<T> *p = first, *q = 0;
	while(p)
	{
		ListNode<T> *r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	first = q;
}


template<class T>
void List<T>::Concatenate(List<T> b)//b���ں���
{
	if(!first){ first = b.first; return;}
	if(b.first)
	{
		ListNode<T> *p;
		for(p=first; p->link; p=p->link) {;}//ѭ������Ϊ��
		p->link = b.first;
	}
}




//Show
template<class T>
void List<T>::Show()
{
	for(ListNode<T> *current = first; current; current=current->link)
	{
		std::cout<< current->data;
		if(current->link)
			std::cout<< " -> ";
	}
	std::cout<< std::endl;
}



template<class T>
bool ListIterator<T>::NotNull()
{
	if(current) 
		return true;
	else
		return false;
}


template<class T>
bool ListIterator<T> ::NextNotNull()
{
	if(current && current->link)
		return true;
	else
		return false;
}


template<class T>
T* ListIterator<T>::First()
{
	if(list.first)
		return &list.first->data;//****���ؽڵ������� ��ָ��
	else
		return 0;
}


template<class T>
T* ListIterator<T>::Next()
{
	if(current)
	{
		current = current->link;
		return &current->data;
	}
	return 0;
}


#endif