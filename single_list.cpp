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
void listinsert(npointer head,npointer node, int data)
{
	npointer temp;
	npointer temp2;
	temp = head;
	//��ʱָ��temp����ָ�������㣬ѭ��ֱ���ߵ����һ���������ҵ�������Ϊֹ
	for (int i = 0; i <= head->data&&temp!=node; i++)
	{
		temp = temp->next;
	}
	//�����ʱָ��tempδָ��ָ����㣬�����ʧ��
	if (temp != node)
		cout << "δ��ѯ������Ľ�㡣" << endl;
	//�����½�����ָ������
	else
	{
		temp2 = temp->next;
		temp->next = new Node;
		temp->next->data = data;
		temp->next->next = temp2;
		//ͷ����н������+1
		++head->data;
	}
}

//�����ɾ��
void listerase(npointer head,npointer node)
{
	npointer temp;
	npointer temp2;
	temp = head;
	if (temp != NULL)
	{
		//��ʱָ��temp����ָ�������㣬ѭ��ֱ���ߵ����һ���������ҵ�������Ϊֹ
		for (int i = 0; i <= head->data && temp->next != node; i++)
		{
			temp = temp->next;
		}
		//�ͷŶ���㣬��������ƴ��
		temp2 = temp->next->next;
		delete (temp->next);
		temp->next = temp2;
		//ͷ����н������-1
		head->data--;
	}
	else
		cout << "����Ϊ��,�޷�ɾ��!" << endl;
}

//��ֵɾ��
void listremove(npointer head, int data,int num)
{
	npointer temp;
	npointer temp2;
	int temp3 = 0;
	temp = head;
	if (temp != NULL)
	{
		//��ʱָ��temp����ָ�������㣬ѭ��ֱ���ߵ����һ���������ҵ�������Ϊֹ
		for (int i = 1; i <= head->data&&temp3!=num; i++)
		{
			if (temp->next->data == data)
			{
				temp2 = temp->next;
				listerase(head, temp2);
				temp3++;
			}
			temp = temp->next;
		}
		if (temp3 !=num)
			cout << "������ֵΪ" << data << "�Ľ��ֻ��" << temp3 << "����" << endl;
	}
	else
		cout << "����Ϊ��,�޷�ɾ��!" << endl;
}

//��ֵ���� ֻ�������ϸ�ֵ�ĵ�һ������λ��
npointer listfind(npointer head, int data)
{
	npointer temp;
	temp = head->next;
	if (temp != NULL)
	{
		//��ʱָ��temp����ָ�������㣬ѭ��ֱ���ߵ����һ���������ҵ����������Ľ��Ϊֹ
		for (int i = 1; i <= head->data && temp->data!=data; i++)
		{
			if(i!=head->data)
				temp = temp->next;
		}
		if (temp->data == data)
			return temp;
		else
		{
			cout << "�����޷��ϸ�ֵ�Ľ��!" << endl;
			return NULL;
		}
	}
	else
	{
		cout << "����Ϊ��,�޷�����!" << endl;
		return NULL;
	}
}

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

//�������������� ð�ݽ���������
void listsort(npointer head)
{
	npointer temp=head->next;
	npointer temp2=temp;
	int temp3=0;
	if (temp != NULL&&temp->next!=NULL)
	{
		for (; temp != NULL; temp = temp->next)
			for (temp2 = temp->next; temp2 != NULL; temp2 = temp2->next)
			{
				if (temp->data > temp2->data)
				{
					temp3 = temp->data;
					temp->data = temp2->data;
					temp2->data = temp3;
				}
			}
	}
	else
		cout << "����Ϊ��!" << endl;
}

//����������ϲ�������������
void listcombine(npointer head1, npointer head2)
{
	npointer temp = head1;
	npointer temp2 = head2;
	for (; temp->next != NULL; temp = temp->next);
	temp->next = temp2->next;
	//����������
	head1->data += head2->data;
	delete temp2;
	listsort(head1);
}

//��ѯ�����ڽ���������Ϊ�շ���-1
int totlsit(npointer head)
{
	if (head->data != 0)
		return head->data;
	else
		return -1;
}