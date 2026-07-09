#pragma once

// C++ class for "stack" of cubes in a tower of Hanoi Problem

#include <iostream>
#include <vector>
#include "uiuc/Cube.h"
using uiuc::Cube;

class Stack
{
    public:
    void push_back(const Cube & cube);
    Cube removeTop();
    Cube & peekTop();
    unsigned size() const;

    // An overloaded operator<<, allowing us to print the stack via 'cout<<'
    friend std::ostream & operator<<(std::ostream & os, const Stack & stack);

    private:
    std::vector<Cube> cubes_;

};

