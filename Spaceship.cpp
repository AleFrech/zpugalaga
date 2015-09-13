#include "Spaceship.h"

Spaceship::Spaceship(int x,unsigned char *enemyImage)
{
    //ctor
    Lives = 3;
    PixelMap = enemyImage;
    this->x = x;
    this->y = 100;
    this->width =16;
    this-> height = 16;
}

Spaceship::~Spaceship()
{
    //dtor
}
