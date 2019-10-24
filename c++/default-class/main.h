#include <string.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <string>

class Person
{
public:
    Person();

private:
    std::string name;
    int note_size;
    char *note;
};

// Default Constructor
Person::Person() : name(), note_size(0), note(nullptr)
{
    std::cout << "Constructor" << std::endl;
}
