#include <string.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <string>

class Person
{
public:
    Person();
    Person(const char *, const char *);
    Person(const Person &);
    Person(Person &&) noexcept;
    Person &operator=(const Person &);
    Person &operator=(Person &&) noexcept;
    ~Person();

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

// Custom Constructor
Person::Person(const char *name, const char *note) : name(name), note_size(strlen(note) ? strlen(note) + 1 : 0), note(note_size ? new char[note_size] : nullptr)
{
    strcpy(this->note, note);
    std::cout << "Custom Constructor" << std::endl;
}

// Copy Constructor
Person::Person(const Person &other) : name(other.name), note_size(other.note_size), note(note_size ? new char[note_size] : nullptr)
{
    std::cout << "Copy Constructor" << std::endl;
    std::copy(other.note, other.note + note_size, note);
}

// Move Constructor
Person::Person(Person &&other) noexcept
    : name(other.name), note_size(other.note_size), note(other.note)
{
    std::cout << "Move Constructor" << std::endl;
    other.note = nullptr;
}

// Copy Assignment
Person &Person::operator=(const Person &other)
{
    std::cout << "Copy Assignment" << std::endl;
    Person tmp(other);
    *this = std::move(tmp);
    return *this;
}

// Move Assignment
Person &Person::operator=(Person &&other) noexcept
{
    std::cout << "Move Assignment" << std::endl;
    if (this == &other)
        return *this;
    delete[] note;
    name = other.name;
    note_size = other.note_size;
    note = other.note;
    other.note_size = 0;
    other.note = nullptr;
    return *this;
}

// Deconstructor
Person::~Person()
{
    std::cout << "Deconstructor" << std::endl;
    delete[] note;
}
