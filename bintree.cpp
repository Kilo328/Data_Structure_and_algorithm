#include<iostream>
#include"bintree.h"
using namespace std;
//初始化一颗二叉搜索树
tnpointer initbintree()
{
	tnpointer T = NULL;
	return T;
}
//插入结点 递归
tnpointer bintree_insert(tnpointer T, int tdata)
{
	//递归至某个位置为空时，插入结点
	if (!T)
	{
		T = new tNode;
		T->data = tdata;
		T->left = NULL;
		T->right = NULL;
	}
	else
	{
		if (tdata < T->data)
			T->left=bintree_insert(T->left, tdata);
		else if (tdata > T->data)
			T->right=bintree_insert(T->right,tdata);
		else
		{
			cout << "该树中已有该结点，请勿重复插入!" << endl;
		}
	}
	return T;
}
//查找最大值
tnpointer bintree_findmax(tnpointer T)
{
	while (T->right)
		T = T->right;
	return T;
}
//查找
tnpointer bintree_find(tnpointer T, int fdata)
{
	if (T)
	{
		tnpointer Temp = T;
		while (Temp)
		{
			if (Temp->data < fdata)
				Temp = Temp->right;
			else if (Temp->data > fdata)
				Temp = Temp->left;
			else
				break;
		}
		//判断是否遍历完所有结点仍未找到
		if (!Temp)
		{
			cout << "结点不存在!" << endl;
			return NULL;
		}
		else
			return Temp;
	}
	else
		return NULL;
}
//查找定结点的父亲
tnpointer bintree_findfather(tnpointer T, int fdata)
{
	if (T)
	{
		tnpointer Temp = T;
		tnpointer Temp2 = NULL;;
		while (Temp)
		{
			if (Temp->data < fdata)
			{
				Temp2 = Temp;
				Temp = Temp->right;
			}
			else if (Temp->data > fdata)
			{
				Temp2 = Temp;
				Temp = Temp->left;
			}
			else
				break;
		}
		//判断是否遍历完所有结点仍未找到
		if (!Temp)
		{
			cout << "结点不存在!" << endl;
			return NULL;
		}
		else
			return Temp2;
	}
	else
		return NULL;
}
//删除结点 递归
tnpointer bintree_delete(tnpointer T, int tdata)
{
	tnpointer Temp;
	//递归遍历寻找要删除的元素位置
	if (!T)
		cout << "未查到到要删除的元素!" << endl;
	else if (tdata < T->data)
		T->left = bintree_delete(T->left, tdata);
	else if (tdata >T->data)
		T->right = bintree_delete(T->right, tdata);
	//判断删除结点有几个儿子
	else
	{
		//左右儿子均有，将左子树最大值替代该结点值并删除左子树最大结点
		if (T->left && T->right)
		{
			Temp = bintree_findmax(T->left);
			T->data = Temp->data;
			T->left = bintree_delete(T->left, Temp->data);
		}
		//只有一个或没儿子
		else
		{
			Temp = T;
			if (!T->left)
				T = T->right;
			else if (!T->right)
				T = T->left;
			delete(Temp);
			Temp = NULL;
		}
	}
	return T;
}
//删除结点 非递归
tnpointer bintree_del(tnpointer T, int tdata)
{
	if (T)
	{
		tnpointer Temp = T;
		tnpointer Temp2 = NULL;
		tnpointer Temp3 = NULL;
		//遍历寻找要删除的元素位置
		while (Temp)
		{
			if (Temp->data < tdata)
			{
				Temp2 = Temp;
				Temp = Temp->right;
			}
			else if (Temp->data > tdata)
			{
				Temp2 = Temp;
				Temp = Temp->left;
			}
			else
				break;
		}
		if (!Temp)
			return T;
		//判断删除结点有几个儿子
		else
		{
			//左右儿子均有，将左子树最大值替代该结点值并删除左子树最大结点
			if (Temp->left && Temp->right)
			{
				Temp3 = Temp;
				Temp2 = Temp->left;
				while (Temp2->right)
				{
					Temp3 = Temp2;
					Temp2 = Temp2->right;
				}
				Temp->data = Temp2->data;
				if (Temp3->left == Temp2)
					Temp3->left = Temp2->left ? Temp2->left : Temp2->right;
				else
					Temp3->right=Temp2->left ? Temp2->left : Temp2->right;
				delete(Temp2);
				return T;
			}
			//只有一个或没儿子
			else
			{
				if (Temp2->right = Temp)
				{
					if (!Temp->right)
						Temp2->right = Temp->left;
					else
						Temp2->right = Temp->right;
				}
				else
				{
					if (!Temp->right)
						Temp2->left = Temp->left;
					else
						Temp2->left = Temp->right;
				}
				delete(Temp);
				return T;
			}
		}
	}
	if (!T)
		return NULL;
}
//先序遍历 递归
void bintree_traverse(tnpointer T)
{
	//结点非空，进行遍历
	if (T)
	{
		cout<< T->data << endl;
		bintree_traverse(T->left);
		bintree_traverse(T->right);
	}
}
//中序遍历 非递归
void bintree_traverse2(tnpointer T)
{
	//利用堆栈，一路压入左树，然后堆栈弹出并输出，再转向右树
	stack<tnpointer> S;
	while (T || !empty(S))
	{
		while (T)
		{
			S.push(T);
			T = T->left;
		}
		if (!empty(S))
		{
			T = S.top();
			S.pop();
			cout << T->data << endl;
			T = T->right;
		}
	}
}
//稍微直观的遍历
void bintree_traverse3(tnpointer T)
{
	//结点非空，进行遍历
	if (T)
	{
		cout << T->data << endl;
		if (T->left)
		{
			cout <<T->data<<"的左：";
			bintree_traverse3(T->left);
		}
		if (T->right)
		{
			cout << T->data << "的右：";
			bintree_traverse3(T->right);
		}
	}
}