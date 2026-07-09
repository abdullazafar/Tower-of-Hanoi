#include "Game.h"
#include <iostream>
using namespace std;

int main()
{
    Game g;
    cout<<"Initial game state: "<<endl;
    cout<<g<<endl;

    g.solve();

    cout<<"Final game state: "<<endl;
    cout<<g<<endl;


    return 0;
}