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
void listinsert(npointer node, int data)
{

}

//定结点删除
void listerase(npointer node)
{

}

//按值删除
void listremove(npointer head, int num)
{

}

//按值查找
/*npointer listfind(npointer head, int data)
{

}*/

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

//将链表按升序排序
void listsort(npointer head)
{

}

//将两个链表合并并按升序排序
void listcombine(npointer head1, npointer head2)
{

}

//查询链表内结点数，如果为空返回-1
int totlsit(npointer head)
{
	if (head->data != 0)
		return head->data;
	else
		return -1;
}