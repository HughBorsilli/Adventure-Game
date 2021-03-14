//Area class written by JS, 02/27/21.

#include <iostream>
#include "AREA.h"
#include "PARSER.cpp"
using std::cout; using std::cin; using std::string; using std::endl;

//Displays description text for the given area. Could be used with a
//>look command if we end up implementing a parser.
void area::displayArea()
{
    cout << areaDescription << endl;
}

//Displays the area description, moves the player, and displays the area's exits.
void area::enterArea()
{
    displayArea();
    player* p1 = player::getPlayer();
    p1->playerLocationX = areaLocationX;
    p1->playerLocationY = areaLocationY;
    findExits();
}

//Basic coordinate math on the 2D array allows us to determine if a room has exits.
void area::findExits()
{
    if (areaMap[areaLocationX][areaLocationY - 1]->areaTag != "") //is the adjacent area instantiated?
    {
        cout << "To the north, there is the " << areaMap[areaLocationX][areaLocationY - 1]->areaName << "." << endl;
    }
    if (areaMap[areaLocationX][areaLocationY + 1]->areaTag != "")
    {
        cout << "To the south, there is the " << areaMap[areaLocationX][areaLocationY + 1]->areaName << "." << endl;
    }
    if (areaMap[areaLocationX + 1][areaLocationY]->areaTag != "")
    {
        cout << "To the east, there is the " << areaMap[areaLocationX + 1][areaLocationY]->areaName << "." << endl;
    }
    if (areaMap[areaLocationX - 1][areaLocationY]->areaTag != "")
    {
        cout << "To the west, there is the " << areaMap[areaLocationX - 1][areaLocationY]->areaName << "." << endl;
    }
}

//Sets the description of the area. Call upon area creation and if you
//change something about the room.
void area::setAreaDescription(string description)
{
    areaDescription = description;
}

//Moves the player in a given direction.
void area::goDirection(eVerb direction)
{
    switch (direction)
    {
        case north:
        areaMap[areaLocationX][areaLocationY - 1]->enterArea();
        break;
        case south:
        areaMap[areaLocationX][areaLocationY + 1]->enterArea();
        break;
        case east:
        areaMap[areaLocationX + 1][areaLocationY]->enterArea();
        break;
        case west:
        areaMap[areaLocationX - 1][areaLocationY]->enterArea();
        break;
    }
}

//Basic constructor for an area.
area::area(int X, int Y, string name)
{
    areaLocationX = X;
    areaLocationY = Y;
    areaMap[X][Y] = this;
    areaName = name;
}

//Constructor for areas that don't fit on the map.
area::area(string tag, string name)
{
    areaTag = tag;
    areaName = name;
}

area* area::getArea(int X, int Y)
{
    return areaMap[X][Y];
}

area* area::getCurrentArea()
{
    player* p1 = player::getPlayer();
    return areaMap[(p1->getPlayerX()][p1->getPlayerY()];
}