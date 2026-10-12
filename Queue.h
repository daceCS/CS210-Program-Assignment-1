#pragma once

// The Queue ADT. First in, first out.
// This file only says WHAT a queue can do. It has no data and no code.
// QueueList.h (you write it) says HOW.

template <typename T>
class Queue {
public:
    virtual ~Queue() = default;

    virtual void enqueue(T* value) = 0;  // add at the back, queue owns value
    virtual void dequeue() = 0;          // remove the front and delete it
    virtual T* front() const = 0;        // look at the front, nullptr if empty
    virtual bool isEmpty() const = 0;
    virtual int size() const = 0;
    virtual void print() const = 0;      // front first
};
