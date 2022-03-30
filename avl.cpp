#include<iostream>
#include"avl.h"
using namespace std;
//高度获取函数
int Height(avlnpointer AVL)
{
	if (AVL == NULL)
		return 0;
	else
		return AVL->height;
}
//最大值函数
int MAX(int height1, int height2)
{
	return (height1>height2) ? height1 : height2;
}
//生成avl树
avlnpointer initavl()
{
	avlnpointer AVL = NULL;
	return AVL;
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
	while (!empty(S) || AVL)
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
//稍微直观的遍历
void avl_traverse3(avlnpointer AVL)
{
	//结点非空，进行遍历
	if (AVL)
	{
		cout << AVL->data << endl;
		if (AVL->left)
		{
			cout << AVL->data << "的左：";
			avl_traverse3(AVL->left);
		}
		if (AVL->right)
		{
			cout << AVL->data << "的右：";
			avl_traverse3(AVL->right);
		}
	}
}
//删除结点
avlnpointer avl_del(avlnpointer AVL,int data)
{
	if (!AVL)
		return NULL;
	//要删除的结点在左子树
	if (data < AVL->data)
	{
		AVL->left = avl_del(AVL->left, data);
		//判断平衡,在左子树删可能导致右子树高
		if (Height(AVL->right) - Height(AVL->left) == 2)
		{
			//右子树的右子树高于右子树的左子树，相当于在右子树的右子树插入了结点，做RR旋转
			if (Height(AVL->right->right) > Height(AVL->right->left))
			{
				AVL = RR_rotation(AVL);
			}
			//相当于在右子树的左子树插入结点，做RL旋转
			else
			{
				AVL = RL_rotation(AVL);
			}
		}
	}
	else if (data > AVL->data)
	{
		AVL->right = avl_del(AVL->right, data);
		//判断平衡,在右子树删可能导致左子树高
		if (Height(AVL->left) - Height(AVL->right) == 2)
		{
			//左子树的右子树高于左子树的左子树，相当于在左子树的右子树插入了结点，做LR旋转
			if (Height(AVL->left->right) > Height(AVL->left->left))
			{
				AVL = LR_rotation(AVL);
			}
			//相当于在左子树的左子树插入结点，做LL旋转
			else
			{
				AVL = LL_rotation(AVL);
			}
		}
	}
	//找到了要删除结点
	else
	{
		//如果左右子树非空
		if (AVL->left && AVL->right)
		{
			//如果左子树高度大于右子树高度，将左子树最大结点替换被删除结点，这样avl树仍然平衡
			if (Height(AVL->left) > Height(AVL->right))
			{
				avlnpointer lmax = avl_findmax(AVL->left);
				AVL->data = lmax->data;
				AVL->left = avl_del(AVL->left, lmax->data);
			}
			else
			{
				avlnpointer rmin = avl_findmin(AVL->right);
				AVL->data = rmin->data;
				AVL->right = avl_del(AVL->right, rmin->data);
			}
		}
		else
		{
			avlnpointer temp = AVL;
			AVL = AVL->right ? AVL->right : AVL->left;
			delete temp;
		}
	}
	return AVL;
}
//查找最大值
avlnpointer avl_findmax(avlnpointer AVL)
{
	if (AVL->right)
	{
		AVL = AVL->right;
	}
	return AVL;
}
//查找最小值
avlnpointer avl_findmin(avlnpointer AVL)
{
	if (AVL->left)
	{
		AVL = AVL->left;
	}
	return AVL;
}
//LL旋转
avlnpointer LL_rotation(avlnpointer AVL)
{
	avlnpointer avl_l;
	avl_l = AVL->left;
	AVL->left = avl_l->right;
	avl_l->right = AVL;
	AVL->height = MAX(Height(AVL->left), Height(AVL->right))+1;
	avl_l->height = MAX(Height(avl_l->left), Height(avl_l->right))+1;
	return avl_l;
}
//RR旋转
avlnpointer RR_rotation(avlnpointer AVL)
{
	avlnpointer avl_r;
	avl_r = AVL->right;
	AVL->right = avl_r->left;
	avl_r->left = AVL;
	AVL->height = MAX(Height(AVL->left), Height(AVL->right)) + 1;
	avl_r->height = MAX(Height(avl_r->left), Height(avl_r->right)) + 1;
	return avl_r;
}
//LR旋转
avlnpointer LR_rotation(avlnpointer AVL)
{
	//先RR再LL
	AVL->left = RR_rotation(AVL->left);
	return LL_rotation(AVL);
}
//RL旋转
avlnpointer RL_rotation(avlnpointer AVL)
{
	//先LL再RR
	AVL->right = LL_rotation(AVL->right);
	return RR_rotation(AVL);
}
//插入结点 递归
avlnpointer avl_insert(avlnpointer AVL,int data)
{
	//如果是空结点，那么创建新结点并初始化
	if (AVL == NULL)
	{
		AVL = new avlNode;
		AVL->height = 0;
		AVL->data = data;
		AVL->left = AVL->right = NULL;
		return AVL;
	}
	//插入结点值与各个结点比较，如果小则插入左树
	else if (data < AVL->data)
	{
		AVL->left = avl_insert(AVL->left, data);
		//判断是否平衡
		if (Height(AVL->left) - Height(AVL->right) == 2)
		{
			if (data < AVL->left->data)
			{
				AVL = LL_rotation(AVL);
			}
			else
			{
				AVL = LR_rotation(AVL);
			}
		}
	}
	//插入右树
	else if (data > AVL->data)
	{
		AVL->right = avl_insert(AVL->right, data);
		//判断是否平衡
		if (Height(AVL->right) - Height(AVL->left) == 2)
		{
			if (data < AVL->right->data)
			{
				AVL = RL_rotation(AVL);
			}
			else
			{
				AVL = RR_rotation(AVL);
			}
		}
	}
	else
	{
		cout << "结点值重复" << endl;
	}
	AVL->height = MAX(Height(AVL->left), Height(AVL->right)) + 1;
	return AVL;
}