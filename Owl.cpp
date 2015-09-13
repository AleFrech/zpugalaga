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
  
  goalX = 160 - width;
  goalY = y + height;
  axisToggle = false;
}

Owl::~Owl()
{
    //dtor
}

void Owl::processMovementPattern(){
   
//    direction = 'd';
  if(x >= 160-(width+10) && direction == 'r')
  {
      direction = 'l';  
  }
  else if (x <= 0 && direction == 'l')
     direction = 'r'; 
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
