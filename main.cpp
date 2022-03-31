#include<iostream>
#include"single_list.h"
#include"stack.h"
#include"circlequeue.h"
#include"bintree.h"
#include"avl.h"
#include"minheap.h"
#include"huffmantree.h"
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
	x1->weight = 5;
	x1->left = x1->right = NULL;
	x2->weight = 10;
	x2->left = x2->right = NULL;
	x3->weight = 6;
	x3->left = x3->right = NULL;
	x4->weight = 1;
	x4->left = x4->right = NULL;
	x5->weight = 4;
	x5->left = x5->right = NULL;
	x6->weight = 3;
	x6->left = x6->right = NULL;
	MH = minheap_insert(MH,x1);
	MH = minheap_insert(MH,x2);
	MH = minheap_insert(MH,x3);
	MH = minheap_insert(MH,x4);
	MH = minheap_insert(MH,x5);
    MH = minheap_insert(MH,x6);
	hftnpointer huffmantree = inithuffmantree(MH);
	huffmantree_traverse(huffmantree);
}
int main()
{
	test();
	return 0;
}