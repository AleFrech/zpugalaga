#include "Sprite.h"

Sprite::Sprite()
{
    //ctor
}

Sprite::~Sprite()
{
    //dtor
}

void Sprite::move(){
   processMovementPattern();
   if(movement){
      if(++movementCounter == movementRate){
        movementCounter  = 0;
        switch(direction){
           case 'r': 
                     if(x+width<160)
                       x++; 
                     break;
           case 'l': 
                     if(x>0)
                       x--; 
                     break;
           case 'u': y--; break;
           case 'd': y++; break;
        }
      }
   } 
  
}

void Sprite::setMovement(char direction){
   movement  = true;
   this->direction = direction; 
}

void Sprite::processMovementPattern(){
}

void Sprite::shoot(){
}
