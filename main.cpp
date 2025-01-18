#include <iostream>
#include <list>
#include <vector>
#include <memory>
#include <array>

#include "linked_list.hpp"
#include "array.hpp"


int main()
{
     
    mh::array<int,3> array;
    array[0] = 10;

    for(int i : array)
    {
        std::cout << i << std::endl;
    }

    return 0;
};