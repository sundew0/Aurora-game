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
		gravity();
		Vector2f player_pos(player_x, player_y += acceleration);
	
		return player_pos;
	};	
	float gravity() {
		gravityval * mass;
		velocity += gravityval;
		player_y += velocity;
		return acceleration;
		
	}

	
	enum class Direction
	{
		NONE,
		UP,
		DOWN,
		LEFT,
		RIGHT
	};
	void collisionY() {
		velocity = 0;
	}

	float acceleration = 0;
	
	float velocity = 0;
	float gravityval = 0.0001;

private:
	int mass = 100;
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