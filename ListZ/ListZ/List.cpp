#include <cstddef>
#include "List.h"

List::List() : count(0)
{
    buffer = new Node;
    buffer->next = buffer;
    buffer->prev = buffer;
    buffer->data = -1;
}

List::List(const List& list) : buffer(new Node), count(list.count)
{
    buffer = new Node;
    const Node* tmp = list.buffer->next;
    Node* p = buffer;
    Node* n = NULL;
    while (tmp != list.buffer) {
        n = new Node;
        p->next = n;
        n->prev = p;
        n->data = tmp->data;
        p = p->next;
        tmp = tmp->next;
    }
    buffer->prev = p;
    p->next = buffer;
}

List::List(List&& obj) : buffer(obj.buffer), count(obj.count)
{
    obj.buffer = nullptr;
    obj.count = 0;
}

List::~List()
{
    if (!empty()) {
        clear();
    }
    delete buffer;
    buffer = nullptr;
}

void List::push_I(Iterator_Abstr* index, int v) {
    Node* tmp = new Node;
    auto it = dynamic_cast<Iterator*>(index);
    if (count == 0) {
        tmp->next = buffer;
        tmp->prev = buffer;
        tmp->data = v;
        buffer->next = tmp;
        buffer->prev = tmp;
        count++;
    }
    else {
        Node* k = it->get();
        k->next->prev = tmp;
        tmp->next = k->next;
        tmp->prev = k;
        tmp->data = v;
        k->next = tmp;
        count++;
    }
}

void List::del_I(Iterator_Abstr* index) {
    auto it = dynamic_cast<Iterator*>(index); //преобразует тип данных (указатель или ссылку) вниз по иерархии наследования
    Node* p = it->get();
    p->next->prev = p->prev;
    p->prev->next = p->next;
    delete p;
    count--;
}

void List::clear() {
    Node* tmp = buffer;
    Node* n = nullptr;
    while (tmp->next != buffer) {
        tmp = tmp->next;
        delete n;
        n = tmp;
        count--;
    }
    delete n;
}

bool List::empty() {
    return count == 0;
}

int List::size_() const {
    return count;
}

Iterator_Abstr* List::first_I() {
    Iterator_Abstr* it = new Iterator(*this);
    it->start();
    it->next();
    return it;
}

const Iterator_Abstr* List::first_appearance_I(int n) {
    Iterator_Abstr* it = new Iterator(*this);
    it->start();
    for (int i = 0; i < count; i++) {
        if (it->get()->data == n) {
            break;
        }
        it->next();
    }
    return it;
}

Node* List::getBuffer() const {
    return buffer;
}

List::Iterator::Iterator(const List& list) : buf(list.getBuffer()), count(list.count) {
}

void List::Iterator::start() {
    p = buf;
    index = -1;
}

bool List::Iterator::finish() {
    return index >= count - 1;
}

void List::Iterator::next() {
    p = p->next;
    index++;
}

Node* List::Iterator::get() {
    return p;
}

List& List::operator=(const List& obj) {
    if (this != &obj) {
        this->clear();
       // buffer = new Node;
        const Node* tmp = obj.buffer->next;
        Node* p = buffer;
        Node* n;
        while (tmp != obj.buffer) {
            n = new Node;
            p->next = n;
            n->prev = p;
            n->data = tmp->data;
            p = p->next;
            tmp = tmp->next;
        }
        buffer->prev = p;
        p->next = buffer;
    }
    return *this;
}

List List::operator=(List&& obj) {
    if (this != &obj) {
        this->clear();
        buffer = obj.buffer;
        count = obj.count;
        obj.buffer = nullptr;
        obj.count = 0;
    }
    return *this;
}