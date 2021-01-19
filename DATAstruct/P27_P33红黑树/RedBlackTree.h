#ifndef RED_BLACK_TREE_H_
#define RED_BLACK_TREE_H_

#include "Except.h"
#include "Wrapper.h"

template<class T>
class RedBlackTree;

template<class T>
class RedBlackNode;



template<class T>
class RedBlackTree
{
public:
	RedBlackTree(const T& nefInf);//���캯��
	~RedBlackTree();

	Cref<T> find(const T& x) const;
	Cref<T> findMin() const;
	Cref<T> findMax() const;
	bool isEmpty() const;
	void makeEmpty();

	enum {RED, BLACK};

	void insert(const T& x);//����

	typedef RedBlackNode<T> Node;//��һ����һ�������Node����RedBlackNode<T>
//private:
public://Ϊ�˲��ԣ���ʱ�ĳ�public
	Node *header;
	Node *nullNode;

	Node *current;
	Node *parent;//���ڵ�
	Node *grand;//�游�ڵ�
	Node *great;//���游�ڵ�

	void reclaimMemory(Node* t) const;//�ӽڵ�t��ʼ��ɾ����������н�㣬�ʺ��õݹ�

	void rotateWithLeftChild(Node* &k2) const;//������������ת,k2�ǻ�׼
	void rotateWithRightChild(Node* &k1) const;//�����Һ�������ת��k1�ǻ�׼
	
	void doubleRotateWithLeftChild(Node* &k3) const;//˫��ת�����մ�����������ת
	void doubleRotateWithRightChild(Node* &k1) const;//˫��ת�����մ����Һ�������ת

	void handleReorient(const T& item);//���µ�����1.�������ӽڵ㶼�Ǻ�ɫʱ 2.�²���Ľڵ�ĸ��ڵ��Ǻ�ɫʱ
	RedBlackNode<T>* rotate(const T& item, Node* theParent) const;//ͨ����ת����


};


template<class T>
class RedBlackNode
{
//private:
public://Ϊ�˲��ԣ���ʱ�ĳ�public
	friend class RedBlackTree<T>;
	T element;
	RedBlackNode *left;
	RedBlackNode *right;
	int color;

	RedBlackNode(const T& theElement = T(), RedBlackNode *lt = NULL, RedBlackNode *rt = NULL, int c = RedBlackTree<T>::BLACK)
		:element(theElement), left(lt), right(rt), color(c){}//���캯��
};


///////////����ʵ�ֲ���///////////

/********************************************
name: RedBlackTree
description: ���캯��
********************************************/
template<class T>
RedBlackTree<T>::RedBlackTree(const T& nefInf)
{
	nullNode = new Node();
	nullNode->left = nullNode->right = nullNode;
	header = new Node(nefInf);
	header->left = header->right = nullNode;
}


/********************************************
name: ~RedBlackTree
description: ��������
********************************************/
template<class T>
RedBlackTree<T>::~RedBlackTree()
{
	makeEmpty();
	delete nullNode;
	delete header;
}


/********************************************
name: insert
description: ����
********************************************/
template<class T>
void RedBlackTree<T>::insert(const T& x)
{
	current = parent = grand = header;
	nullNode->element = x;

	while(current->element != x)
	{
		great = grand;
		grand = parent;
		parent = current;
		//current = x < current->element ? current->left : current->right; //��ʦ�õ�
		//(current=x) < (current->element) ? (current=current->left) : (current=current->right);
		current = ( x<current->element ? current->left : current->right);
		
		//�����ǰ�ڵ�������������ӽڵ㶼�Ǻ�ɫ�ģ�
		if(current->left->color == RED && current->right->color == RED)
			handleReorient(x);
	}

	if(current != nullNode)
		throw DuplicateItemException();

	current = new Node(x, nullNode, nullNode);

	if(x < parent->element)
		parent->left = current;
	else if(x > parent->element)
		parent->right = current;
	//�Զ�ƽ�� -> �����  
	////////�ص�////////
	handleReorient(x);
}


/********************************************
name: rotateWithLeftChild
description: ������������ת
********************************************/
template<class T>
void RedBlackTree<T>::rotateWithLeftChild(Node* &k2) const
{
	Node *k1 = k2->left;
	k2->left = k1->right;//�ƶ��ڲ�����
	k1->right = k2;
	k2 = k1;//��k1��ת��������,k1�����k2��λ��
}


