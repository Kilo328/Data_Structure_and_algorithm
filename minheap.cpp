#include<iostream>
#include"minheap.h"
using namespace std;
//初始化最小堆
mhpointer initminheap(int max)
{
	mhpointer MH=new minheap;
	MH->capacity = max + 1;
	MH->size = 0;
	MH->p = new elementtype[max + 1];
	return MH;
}
//插入
mhpointer minheap_insert(mhpointer MH,elementtype* node)
{
	if (!minheap_isfull(MH))
	{
		MH->p[++MH->size] = *node;
		int parent=MH->size, son=MH->size;
		for (parent=parent/2; parent> 0; son=parent,parent=parent/2)
		{
			elementtype temp;
			temp.weight = MH->p[parent].weight;
			temp.left = MH->p[parent].left;
			temp.right = MH->p[parent].right;
			if (MH->p[parent].weight > MH->p[son].weight)
			{
				MH->p[parent].weight = MH->p[son].weight;
				MH->p[parent].left = MH->p[son].left;
				MH->p[parent].right = MH->p[son].right;
				MH->p[son].weight = temp.weight;
				MH->p[son].left = temp.left;
				MH->p[son].right = temp.right;
			}
		}
		return MH;
	}
	else
	{
		cout << "最小堆已满!" << endl;
		return MH;
	}
}
//弹出最小堆堆顶元素
elementtype* minheap_pop(mhpointer MH)
{
	if (!minheap_isempty(MH))
	{
		int parent, son;
		elementtype* temp = new elementtype;
		int temp3;
		temp->weight= MH->p[1].weight;
		temp->left = MH->p[1].left;
		temp->right = MH->p[1].right;
		//将根节点用最小堆最后一个元素代替
		MH->p[1].weight = MH->p[MH->size--].weight;
		parent = son = 1;
		//从根节点开始遍历比较，一直到最后一行
		for (; parent * 2 <= MH->size; parent = parent * 2)
		{
			//定义一个temp2保存父节点
			elementtype temp2 = MH->p[parent];
            son = parent * 2;
			//将儿子指向更小的那个结点
			if (son + 1 <= MH->size && MH->p[son].weight >MH->p[son + 1].weight)
				son++;
			//如果父结点的权值大于子结点权值，那么交换结点
			if (MH->p[parent].weight > MH->p[son].weight)
			{
				MH->p[parent].weight = MH->p[son].weight;
				MH->p[parent].left = MH->p[son].left;
				MH->p[parent].right = MH->p[son].right;
				MH->p[son].weight = temp2.weight;
				MH->p[son].left = temp2.left;
				MH->p[son].right = temp2.right;
			}
		}
		return temp;
	}
	else
	{
		cout << "最小堆已空,无法弹出!" << endl;
		return NULL;
	}
}
//遍历
void minheap_traverse(mhpointer MH)
{
	for (int i = 1; i <= MH->size; i++)
	{
		cout <<"最小堆中第"<<i<<"个元素:" << MH->p[i].weight << endl;
	}
}
//判断是否满
bool minheap_isfull(mhpointer MH)
{
	if (MH->size ==MH->capacity)
		return true;
	else
		return false;
}
//判断是否空
bool minheap_isempty(mhpointer MH)
{
	if (MH->size==0)
		return true;
	else
		return false;
}