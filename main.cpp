#include <iostream>
#include "List.h"
#include "Player.h"

int main() {
    // ---- Part 1: required test harness, do not modify ----
    std::cout << "== List<int>: addAnywhere / deleteAnywhere / reverse =="
              << std::endl;
    std::unique_ptr<List<int>> nums = makeList<int>();
    nums->addFront(new int(10));
    nums->addFront(new int(20));
    nums->addFront(new int(30));
    nums->print();
    nums->addAnywhere(1, new int(99));
    nums->print();
    nums->deleteAnywhere(2);
    nums->print();
    nums->reverse();
    nums->print();

    std::cout << std::endl << "== List<int>: concat ==" << std::endl;
    std::unique_ptr<List<int>> more = makeList<int>();
    more->addFront(new int(2));
    more->addFront(new int(1));
    more->print();
    nums->concat(more.get());
    nums->print();
    more->print();

    // ---- Part 2: Uno scene ----
    std::cout << std::endl << "== Uno: the table forms ==" << std::endl;
    std::unique_ptr<List<Player>> table = makeList<Player>();
    table->addBack(new Player(1, "Ana"));
    table->addBack(new Player(2, "Ben"));
    table->addBack(new Player(3, "Cam"));
    table->print();

    std::cout << std::endl << "== Dee pulls up a chair (position 1) ==" << std::endl;
    table->addAnywhere(1, new Player(4, "Dee"));
    table->print();

    std::cout << std::endl << "== Someone plays a Reverse card ==" << std::endl;
    std::cout << "Before: ";
    table->print();
    table->reverse();   // <-- the Reverse card: flips the direction of play
    std::cout << "After:  ";
    table->print();

    std::cout << std::endl << "== A player runs out of cards (position 2) ==" << std::endl;
    table->deleteAnywhere(2);
    table->print();

    std::cout << std::endl << "== A second table joins ==" << std::endl;
    std::unique_ptr<List<Player>> table2 = makeList<Player>();
    table2->addBack(new Player(5, "Eli"));
    table2->addBack(new Player(6, "Fay"));
    std::cout << "Table 1 before: ";
    table->print();
    std::cout << "Table 2 before: ";
    table2->print();
    table->concat(table2.get());
    std::cout << "Table 1 after:  ";
    table->print();
    std::cout << "Table 2 after:  ";
    table2->print();

    return 0;
}
