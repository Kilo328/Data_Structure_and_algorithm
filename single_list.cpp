#include<iostream>
#include"single_list.h"
using namespace std;
//初始化链表
npointer initlist() 
{
	npointer head = new Node;
	head->next = NULL;
	head->data = 0;
	return head;
}

//尾部插入
void listpushback(npointer head)
{
	npointer temp;
	temp = head;
	//将临时指针temp遍历指向链表的最后一个数据
	for (int i = 1; i <= head->data; i++)
	{
		temp = temp->next;
	}
	//链表尾部接上新结点
	temp->next = new Node;
	temp = temp->next;
	temp->next= NULL;
	cout << "请输入尾部插入结点的数据:" << endl;
	cin >> temp->data;
	//在头结点中代表结点数的数据域+1
	++head->data;
}

//头部插入
void listpushfront(npointer head)
{
	npointer temp;
	//临时指针指向链表原本的第一个数据
	temp = head;
	temp = temp->next;
	//将新结点接在头结点后
	head->next = new Node;
	cout << "请输入头部插入结点的数据:" << endl;
	cin >> head->next->data;
	//将原链表接在新结点后
	head->next->next = temp;
	//在头结点中代表结点数的数据域+1
	++head->data;
}

//尾部删除
void listpopback(npointer head)
{
	//先判断链表是否为空，若为空则不可进行删除操作
	if (head->data != 0)
	{
		npointer temp;
		temp = head;
		//临时指针遍历指向链表倒数第二个数据，因为待会这个结点将成为链表尾结点，要对尾结点的next指针进行指空操作
		for (int i = 1; i < head->data; i++)
		{
			temp = temp->next;
		}
		//释放删除的结点
		delete temp->next;
		//新的尾结点next指针指空
		temp->next = NULL;
		//在头结点中代表结点数的数据域-1
		--head->data;
	}
	else
		cout << "链表为空,无法删除!" << endl;
}

//头部删除
void listpopfront(npointer head)
{
	//先判断链表是否为空，若为空则不可进行删除操作
	if (head->data != 0)
	{
		npointer temp;
		//临时指针指向原链表的第二个数据（新链表的第一个数据）
		temp = head->next;
		temp = temp->next;
		//释放删除的结点
		delete head->next;
		//将剩下的链表接在头结点后
		head->next = temp;
		//在头结点中代表结点数的数据域-1
		--head->data;
	}
	else
		cout << "链表为空,无法删除!" << endl;
}

//在定结点处插入，插入到结点后
void listinsert(npointer head,npointer node, int data)
{
	npointer temp;
	npointer temp2;
	temp = head;
	//临时指针temp遍历指向输入结点，循环直到走到最后一个结点或者找到输入结点为止
	for (int i = 0; i <= head->data&&temp!=node; i++)
	{
		temp = temp->next;
	}
	//如果临时指针temp未指向指定结点，则查找失败
	if (temp != node)
		cout << "未查询到输入的结点。" << endl;
	//建立新结点接在指定结点后
	else
	{
		temp2 = temp->next;
		temp->next = new Node;
		temp->next->data = data;
		temp->next->next = temp2;
		//头结点中结点数域+1
		++head->data;
	}
}

//定结点删除
void listerase(npointer head,npointer node)
{
	npointer temp;
	npointer temp2;
	temp = head;
	if (temp != NULL)
	{
		//临时指针temp遍历指向输入结点，循环直到走到最后一个结点或者找到输入结点为止
		for (int i = 0; i <= head->data && temp->next != node; i++)
		{
			temp = temp->next;
		}
		//释放定结点，并将链表拼接
		temp2 = temp->next->next;
		delete (temp->next);
		temp->next = temp2;
		//头结点中结点数域-1
		head->data--;
	}
	else
		cout << "链表为空,无法删除!" << endl;
}

//按值删除
void listremove(npointer head, int data,int num)
{
	npointer temp;
	npointer temp2;
	int temp3 = 0;
	temp = head;
	if (temp != NULL)
	{
		//临时指针temp遍历指向输入结点，循环直到走到最后一个结点或者找到输入结点为止
		for (int i = 1; i <= head->data&&temp3!=num; i++)
		{
			if (temp->next->data == data)
			{
				temp2 = temp->next;
				listerase(head, temp2);
				temp3++;
			}
			temp = temp->next;
		}
		if (temp3 !=num)
			cout << "链表中值为" << data << "的结点只有" << temp3 << "个。" << endl;
	}
	else
		cout << "链表为空,无法删除!" << endl;
}

//按值查找 只返还符合该值的第一个结点的位置
npointer listfind(npointer head, int data)
{
	npointer temp;
	temp = head->next;
	if (temp != NULL)
	{
		//临时指针temp遍历指向输入结点，循环直到走到最后一个结点或者找到符合条件的结点为止
		for (int i = 1; i <= head->data && temp->data!=data; i++)
		{
			if(i!=head->data)
				temp = temp->next;
		}
		if (temp->data == data)
			return temp;
		else
		{
			cout << "链表无符合该值的结点!" << endl;
			return NULL;
		}
	}
	else
	{
		cout << "链表为空,无法查找!" << endl;
		return NULL;
	}
}

//按顺序打印链表
void listprint(npointer head)
{
	npointer temp;
	temp = head->next;
	for (int i = 1; i <= head->data; i++)
	{
		cout << "第" << i << "个结点的数据为:" << temp->data << endl;
		temp = temp->next;
	}
	if (head->data == 0)
		cout << "链表为空!" << endl;
}

//将链表按升序排序 冒泡交换数据域
void listsort(npointer head)
{
	npointer temp=head->next;
	npointer temp2=temp;
	int temp3=0;
	if (temp != NULL&&temp->next!=NULL)
	{
		for (; temp != NULL; temp = temp->next)
			for (temp2 = temp->next; temp2 != NULL; temp2 = temp2->next)
			{
				if (temp->data > temp2->data)
				{
					temp3 = temp->data;
					temp->data = temp2->data;
					temp2->data = temp3;
				}
			}
	}
	else
		cout << "链表为空!" << endl;
}

//将两个链表合并并按升序排序
void listcombine(npointer head1, npointer head2)
{
	npointer temp = head1;
	npointer temp2 = head2;
	for (; temp->next != NULL; temp = temp->next);
	temp->next = temp2->next;
	//数据域增加
	head1->data += head2->data;
	delete temp2;
	listsort(head1);
}

//查询链表内结点数，如果为空返回-1
int totlsit(npointer head)
{
	if (head->data != 0)
		return head->data;
	else
		return -1;
}