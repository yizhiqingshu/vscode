#include<iostream>
#include<vector>
using namespace  std;
int main ()
{
    vector<int>chuan={1,2,3,4};
    vector<int>::iterator it1=chuan.begin();
    vector<int>::iterator it2=chuan.end();
    
    vector<int>b;
     b.assign(it1,it2);
    vector<int>::iterator it3;
    vector<int>::iterator it4;
    it3=b.begin();
    for(int i=0;i<chuan.size();i++)
    {
        cout<<chuan[i]<<endl;
        cout<<b[i]<<endl;
    }
    while (it3!=b.end())
    {
        cout<<*it3;
        it3++;
    }
    
   
    
    return 0;
}
