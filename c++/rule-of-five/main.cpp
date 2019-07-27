#include "person.hpp"

int main()
{
    // constructor
    Person empty_person = Person();

    // custom construtor
    Person custom_person = Person("Bill", "My friend");

    // copy construtor
    Person copy_person = Person(custom_person);

    // move constructor
    Person move_person = Person(std::move(custom_person));

    // copy assignment
    // Person assignment_person = move_person;
    // copy constructor called and move construtor to initialize instead
    Person assignment_person = Person();
    assignment_person = move_person;

    // move assignment
    // Person move_assignment_person = std::move(move_person);
    // move constructor called to initialize instead
    Person move_assignment_person = Person();
    move_assignment_person = std::move(move_person);


}
