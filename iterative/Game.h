#pragma once

#include "Stack.h"
#include <vector>
using namespace std;


class Game
{
    public:
    Game();
    void solve();

    // An overloaded operator<<, allowing us to print the stack via 'cout<<':
    friend ostream& operator<<(ostream & os, const Game & game);

    private:
    std::vector<Stack> stacks_;

    private:
    void _move(unsigned index1, unsigned index2);
    void _legalMove(unsigned index1, unsigned index2);

};