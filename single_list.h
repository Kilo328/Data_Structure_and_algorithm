#pragma once
//��������
#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
typedef Node* npointer;
//��ʼ������
npointer initlist();

//β������
void listpushback(npointer head);

//ͷ������
void listpushfront(npointer head);

//β��ɾ��
void listpopback(npointer head);

//ͷ��ɾ��
void listpopfront(npointer head);

//�ڶ���㴦���룬���뵽����
void listinsert(npointer head, npointer node, int data);

//�����ɾ��
void listerase(npointer head,npointer node);

//��ֵɾ��
void listremove(npointer head,int data,int num);

//��ֵ���� ֻ�������ϸ�ֵ�ĵ�һ������λ��
npointer listfind(npointer head,int data);

//��˳���ӡ����
void listprint(npointer head);

//��������������
void listsort(npointer head);

//����������ϲ�������������
void listcombine(npointer head1,npointer head2);

//��ѯ�����ڽ���������Ϊ�շ���-1
int totlsit(npointer head);