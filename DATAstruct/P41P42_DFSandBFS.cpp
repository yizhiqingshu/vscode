#include <iostream>
#include <stack>
#include <queue>

#define MAX_VERTS 20

using namespace std;


class Vertex//����
{
public:
	Vertex(char lab)
	{
		Label = lab;
		wasVisited = false;
	}

//private:
	bool wasVisited;//��¼�����Ƿ񱻷��ʹ�
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

	void showVertex(int v);//��ʾ�±�Ϊv�Ķ���

	void DFS();
	void BfS();

private:
	Vertex* vertexList[MAX_VERTS];//Vertex���͵�ָ�����飬�������涥��
	int nVerts;//��������
	int adjMat[MAX_VERTS][MAX_VERTS];//�������ڽ׾��������

	int getAdjUnvisitedVertex(int v);//��ú�v���ڵĻ�û�з��ʵ���һ������,�����±꣬û���򷵻�-1
};


/////////����ʵ��/////////

//BFS
void Graph::BfS()
{
	queue<int> gQueue;//�����±�
	vertexList[0]->wasVisited = true;
	showVertex(0);
	gQueue.push(0);//�ѵ�һ���Ž�����
	int vert1, vert2;
	while(gQueue.size() > 0)
	{
		vert1 = gQueue.front();//���ʶ��е�һ��
		gQueue.pop();//������ʹӶ�����ɾ��
		vert2 = getAdjUnvisitedVertex(vert1);//��vert1���ڽӵģ�δ���ʹ���
		while(vert2 != -1)//���ڽӵĿ��ܲ�ֹһ��
		{
			vertexList[vert2]->wasVisited = true;
			showVertex(vert2);
			gQueue.push(vert2);//������һ���ʹӶ�����ɾ���Ǹ�
			vert2 = getAdjUnvisitedVertex(vert1);
		}
	}
	cout<< endl;

	for(int j=0; j<nVerts; j++)
		vertexList[j]->wasVisited = false;
}


//DFS
void Graph::DFS()
{
	stack<int> gStack;//�����±�
	vertexList[0]->wasVisited = true;
	showVertex(0);
	gStack.push(0);//�ѷ��ʹ��Ķ��㶼ѹ���ջ
	int v;
	while(gStack.size() > 0)
	{
		v = getAdjUnvisitedVertex(gStack.top());
		if(v == -1)
			gStack.pop();
		else
		{
			vertexList[v]->wasVisited = true;
			showVertex(v);
			gStack.push(v);
		}
	}
	cout<< endl;
	//������һ���Ϊ�����ظ�����
	for(int j=0; j<nVerts; j++)
		vertexList[j]->wasVisited = false;
}

//
int Graph::getAdjUnvisitedVertex(int v)
{
	for(int j=0; j<nVerts; j++)
	{
		//1.�ڽӾ����ӦֵΪ1 2.��û�����ʹ�
		if((adjMat[v][j] == 1) && (vertexList[j]->wasVisited == false))//��������
			return j;
	}
	return -1;
}

//
void Graph::showVertex(int v)
{
	cout<< vertexList[v]->Label << " ";
}

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

	cout<< "������������Ľ����" << endl;
	g.DFS();
	cout<< endl;

	cout<< "������������Ľ���� " << endl;
	g.BfS();

	cout<< endl;

	system("pause");
	return 0;
}