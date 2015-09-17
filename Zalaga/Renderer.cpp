#include "Renderer.h"
#include "Spaceship.h"
#include "Owl.h"


Renderer::Renderer()
{
    //ctor
    //this->screen = screen;
    
}

Renderer::~Renderer()
{
    //dtor
}

void Renderer::render(Sprite* sprite){
    if(sprite->instanceOf == 'O')
    {
       Owl* owl = (Owl*)sprite;
       render(owl->projectile); 
    }
    
    if(!sprite->active)
      return;
    VGA.writeArea(sprite->x,sprite->y,sprite->width,sprite->height,sprite->PixelMap);
    
    if(sprite->instanceOf == 'P')
    {
      Spaceship* spaceship = (Spaceship*)sprite;
      for(int c = 0; c<5;c++)
      if(spaceship->projectiles[c]-> active)
          render(spaceship->projectiles[c]);
    }
}

void Renderer::clear(){
    VGA.clear();
}
