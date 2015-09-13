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
}

Enemy::~Enemy()
{
    //dtor
}

void Enemy::processMovementPattern(){
    if(y > 60)
        y = 0;
}
