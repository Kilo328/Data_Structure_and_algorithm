#pragma once
//��ջ����ʽ����ṹ
#include<iostream>
#define STACKMAX 10
using namespace std;
struct sNode
{
	int data;
	sNode* next;
};
typedef sNode* snpointer;
//��ʼ����ջ
snpointer initstack();
//�ж�ջ�Ƿ��
bool isempty(snpointer head);
//�ж�ջ�Ƿ���
bool isfull(snpointer head);
//��Ԫ�س�ջ
int stack_pop(snpointer head);
//��Ԫ����ջ
void stack_push(snpointer head);
//ȡջ��Ԫ��
int stack_getdata(snpointer head);
//�����ô�ӡ
void sprint(snpointer head);