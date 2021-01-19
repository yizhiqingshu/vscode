#include<iostream>//failure 
#include<algorithm>
#include<sstream>
#include<string>
using namespace std;
#define MIN(a,b) (a>b)?b:a
template <class T>
void changArraylength(T*& a,int oldLength,int newLength)
{
    if(newLength<0)
    throw "newLength is must be >0";
    T* temp = new T[newLength];
    int number = MIN(oldLength,newLength);
    copy(a,a+number,temp);
    delete[] a;
    a=temp;
}
template<class T>
class arrayList
{
    public:
    arrayList(int initLength=10);
    arrayList(const arrayList<T>&);
    ~arrayList(){delete[]element;}

    bool empty()const {return listSize==0;}
    int size()const {return listSize;}
    T& get(int theIndex)const;
    int indexOf(const T& theElement)const ;
    void erase(int theIndex);
    void insert(int theIndex,const T& theElement);
    void output(ostream & out)const ;
    bool checkIndex(int theIndex)const;

  //  private:
  protected:
  
    int listSize;
    int arrayLength;
    T* element;
};
template <class T>
arrayList<T>::arrayList(int initLength)
{
    arrayLength = initLength;
    element = new T[arrayLength];
    listSize=0;
}
template<class T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{
    arrayLength = theList.arrayLength;
    listSize = theList.listSize;
    element = new T[arrayLength];
    copy(theList.element,theList.element+listSize,element);
}
template<class T>
bool arrayList<T>::checkIndex(int theIndex)const
{
if(theIndex<0||theIndex>=listSize) throw "error ";
}
template<class T>
T& arrayList<T>::get(int theIndex)const
{
    checkIndex(theIndex);
    return element[theIndex];
}
template<class T>
int arrayList<T>::indexOf(const T& theElement)const 
{
    int theIndex = (int) (find(element,element+listSize,theElement)-element);
    if(theIndex==listSize)
    return -1;
    else return theIndex;
}
template<class T>
void arrayList<T>::erase(int theIndex)
{
    checkIndex(theIndex);
    copy(element+theIndex+1,element+listSize,element+theIndex);
    element[--listSize].~T();
}
template<class T>
void arrayList<T>::insert(int theIndex,const T& theElement)
{
    checkIndex(theIndex);
    if(listSize == arrayLength)
    {
        changArraylength(element,arrayLength,2*arrayLength);
        arrayLength*=2;
    }
    copy_backward(element+theIndex,element+listSize,element+listSize+1);
    element[theIndex] = theElement;
    listSize++;
}
template<class T>
void arrayList<T>::output(ostream & out)const 
{
    copy(element,element+listSize,ostreambuf_iterator<T>(cout," "));
}
template<class T>
ostream& operator<<(ostream& out,const arrayList<T>& x)
{
    x.output(out);return out;
}
int main()
{
    arrayList<int> chuan(10);
    cout<<chuan.empty();
    chuan.insert(0,2);
    chuan.insert(1,6);
    cout<<chuan.empty();
    return 0;
}