#include<iostream>
#include"single_list.h"
using namespace std;
int main()
{
	npointer head1 = initlist();
	listpushback(head1);
	listpushback(head1);
	listpushback(head1);
	npointer head2 = initlist();
	listpushback(head2);
	listpushback(head2);
	listpushback(head2);
	listcombine(head1,head2);
	listprint(head1);
	return 0;
}