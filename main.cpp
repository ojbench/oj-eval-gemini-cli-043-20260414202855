#include <iostream>
#include <cstdio>
using namespace std;

namespace LIST
{

struct NODE
{
    int data;
    NODE *prev;
    NODE *next;
};

NODE *head = nullptr, *tail = nullptr;
int len = 0;

void Pre()
{
    head = nullptr;
    tail = nullptr;
    len = 0;
}

NODE* move(int i)
{
    if (i < 0 || i > len) return nullptr;
    NODE *cur = head;
    for (int j = 0; j < i; ++j) {
        if (cur == nullptr) break;
        cur = cur->next;
    }
    return cur;
}

void insert(int i, int x)
{
    NODE *newNode = new NODE;
    newNode->data = x;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    if (len == 0) {
        head = tail = newNode;
    } else if (i == 0) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else if (i == len) {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    } else {
        NODE *cur = move(i);
        newNode->prev = cur->prev;
        newNode->next = cur;
        cur->prev->next = newNode;
        cur->prev = newNode;
    }
    len++;
}

void remove(int i)
{
    if (i < 0 || i >= len) return;
    NODE *cur = move(i);
    if (len == 1) {
        head = tail = nullptr;
    } else if (i == 0) {
        head = cur->next;
        head->prev = nullptr;
    } else if (i == len - 1) {
        tail = cur->prev;
        tail->next = nullptr;
    } else {
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
    }
    delete cur;
    len--;
}

int Get_length()
{
    return len;
}

int Query(int i)
{
    if (i < 0 || i >= len) return -1;
    NODE *cur = move(i);
    return cur->data;
}

void Print()
{
    if (len == 0) {
        cout << -1 << endl;
        return;
    }
    NODE *cur = head;
    bool first = true;
    while (cur != nullptr) {
        if (!first) cout << " ";
        cout << cur->data;
        first = false;
        cur = cur->next;
    }
    cout << endl;
}

void Clear()
{
    NODE *cur = head;
    while (cur != nullptr) {
        NODE *next = cur->next;
        delete cur;
        cur = next;
    }
    head = nullptr;
    tail = nullptr;
    len = 0;
}

}
int n;
int main()
{
    cin >> n;
    int op, x, p, ans;
    LIST::Pre();
    for (int _=0;_<n;++_)
    {
        cin >> op;
        switch(op)
        {
            case 0:
                ans = LIST::Get_length();
                cout << ans << endl;
                break;
            case 1:
                cin >> p >> x;
                LIST::insert(p,x);
                break;
            case 2:
                cin >> p;
                ans = LIST::Query(p);
                cout << ans << endl;
                break;
            case 3:
                cin >> p;
                LIST::remove(p);
                break;
            case 4:
                LIST::Print();
                break;
        }
    }
    LIST::Clear();
    return 0;
}
