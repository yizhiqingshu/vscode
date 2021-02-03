#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <vector>
#include <string>
using namespace std;
class qiuqian;
class rand_data
{
    friend class qiuqian;
    friend ostream& operator<<(ostream& os,rand_data& item);
    public:
        rand_data():now(time(0)),ltm(localtime(&now)),u(0,9),e(time(0))
    {
    }
        void print_date();
        unsigned rand_date();
        vector<int>& jilu();
    vector<int> TIME;
    private:
        time_t now;
        tm *ltm;
        uniform_int_distribution<unsigned> u;
        default_random_engine e;
};
ostream& operator<<(ostream& os,rand_data& item)
{
    os<<"data:"<<item.ltm->tm_year+1900<<"/"<<1+item.ltm->tm_mon<<"/"<<item.ltm->tm_mday<<"/"
      <<item.ltm->tm_hour<<"/"<<item.ltm->tm_min<<"/"<<item.ltm->tm_sec ;
    return os;
}
void rand_data::print_date()
{
    std::cout<<"今日";
    std::cout<<1900+ltm->tm_year<<" "<<1+ltm->tm_mon<<" "<<ltm->tm_mday;
    std::cout<<ltm->tm_hour<<" "<<ltm->tm_min<<" "<<ltm->tm_sec<<std::endl;
    std::cout<<"解签 宜"<<std::endl;
}
unsigned rand_data::rand_date()
{
    u(e);//舍弃第一个生成的随机数
    return u(e);
}
vector<int>& rand_data::jilu()
{
    TIME.push_back(int(1900+ltm->tm_year));
    TIME.push_back(int(1+ltm->tm_mon));
    TIME.push_back((int)ltm->tm_mday);
    TIME.push_back((int)ltm->tm_hour);
    TIME.push_back((int)ltm->tm_min);
    TIME.push_back((int)ltm->tm_sec);
    vector<int>::iterator iter = TIME.begin();
    /*for(;iter!=TIME.end();iter++)
        cout<<*iter;*/
    return TIME;
}
class qiuqian
{
    typedef vector<string> arr;
    public:
        qiuqian(){}
        qiuqian(arr shuju,arr qian):data(shuju),qian(qian){}
        void writeQian(string &k);
        int jieqian();
    private:
    vector<string> data;//数据
    vector<string> qian;//签
};
int qiuqian::jieqian()
{
    unsigned qian;
    rand_data a;
    qian = a.rand_date();
    cout<<qian<<endl;
    switch (qian)
    {
    case 0:  std::cout<<this->data[0] <<std::endl; break;
    case 1:  std::cout<<this->data[1] <<std::endl; break;
    case 2:  std::cout<<this->data[2] <<std::endl; break;
    case 3:  std::cout<<this->data[3] <<std::endl; break;
    case 4:  std::cout<<this->data[4] <<std::endl; break;
    case 5:  std::cout<<this->data[5] <<std::endl; break;
    case 6:  std::cout<<this->data[6] <<std::endl; break;
    case 7:  std::cout<<this->data[7] <<std::endl; break;
    case 8:  std::cout<<this->data[8] <<std::endl; break;
    case 9:  std::cout<<this->data[9] <<std::endl; break;
    default: std::cout<<this->data[0] <<std::endl; break;
    }
    return qian;
}
void qiuqian::writeQian(string &k)
{
   this->data.push_back(k);
}
int main()
{
    vector<string> shuju_a={"xuexi","jianlai","c++","tcp/ip","run","missing","mcu","linux","rest","chuan"};
    vector<int>::iterator rand_iter;
    ofstream outfile;
    rand_data a;
    qiuqian b;
    vector<string>::iterator iter = shuju_a.begin();
    for(;iter!=shuju_a.end();iter++)
    b.writeQian(*iter);
    //b.jieqian();
    char Log[100]={0};
    outfile.open("hello.txt",ofstream::app);
    //a.print_date();
   // cout<<a<<endl;
    outfile<<a<<endl;
    while(cin.getline(Log,100)&&Log[0]!='#')
        outfile<<Log<<endl;
    outfile <<"今日宜:"<<shuju_a[b.jieqian()]<<endl;
    outfile.close();
    vector<int> jilu1(a.jilu());
    for(rand_iter=jilu1.begin();rand_iter!=jilu1.end();rand_iter++)
        cout<<*rand_iter;
    std::cout << "Hello world" << std::endl;
    return 0;
}

