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
//初始化一颗二叉搜索树
tnpointer initbintree();
//插入结点
tnpointer bintree_insert(tnpointer T, int tdata);
//查找最大值
tnpointer bintree_findmax(tnpointer T);
//查找
tnpointer bintree_find(tnpointer T, int fdata);
//查找定结点的父亲
tnpointer bintree_findfather(tnpointer T, int fdata);
//删除结点
tnpointer bintree_delete(tnpointer T, int tdata);
//遍历 递归
void bintree_traverse(tnpointer T);
//遍历 非递归
void bintree_traverse2(tnpointer T);
//稍微直观的遍历
void bintree_traverse3(tnpointer T);
//删除结点 非递归
tnpointer bintree_del(tnpointer T, int tdata);
