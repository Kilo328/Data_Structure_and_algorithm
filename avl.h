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
//最大值函数
int MAX(int height1, int height2);
//高度获取函数
int Height(avlnpointer AVL);
//生成avl树
avlnpointer initavl();
//插入结点
avlnpointer avl_insert(avlnpointer AVL,int data);
//先序遍历 递归
void avl_traverse(avlnpointer AVL);
//中序遍历 非递归
void avl_traverse2(avlnpointer AVL);
//稍微直观的遍历
void avl_traverse3(avlnpointer AVL);
//删除结点
avlnpointer avl_del(avlnpointer AVL,int data);
//查找最大值
avlnpointer avl_findmax(avlnpointer AVL);
//查找最小值
avlnpointer avl_findmin(avlnpointer AVL);
//LL旋转
avlnpointer LL_rotation(avlnpointer AVL);
//RR旋转
avlnpointer RR_rotation(avlnpointer AVL);
//RL旋转
avlnpointer RL_rotation(avlnpointer AVL);
//LR旋转
avlnpointer LR_rotation(avlnpointer AVL);