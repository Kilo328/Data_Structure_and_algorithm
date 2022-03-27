#include<iostream>
#include"single_list.h"
#include"stack.h"
#include"circlequeue.h"
#include"bintree.h"
using namespace std;
void test()
{
	tnpointer T = initbintree();
	T = bintree_insert(T, 2);
	T = bintree_insert(T, 4);
	T = bintree_insert(T, 0);
	T = bintree_insert(T, 5);
	T = bintree_insert(T, 1);
	T = bintree_insert(T, 6);
	T = bintree_insert(T, 3);
	T = bintree_del(T, 4);
	bintree_traverse3(T);
}
int main()
{
	test();
	return 0;
}