#include "Owl.h"

Owl::Owl(int x, int y, unsigned char* enemyImage)
{
    //ctor
    
  PixelMap = enemyImage;
  width = 16;
  height = 16;
  this->x = x;
  this->y = y;
  movement = true;
  instanceOf = 'O';
  direction = 'r';
  movementRate = 15;  
  movementCounter = 0;
  shootingCooldownRate = 100;
  shootingCooldownTime = 0;
  goalX = 160 - width;
  goalY = y + height;
  axisToggle = false;
  active = true;
}

Owl::~Owl()
{
    //dtor
}

void Owl::shoot(){
  
  if(shootingCooldownTime == 0)
      if(!projectile->active){
          projectile->activate(x+8,y);
          shootingCooldownTime = shootingCooldownRate;      
    }
}

void Owl::processMovementPattern(){
   

  if(projectile->active){
          if(projectile->y >120 ){
              projectile->active = false;              
          }
          
      }
  this->shoot();
  if(shootingCooldownTime > 0)
      shootingCooldownTime--;
  if(projectile->active)
    projectile->move();
  if(x >= 160-(width+10) && direction == 'r')
  {
      direction = 'l';  
  }
  else if (x <= 0 && direction == 'l')
     direction = 'r'; 
}

void Owl::initProjectile(unsigned char* image)
{
          projectile = new Projectile(x+8,y-height,image);
          projectile->direction = 'd';
}
/*

  direction = 'd';
  if(x >= 160-(width+10) && direction == 'r')
  {
      direction = 'l';  
  }
  else if (x <= 0 && direction == 'l')
     direction = 'r';  
     
*/
