#include<iostream>
#include"stack.h"
using namespace std;
//初始化堆栈
snpointer initstack()
{
	snpointer head = new sNode;
	head->data = 0;
	head->next = NULL;
	return head;
}
//判断栈是否空
bool isempty(snpointer head)
{
	if (head->data == 0)
		return true;
	else
		return false;
}
//判断栈是否满
bool isfull(snpointer head)
{
	if (head->data == STACKMAX)
		return true;
	else
		return false;
}
//让元素出栈
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
		cout << "堆栈已空，出栈操作失败!" << endl;
		return -1;
	}
}
//让元素入栈
void stack_push(snpointer head)
{
	if (!isfull(head))
	{
		snpointer temp = head->next;
		head->next = new sNode;
		head->next->next = temp;
		cout << "请输入入栈的元素值" << endl;
		cin >> head->next->data;
		head->data++;
	}
	else
	{
		cout << "堆栈已满，入栈操作失败!" << endl;
	}
}
//取栈顶元素
int stack_getdata(snpointer head)
{
	if (!isempty(head))
		return head->next->data;
}
//测试用打印
void sprint(snpointer head)
{
	if (!isempty(head))
	{
		snpointer temp = head->next;
		for (int i = 1; i <= head->data; i++)
		{
			cout << "第" << i << "个结点的数据为:" << temp->data << endl;
			temp = temp->next;
		}
	}
	else
		cout << "堆栈为空!" << endl;
}