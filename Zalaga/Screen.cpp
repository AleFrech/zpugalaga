#include "Screen.h"

Screen::Screen()
{
    //ctor
}

Screen::~Screen()
{
    //dtor
}

void Screen::executeScreen(){
   render();
   handleInput();
}

void Screen::render(){
  renderer.clear();
  //if(Collision(&spaceship1,&enemy))
        
  spaceship1->move();
  spaceship2->move();
  //enemy.move();
  //renderer.render(&enemy);
  renderer.render(spaceship1);
  renderer.render(spaceship2);
}

void Screen::handleInput(){
  if(digitalRead(FPGA_BTN_1))
  {
    spaceship1->setMovement('r');
  }
  else if(digitalRead(FPGA_BTN_0))
    spaceship1->setMovement('l');
   else{
     spaceship1->movement = false;
   }
    
  if(digitalRead(FPGA_BTN_3))
    spaceship2->setMovement('r');
  else if(digitalRead(FPGA_BTN_2))
    spaceship2->setMovement('l');
    else{
     spaceship2->movement = false;
   }

}

int Screen::PointInRectangle(int x,int y,int x1,int y1,int x2,int y2){
  	return ((( (x) >= (x1)) && ((y) >= (y1))) && (((x) <= (x2)) && ((y) <= (y2))));
}

int Screen::Collision(Sprite *s1, Sprite *s2)
{
	return (PointInRectangle(s1->x, s1->y, s2->x, s2->y, s2->x+s2->width, s2->y+s2->height) ||
		PointInRectangle(s1->x+s1->width, s1->y+s1->height, s2->x,s2->y, s2->x+s2->width, s2->y+s2->height) ||
		PointInRectangle(s1->x, s1->y+s1->height, s2->x, s2->y, s2->x+s2->width, s2->y+s2->height) ||
		PointInRectangle(s1->x+s1->width, s1->y, s2->x, s2->y, s2->x+s2->width, s2->y+s2->height));
}
