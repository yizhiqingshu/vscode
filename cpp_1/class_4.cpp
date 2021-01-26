#include <iostream>
#include <string>
using namespace std;
class Record
{
    public:
        typedef std::size_t size;
        Record():byte_count(0){}
        Record(size s):byte_count(s){}
        Record(std::string s):name(s),byte_count(0){}

        size get_count()const{return byte_count;}
        std::string get_name()const {return name;}
    private:
        size byte_count;
        string name;
};
int main()
{
    Record r;
    
    std::cout << "Hello world" << std::endl;
    return 0;
}

