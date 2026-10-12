#include <iostream>
#include "List.h"   // brings in ArrayList.h and LinkedList.h

int main() {
    LinkedList<int> linked;
    ArrayList<int> array;

    linked.addBack(new int(1));
    array.addBack(new int(2));

    std::cout << "Before:" << std::endl;
    std::cout << "linked: ";
    linked.print();
    std::cout << "array:  ";
    array.print();

    std::cout << std::endl << "linked.concat(array):" << std::endl;
    linked.concat(&array);   // mismatch: should print a message and do nothing

    std::cout << "array.concat(linked):" << std::endl;
    array.concat(&linked);   // mismatch: same

    std::cout << std::endl << "After (both should be unchanged):" << std::endl;
    std::cout << "linked: ";
    linked.print();
    std::cout << "array:  ";
    array.print();

    return 0;
}
