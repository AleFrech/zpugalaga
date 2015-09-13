#include "Spaceship.h"

Spaceship::Spaceship(int x,unsigned char *enemyImage)
{
    //ctor
    Lives = 3;
    Score = 0;
    PixelMap = enemyImage;
    this->x = x;
    this->y = 100;
    this->width =16;
    this-> height = 16;
    movement = false;
    instanceOf = 'P';
    direction = 'd';
    movementRate = 3;
    movementCounter = 0;
}

Spaceship::~Spaceship()
{
    //dtor
}

void Spaceship::processMovementPattern(){
}
