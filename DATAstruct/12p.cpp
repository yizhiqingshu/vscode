#include<iostream>
 
using namespace std;
 
#define MAXSIZE 100
typedef int ELETYPE;
 
class Stack
{
private:
	ELETYPE *base;//栈底
	int top;//栈顶
	int stacksize;//栈空间
public:
	Stack();
	~Stack();
	bool IsEmpty();//是否为空栈
	bool ClearStack();//清空栈
	int StackLength();//栈长度
	bool PushStack(ELETYPE a);//压栈
	bool PopStack(ELETYPE &a);//出栈
	bool TopStack(ELETYPE &a);//返回栈顶元素
	bool IsFull();//栈是否满了
};
 
bool Stack::TopStack(ELETYPE &a)
{
	if(-1==top)
		return false;
	a=base[top];
}
 
bool Stack::IsFull()
{
	//if(stacksize-1==top)
	//	return true;
	//return false;
	return top==stacksize-1;//这种写法更为简洁
}
 
bool Stack::PopStack(ELETYPE &a)
{
	if(-1==top)
		return false;
	a=base[top--];
	return true;
}
 
bool Stack::PushStack(ELETYPE a)
{
	if(top==stacksize-1)
		return false;
	base[++top]=a;
	return true;
}
 
int Stack::StackLength()
{
	return top+1;
}
 
bool Stack::ClearStack()
{
	top=-1;//这样是有问题的
	return true;
}
 
bool Stack::IsEmpty()//空栈返回true,否则返回false
{
	if(-1==top)
		return true;
	return false;
}
 
Stack::Stack()
{
	top=-1;//数组第一个元素下标为0，所以用-1来表示空栈
	stacksize=MAXSIZE;
	base=new ELETYPE[MAXSIZE];
}
 
Stack::~Stack()
{
	delete []base;//析构函数不会自动回收new的空间，所以在析构函数里手动delete   new的空间
}
 
void main()
{
	Stack sta;
	for(int i=0;i<10000;++i)
	{
		if(!sta.PushStack(i))
			break;
	}
	int a;
	for(;sta.StackLength()!=0;)
	{
		sta.PopStack(a);
		cout<<a<<" ";
	}
}