#include<iostream>
#include"stack.h"
using namespace std;
//³õÊ¼»¯¶ÑÕ»
snpointer initstack()
{
	snpointer head = new sNode;
	head->data = 0;
	head->next = NULL;
	return head;
}
//ÅĞ¶ÏÕ»ÊÇ·ñ¿Õ
bool isempty(snpointer head)
{
	if (head->data == 0)
		return true;
	else
		return false;
}
//ÅĞ¶ÏÕ»ÊÇ·ñÂú
bool isfull(snpointer head)
{
	if (head->data == STACKMAX)
		return true;
	else
		return false;
}
//ÈÃÔªËØ³öÕ»
int stack_pop(snpointer head)
{
	if (!isempty(head))
	{
		snpointer temp = head->next;
		int temp2 = 0;
		head->next = temp->next;
		temp2 = temp->data;
		delete temp;
		head->data--;
		return temp2;
	}
	else
	{
		cout << "¶ÑÕ»ÒÑ¿Õ£¬³öÕ»²Ù×÷Ê§°Ü!" << endl;
		return -1;
	}
}
//ÈÃÔªËØÈëÕ»
void stack_push(snpointer head,int pushdata)
{
	if (!isfull(head))
	{
		snpointer temp = head->next;
		head->next = new sNode;
		head->next->next = temp;
		head->next->data = pushdata;
		head->data++;
	}
	else
	{
		cout << "¶ÑÕ»ÒÑÂú£¬ÈëÕ»²Ù×÷Ê§°Ü!" << endl;
	}
}
//È¡Õ»¶¥ÔªËØ
int stack_getdata(snpointer head)
{
	if (!isempty(head))
		return head->next->data;
}
//²âÊÔÓÃ´òÓ¡
void sprint(snpointer head)
{
	if (!isempty(head))
	{
		snpointer temp = head->next;
		for (int i = 1; i <= head->data; i++)
		{
			cout << "µÚ" << i << "¸ö½áµãµÄÊı¾İÎª:" << temp->data << endl;
			temp = temp->next;
		}
	}
	else
		cout << "¶ÑÕ»Îª¿Õ!" << endl;
}