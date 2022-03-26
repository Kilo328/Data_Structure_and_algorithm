#pragma once
//堆栈的链式储存结构
#include<iostream>
#define STACKMAX 10
using namespace std;
struct sNode
{
	int data;
	sNode* next;
};
typedef sNode* snpointer;
//初始化堆栈
snpointer initstack();
//判断栈是否空
bool isempty(snpointer head);
//判断栈是否满
bool isfull(snpointer head);
//让元素出栈
int stack_pop(snpointer head);
//让元素入栈
void stack_push(snpointer head);
//取栈顶元素
int stack_getdata(snpointer head);
//测试用打印
void sprint(snpointer head);