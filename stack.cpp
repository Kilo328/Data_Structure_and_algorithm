#include<iostream>
#include"stack.h"
using namespace std;
//��ʼ����ջ
snpointer initstack()
{
	snpointer head = new sNode;
	head->data = 0;
	head->next = NULL;
	return head;
}
//�ж�ջ�Ƿ��
bool isempty(snpointer head)
{
	if (head->data == 0)
		return true;
	else
		return false;
}
//�ж�ջ�Ƿ���
bool isfull(snpointer head)
{
	if (head->data == STACKMAX)
		return true;
	else
		return false;
}
//��Ԫ�س�ջ
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
		cout << "��ջ�ѿգ���ջ����ʧ��!" << endl;
		return -1;
	}
}
//��Ԫ����ջ
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
		cout << "��ջ��������ջ����ʧ��!" << endl;
	}
}
//ȡջ��Ԫ��
int stack_getdata(snpointer head)
{
	if (!isempty(head))
		return head->next->data;
}
//�����ô�ӡ
void sprint(snpointer head)
{
	if (!isempty(head))
	{
		snpointer temp = head->next;
		for (int i = 1; i <= head->data; i++)
		{
			cout << "��" << i << "����������Ϊ:" << temp->data << endl;
			temp = temp->next;
		}
	}
	else
		cout << "��ջΪ��!" << endl;
}