#include<iostream>
#include"minheap.h"
using namespace std;
//��ʼ����С��
mhpointer initminheap(int max)
{
	mhpointer MH=new minheap;
	MH->capacity = max + 1;
	MH->size = 0;
	MH->p = new elementtype[max + 1];
	return MH;
}
//����
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
		cout << "��С������!" << endl;
		return MH;
	}
}
//������С�ѶѶ�Ԫ��
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
		//�����ڵ�����С�����һ��Ԫ�ش���
		MH->p[1].weight = MH->p[MH->size--].weight;
		parent = son = 1;
		//�Ӹ��ڵ㿪ʼ�����Ƚϣ�һֱ�����һ��
		for (; parent * 2 <= MH->size; parent = parent * 2)
		{
			//����һ��temp2���游�ڵ�
			elementtype temp2 = MH->p[parent];
            son = parent * 2;
			//������ָ���С���Ǹ����
			if (son + 1 <= MH->size && MH->p[son].weight >MH->p[son + 1].weight)
				son++;
			//���������Ȩֵ�����ӽ��Ȩֵ����ô�������
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
		cout << "��С���ѿ�,�޷�����!" << endl;
		return NULL;
	}
}
//����
void minheap_traverse(mhpointer MH)
{
	for (int i = 1; i <= MH->size; i++)
	{
		cout <<"��С���е�"<<i<<"��Ԫ��:" << MH->p[i].weight << endl;
	}
}
//�ж��Ƿ���
bool minheap_isfull(mhpointer MH)
{
	if (MH->size ==MH->capacity)
		return true;
	else
		return false;
}
//�ж��Ƿ��
bool minheap_isempty(mhpointer MH)
{
	if (MH->size==0)
		return true;
	else
		return false;
}