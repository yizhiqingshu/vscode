#include <fstream>
#include <iostream>
using namespace std;
 
int main ()
{
    
   char data[100];

   // 以写模式打开文件
   ofstream outfile;
   outfile.open("hello.txt",fstream::app);

   cout << "Writing to the file" << endl;
   cout << "Enter your name: "; 
   cin.getline(data, 100);

   // 向文件写入用户输入的数据
   outfile << data << endl;

   cout << "Enter your age: "; 
   cin >> data;
   cin.ignore();
   
   // 再次向文件写入用户输入的数据
   outfile << data << endl;

   // 关闭打开的文件
   outfile.close();

   // 以读模式打开文件
   ifstream infile; 
   infile.open("hello.txt",ofstream::app); 
 
   cout << "Reading from the file" << endl; 

   // 在屏幕上写入数据
   
   // 再次从文件读取数据，并显示它
   for(int i=0;i<3;i++)
   {
   infile >> data; 
   cout << data << endl; 
   }
   // 关闭打开的文件
   infile.close();

   return 0;
}
