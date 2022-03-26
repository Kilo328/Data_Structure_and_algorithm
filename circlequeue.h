#pragma once
#include<iostream>
#define MAXSIZE 5
using namespace std;
//对循环队列的实现,通过少使用一个空间来完成循环而非使用flag标记
struct qNode
{
	int queue[MAXSIZE+1];
	int front;
	int rear;
};
typedef qNode* cqueue;
//初始化队列
cqueue initcqueue();
//判断队列是否已满
bool isfullcq(cqueue Q);
//判断队列是否为空
bool isemptycq(cqueue Q);
//入队
void cqueue_push(cqueue Q);
//出队
int cqueue_pop(cqueue Q);
//测试用打印
void cqprint(cqueue Q);