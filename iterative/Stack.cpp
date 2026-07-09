// C++ class for a "stack" of cubes in a Tower of Hanoi Puzzle

#include "Stack.h"
#include <stdexcept>
#include <iostream>
using namespace std;

void Stack::push_back(const Cube & cube)
{
    // Ensure we do not push a cube on top of a smaller cube:
    if(size() > 0 && cube.getLength() > peekTop().getLength())
    {
        cerr<<"A smaller cube cannot be placed on top of a larger cube."<<endl;
        cerr<<"  Tried to add Cube(length=" <<cube.getLength()<< ")" <<endl;
        cerr<<"  Current stack: "<<*this<<endl;

        throw runtime_error("A smaller cube cannot be placed on top of a larger cube.");
    }

    cubes_.push_back(cube);
}

Cube Stack::removeTop()
{
    Cube cube = peekTop();
    cubes_.pop_back();
    return cube;
}

Cube & Stack::peekTop()
{
    return cubes_[cubes_.size() - 1];
}

unsigned Stack::size() const
{
    return cubes_.size();
}

ostream& operator<<(ostream & os, const Stack & stack)
{
    for(unsigned i=0; i<stack.size(); i++)
    {
        os << stack.cubes_[i].getLength()<<" ";
    }
    os<<endl;
    return os;
}