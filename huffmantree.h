#pragma once
#include<iostream>
#include"minheap.h"
using namespace std;
typedef hNode* hftnpointer;
//�����������
hftnpointer inithuffmantree(mhpointer MH);
//��΢ֱ�۵ı���
void huffmantree_traverse(hftnpointer T);
