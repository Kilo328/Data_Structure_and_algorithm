#include<iostream>
#include"single_list.h"
#include"stack.h"
#include"circlequeue.h"
#include"bintree.h"
#include"avl.h"
using namespace std;
void test()
{
	avlnpointer AVL = initavl();
	AVL= avl_insert(AVL, 10);
	AVL = avl_insert(AVL, 1);
	AVL = avl_insert(AVL, 13);
	AVL = avl_insert(AVL, 6);
	AVL = avl_insert(AVL, 5);
	AVL = avl_insert(AVL, -1);
	AVL = avl_del(AVL, 1);
	avl_traverse3(AVL);
}
void test2()
{
	tnpointer T = initbintree();
	T = bintree_insert(T, 6);
	T = bintree_insert(T, 1);
	T = bintree_insert(T, 10);
	T = bintree_insert(T, -1);
	T = bintree_insert(T, 13);
	T = bintree_insert(T, 0);
	T = bintree_insert(T, 5);
	bintree_traverse3(T);
	T=bintree_del(T, 1);
	bintree_traverse3(T);
}
int main()
{
	test2();
	return 0;
}