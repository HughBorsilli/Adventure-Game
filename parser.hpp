//This file exists to avoid linker errors.

#ifndef parser_h
#define parser_h
#include <locale>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "area.hpp"
#include "player.hpp"
#include "enums.hpp"
using std::string; using std::vector;

string lowercase(string);
std::map<string, eVerb> makeVerbMap();
bool parseInput(vector<string> sentence);
void userInput();

#endif