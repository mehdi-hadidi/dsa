#include <iostream>
#include <list>
#include <vector>
#include <memory>

#include "linked_list.hpp"

struct person
{
    std::string name;
};

int main()
{
    mh::linked_list<int> lst;
    lst.add_last(10);
    lst.add_last(20);
    lst.add_last(30);
    lst.add_first(50);

    lst.print();

    return 0;
};