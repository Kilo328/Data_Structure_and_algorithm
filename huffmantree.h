#pragma once
#include<iostream>
#include"minheap.h"
using namespace std;
typedef hNode* hftnpointer;
//构造哈夫曼树
hftnpointer inithuffmantree(mhpointer MH);
//稍微直观的遍历
void huffmantree_traverse(hftnpointer T);
