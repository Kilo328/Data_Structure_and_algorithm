#pragma once
//单向链表
#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
typedef Node* npointer;
//初始化链表
npointer initlist();

//尾部插入
void listpushback(npointer head);

//头部插入
void listpushfront(npointer head);

//尾部删除
void listpopback(npointer head);

//头部删除
void listpopfront(npointer head);

//在定结点处插入，插入到结点后
void listinsert(npointer head, npointer node, int data);

//定结点删除
void listerase(npointer head,npointer node);

//按值删除
void listremove(npointer head,int data,int num);

//按值查找 只返还符合该值的第一个结点的位置
npointer listfind(npointer head,int data);

//按顺序打印链表
void listprint(npointer head);

//将链表按升序排序
void listsort(npointer head);

//将两个链表合并并按升序排序
void listcombine(npointer head1,npointer head2);

//查询链表内结点数，如果为空返回-1
int totlsit(npointer head);