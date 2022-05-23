#pragma once
#include <iostream>

using namespace std;

struct  Trailer;

struct Lider
{
    int key, count;
    Lider* next;
    Trailer* tr;
    Lider() {
        key = count = NULL;
        next = NULL;
        tr = NULL;
    }
    void AddTrailer(Lider* p);
    void DelTrailer(Lider* p);
    void ReduceCount();
    void IncreaseCount();
};

struct Trailer
{
    Lider* pointer;
    Trailer* next;
    Trailer() {
        pointer = NULL;
        next = NULL;
    }
};

struct Graph
{
    Lider* head;
    Graph();
    ~Graph();
    void AddToTail(Lider* p);
    void AddToHead(int k);
    void Del(Lider* p);
    void Exclude(Lider* p);
    Lider* FindKey(int);
    Lider* FindCount(int);
    int FormGraph();
    void SortGraph(Graph&);
    void Clear();
    bool Empty();
};
// Lider *FindCount(int k); //поиск узла у которого count = k
//void Del(Lider *p); //удаление узла, для ф-ции Clear
//void Exclude(Lider *p); //исключение узла из списка, без удаления узла
