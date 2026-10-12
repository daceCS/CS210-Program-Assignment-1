#pragma once

// The Stack ADT. Last in, first out.
// This file only says WHAT a stack can do. It has no data and no code.
// StackList.h (you write it) says HOW.

template <typename T>
class Stack {
public:
    virtual ~Stack() = default;

    virtual void push(T* value) = 0;   // add on top, stack owns value
    virtual void pop() = 0;            // remove the top and delete it
    virtual T* peek() const = 0;       // look at the top, nullptr if empty
    virtual bool isEmpty() const = 0;
    virtual int size() const = 0;
    virtual void print() const = 0;    // top first
};
