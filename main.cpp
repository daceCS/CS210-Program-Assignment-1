#include <iostream>
#include "List.h"
#include "Data.h"

int main() {
    std::cout << "== List<int> ==" << std::endl;
    std::unique_ptr<List<int>> list = makeList<int>();
    list->addFront(new int(20));
    list->addFront(new int(10));
    list->addBack(new int(30));
    list->print();                                           // 10,20,30,
    std::cout << "getFront: " << *list->getFront() << std::endl;   // 10
    std::cout << "size: " << list->size() << std::endl;            // 3
    list->deleteFront();
    list->print();                                           // 20,30,

    return 0;
}
