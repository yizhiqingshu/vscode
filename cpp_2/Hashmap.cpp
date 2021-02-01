#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<class Key,class Value>
class Hashmap
{
    public:
        Hashmap(int size=101):arr(size)
        {
            currentSize = 0;
        }
        void Put(const Key& k,const Value& v)
        {
            int pos = hash_2(k);
            arr[pos] = Data(k,v);
            currentSize++;
        }
        Value Get(const Key& k)
        {
            int pos = hash_2(k);
            if(arr[pos].key==k)
                return arr[pos].value;
            else return Value();
        }
        unsigned hash(const Key& k)const
        {
            unsigned int HashVal = 0;
            const char *keyp = reinterpret_cast<const char *>(&k);
            for(size_t i;i<sizeof(Key);i++)
            {
                HashVal = 37 * HashVal + keyp[i];
            }
            return  HashVal;
        }
        int hash_2(const Key& k)const
        {
            unsigned HashVal = hash(k);
            HashVal %= arr.size();
            return HashVal;
        }
    private:
        struct Data
        {
            Key key;
            Value value;
            Data(const Key & k= Key(),const Value& v=Value()):key(k),value(v){}
        };
        std::vector<Data>arr;
        int currentSize;
};

int main()
{
    Hashmap<string,int> chuanHash;
    chuanHash.Put("bill",999);
    chuanHash.Put("mary",888);
    chuanHash.Put("tom",777);
    cout<<chuanHash.Get("tom")<<endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

