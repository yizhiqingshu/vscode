#include<iostream>
#include<string>
#include <stdio.h>
using namespace std;
class Sales_item
{
public:
    Sales_item(string &book,unsigned int units,double amout):isbn(book),units_sold(units),revenue(amout)
    {}
    double avg_price()const
    {
        if(units_sold)
            return revenue / units_sold;
        else return 0;
    }
    bool same_isbn(const Sales_item &rhs)const
    {
        return isbn == rhs.isbn;
    }
    void add(const Sales_item& rhs)
    {
        units_sold += rhs.units_sold;
        revenue += rhs.revenue;
    }
    private:
        string isbn;
        unsigned int units_sold;
        double revenue;
};
class Person
{
public:
    Person(const string& nm,const string& ads):name(nm),address(ads)
    {
    //    name = nm;
    //    address = ads;
    }
    string getName()const{return name;}
    string getAdress()const{return address;}
private:
    std::string name;
    std::string address;
};
int main()
{
    Person a("mc","SUST");
    a.getAdress();
    a.getName();
    cout<<a.getName()<<" "<<a.getAdress();
    cout<<"class"<<endl;
    string b="1-2-3-45";
    Sales_item x(b,1,2);
    Sales_item y(b,7,14);
    cout<<x.avg_price()<<endl;
}
