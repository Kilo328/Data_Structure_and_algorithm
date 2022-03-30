#include<iostream>
#include"bintree.h"
using namespace std;
//��ʼ��һ�Ŷ���������
tnpointer initbintree()
{
	tnpointer T = NULL;
	return T;
}
//������ �ݹ�
tnpointer bintree_insert(tnpointer T, int tdata)
{
	//�ݹ���ĳ��λ��Ϊ��ʱ��������
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
			cout << "���������иý�㣬�����ظ�����!" << endl;
		}
	}
	return T;
}
//�������ֵ
tnpointer bintree_findmax(tnpointer T)
{
	while (T->right)
		T = T->right;
	return T;
}
//����
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
		//�ж��Ƿ���������н����δ�ҵ�
		if (!Temp)
		{
			cout << "��㲻����!" << endl;
			return NULL;
		}
		else
			return Temp;
	}
	else
		return NULL;
}
//���Ҷ����ĸ���
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
		//�ж��Ƿ���������н����δ�ҵ�
		if (!Temp)
		{
			cout << "��㲻����!" << endl;
			return NULL;
		}
		else
			return Temp2;
	}
	else
		return NULL;
}
//ɾ����� �ݹ�
tnpointer bintree_delete(tnpointer T, int tdata)
{
	tnpointer Temp;
	//�ݹ����Ѱ��Ҫɾ����Ԫ��λ��
	if (!T)
		cout << "δ�鵽��Ҫɾ����Ԫ��!" << endl;
	else if (tdata < T->data)
		T->left = bintree_delete(T->left, tdata);
	else if (tdata >T->data)
		T->right = bintree_delete(T->right, tdata);
	//�ж�ɾ������м�������
	else
	{
		//���Ҷ��Ӿ��У������������ֵ����ý��ֵ��ɾ�������������
		if (T->left && T->right)
		{
			Temp = bintree_findmax(T->left);
			T->data = Temp->data;
			T->left = bintree_delete(T->left, Temp->data);
		}
		//ֻ��һ����û����
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
//ɾ����� �ǵݹ�
tnpointer bintree_del(tnpointer T, int tdata)
{
	if (T)
	{
		tnpointer Temp = T;
		tnpointer Temp2 = NULL;
		tnpointer Temp3 = NULL;
		//����Ѱ��Ҫɾ����Ԫ��λ��
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
		//�ж�ɾ������м�������
		else
		{
			//���Ҷ��Ӿ��У������������ֵ����ý��ֵ��ɾ�������������
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
			//ֻ��һ����û����
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
//������� �ݹ�
void bintree_traverse(tnpointer T)
{
	//���ǿգ����б���
	if (T)
	{
		cout<< T->data << endl;
		bintree_traverse(T->left);
		bintree_traverse(T->right);
	}
}
//������� �ǵݹ�
void bintree_traverse2(tnpointer T)
{
	//���ö�ջ��һ·ѹ��������Ȼ���ջ�������������ת������
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
//��΢ֱ�۵ı���
void bintree_traverse3(tnpointer T)
{
	//���ǿգ����б���
	if (T)
	{
		cout << T->data << endl;
		if (T->left)
		{
			cout <<T->data<<"����";
			bintree_traverse3(T->left);
		}
		if (T->right)
		{
			cout << T->data << "���ң�";
			bintree_traverse3(T->right);
		}
	}
}