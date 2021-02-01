#include <iostream>
#include <list>
using namespace std;

class Vertex
{
public:
    char Label;
    Vertex(char lab):Label(lab){}
};

ostream& operator<<(ostream & out,const Vertex& v)
{
    cout<<v.Label;
    return out;
}
template<class T>
class Graph
{
public:
    Graph(const int vertices):n(vertices)
    {
        VertexList = new T*[n];
        HeadNode = new list<int>[n];
        Nverts = 0;
    }
    ~Graph()
    {
        delete [] VertexList;
        delete [] HeadNode;
    }
    void addVertex(T* v);
    void addEdge(int start,int end);
    void printVertice();
    void printAdjlist();
        
private:

    T** VertexList;
    list<int>* HeadNode;
    int n;
    int Nverts;
};

template<class T>
void Graph<T>::addVertex(T* v)
{
    VertexList[Nverts++] = v;
}
template<class T>
void Graph<T>::addEdge(int start,int end)
{
    HeadNode[start].push_back(end);
}
template<class T>
void Graph<T>::printVertice()
{
    for(int i=0;i<Nverts;i++)
        std::cout<<*VertexList[i]<<" ";
    std::cout<<std::endl;
}
template<class T>
void Graph<T>::printAdjlist()
{
    for(int i = 0;i<Nverts;i++)
    {
        cout<<i<<":";
        for(list<int>::iterator iter = HeadNode[i].begin();iter!=HeadNode[i].end();++iter)
            cout<<*iter<<" ";
                cout<<endl;
    }
}
int main()
{
    Graph<char> g(5);
    char a = 'A';
    char b= 'B';
    char c = 'C';
    char d = 'D';
    char e = 'E';
    
    g.addVertex(&a);
    g.addVertex(&b);
    g.addVertex(&c);
    g.addVertex(&d);
    g.addVertex(&e);
    g.printVertice();

    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,0);
    g.addEdge(1,4);
    g.addEdge(2,4);
    g.addEdge(3,0);
    g.addEdge(3,4);
    g.addEdge(4,1);
    g.addEdge(4,2);
    g.addEdge(4,3);

    g.printAdjlist();

    std::cout << "Hello world" << std::endl;
    return 0;
}

