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
    void _moveCube(Stack & s1, Stack & s2);
    void _move(unsigned start, unsigned end, Stack & source, Stack & target, Stack & spare, unsigned depth);

};