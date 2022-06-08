#pragma once
#include<iostream>
using namespace std;

struct node
{
    int info;
    struct node* pNext;
    struct node* pPrev;
};
typedef struct node NODE;
struct list
{
    NODE* pHead;
    NODE* pTail;
};
typedef struct list LIST;
void Init(LIST& l);
NODE* GetNode(int x);
void AddHead(LIST& l, NODE* p);
void AddTail(LIST& l, NODE* p);
void Input(LIST& l);
void Output(LIST l);
void DelHead(LIST& l);
void DelTail(LIST& l);
int KT(LIST l, int n);
void GiaoHoi(LIST l1, LIST l2);
