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
	//ָ���Ԫ�������ָ��p
	elementtype* p;
	//����Ԫ����
	int size;
	//���������
	int capacity;
};
typedef minheap* mhpointer;
//��ʼ����С��
mhpointer initminheap(int max);
//����
mhpointer minheap_insert(mhpointer MH, elementtype* node);
//������С�ѶѶ�Ԫ��
elementtype* minheap_pop(mhpointer MH);
//����
void minheap_traverse(mhpointer MH);
//�ж��Ƿ���
bool minheap_isfull(mhpointer MH);
//�ж��Ƿ��
bool minheap_isempty(mhpointer MH);