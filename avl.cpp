#include<iostream>
#include"avl.h"
using namespace std;
//����avl��
avlnpointer initavl()
{
	avlnpointer AVL = NULL;
	return AVL;
}
//������
avlnpointer avl_insert(avlnpointer AVL)
{

}
//������� �ݹ�
void avl_traverse(avlnpointer AVL)
{
	if (AVL)
	{
		cout << AVL->data << endl;
		avl_traverse(AVL->left);
		avl_traverse(AVL->right);
	}
}
//������� �ǵݹ�
void avl_traverse2(avlnpointer AVL)
{
	stack<avlnpointer> S;
	while (!empty(S) && AVL)
	{
		while (AVL)
		{
			S.push(AVL);
			AVL = AVL->left;
		}
		if (!empty(S))
		{
			AVL = S.top();
			S.pop();
			cout << AVL->data << endl;
			AVL = AVL->right;
		}
	}
}
//ɾ�����
avlnpointer avl_del(avlnpointer AVL)
{

}
//�������ֵ
avlnpointer avl_findmax(avlnpointer AVL)
{

}
//������Сֵ
avlnpointer avl_findmin(avlnpointer AVL)
{

}
