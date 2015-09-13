#include "Renderer.h"

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
    VGA.writeArea(sprite->x,sprite->y,sprite->width,sprite->height,sprite->PixelMap);
}
