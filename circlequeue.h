#pragma once
#include<iostream>
#define MAXSIZE 5
using namespace std;
//��ѭ�����е�ʵ��,ͨ����ʹ��һ���ռ������ѭ������ʹ��flag���
struct qNode
{
	int queue[MAXSIZE+1];
	int front;
	int rear;
};
typedef qNode* cqueue;
//��ʼ������
cqueue initcqueue();
//�ж϶����Ƿ�����
bool isfullcq(cqueue Q);
//�ж϶����Ƿ�Ϊ��
bool isemptycq(cqueue Q);
//���
void cqueue_push(cqueue Q);
//����
int cqueue_pop(cqueue Q);
//�����ô�ӡ
void cqprint(cqueue Q);