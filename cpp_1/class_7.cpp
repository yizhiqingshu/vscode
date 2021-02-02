#include <iostream>
#include <memory>
using namespace std;

class Sale_data
{
public:
    Sale_data(int num1,int num2):num1(num1),num2(num2){}
//private:
    int sum;
    int num1;
    int num2;
};
ostream& operator<<(ostream& os,const Sale_data& item )
{
    os<<item.num1<<" "<<item.num2;
    return os;
}
int main()
{
    Sale_data a(1,2);
    cout<<a<<endl;
    int *p=new int [10];
    unique_ptr<int []> up(new int[10]);
    
    for(int i=0;i<10;i++)
        up[i]=i+1;
    for(int j=0;j<10;j++)
        cout<<up[j]<<endl;

    delete [] p;
    return 0;
}
