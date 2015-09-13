#include "Enemy.h"

Enemy::Enemy(int x, int y, unsigned char* enemyImage)
{
    //ctor
    
  PixelMap = enemyImage;
  width = 13;
  height = 10;
  this->x = x;
  this->y = y;
}

Enemy::~Enemy()
{
    //dtor
}
