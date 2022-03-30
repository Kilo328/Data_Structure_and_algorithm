#pragma once
#include<iostream>
#include<stack>
using namespace std;
struct avlNode
{
	int data;
	int BF;
	avlNode* left;
	avlNode* right;
};
typedef avlNode* avlnpointer;
//����avl��
avlnpointer initavl();
//������
avlnpointer avl_insert(avlnpointer AVL);
//������� �ݹ�
void avl_traverse(avlnpointer AVL);
//������� �ǵݹ�
void avl_traverse2(avlnpointer AVL);
//ɾ�����
avlnpointer avl_del(avlnpointer AVL);
//�������ֵ
avlnpointer avl_findmax(avlnpointer AVL);
//������Сֵ
avlnpointer avl_findmin(avlnpointer AVL);
