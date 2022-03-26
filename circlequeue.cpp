#include<iostream>
#include"circlequeue.h"
using namespace std;
//初始化队列
cqueue initcqueue()
{
	const cqueue Q = new qNode;
	Q->front = 0;
	Q->rear = 0;
	return Q;
}
//判断队列是否已满
bool isfullcq(cqueue Q)
{
	if ((Q->rear + 1) %( MAXSIZE+1) == Q->front)
		return true;
	else
		return false;
}
//判断队列是否为空
bool isemptycq(cqueue Q)
{
	if (Q->rear == Q->front)
		return true;
	else
		return false;
}
//入队
void cqueue_push(cqueue Q)
{
	if (!isfullcq(Q))
	{
		cout << "请输入入队的元素值:" << endl;
		cin >> Q->queue[(Q->rear+1)% (MAXSIZE + 1)];
		Q->rear = (Q->rear + 1) % (MAXSIZE + 1);
	}
	else
		cout << "队列已满，无法入队!" << endl;
}
//出队
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
		cout << "队列已空，无法出队!" << endl;
		return -1;
	}
}
//测试用打印
void cqprint(cqueue Q) 
{
	for (int i = Q->front; i != Q->rear; i = (i + 1) % (MAXSIZE + 1))
		cout << Q->queue[i+1] << endl;
}