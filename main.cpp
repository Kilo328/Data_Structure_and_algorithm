#include<iostream>
#include"single_list.h"
using namespace std;
int main()
{
	npointer head = initlist();
	listpushback(head);
	listprint(head);
	listpushfront(head);
	listprint(head);
	listpopfront(head);
	listprint(head);
	return 0;
}