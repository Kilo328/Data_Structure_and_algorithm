#include<iostream>
#include"single_list.h"
#include"stack.h"
#include"circlequeue.h"
using namespace std;
void test()
{
	cqueue Q = initcqueue();
	cqueue_push(Q);
	cqueue_push(Q);
	cqueue_push(Q);
	cqueue_push(Q);
	cqueue_push(Q);
	int x = cqueue_pop(Q);
	cout << x;
}
int main()
{
	test();
	return 0;
}