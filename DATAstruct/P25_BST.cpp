//����

#include <iostream>
#include "P25_BST.h"

using namespace std;




int main()
{
	// cout<< "������" << endl << endl;

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

	cout<< m.Insert(a) << endl;//a=5, ����root
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

	// BstNode<int> *p2 = m.IterSearch(e);
	// cout<< "�ҵ����ǣ� " << p2->getdata().key << endl;

	
	return 0;
}