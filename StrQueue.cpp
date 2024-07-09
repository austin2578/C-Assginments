// Attached: HW_7
// ===================================================
// Program: StrQueue.cpp
// ===================================================
// Programmer: Austin Monroe
// Class: CS-1C
//====================================================
//Description:
// This is the queue function definition file
//=====================================================

#include "StrQueue.h"

StrQueue::StrQueue(int size) {
    maxSize = size;
    strPtr = new std::string[size];
    front = rear = -1;
}

StrQueue::~StrQueue() {
    delete[] strPtr;
}

bool StrQueue::isEmpty() const {
    return (front == -1 && rear == -1);
}

bool StrQueue::isFull() const {
    return (rear == maxSize - 1);
}

bool StrQueue::enqueue(const std::string &item) {
    if (isFull())
        return false;
    if (isEmpty())
        front = rear = 0;
    else
        rear++;
    strPtr[rear] = item;
    return true;
}

bool StrQueue::dequeue(std::string &item) {
    if (isEmpty())
        return false;
    item = strPtr[front];
    if (front == rear)
        front = rear = -1;
    else
        front++;
    return true;
}

void StrQueue::makeEmpty() {
    front = rear = -1;
}