#include<iostream>
#include"avl.h"
using namespace std;
//生成avl树
avlnpointer initavl()
{
	avlnpointer AVL = NULL;
	return AVL;
}
//插入结点
avlnpointer avl_insert(avlnpointer AVL)
{

}
//先序遍历 递归
void avl_traverse(avlnpointer AVL)
{
	if (AVL)
	{
		cout << AVL->data << endl;
		avl_traverse(AVL->left);
		avl_traverse(AVL->right);
	}
}
//中序遍历 非递归
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
//删除结点
avlnpointer avl_del(avlnpointer AVL)
{

}
//查找最大值
avlnpointer avl_findmax(avlnpointer AVL)
{

}
//查找最小值
avlnpointer avl_findmin(avlnpointer AVL)
{

}
