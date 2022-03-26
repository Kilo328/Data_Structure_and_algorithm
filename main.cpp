#include<iostream>
#include"single_list.h"
#include"stack.h"
using namespace std;
int main()
{
	snpointer head = initstack();
	stack_push(head);
	stack_push(head);
	stack_push(head);
	stack_push(head);
	sprint(head);
	return 0;
}