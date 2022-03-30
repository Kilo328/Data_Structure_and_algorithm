#include<iostream>
#include"avl.h"
using namespace std;
//�߶Ȼ�ȡ����
int Height(avlnpointer AVL)
{
	if (AVL == NULL)
		return 0;
	else
		return AVL->height;
}
//���ֵ����
int MAX(int height1, int height2)
{
	return (height1>height2) ? height1 : height2;
}
//����avl��
avlnpointer initavl()
{
	avlnpointer AVL = NULL;
	return AVL;
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
//��΢ֱ�۵ı���
void avl_traverse3(avlnpointer AVL)
{
	//���ǿգ����б���
	if (AVL)
	{
		cout << AVL->data << endl;
		if (AVL->left)
		{
			cout << AVL->data << "����";
			avl_traverse3(AVL->left);
		}
		if (AVL->right)
		{
			cout << AVL->data << "���ң�";
			avl_traverse3(AVL->right);
		}
	}
}
//ɾ�����
avlnpointer avl_del(avlnpointer AVL,int data)
{
	if (!AVL)
		return NULL;
	//Ҫɾ���Ľ����������
	if (data < AVL->data)
	{
		AVL->left = avl_del(AVL->left, data);
		//�ж�ƽ��,��������ɾ���ܵ�����������
		if (Height(AVL->right) - Height(AVL->left) == 2)
		{
			//�����������������������������������൱�����������������������˽�㣬��RR��ת
			if (Height(AVL->right->right) > Height(AVL->right->left))
			{
				AVL = RR_rotation(AVL);
			}
			//�൱�����������������������㣬��RL��ת
			else
			{
				AVL = RL_rotation(AVL);
			}
		}
	}
	else if (data > AVL->data)
	{
		AVL->right = avl_del(AVL->right, data);
		//�ж�ƽ��,��������ɾ���ܵ�����������
		if (Height(AVL->left) - Height(AVL->right) == 2)
		{
			//�����������������������������������൱�����������������������˽�㣬��LR��ת
			if (Height(AVL->left->right) > Height(AVL->left->left))
			{
				AVL = LR_rotation(AVL);
			}
			//�൱�����������������������㣬��LL��ת
			else
			{
				AVL = LL_rotation(AVL);
			}
		}
	}
	//�ҵ���Ҫɾ�����
	else
	{
		//������������ǿ�
		if (AVL->left && AVL->right)
		{
			//����������߶ȴ����������߶ȣ���������������滻��ɾ����㣬����avl����Ȼƽ��
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
//�������ֵ
avlnpointer avl_findmax(avlnpointer AVL)
{
	if (AVL->right)
	{
		AVL = AVL->right;
	}
	return AVL;
}
//������Сֵ
avlnpointer avl_findmin(avlnpointer AVL)
{
	if (AVL->left)
	{
		AVL = AVL->left;
	}
	return AVL;
}
//LL��ת
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
//RR��ת
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
//LR��ת
avlnpointer LR_rotation(avlnpointer AVL)
{
	//��RR��LL
	AVL->left = RR_rotation(AVL->left);
	return LL_rotation(AVL);
}
//RL��ת
avlnpointer RL_rotation(avlnpointer AVL)
{
	//��LL��RR
	AVL->right = LL_rotation(AVL->right);
	return RR_rotation(AVL);
}
//������ �ݹ�
avlnpointer avl_insert(avlnpointer AVL,int data)
{
	//����ǿս�㣬��ô�����½�㲢��ʼ��
	if (AVL == NULL)
	{
		AVL = new avlNode;
		AVL->height = 0;
		AVL->data = data;
		AVL->left = AVL->right = NULL;
		return AVL;
	}
	//������ֵ��������Ƚϣ����С���������
	else if (data < AVL->data)
	{
		AVL->left = avl_insert(AVL->left, data);
		//�ж��Ƿ�ƽ��
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
	//��������
	else if (data > AVL->data)
	{
		AVL->right = avl_insert(AVL->right, data);
		//�ж��Ƿ�ƽ��
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
		cout << "���ֵ�ظ�" << endl;
	}
	AVL->height = MAX(Height(AVL->left), Height(AVL->right)) + 1;
	return AVL;
}