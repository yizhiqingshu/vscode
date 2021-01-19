#include <iostream>

#define MAX_VERTS 20

using namespace std;


class Vertex//����
{
public:
	Vertex(char lab){ Label = lab;}

private:
	char Label;
};


class Graph
{
public:
	Graph();
	~Graph();
	void addVertex(char lab);//���Ӷ���
	void addEdge(int start, int end);//�������ߣ����ӱ�
	void printMatrix();//��ӡ�ڽӾ���
private:
	Vertex* vertexList[MAX_VERTS];//Vertex���͵�ָ�����飬�������涥��
	int nVerts;//��������
	int adjMat[MAX_VERTS][MAX_VERTS];//�������ڽ׾��������
};

//���캯��
Graph::Graph()
{
	nVerts = 0;
	for(int i=0; i<MAX_VERTS; i++)
		for(int j=0; j<MAX_VERTS; j++)
			adjMat[i][j] = 0;
}

//���Ӷ���
void Graph::addVertex(char lab)
{
	vertexList[nVerts++] = new Vertex(lab);
}

//���ӱ�
void Graph::addEdge(int start, int end)
{
	adjMat[start][end] = 1;
	adjMat[end][start] = 1;
}

//��ӡ�ڽӾ���
void Graph::printMatrix()
{
	for(int i=0; i<nVerts; i++)
	{
		for(int j=0; j<nVerts; j++)
			cout<< adjMat[i][j] << " ";
		cout<< endl;
	}
}

//��������
Graph::~Graph()
{
	for(int i=0; i<nVerts; i++)
		delete vertexList[i];
}



int main()
{
	cout<< "�����С�����" << endl;

	Graph g;

	g.addVertex('A');//0,������λ��
	g.addVertex('B');//1
	g.addVertex('C');//2
	g.addVertex('D');//3
	g.addVertex('E');//4

	//A-B���һ��ͺ���
	g.addEdge(0, 1);//A-B,�������±������ӱߣ��˴�Ϊ��A,B������һ����
	g.addEdge(0,3);
	g.addEdge(1,0);
	g.addEdge(1,4);
	g.addEdge(2,4);
	g.addEdge(3,0);
	g.addEdge(3,4);//
	g.addEdge(4,1);
	g.addEdge(4,2);
	g.addEdge(4,3);
	
	g.printMatrix();


	system("pause");
	return 0;
}