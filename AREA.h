//Area class written by JS, 02/27/21.

#ifndef AREA_H
#define AREA_H
#include <string>
#include "PLAYER.h"
using std::string;

//Directions for move function. Using unscoped enum instead of enum class so enum values
//can index arrays without using static_cast.
enum eDir {north = 1, south = 2, east = 3, west = 4};

class area
{
    private:
    static area* areaMap[5][5]; //Grid in which to store pointers to areas
    //for the purpose of movement.
    string areaTag; //Simple identifier; bloodRoom, waterfallRoom, treasureRoom, etc.
    int areaLocationX; //Room's location along the X/east-west axis.
    int areaLocationY; //Room's location along the Y/north-south axis.
    string areaDescription; //What is displayed when entering or looking around the room.
    string areaName; //The room's official name.

    public:
    area(string, int, int, string); //Basic constructor.
    area(string, string); //Constructor for areas that don't fit on the map.
    void displayArea(); //Displays the area description.
    void findExits(); //Finds any exits and outputs their locations.
    void enterArea(); //Moves the player to a given area.
    void setAreaDescription(string); //Sets the area description.
    void goDirection(eDir); //Moves the player in a given direction.
};

#endif