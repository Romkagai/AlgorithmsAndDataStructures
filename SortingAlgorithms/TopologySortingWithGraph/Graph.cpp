#include <stdio.h>
#include "Graph.h"
void Lider::AddTrailer(Lider* p) {
    Trailer* q = new Trailer;
    q->pointer = p;
    q->next = tr;
    tr = q;
}

void  Lider::DelTrailer(Lider* p) {
    Trailer* s, * t = p->tr;
    while (t != NULL) {
        s = t;
        p->tr = t->next;
        t = t->next;
        delete s;
    }
}

void  Lider::ReduceCount()
{
    Trailer* t = tr;
    while (t != NULL) {
        t->pointer->count--;
        t = t->next;
    }
}

Graph::Graph() {
    head = new Lider;
}

Graph:: ~Graph()
{
    Clear();
    delete head;
}

int Graph::FormGraph() {
    int n = 0;
    int x, y;
    Lider* px, * py;
    cout << "Введите a и b: ";
    cin >> x >> y;
    while (x && y) {
        if (FindKey(x) == NULL) {
            AddToHead(x);
            px = head->next;
            n++;
        }
        else
            px = FindKey(x);
        if (FindKey(y) == NULL) {
            AddToHead(y);
            py = head->next;
            n++;
        }
        else
            py = FindKey(y);
        py->count++;
        px->AddTrailer(py);
        cout << "Введите a и b: ";
        cin >> x >> y;
    }
    return n;
}

void Graph::SortGraph(Graph& newGraph) {
    Lider* p, * q;
    while (!Empty())
    {
        p = FindCount(0);
        if (p != NULL)
        {
            Exclude(p);
            newGraph.AddToTail(p);
            p->ReduceCount();
        }
        else
        {
            cout << "Ошибка!";
            exit(-1);
        }
    }
    q = newGraph.head->next;
    while (q != NULL)
    {
        q->IncreaseCount();
        q = q->next;
    }
}

void Graph::AddToHead(int k)
{
    Lider* t;
    t = new Lider;
    t->key = k;
    t->next = head->next;
    head->next = t;
}

void Graph::AddToTail(Lider* q)
{
    Lider* p = head;
    for (; p->next != NULL; p = p->next);
    p->next = q;
    q->next = 0;
}

void Graph::Del(Lider* p)
{
    if (p->tr != 0) {
        p->DelTrailer(p);
    }
    Lider* t = head;
    while (t->next != p)
    {
        t = t->next;
    }
    if (p->next == NULL) {
        t->next = NULL;
    }
    else
        t->next = p->next;
    delete p;
}

void Graph::Exclude(Lider* q)
{
    Lider* t = head;
    while (t->next != q)
    {
        t = t->next;
    }
    if (q->next == NULL) {
        t->next = NULL;
    }
    else
        t->next = q->next;
}

void Lider::IncreaseCount()
{
    if (tr != 0)
    {
        Trailer* q = tr;
        q->pointer->count++;
        while (q->next != 0)
        {
            q = q->next;
            q->pointer->count++;
        }
        q->pointer->count++;
    }
}

Lider* Graph::FindKey(int k)
{
    Lider* q = head;
    if (!Empty())
    {
        for (q = q->next; (q->key != k) && (q->next != NULL); q = q->next);
        if (q->key != k)
            return 0;
        else
            return q;
    }
    else
    {
        return 0;
    }
}

Lider* Graph::FindCount(int x)
{
    Lider* q = head;
    if (!Empty())
    {
        for (q = q->next; q->count != x && q->next != NULL; q = q->next);
        if (q->count != x)
            return 0;
        else
            return q;
    }
    else
    {
        return 0;
    }
}

void Graph::Clear()
{
    while (!Empty())
        Del(head->next);
}

bool Graph::Empty()
{
    if (head->next == NULL)
        return true;
    else
        return false;
}


