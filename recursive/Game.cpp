#include "Game.h"
#include "Stack.h"
#include "uiuc/Cube.h"
#include "uiuc/HSLAPixel.h"

#include <iostream>
using namespace std;


// Default constructor to create an initial state
Game::Game()
{
    // Creates the three empty stacks
    for(int i=0; i<3; i++)
    {
        Stack stackOfCubes;
        stacks_.push_back(stackOfCubes);
    }


// Create the four cubes, placing each on the [0]th stack:
Cube blue(4, uiuc::HSLAPixel::BLUE);
stacks_[0].push_back(blue);

Cube orange(3, uiuc::HSLAPixel::ORANGE);
stacks_[0].push_back(orange);

Cube purple(2, uiuc::HSLAPixel::PURPLE);
stacks_[0].push_back(purple);

Cube yellow(1, uiuc::HSLAPixel::YELLOW);
stacks_[0].push_back(yellow);
}

void Game::_moveCube(Stack & s1, Stack & s2)
{
    Cube cube = s1.removeTop();
    s2.push_back(cube);
}

void Game::_move(unsigned start, unsigned end, Stack & source, Stack & target, Stack & spare, unsigned depth)
{
    // Checking if we are only moving one cube
    if(start == end)
    {
        //If so, move it directly
        _moveCube(source, target);
        cout<<*this<<endl;
        
    }

    else
    {
        // Otherwise, use my move strategy
        _move(start + 1, end , source, spare , target, depth);
        _move(start    ,start, source, target, spare , depth);
        _move(start + 1, end , spare , target, source, depth);

    }   
}

// Solving for Tower of Hanoi Puzzle
void Game::solve()
{
    _move
    (
        0, stacks_[0].size()-1, // Move the entire set of cobes, [0 to size-1]
        stacks_[0], // Source stack is [0]
        stacks_[2], // Target stack is [2]
        stacks_[1], // Spare stack is [1]
        0  // Initial depth (for printouts only) is 0
    );
}

ostream& operator<<(ostream & os, const Game & game)
{
    for(unsigned i=0; i<game.stacks_.size(); i++)
    {
        os << "Stack[" <<i<<", "<<&game.stacks_[i]<<"]: "<<game.stacks_[i]<<endl;
    }
    return os;
}






