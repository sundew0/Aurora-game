#pragma once
#include <iostream>
#include "math.h"



class player
{
public:
	void control(std::string keyPressed);

private:
	Vector2f player_pos();

};
//
//vector pos
//call control on main
//switch and case funcations for sdl2 keys
//for movement