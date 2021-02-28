#include <iostream>
#include <iomanip>
#include "AREA.h"
using std::cout; using std::cin; using std::string; using std::endl;

//JS: Displays description text for the given area. Could be used with a
//>look command if we end up implementing a parser.
void area::displayArea()
{
    cout << areaDescription << endl;
}

//JS: Displays the area description, moves the player, and displays the
//areas exits. Well, 1/3 ain't bad.
void area::enterArea()
{
    area::displayArea();
}

//JS: This will depend on principles I don't fully understand yet. I
//fully intend to implement it. (I'm thinking along the lines of "the X
//and Y coordinates determine adjacency, and by default there's a
//connecting door, but the bool can be flipped to 'there's a wall here'".)
void area::findExits()
{
    cout << "Hello, world!" << endl;
}

//JS: Sets the description of the area. Call upon area creation and if you
//change something about the room (besides picking something up, natch.)
void area::setAreaDescription(string description)
{
    area::areaDescription = description;
}

//JS: Basic constructor for an area.
area::area(string tag, int X, int Y)
{
    area::areaTag = tag;
    area::areaLocationX = X;
    area::areaLocationY = Y;
}