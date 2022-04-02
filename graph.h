#pragma once
#include<iostream>
#include<deque>
#define Maxvcount 10
using namespace std;
typedef int vertex;
typedef int edge;
//图结构
struct gNode 
{
	//结点数
	vertex vcount;
	//边数
	edge ecount;
	//邻接矩阵表示
	int Edge[Maxvcount][Maxvcount];
	//结点表
	vertex vn[Maxvcount];
};
typedef gNode* gnpointer;
//生成一个图
gnpointer initgraph(vertex vcount_);
//判断图中两个顶点间是否存在边
bool graph_adjacent(gnpointer G, vertex x, vertex y);
//在图中插入顶点x
gnpointer graph_vinsert(gnpointer G,vertex x);
//在图中删除顶点x
gnpointer graph_vdel(gnpointer G, vertex x);
//在图中结点xy间添加边
gnpointer graph_eadd(gnpointer G, vertex x,vertex y);
//在图中删除边
gnpointer graph_edel(gnpointer G, vertex x, vertex y);
//求图中G顶点x的第一个邻结点，不存在返回-1
vertex graph_firstneighbor(gnpointer G, vertex x);
//求图中G顶点x除了y以外的下一个邻结点，不存在返回-1
vertex graph_nextneighbor(gnpointer G, vertex x,vertex y);
//设置权值
gnpointer graph_setweight(gnpointer G, vertex x, vertex y, int weight);
//获得权值
int graph_getweight(gnpointer G, vertex x, vertex y);
//bfs广度优先遍历
void graph_bfs(gnpointer G, vertex x);
//dfs深度优先遍历
void graph_dfs(gnpointer G, vertex x);