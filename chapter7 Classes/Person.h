#include <iostream>
#include <string>

#ifndef PERSON_H
#define PERSON_H

struct Person {
    friend std::istream &read(std::istream &is, Person &np);
    friend std::ostream &print(std::ostream &os, Person const &p);

  private:
    std::string name;
    std::string address;
  public:
    Person() = default;
    Person(const std::string &n, const std::string &a) : name(n), address(a) {} 
    Person(const std::string &n) : name(n) {}
    std::string const &getName() const { return name; };
    std::string const &getAddress() const { return address; };
};


std::istream &read(std::istream &is, Person &np);
std::ostream &print(std::ostream &os, Person const &p);

#endif