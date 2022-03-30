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
//生成avl树
avlnpointer initavl();
//插入结点
avlnpointer avl_insert(avlnpointer AVL);
//先序遍历 递归
void avl_traverse(avlnpointer AVL);
//中序遍历 非递归
void avl_traverse2(avlnpointer AVL);
//删除结点
avlnpointer avl_del(avlnpointer AVL);
//查找最大值
avlnpointer avl_findmax(avlnpointer AVL);
//查找最小值
avlnpointer avl_findmin(avlnpointer AVL);
