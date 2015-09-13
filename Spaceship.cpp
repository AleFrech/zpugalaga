#include "Spaceship.h"

using namespace std;

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
    shootingCooldownRate = 25;
    shootingCooldownTime = 0;
    active = true;
}

Spaceship::~Spaceship()
{
    //dtor
}

void Spaceship::processMovementPattern(){
  for(int c = 0; c<5; c++)
    if(projectiles[c]->active)
        projectiles[c]->move(); 
   
  
  if(shootingCooldownTime > 0)
      shootingCooldownTime--;
      
    for(int c = 0; c<5;c++)
    {
      if(projectiles[c]->active){
          if(projectiles[c]->y <0 - projectiles[c]->height ){
              projectiles[c]->active = false;              
          }
          
      }
    }  
}

void Spaceship::shoot(){
  
  if(shootingCooldownTime == 0)
    for(int c = 0; c<5;c++)
    {
      if(!projectiles[c]->active){
          projectiles[c]->activate(x+8,y-height);
          shootingCooldownTime = shootingCooldownRate;
          break;
      }
    }
}

void Spaceship::initProjectiles(unsigned char* image)
{
      for(int c = 0; c<5;c++)
          projectiles[c] = new Projectile(x+8,y-height,image);
}
