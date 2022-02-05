#include "snake.h"

snake::snake(COORD position, int velocity)
{
    this->position=position;
    this->velocity=velocity;
    direction='n';
    length=1;
    body.push_back(position);
}
