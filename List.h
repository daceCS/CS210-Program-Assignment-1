#pragma once
#include <memory>

// The List ADT. ArrayList and LinkedList both implement all of these.

template <typename T>
class List {
public:
    virtual ~List() = default;

    virtual void addFront(T* value) = 0;
    virtual void deleteFront() = 0;
    virtual bool search(T* value) const = 0;
    virtual void print() const = 0;

    virtual void addBack(T* value) = 0;    // add at the end, list owns value
    virtual T* getFront() const = 0;       // look at the first item, nullptr if empty
    virtual bool isEmpty() const = 0;
    virtual int size() const = 0;
};

#include "ArrayList.h"
#include "LinkedList.h"

template <typename T>
std::unique_ptr<List<T>> makeList() {
    return std::make_unique<LinkedList<T>>();
    // return std::make_unique<ArrayList<T>>();
}
