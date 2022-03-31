#include<iostream>
#include"single_list.h"
#include"stack.h"
#include"circlequeue.h"
#include"bintree.h"
#include"avl.h"
#include"minheap.h"
using namespace std;
void test()
{
	mhpointer MH = initminheap(10);
	hNode* x1 = new hNode;
	hNode* x2 = new hNode;
	hNode* x3 = new hNode;
	hNode* x4 = new hNode;
	hNode* x5 = new hNode;
	hNode* x6 = new hNode;
	x1->weight = 10;
	x2->weight = 5;
	x3->weight = 11;
	x4->weight = 1;
	x5->weight = 4;
	x6->weight = 21;
	MH = minheap_insert(MH,x1);
	MH = minheap_insert(MH,x2);
	MH = minheap_insert(MH,x3);
	MH = minheap_insert(MH,x4);
	MH = minheap_insert(MH,x5);
    MH = minheap_insert(MH,x6);
	minheap_traverse(MH);
	elementtype* min = minheap_pop(MH);
	minheap_traverse(MH);
	cout << min->weight;
}
int main()
{
	test();
	return 0;
}