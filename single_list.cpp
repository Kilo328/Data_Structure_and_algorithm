#include<iostream>
#include"single_list.h"
using namespace std;
//��ʼ������
npointer initlist() 
{
	npointer head = new Node;
	head->next = NULL;
	head->data = 0;
	return head;
}

//β������
void listpushback(npointer head)
{
	npointer temp;
	temp = head;
	//����ʱָ��temp����ָ����������һ������
	for (int i = 1; i <= head->data; i++)
	{
		temp = temp->next;
	}
	//����β�������½��
	temp->next = new Node;
	temp = temp->next;
	temp->next= NULL;
	cout << "������β�������������:" << endl;
	cin >> temp->data;
	//��ͷ����д���������������+1
	++head->data;
}

//ͷ������
void listpushfront(npointer head)
{
	npointer temp;
	//��ʱָ��ָ������ԭ���ĵ�һ������
	temp = head;
	temp = temp->next;
	//���½�����ͷ����
	head->next = new Node;
	cout << "������ͷ�������������:" << endl;
	cin >> head->next->data;
	//��ԭ��������½���
	head->next->next = temp;
	//��ͷ����д���������������+1
	++head->data;
}

//β��ɾ��
void listpopback(npointer head)
{
	//���ж������Ƿ�Ϊ�գ���Ϊ���򲻿ɽ���ɾ������
	if (head->data != 0)
	{
		npointer temp;
		temp = head;
		//��ʱָ�����ָ���������ڶ������ݣ���Ϊ���������㽫��Ϊ����β��㣬Ҫ��β����nextָ�����ָ�ղ���
		for (int i = 1; i < head->data; i++)
		{
			temp = temp->next;
		}
		//�ͷ�ɾ���Ľ��
		delete temp->next;
		//�µ�β���nextָ��ָ��
		temp->next = NULL;
		//��ͷ����д���������������-1
		--head->data;
	}
	else
		cout << "����Ϊ��,�޷�ɾ��!" << endl;
}

//ͷ��ɾ��
void listpopfront(npointer head)
{
	//���ж������Ƿ�Ϊ�գ���Ϊ���򲻿ɽ���ɾ������
	if (head->data != 0)
	{
		npointer temp;
		//��ʱָ��ָ��ԭ����ĵڶ������ݣ�������ĵ�һ�����ݣ�
		temp = head->next;
		temp = temp->next;
		//�ͷ�ɾ���Ľ��
		delete head->next;
		//��ʣ�µ��������ͷ����
		head->next = temp;
		//��ͷ����д���������������-1
		--head->data;
	}
	else
		cout << "����Ϊ��,�޷�ɾ��!" << endl;
}

//�ڶ���㴦���룬���뵽����
void listinsert(npointer node, int data)
{

}

//�����ɾ��
void listerase(npointer node)
{

}

//��ֵɾ��
void listremove(npointer head, int num)
{

}

//��ֵ����
/*npointer listfind(npointer head, int data)
{

}*/

//��˳���ӡ����
void listprint(npointer head)
{
	npointer temp;
	temp = head->next;
	for (int i = 1; i <= head->data; i++)
	{
		cout << "��" << i << "����������Ϊ:" << temp->data << endl;
		temp = temp->next;
	}
	if (head->data == 0)
		cout << "����Ϊ��!" << endl;
}

//��������������
void listsort(npointer head)
{

}

//����������ϲ�������������
void listcombine(npointer head1, npointer head2)
{

}

//��ѯ�����ڽ���������Ϊ�շ���-1
int totlsit(npointer head)
{
	if (head->data != 0)
		return head->data;
	else
		return -1;
}