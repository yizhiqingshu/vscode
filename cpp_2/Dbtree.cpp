#include <iostream>
#include <queue>

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
	void Visit(TreeNode<T>* currentNode);
	void PreOrder();
	void PreOrder(TreeNode<T>* currentNode);
	void InOrder();
	void InOrder(TreeNode<T>* currentNode);
	void PostOrder();
	void PostOrder(TreeNode<T>* currentNode);
	void LevelOrder();
public:
	TreeNode<T> *root;
};



template<class T>
void BinaryTree<T>::Visit(TreeNode<T>* currentNode)
{
	std::cout<< currentNode->data;
}

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
		InOrder(currentNode->leftChild);
	
		Visit(currentNode);
		InOrder(currentNode->rightChild);
	}
}


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
int main()
{
    using std::cout;
    using std::endl;
    BinaryTree<char> tree;
	TreeNode<char> add, sub, mul, div, a, b, c, d, e;

	add.data = '+';
	sub.data = '-';
	mul.data = '*';
	div.data = '/';
	a.data = 'A';
	b.data = 'B';
	c.data = 'C';
	d.data = 'D';
	e.data = 'E';

	tree.root = &add;
	add.leftChild = &sub;
	add.rightChild = &e;
	sub.leftChild = &mul;
	sub.rightChild = &d;
	mul.leftChild = &div;
	mul.rightChild = &c;
	div.leftChild = &a;
	div.rightChild = &b;

	cout<< "PreOrder";
	tree.PreOrder();
	cout<< endl;

	cout<< "InOrder " ;
	tree.InOrder();
	cout<< endl;

	cout<< "PostOrder" ;
	tree.PostOrder();
	cout<< endl;

	cout<< "LevelOrder" ;
	tree.LevelOrder();
	cout<< endl;
    
	return 0;
}
