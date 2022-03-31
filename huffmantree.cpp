#include<iostream>
#include"huffmantree.h"
using namespace std;
//构造哈夫曼树
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
//稍微直观的遍历
void huffmantree_traverse(hftnpointer T)
{
	//结点非空，进行遍历
	if (T)
	{
		cout << T->weight<< endl;
		if (T->left)
		{
			cout << T->weight << "的左：";
			huffmantree_traverse(T->left);
		}
		if (T->right)
		{
			cout << T->weight << "的右：";
			huffmantree_traverse(T->right);
		}
	}
}
