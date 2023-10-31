#pragma once
#include <iostream>
#include "math.h"
#include <SDL.h>


class player
{
public:
	void control(SDL_Event const& event);
	Vector2f& get_Player_Pos()
	{
		Vector2f player_pos(player_x, player_y);
	
		return player_pos;
	};
	
	enum class Direction
	{
		NONE,
		UP,
		DOWN,
		LEFT,
		RIGHT
	};
private:
	Vector2f player_pos;
	
	float player_x = 200;

	float player_y = 100;
	Direction    m_direction;
};
//
//vector pos
//call control on main
//switch and case funcations for sdl2 keys
//for movement