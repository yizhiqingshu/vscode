#include <iostream>
#include <random>
#include <fstream>
#include <ctime>
#include <vector>
using namespace std;
void display_time()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    std::cout<<"\t"<<1900+ltm->tm_year<<"年"<<1+ltm->tm_mon<<"月"<<ltm->tm_mday<<"日 ";
    std::cout<<"\t"<<ltm->tm_hour<<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<endl;
}
unsigned num()
{
    time_t now = time(0);
    tm *suijinum = localtime(&now);
    static std::uniform_int_distribution<unsigned> u(0,9);
    static std::default_random_engine e(now);
    for(size_t i=0;i<10;i++)
        u(e);
    return u(e);
}
int main()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    vector<int> chuan;
    chuan.push_back(1900+ltm->tm_year);
    cout<<chuan[0]<<endl;
    unsigned lucknum = num();
    //cout<<lucknum<<endl;
    std::cout<<"\t今日"<<std::endl;
    display_time();
    std::cout<<"\t解签 宜"<<" ";
    switch(lucknum)
    {
    case 0:std::cout<<"\t学习\t"<<std::endl;break;
    case 1:std::cout<<"\t出行\t "<<std::endl;break;
    case 2:std::cout<<"\t写代码\t"<<std::endl;break;
    case 3:std::cout<<"\t单片机\t"<<std::endl;break;
    case 4:std::cout<<"\t跑步"<<std::endl;break;
    case 5:std::cout<<"\t听歌"<<std::endl;break;
    case 6:std::cout<<"\t休息"<<std::endl;break;
    case 7:std::cout<<"\t操作系统"<<std::endl;break;
    case 8:std::cout<<"\t网络"<<std::endl;break;
    case 9:std::cout<<"\tRTOS"<<std::endl;break;
    default:std::cout<<"jianlai"<<endl;
            break;
    }
    return 0;
}

