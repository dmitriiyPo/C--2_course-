#include "Queue.h"


Queue::Queue(int n) {
    this->maxSize = n + 1;
    this->Array = new int[maxSize];
    this->head = 0;
    this->tail = 0;
}

bool Queue::full() {
    return (tail + 1) % maxSize == head;
}

bool Queue::empty() {
    return tail == head;
}

int Queue::size() {
    return maxSize;
}

void Queue::clear() {
    //delete[] Array;
   // this->Array = new int[maxSize];
    head = tail = 0;
}

int Queue::size_()
{
    if (tail >= head) {
        return tail - head;
    }
    return maxSize - head + tail;
}

int Queue::getHead() {
    return head;
}

int Queue::getTail() {
    return tail;
}

int* Queue::getArr() {
    return Array;
}

void Queue::push(int e) {
    if (full()) {
        throw "!!!������� �����������!!!";
    }
    Array[tail] = e;
    tail = (tail + 1) % maxSize;
}

void Queue::pop() {
    if (empty()) {
        throw "!!!������� �����!!!";
    }
    head = (head + 1) % maxSize;
}

int Queue::front() {
    if (empty()) {
        throw "!!!������� �����!!!";
    }
    return Array[head];
}



