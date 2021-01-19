#ifndef _BTREE_H
#define _BTREE_H

#include <iostream>
#include <queue>//��׼����Ķ���

template<class T> class BinaryTree;


template<class T>
class TreeNode
{
public:
	TreeNode(){leftChild = NULL; rightChild = NULL;}
	T data;
	TreeNode<T> *leftChild;
	TreeNode<T> *rightChild;
};


template<class T>
class BinaryTree
{
public:
	//���������Խ��еĲ���
	void Visit(TreeNode<T>* currentNode);
	void PreOrder();//ǰ�����
	void PreOrder(TreeNode<T>* currentNode);
	void InOrder();//�������
	void InOrder(TreeNode<T>* currentNode);
	void PostOrder();//�������
	void PostOrder(TreeNode<T>* currentNode);
	void LevelOrder();//�������
public:
	TreeNode<T> *root;
};



/******����ʵ�ֲ���******/
/***********************/
/***********************/

template<class T>
void BinaryTree<T>::Visit(TreeNode<T>* currentNode)
{
	std::cout<< currentNode->data;
}

//ǰ�����
template<class T>
void BinaryTree<T>::PreOrder()
{
	PreOrder(root);
}

template<class T>
void BinaryTree<T>::PreOrder(TreeNode<T>* currentNode)
{
	if(currentNode)
	{
		Visit(currentNode);
		PreOrder(currentNode->leftChild);
		PreOrder(currentNode->rightChild);
	}
}


//�������
template<class T>
void BinaryTree<T>::InOrder()
{
	InOrder(root);
}

template<class T>
void BinaryTree<T>::InOrder(TreeNode<T> *currentNode)
{
	if(currentNode)
	{
		//�ݹ�
		InOrder(currentNode->leftChild);
		//��ʾ��ǰ�ڵ� 
		Visit(currentNode);
		InOrder(currentNode->rightChild);
	}
}

//�������
template<class T>
void BinaryTree<T>::PostOrder()
{
	PostOrder(root);
}

template<class T>
void BinaryTree<T>::PostOrder(TreeNode<T>* currentNode)
{
	if(currentNode)
	{
		PostOrder(currentNode->leftChild);
		PostOrder(currentNode->rightChild);
		Visit(currentNode);
	}
}

//�������
template<class T>
void BinaryTree<T>::LevelOrder()
{
	std::queue<TreeNode<T>*> q;
	TreeNode<T>* currentNode = root;
	while(currentNode)
	{
		Visit(currentNode);
		if(currentNode->leftChild)
			q.push(currentNode->leftChild);
		if(currentNode->rightChild)
			q.push(currentNode->rightChild);
		if(q.empty())
			return;
		currentNode = q.front(); 
		q.pop();
	}
}


#endif