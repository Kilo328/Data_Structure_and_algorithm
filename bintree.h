#pragma once
#include<iostream>
#include<stack>
using namespace std;
struct tNode 
{
	int data;
	tNode* left;
	tNode* right;
};
typedef tNode* tnpointer;
//��ʼ��һ�Ŷ���������
tnpointer initbintree();
//������
tnpointer bintree_insert(tnpointer T, int tdata);
//�������ֵ
tnpointer bintree_findmax(tnpointer T);
//����
tnpointer bintree_find(tnpointer T, int fdata);
//���Ҷ����ĸ���
tnpointer bintree_findfather(tnpointer T, int fdata);
//ɾ�����
tnpointer bintree_delete(tnpointer T, int tdata);
//���� �ݹ�
void bintree_traverse(tnpointer T);
//���� �ǵݹ�
void bintree_traverse2(tnpointer T);
//��΢ֱ�۵ı���
void bintree_traverse3(tnpointer T);
//ɾ����� �ǵݹ�
tnpointer bintree_del(tnpointer T, int tdata);
