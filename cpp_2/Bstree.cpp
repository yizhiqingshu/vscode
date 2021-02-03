#include <iostream>
using std::cout;
using std::endl;

enum Boolean {FALSE, TRUE};

template<class T> class BST;


template<class T>
class Element
{
public:
	T key;
	
};


template<class T>
class BstNode
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
	Boolean Insert(const Element<T>& x);
	BstNode<T>* Search(const Element<T>& x);
	BstNode<T>* Search(BstNode<T>*, const Element<T>&);
	BstNode<T>* IterSearch(const Element<T>&);

	void display()
	{
		std::cout << "\n";
		if(root)
			root->display(1);
		else
			std::cout<<" \n";
	}
private:
	BstNode<T>* root;
};


template<class T>
void BstNode<T>::display(int i)
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
	BstNode<T> *q = 0;
	while(p)
	{
		q = p;
		if(x.key == p->data.key)
			return FALSE;
		if(x.key < p->data.key)
			p = p->leftChild;
		else if(x.key > p->data.key)
				p = p->rightChild;
	}
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
BstNode<T>* BST<T>::Search(BstNode<T> *b, const Element<T> &x)
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
int main()
{
    BST<int> m;
	Element<int> a, b, c, d, e, f, g, h, j, k, l;
	a.key = 5;
	b.key = 3;
	c.key = 11;
	d.key = 3;
	e.key = 15;
	f.key = 2;
	g.key = 8;
	h.key = 22;
	k.key = 20;
	l.key = 9;

	cout<< m.Insert(a) << endl;//a=5, root
	cout<< m.Insert(b) << endl;
	cout<< m.Insert(c) << endl;
	cout<< m.Insert(d) << endl;
	cout<< m.Insert(e) << endl;
	cout<< m.Insert(f) << endl;
	cout<< m.Insert(g) << endl;
	cout<< m.Insert(h) << endl;
	cout<< m.Insert(j) << endl;
	cout<< m.Insert(k) << endl;
	cout<< m.Insert(l) << endl;
	m.display();
	BstNode<int> *p = m.Search(f);
	 cout<< "find: " << p->getdata().key << endl;
}
