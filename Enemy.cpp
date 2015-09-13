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
  movementRate = 20;
  movementCounter = 0;
  active = true;
}

Enemy::~Enemy()
{
    //dtor
}

void Enemy::processMovementPattern(){
    if(y > 120)
        y = 0;
}
