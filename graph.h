#pragma once
#include<iostream>
#include<deque>
#define Maxvcount 10
using namespace std;
typedef int vertex;
typedef int edge;
//ͼ�ṹ
struct gNode 
{
	//�����
	vertex vcount;
	//����
	edge ecount;
	//�ڽӾ����ʾ
	int Edge[Maxvcount][Maxvcount];
	//����
	vertex vn[Maxvcount];
};
typedef gNode* gnpointer;
//����һ��ͼ
gnpointer initgraph(vertex vcount_);
//�ж�ͼ������������Ƿ���ڱ�
bool graph_adjacent(gnpointer G, vertex x, vertex y);
//��ͼ�в��붥��x
gnpointer graph_vinsert(gnpointer G,vertex x);
//��ͼ��ɾ������x
gnpointer graph_vdel(gnpointer G, vertex x);
//��ͼ�н��xy����ӱ�
gnpointer graph_eadd(gnpointer G, vertex x,vertex y);
//��ͼ��ɾ����
gnpointer graph_edel(gnpointer G, vertex x, vertex y);
//��ͼ��G����x�ĵ�һ���ڽ�㣬�����ڷ���-1
vertex graph_firstneighbor(gnpointer G, vertex x);
//��ͼ��G����x����y�������һ���ڽ�㣬�����ڷ���-1
vertex graph_nextneighbor(gnpointer G, vertex x,vertex y);
//����Ȩֵ
gnpointer graph_setweight(gnpointer G, vertex x, vertex y, int weight);
//���Ȩֵ
int graph_getweight(gnpointer G, vertex x, vertex y);
//bfs������ȱ���
void graph_bfs(gnpointer G, vertex x);
//dfs������ȱ���
void graph_dfs(gnpointer G, vertex x);