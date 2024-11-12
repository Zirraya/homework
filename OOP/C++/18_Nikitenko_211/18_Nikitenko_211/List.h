#pragma once

#include "Pokemon.h"



// � ��� ��� ����������� ��������� ������, ����� ������ � ��� ����� ���� ��� (���� �������, ���� ��������)
struct node {
    Pokemon* inf; // ��� ��� ����� ���������, �� ���������� ����� ������ ������� ��������� Animals
    node* next;
    node* prev;
};

// ������
class List {
private:
    node* head;
    node* tail;
    int cnt;
public:
    List() { head = NULL; tail = NULL; cnt = 0; }
    void push(Pokemon* p);
    void print(ostream& out);
    bool find(Pokemon* p); //  ����� ������ ����������� ���������
    bool findAll(bool condition(Pokemon* p1));  // ����� ���� �������� �� �������
};

void List::push(Pokemon* p) { // �������� �������� � ����������
    node* r = new node;
    r->inf = p;
    r->next = NULL;
    if (!head && !tail) {
        r->prev = NULL;
        head = r;
    }
    else {
        tail->next = r;
        r->prev = tail;
    }
    tail = r;
}


void List::print(ostream& out)
{
    node* r = head;
    while (r != NULL) {
        (*(r->inf)).print(out);
        r = r->next;
    }
    cout << '\n';
}


bool List::find(Pokemon* p) {
    node* r = head;
    while (r != NULL) {
        if (*(r->inf) == *p)
            return true;
        r = r->next;
    }
    return false;
}


bool List::findAll(bool condition(Pokemon* p1)) {
    node* r = head;
    while (r != NULL) {
        if (condition(r->inf))
        {
            (*(r->inf)).print(cout);
        }
        r = r->next;
    }
    return (r != NULL);
}


