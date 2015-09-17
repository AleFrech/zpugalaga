#include "Enemy.h"

Enemy::Enemy(int x, int y, unsigned char* enemyImage)
{
    //ctor
    
  PixelMap = enemyImage;
  width = 13;
  height = 10;
  this->x = x;
  this->y = y;
  movement = true;
  instanceOf = 'B';
  direction = 'd';
  movementRate = 8;
  movementCounter = 0;
  active = false;
}

Enemy::~Enemy()
{
    //dtor
}

void Enemy::processMovementPattern(){
    if(y >= 120 - height)
        y = 0;
}
