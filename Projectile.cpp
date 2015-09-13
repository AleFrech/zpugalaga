#include "Projectile.h"

Projectile::Projectile(int x, int y, unsigned char *image)
{
    //ctor
    PixelMap = image;
    this->x = x;
    this->y = y;
    this->width =3;
    this-> height = 6;
    movement = true;
    instanceOf = 'p';
    direction = 'u';
    movementRate = 2;
    movementCounter = 0;
    active = false;
}

Projectile::~Projectile()
{
    //dtor
    delete PixelMap;
}

void Projectile::activate(int x, int y)
{
    this->x = x;
    this->y = y;
    active = true;
    
}
