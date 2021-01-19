#ifndef _BST_H
#define _BST_H

#include <iostream>

enum Boolean {FALSE, TRUE};

template<class T> class BST;


template<class T>
class Element//�ڵ��������
{
public:
	T key;
	//��Ӹ��������
};


template<class T>
class BstNode//���ڵ�
{
	friend class BST<T>;
public:
	Element<T> getdata(){return data;}
private:
	Element<T> data;
	BstNode* leftChild;
	BstNode* rightChild;
	void display(int i);
};


template<class T>
class BST
{
public:
	BST(BstNode<T> *init = 0){root = init;}
	//~BST();
	Boolean Insert(const Element<T>& x);//����,���ز����Ƿ�ɹ�
	BstNode<T>* Search(const Element<T>& x);//����x���ҵ����򷵻�ָ������ڵ��ָ�룬û�ҵ��ͷ��ؿ�ָ��
	BstNode<T>* Search(BstNode<T>*, const Element<T>&);//�ݹ�汾�Ĳ���
	BstNode<T>* IterSearch(const Element<T>&);//�����汾�Ĳ���
	//Ҫ����Delete
	//Ҫ����InOrder
	//      PreOrder
	//      PostOrder
	//      LevelOrder
	void display()
	{
		std::cout << "\n";
		if(root)
			root->display(1);//����BstNode��display���Ӹ��ڵ㿪ʼ��ʾ����
		else
			std::cout<<"����һ�ÿ���\n";
	}
private:
	BstNode<T>* root;
};


/******����ʵ�ֲ���******/
/***********************/
/***********************/

template<class T>
void BstNode<T>::display(int i)//��ʾ��ǰ�ڵ㼰�����������нڵ������
{
	std::cout<< "position: " << i << "  data.key= " << data.key << std::endl;
	if(leftChild)
		leftChild->display(2*i);
	if(rightChild)
		rightChild->display(2*i + 1);
}

template<class T>
Boolean BST<T>::Insert(const Element<T> &x)
{
	BstNode<T> *p = root;
	BstNode<T> *q = 0;//qָ��p�ĸ��ڵ�
	//insert֮ǰҪ�Ȳ���
	while(p)
	{
		q = p;
		if(x.key == p->data.key)
			return FALSE;//�����ظ���ʧ�ܣ�����FALSE
		if(x.key < p->data.key)
			p = p->leftChild;
		else if(x.key > p->data.key)
				p = p->rightChild;
	}
	//�ҵ���λ�þ���q
	p = new BstNode<T>;
	p->leftChild = p->rightChild =0;
	p->data = x;
	if(!root)
		root = p;
	else if(x.key < q->data.key)
		q->leftChild = p;
	else
		q->rightChild = p;
	return TRUE;
}


template<class T>
BstNode<T>* BST<T>::Search(const Element<T> &x)
{
	return Search(root, x);
}
   
template<class T>
BstNode<T>* BST<T>::Search(BstNode<T> *b, const Element<T> &x)//�ҵ�����һ��ָ��
{
	if(!b)
		return 0;
	if(x.key == b->data.key)
		return b;
	if(x.key < b->data.key)
		return Search(b->leftChild, x);
	// if(x.key > b->data.key)
	else
		return Search(b->rightChild, x);
}

template<class T>
BstNode<T>* BST<T>::IterSearch(const Element<T> &x)
{
	for(BstNode<T> *t = root; t; )
	{
		if(x.key == t->data.key)
			return t;
		if(x.key < t->data.key)
			t = t->leftChild;
		else if(x.key > t->data.key)
			t = t->rightChild;
	}
	return 0;
}






#endif