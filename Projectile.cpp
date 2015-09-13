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
    movementRate = 1;
    movementCounter = 0;
}

Projectile::~Projectile()
{
    //dtor
}
