#include "player.h"
using namespace std;
#include <iostream>
#include "math.h"


void player::control(SDL_Event const& event)
{

    float delta_time = 0.5;
    cout << "x " << player_x << " y " << player_y << endl;
    switch (event.type)
        {
        case SDL_KEYDOWN:
            Uint8 const* keys = SDL_GetKeyboardState(nullptr);

            if (keys[SDL_SCANCODE_W] == 1)
                m_direction = Direction::UP;
            else if (keys[SDL_SCANCODE_S] == 1)
                m_direction = Direction::DOWN;
            else if (keys[SDL_SCANCODE_A] == 1)
                m_direction = Direction::LEFT;
            else if (keys[SDL_SCANCODE_D] == 1)
                m_direction = Direction::RIGHT;
            break;
    }

    switch (m_direction)
    {
        case Direction::NONE:
            player_x += 0.0;
            player_y += 0.0;
            break;
        case Direction::UP:
            player_y = player_y - (5.0 * delta_time);
            cout << "up" << endl;
            break;
        case Direction::DOWN:
            player_y = player_y + (5.0 * delta_time);
            cout << "down" << endl;
            break;
        case Direction::LEFT:
            player_x = player_x - (5.0 * delta_time);
            cout << "left" << endl;
            break;
        case Direction::RIGHT:
            player_x = player_x + (5.0 * delta_time);
            cout << "right" << endl;
            break;
    }
}
