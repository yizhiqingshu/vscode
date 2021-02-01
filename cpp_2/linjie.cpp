#include <iostream>
#include <string>
#include <stack>
#include <queue>
#define MAX_size 20
class Vertex
{
public:
    Vertex(char lab){ Label = lab;wasVisited = false; }
    char Label;
    bool wasVisited;
};

class Graph
{
public:
    Graph();
    ~Graph();
    void addVertex(char lab);
    void addEdge(int start,int end);
    void printMatrix();
    void showVertex(int v);
    void DFS();
    void BFS();
private:
    Vertex* vertexlist[MAX_size];
    int nVerts;
    int adjMat[MAX_size][MAX_size];
    int NotnextVisit(int v);
};

Graph::Graph()
{
    nVerts = 0;
    for(int i=0;i<MAX_size;i++)
        for(int j=0;j<MAX_size;j++)
            adjMat[i][j]=0;
}
void Graph::addVertex(char lab)
{
    vertexlist[nVerts++] = new Vertex(lab);

}
void Graph::addEdge(int start,int end)
{
    adjMat[start][end] = 1;
    adjMat[end][start] = 1;
}
void Graph::printMatrix()
{
    for(int i=0;i<nVerts;i++)
    {
        for(int j=0;j<nVerts;j++)
        std::cout<<adjMat[i][j]<<" ";
        std::cout<<std::endl;
    }
}
Graph::~Graph()
{
    for(int i=0;i<nVerts;i++)
    {
        delete vertexlist[i];
    }
}

void Graph::showVertex(int v)
{
    std::cout<<vertexlist[v]->Label<<" ";

}

int Graph::NotnextVisit(int v)
{
    for(int j=0;j<nVerts;j++)
        if(adjMat[v][j] == 1&&(vertexlist[j]->wasVisited==false))
            return j;
    return -1;
}
void Graph::DFS()
{
    std::stack<int> gstack;
    vertexlist[0]->wasVisited = true;
    showVertex(0);
    gstack.push(0);
    int v;
    while(gstack.size()>0)
    {
        v = NotnextVisit(gstack.top());
        if(v == -1)
            gstack.pop();
        else 
        {
        vertexlist[v]->wasVisited = true;
        showVertex(v);
        gstack.push(v);
        }
    }
    std::cout<<std::endl;
    for(int j=0;j<nVerts;j++)
        vertexlist[j]->wasVisited = false;
}
void Graph::BFS()
{
    std::queue<int>gqueue;
    vertexlist[0]->wasVisited = true;
    showVertex(0);
    gqueue.push(0);
    int vert1,vert2;
    while(gqueue.size()>0)
    {
        vert1 = gqueue.front();
        gqueue.pop();
        vert2 = NotnextVisit(vert1);
        while(vert2!=-1)
        {
            vertexlist[vert2]->wasVisited = true;
            showVertex(vert2);
            gqueue.push(vert2);
        vert2 = NotnextVisit(vert1);
        }
    }
    std::cout<<std::endl;
    for(int j=0;j<nVerts;j++)
        vertexlist[j]->wasVisited = false;
}
int main()
{
    Graph a;
    a.addVertex('A');
    a.addVertex('B');
    a.addVertex('C');
    a.addVertex('D');
    a.addVertex('E');
    
    a.addEdge(0,1);
    a.addEdge(0,3);
    a.addEdge(1,0);
    a.addEdge(1,4);
    a.addEdge(2,4);
    a.addEdge(3,0);
    a.addEdge(3,4);
    a.addEdge(4,1);
    a.addEdge(4,2);
    a.addEdge(4,3);
    a.printMatrix();

    std::cout<<"DFS"<<std::endl;
    a.DFS();
    std::cout<<"BFS"<<std::endl;
    a.BFS();
    std::cout << "Hello world" << std::endl;
    return 0;
}


