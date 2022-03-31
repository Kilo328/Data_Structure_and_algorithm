#include<iostream>
#include"huffmantree.h"
using namespace std;
//�����������
hftnpointer inithuffmantree(mhpointer MH)
{
	hftnpointer temp = NULL;
	for (int i = MH->size-1; i > 0; i--)
	{
		temp = new hNode;
		temp->left = minheap_pop(MH);
		temp->right = minheap_pop(MH);
		temp->weight = temp->left->weight + temp->right->weight;
		MH = minheap_insert(MH, temp);
		delete temp;
		temp = NULL;
	}
	temp= minheap_pop(MH);
	return temp;
}
//��΢ֱ�۵ı���
void huffmantree_traverse(hftnpointer T)
{
	//���ǿգ����б���
	if (T)
	{
		cout << T->weight<< endl;
		if (T->left)
		{
			cout << T->weight << "����";
			huffmantree_traverse(T->left);
		}
		if (T->right)
		{
			cout << T->weight << "���ң�";
			huffmantree_traverse(T->right);
		}
	}
}
