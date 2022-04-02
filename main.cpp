#include<iostream>
#include"single_list.h"
#include"stack.h"
#include"circlequeue.h"
#include"bintree.h"
#include"avl.h"
#include"minheap.h"
#include"huffmantree.h"
#include"graph.h"
using namespace std;
void test()
{
	gnpointer G = initgraph(8);
	G = graph_eadd(G, 1, 5);
	G = graph_eadd(G, 2, 6);
	G = graph_eadd(G, 1, 2);
	G = graph_eadd(G, 6, 3);
	G = graph_eadd(G, 6, 7);
	G = graph_eadd(G, 3, 4);
	G = graph_eadd(G, 3, 7);
	G = graph_eadd(G, 7, 4);
	G = graph_eadd(G, 7, 8);
	G = graph_eadd(G, 4, 8);
	graph_bfs(G, 2);
}
int main()
{
    test();
	return 0;
}