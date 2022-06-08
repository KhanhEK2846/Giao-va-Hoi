#include "list.h"

void Init(LIST& l)
{
    l.pHead = l.pTail = NULL;

}

NODE* GetNode(int x)
{
    NODE* p = new NODE;
    if (p == NULL)
        return NULL;
    p->info = x;
    p->pNext = NULL;
    p->pPrev = NULL;
    return p;
}

void AddHead(LIST& l, NODE* p)
{
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else
    {
        p->pNext = l.pHead;
        l.pHead->pPrev = p;
        l.pHead = p;
    }
}

void AddTail(LIST& l, NODE* p)
{
    if (l.pTail == NULL)
        l.pTail = l.pHead = p;
    else
    {
        p->pPrev = l.pTail;
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void Input(LIST& l)
{
    int n;
    cout << "Nhap n= ";
    cin >> n;
    Init(l);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cout << "Nhap so thu " << i << " :" << endl;
        cin >> x;
        NODE* p = GetNode(x);
        if (p != NULL)
            AddTail(l, p);

    }
}

void Output(LIST l)
{
    for (NODE* p = l.pHead; p != NULL; p = p->pNext)
    {
        cout << p->info << " ";
    }
    cout << endl;
}

void DelHead(LIST& l)
{
    if (l.pHead != NULL)
    {
        l.pHead = l.pHead->pNext;
        l.pHead->pPrev = NULL;
    }

}

void DelTail(LIST& l)
{
    if (l.pTail != NULL)
    {
        l.pTail = l.pTail->pPrev;
        l.pTail->pNext = NULL;
    }
}

int KT(LIST l, int n)
{
    for (NODE* p = l.pHead; p != 0; p = p->pNext)
        if (p->info == n) return 0;
    return 1;
}

void GiaoHoi(LIST l1, LIST l2)
{
    LIST l, lst;
    Init(l);
    Init(lst);
    for (NODE* p = l1.pHead; p != NULL; p = p->pNext)
    {
        NODE* q = GetNode(p->info);
        if (KT(l2, p->info) == 0)
        {
            if (q != NULL) AddTail(l, q);
        }
        else
        {
            if (q != NULL) AddTail(lst, q);
        }
    }
    for (NODE* p = l2.pHead; p != NULL; p = p->pNext)
    {
        if (KT(l1, p->info))
        {
            NODE* q = GetNode(p->info);
            if (q != NULL) AddTail(lst, q);
        }
    }
    cout << "Phan giao cua danh sach: " << endl;
    Output(l);
    cout << "Phan hoi cua danh sach: " << endl;
    Output(lst);

}
