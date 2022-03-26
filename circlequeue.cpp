#include<iostream>
#include"circlequeue.h"
using namespace std;
//��ʼ������
cqueue initcqueue()
{
	const cqueue Q = new qNode;
	Q->front = 0;
	Q->rear = 0;
	return Q;
}
//�ж϶����Ƿ�����
bool isfullcq(cqueue Q)
{
	if ((Q->rear + 1) %( MAXSIZE+1) == Q->front)
		return true;
	else
		return false;
}
//�ж϶����Ƿ�Ϊ��
bool isemptycq(cqueue Q)
{
	if (Q->rear == Q->front)
		return true;
	else
		return false;
}
//���
void cqueue_push(cqueue Q)
{
	if (!isfullcq(Q))
	{
		cout << "��������ӵ�Ԫ��ֵ:" << endl;
		cin >> Q->queue[(Q->rear+1)% (MAXSIZE + 1)];
		Q->rear = (Q->rear + 1) % (MAXSIZE + 1);
	}
	else
		cout << "�����������޷����!" << endl;
}
//����
int cqueue_pop(cqueue Q)
{
	if (!isemptycq(Q))
	{
		Q->front = (Q->front + 1) % (MAXSIZE + 1);
		int temp = Q->queue[Q->front];
		Q->queue[Q->front] = 0;
		return temp;
	}
	else
	{
		cout << "�����ѿգ��޷�����!" << endl;
		return -1;
	}
}
//�����ô�ӡ
void cqprint(cqueue Q) 
{
	for (int i = Q->front; i != Q->rear; i = (i + 1) % (MAXSIZE + 1))
		cout << Q->queue[i+1] << endl;
}