#include "List.h"
List::List() 
{
    head = new Node;
    tail = new Node(0, head, 0);
    head->next = tail;
}
List::List(int m)
{
    head = new Node;
    tail = new Node(0, head, 0);
    head->next = tail;
    for (int i = 0; i < m; i++)
    {
        int x = rand() % 100;
        AddToTail(x);
    }
}
List::List(int* a, int n)
{
    head = new Node;
    tail = new Node(-1, head, NULL);
    head->next = tail;

    for (int i = 0; i < n; i++)
        AddToTail(a[i]);
}
List::List(const List& x)
{
    head = new Node;
    tail = new Node(0, head, 0);
    head->next = tail;

    Node* s = x.head->next;
    while (s != x.tail)
    {
        AddToTail(s->key);
        s = s->next;
    }
}
List::~List()
{
    Clear(); delete head; delete tail;
}
List& List::operator= (const List& x)
{
    if (this != &x)
    {
        Clear();
        Node* s = x.head->next;
        while (s != x.tail)
        {
            AddToTail(s->key);
            s = s->next;
        }
    }
    return *this;
}
bool List::operator==(List x) {
    Node* q1 = this->head->next, *q2 = x.head->next;
    if (q1 == this->tail && q2 == x.tail) return true;

    while (q1 != this->tail && q2 != x.tail) {
        if (q1->key != q2->key) return false;

        q1 = q2->next;
        q2 = q2->next;
    }
    if (q1 == this->tail && q2 == x.tail) return true;

    return false;
}
bool List::operator!=(List x) {
    if (*this == x) {
        return false;
    } return true;
}

void List::Sort()
{
    Node* curr = NULL, *previous = NULL;
      for (curr = head->next; curr->next; curr = curr->next)
      {
          int temp = curr->key;
          for (previous = curr->prev; previous && previous->key > temp; previous = previous->prev)
          {
              previous->next->key = previous->key;
          }
          previous->next->key = temp;
      }
}

void List::AddAfter(int k, Node* pr)
{
    Node* q = new Node(k, pr, pr->next);
    pr->next = q;
    q->next->prev = q;
}
void List::AddToTail(int x)
{
    AddAfter(x, tail->prev);
}
void List::AddToHead(int x)
{
    AddAfter(x, head);
}

void List::AddToHead(List x) {
    Node* q = x.tail->prev;
    while (q != x.head)
    {
        AddToHead(q->key);
        q = q->prev;
    }
}

void List::AddToTail(List x) {
    Node* q = x.head->next;
    while (q != x.tail)
    {
        AddToTail(q->key);
        q = q->next;
    }
}

void List::Del(Node* p)
{
    p->prev->next=p->next;
    p->next->prev=p->prev;
    delete p;
}

void List::DelTail()
{
    Del(tail->prev);
}

void List::DelHead()
{
    Del(head->next);
}

Node* List::FindKey(int x)
{
    Node* q = this->head->next;
    while (q != this->tail) {
        if (q->key == x) {
            return q;
        }
        q = q->next;
    }
    cout << "Элемента " << x << " нет в списке" << endl;
    return 0;
}

Node *List::FindPos(int pos)
{
    Node *q = this->head->next;
    int i = 0;
    while (q != this->tail && i < pos)
    {
        i++; q = q->next;
    }
    if (i <= pos) {
        return q;
    }
    cout << "Позиция выходит за границы";
    return 0;
}

bool List::Empty()
{
    if (this->head->next == this->tail) {
        return true;
    }
    return false;
}

bool List::NotEmpty()
{
    if (Empty()) {
        return false;
    }
    return true;
}

Node* List::Max() {
    Node *M = NULL;
    Node *q = head->next;
    if (q == tail) {
        cout << "Список пустой" << endl;
        return M;
    }
    M = q; q = q->next;
    while (q != tail) {
        if (q->key > M->key) {
            M = q;
        }
        q = q->next;
    }
    return M;
}

Node* List::Min() {
    Node *M = NULL;
    Node *q = head->next;
    if (q == tail) {
        cout << "Список пустой" << endl;
        return M;
    }
    M = q; q = q->next;
    while (q != tail) {
        if (q->key < M->key) {
            M = q;
        }
        q = q->next;
    }
    return M;
}

void List::Clear()
{
    while (head->next != tail) DelHead();
}

void List::Print()
{
    Node* p = head->next;
    while (p != tail)
    {
        cout << p->key << ' ';
        p = p->next;
    }
}

void List::Scan(int n)
{
    Clear();
    int i, x;
    cout << "Введите элементы списка: ";
    for (i = 0; i < n; i++)
    {
        cin >> x;
        AddToTail(x);
    }
}

ostream& operator<< (ostream& r, List& x)
{
    x.Print(); return r;
}

istream& operator>> (istream& r, List& x) {
    int n; cout << "Введите количество элементов в списке: ";
    cin >> n;
    x.Scan(n);
    return r;
}
