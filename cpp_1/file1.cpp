#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    char data[100];
    /*ofstream outfile;
    outfile.open("hello.txt",ofstream::app);
    cin.getline(data,100);
    outfile <<data <<endl;
    outfile.close();*/
    vector<string> a;
    ifstream infile;
    infile.open("hello.txt");
    for(int i=0;i<10&&infile;i++)
    {
    infile>>data;
    a.push_back(data);
    cout<<a[i]<<endl;
    }
    infile.close();
    std::cout << "Hello world" << std::endl;
    return 0;
}

