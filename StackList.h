#pragma once
#include "Stack.h"
#include "List.h"       // brings LinkedList.h with it

// A stack that HAS a LinkedList.
// Top of the stack = front of the list.

template <typename T>
class StackList : public Stack<T> {
public:
    void push(T* value) override {
        list_.addFront(value);
    }

    void pop() override {
        list_.deleteFront();
    }

    T* peek() const override {
        return list_.getFront();
    }

    bool isEmpty() const override {
        return list_.isEmpty();
    }

    int size() const override {
        return list_.size();
    }

    void print() const override {
        list_.print();
    }

private:
    LinkedList<T> list_;
};
