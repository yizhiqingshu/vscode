#include<iostream>
#include<string>
using namespace std;
//类内部的函数的定义 内联函数
//函数声明为 inline
//函数定义的时候写明inline
class Screen
{
public:
	typedef std::string::size_type index;
	Screen(index ht = 0, index wd = 0) :contents(ht*wd, 'A'), cursor(0), height(ht), width(wd){}

    inline char get()const;
	char get(index r, index c)const;
    Screen(index ht,index wd,const std::string &conts):contents(conts),cursor(0),height(ht),width(wd){}

private:
	std::string contents;
	index cursor;
	index height, width;
};
char Screen::get()const
	{
		return contents[cursor];
	}
inline char Screen::get(index r,index c)const
	{
		index row = r;
		return contents[row + c];
	}
int main()
{
	Screen a(10,100);
	a.get();

    
	cout << a.get(2,8) << endl;
    Screen b(6,16,"hello screen class");
    cout<<b.get()<<endl;
    cout<<b.get(0,4)<<endl;
	cout << "hello world!" << endl;
}
