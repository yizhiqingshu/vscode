#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
    Person(const std::string &nm,const std::string &addr)
    {
        this->name = nm;//返回当前this指向的对象的成员，调用this的那个对象的成员
        this->address = addr;
    }
    std::string getName()const
    {
        return this->name;
    }
    std::string getAddress()const
    {
        return this->address;
    }
    private:
        std::string name;
        std::string address;
};
int main()
{
    Person p("chuan","jianlai");
    Person P2("liubei","jianlai2");
    cout<<p.getName()<<endl;
    cout<<P2.getAddress()<<endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

