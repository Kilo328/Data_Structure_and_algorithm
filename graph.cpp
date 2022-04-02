#include<iostream>
#include"graph.h"
using namespace std;
bool visit[Maxvcount];
//����һ��ͼ
gnpointer initgraph(vertex vcount_)
{
	gnpointer G = new gNode;
	G->vcount = vcount_;
	G->ecount = 0;
	for(int i=0;i<Maxvcount;i++)
		for (int j = 0; j < Maxvcount; j++)
	         G->Edge[i][j] =0;
	for (int i = 0; i < vcount_; i++)
		G->vn[i] = 1;
	return G;
}
//�ж�ͼ������������Ƿ���ڱ�
bool graph_adjacent(gnpointer G, vertex x, vertex y)
{
	if (G->Edge[x - 1][y - 1] != 0)
		return true;
	else
		return false;
}
//��ͼ�в��붥��x
gnpointer graph_vinsert(gnpointer G, vertex x)
{
	if (G->vn[x - 1] != 1)
	{
		G->vcount++;
		G->vn[x - 1] = 1;
		return G;
	}
	else
	{
		cout << "�����Ѵ���!" << endl;
		return G;
	}
}
//��ͼ��ɾ������x
gnpointer graph_vdel(gnpointer G, vertex x)
{
	if (G->vn[x - 1] = 1)
	{
		G->vcount--;
		G->vn[x - 1] = 0;
		for (int i = 0; i < Maxvcount; i++)
		{
			G->Edge[x - 1][i] = 0;
			G->Edge[i][x-1] = 0;
		}
		return G;
	}
	else
	{
		cout << "���㲻����!" << endl;
		return G;
	}
}
//��ͼ�н��xy����ӱ�
gnpointer graph_eadd(gnpointer G, vertex x, vertex y)
{
	if(x==y)
	{
		cout << "�������������!" << endl;
		return G;
	}
	else if (G->Edge[x - 1][y - 1] ==0)
	{
		G->ecount++;
		G->Edge[x - 1][y - 1] = 1;
		G->Edge[y - 1][x - 1] = 1;
		return G;
	}
	else
	{
		cout << "�����Ѵ��ڱ�!" << endl;
		return G;
	}
}
//��ͼ��ɾ����
gnpointer graph_edel(gnpointer G, vertex x, vertex y)
{
	if (x == y)
	{
		cout << "�����߲�����!" << endl;
		return G;
	}
	else if (G->Edge[x - 1][y - 1] != 0)
	{
		G->ecount--;
		G->Edge[x - 1][y - 1] = 0;
		G->Edge[y - 1][x - 1] = 0;
		return G;
	}
	else
	{
		cout << "���䲻���ڱ�!" << endl;
		return G;
	}
}
//��ͼ��G����x�ĵ�һ���ڽ�㣬�����ڷ���-1
vertex graph_firstneighbor(gnpointer G, vertex x)
{
	int i = 0;
	for (; i < Maxvcount; i++)
	{
		if (G->Edge[x - 1][i] != 0)
			return i + 1;
	}
		return -1;

}
//��ͼ��G����x����y�������һ���ڽ�㣬�����ڷ���-1
vertex graph_nextneighbor(gnpointer G, vertex x, vertex y)
{
	int i = 0;
	for (; y+i < Maxvcount; i++)
	{
		if (G->Edge[x - 1][y+i] != 0)
			return y+i+1;
	}
		return -1;
}
//����Ȩֵ
gnpointer graph_setweight(gnpointer G, vertex x,vertex y,int weight)
{
	if (G->Edge[x - 1][y - 1] != 0)
	{
		G->Edge[x - 1][y - 1] = weight;
		return G;
	}
	else
	{
		cout << "�ý��䲻���ڱ�!" << endl;
		return G;
	}
}
//���Ȩֵ
int graph_getweight(gnpointer G, vertex x, vertex y)
{
	if (G->Edge[x - 1][y - 1] != 0)
		return 	G->Edge[x - 1][y - 1];
	else
		return -1;
}
//bfs������ȱ���
void graph_bfs(gnpointer G, vertex x)
{
	bool visit2[Maxvcount];
	vertex temp;
	for (int i = 0; i < Maxvcount; i++)
		visit2[i] =0;
	deque<vertex>Q;
	cout << x << endl;
	visit2[x - 1] = true;
	Q.push_back(x);
	while (!Q.empty())
	{
		temp = Q.front();
		Q.pop_front();
		for (vertex y = graph_firstneighbor(G, temp); y > 0; y = graph_nextneighbor(G, temp, y))
		{
			if (visit2[y - 1] == 0)
			{
				cout << y << endl;
				visit2[y - 1] = true;
				Q.push_back(y);
			}
		}
	}
}
//dfs������ȱ���
void graph_dfs(gnpointer G, vertex x)
{
	cout << x << endl;
	visit[x - 1] = true;
	for (vertex y = graph_firstneighbor(G, x); y > 0; y = graph_nextneighbor(G, x, y))
	{
		if (visit[y - 1] == 0)
		{
			graph_dfs(G, y);
		}
	}
}