#pragma once

#include "Pokemon.h"



// А вот как программист переделал список, чтобы теперь в нем могли жить все (даже драконы, если прилетят)
struct node {
    Pokemon* inf; // так как здесь указатель, то подставить можно любого потомка животного Animals
    node* next;
    node* prev;
};

// Список
class List {
private:
    node* head;
    node* tail;
    int cnt;
public:
    List() { head = NULL; tail = NULL; cnt = 0; }
    void push(Pokemon* p);
    void print(ostream& out);
    bool find(Pokemon* p); //  найти одного конкретного животного
    bool findAll(bool condition(Pokemon* p1));  // найти всех животных по условию
};

void List::push(Pokemon* p) { // принятие покемона в заповедник
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


