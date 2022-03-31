#pragma once
#include<iostream>
#define elementtype hNode
using namespace std;
struct hNode 
{
	int weight;
	hNode* left;
	hNode* right;
};
struct minheap
{
	//指向堆元素数组的指针p
	elementtype* p;
	//堆中元素数
	int size;
	//堆最大容量
	int capacity;
};
typedef minheap* mhpointer;
//初始化最小堆
mhpointer initminheap(int max);
//插入
mhpointer minheap_insert(mhpointer MH, elementtype* node);
//弹出最小堆堆顶元素
elementtype* minheap_pop(mhpointer MH);
//遍历
void minheap_traverse(mhpointer MH);
//判断是否满
bool minheap_isfull(mhpointer MH);
//判断是否空
bool minheap_isempty(mhpointer MH);