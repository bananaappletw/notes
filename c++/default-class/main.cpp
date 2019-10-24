#include "main.h"

int main()
{
    // constructor
    Person empty_person = Person();

    // copy construtor
    Person copy_person = Person(empty_person);

    // move constructor
    Person move_person = Person(std::move(copy_person));

    // copy assignment
    Person assignment_person = Person(move_person);

    // move assignment
    Person move_assignment_person = Person(std::move(assignment_person));
}
