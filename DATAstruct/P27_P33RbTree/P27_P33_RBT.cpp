#include <iostream>
#include "RedBlackTree.h"

using namespace std;

int main()
{
	cout<< "���ԡ�����" << endl;
	const int NEG_INF = -9999;
	RedBlackTree<int> t(NEG_INF);

	//t.insert(30);
	//t.insert(15);
	//t.insert(70);
	//t.insert(20);

	//cout<< t.header->right->element << endl;
	//cout<< t.header->right->left->element << endl;
	//cout<< t.header->right->right->element << endl;
	//cout<< t.header->right->left->right->element << endl; //20

	//cout<< "����ת��" << endl;
	//t.rotateWithLeftChild(t.header->right);
	//cout<< t.header->right->element << endl;
	//cout<< t.header->right->right->left->element << endl;

	//cout<< "����ת: " << endl;
	//t.rotateWithRightChild(t.header->right);
	//cout<< t.header->right->element << endl;
	//cout<< t.header->right->left->element << endl;
	//cout<< t.header->right->right->element << endl;
	//cout<< t.header->right->left->right->element << endl;


	//t.insert(12);
	//t.insert(16);
	//t.insert(8);
	//t.insert(10);
	//t.insert(4);
	//t.insert(14);
	//t.insert(2);
	//t.insert(6);
	//t.insert(5);

	//cout<< t.header->right->left->left->right->left->element << endl;
	//cout<< t.header->right->left->element << endl;
	//t.doubleRotateWithLeftChild(t.header->right->left);
	//cout<< t.header->right->left->element << endl;
	//cout<< t.header->right->left->left->right->element << endl;


	t.insert(50);
	t.insert(40);
	t.insert(30);
	cout<< t.header->right->element << endl;

	if(!t.isEmpty()) 
		cout<< "��������ǿյ�" << endl;

	t.makeEmpty();
	if(t.isEmpty()) 
		cout<< "������ǿյ�" << endl;
	//cout<< t.header->right->element << endl;

	t.insert(200);
	t.insert(100);
	t.insert(90);
	t.insert(50);
	t.insert(80);
	t.insert(70);
	t.insert(60);
	
	if(t.findMin().get() == 50)
		cout<< "�ҵ�����С����" << endl;
	
	cout<< "���ģ� " << t.findMax().get() << endl;

	Cref<int> r = t.find(80);
	if(r.isNull())
		cout<< "û�ҵ���" << endl;
	else
		cout<< "�ҵ�: " << r.get() << endl;

	/*system("pause");*/
	return 0;
}