/********************************************
name: rotateWithRightChild
description: �����Һ�������ת
********************************************/
template<class T>
void RedBlackTree<T>::rotateWithRightChild(Node* &k1) const
{
	Node *k2 = k1->right;
	k1->right = k2->left;//�ƶ��ڲ�����
	k2->left = k1;
	k1 = k2;//����k2����Ϊ��
}


/********************************************
name: doubleRotateWithRightChild
description: ˫��ת�����մ�����������ת
********************************************/
template<class T>
void RedBlackTree<T>::doubleRotateWithLeftChild(Node* &k3) const
{
	rotateWithRightChild(k3->left);
	rotateWithLeftChild(k3);
}


/********************************************
name: doubleRotateWithRightChild
description: ˫��ת�����մ����Һ�������ת
********************************************/
template<class T>
void RedBlackTree<T>::doubleRotateWithRightChild(Node* &k1) const
{
	rotateWithLeftChild(k1->right);
	rotateWithRightChild(k1);
}


/********************************************
name: handleReorient
description: 
  ���µ�����1.�������ӽڵ㶼�Ǻ�ɫʱ 2.�²���Ľڵ�ĸ��ڵ��Ǻ�ɫʱ
********************************************/
template<class T>
void RedBlackTree<T>::handleReorient(const T& item)
{
	//��ɫ
	//1.�����ǰ�ڵ�������������ӽڵ㶼�Ǻ�ɫ��,�ȵ�����ɫ
	current->color = RED;
	current->left->color = BLACK;
	current->right->color = BLACK;
	
	//2.�²���Ľڵ�ĸ��ڵ��Ǻ�ɫʱ
	if(parent->color == RED)
	{
		grand->color = RED;
		if(item < grand->element  !=  item < parent->element)//�ж��Ƿ�Ϊ�ڲ�����
			parent = rotate(item, grand);//�ǾͶ��һ����ת
		current = rotate(item, great);
		current->color = BLACK;
	}
	header->right->color = BLACK;
}


/********************************************
name: rotate
description: ͨ����ת����
********************************************/
template<class T>
RedBlackNode<T>* RedBlackTree<T>::rotate(const T& item, Node* theParent) const
{
	if(item < theParent->element)
	{
		item < theParent->left->element  ?  rotateWithLeftChild(theParent->left)  :  rotateWithRightChild(theParent->left);
		return theParent->left;
	}
	else if(item > theParent->element)
	{
		item < theParent->right->element  ?  rotateWithLeftChild(theParent->right)  : rotateWithRightChild(theParent->right);
		return theParent->right;
 	}
}


/********************************************
name: isEmpty
description: �жϺ�����Ƿ�Ϊ��
********************************************/
template<class T>
bool RedBlackTree<T>::isEmpty() const
{
	return header->right == nullNode;
}


/********************************************
name: makeEmpty
description: ��գ�ɾ�����нڵ�
********************************************/
template<class T>
void RedBlackTree<T>::makeEmpty()
{
	reclaimMemory(header->right);//�Ӹ��ڵ㿪ʼ���
	header->right = nullNode;
}


/********************************************
name: reclaimMemory
description: �ӽڵ�t��ʼ��ɾ����������н��
********************************************/
template<class T>
void RedBlackTree<T>::reclaimMemory(Node* t) const
{
	if(t != t->left)
	{
		reclaimMemory(t->left);
		reclaimMemory(t->right);
		delete t;
	}
}


/********************************************
name: findMin
description: ����С����������
********************************************/
template<class T>
Cref<T> RedBlackTree<T>::findMin() const
{
	if(isEmpty())
		return Cref<T>(); 

	Node* itr = header->right;
	while(itr->left != nullNode)
		itr = itr->left;
	return Cref<T>(itr->element);
}


/********************************************
name: findMax
description: �����,��������
********************************************/
template<class T>
Cref<T> RedBlackTree<T>::findMax() const
{
	if(isEmpty())
		return Cref<T>(); 

	Node* itr = header->right;
	while(itr->right != nullNode)
		itr = itr->right;
	return Cref<T>(itr->element);
}


/********************************************
name: find
description: ����x����������
********************************************/
template<class T>
Cref<T> RedBlackTree<T>::find(const T& x) const
{
	nullNode->element = x;
	
	Node* curr = header->right;

	for(;;)
	{
		if(x < curr->element)
			curr = curr->left;
		else if(x > curr->element)
			curr = curr->right;
		    
			else if(curr != nullNode)//�ҵ���
				return Cref<T>(curr->element);
				else//û�ҵ�
					return Cref<T>();
	}
}


/********************************************
name: 
description: ������,
********************************************/

#endif