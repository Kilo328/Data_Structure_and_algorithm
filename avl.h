#pragma once
#include<iostream>
#include<stack>
using namespace std;
struct avlNode
{
	int data;
	int height;
	avlNode* left;
	avlNode* right;
};
typedef avlNode* avlnpointer;
//���ֵ����
int MAX(int height1, int height2);
//�߶Ȼ�ȡ����
int Height(avlnpointer AVL);
//����avl��
avlnpointer initavl();
//������
avlnpointer avl_insert(avlnpointer AVL,int data);
//������� �ݹ�
void avl_traverse(avlnpointer AVL);
//������� �ǵݹ�
void avl_traverse2(avlnpointer AVL);
//��΢ֱ�۵ı���
void avl_traverse3(avlnpointer AVL);
//ɾ�����
avlnpointer avl_del(avlnpointer AVL,int data);
//�������ֵ
avlnpointer avl_findmax(avlnpointer AVL);
//������Сֵ
avlnpointer avl_findmin(avlnpointer AVL);
//LL��ת
avlnpointer LL_rotation(avlnpointer AVL);
//RR��ת
avlnpointer RR_rotation(avlnpointer AVL);
//RL��ת
avlnpointer RL_rotation(avlnpointer AVL);
//LR��ת
avlnpointer LR_rotation(avlnpointer AVL);