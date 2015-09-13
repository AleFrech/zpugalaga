#include "VGA.h"
#include <stdio.h>     
#include <stdlib.h>     
#include <time.h>
#include "Renderer.h"
#include "Sprite.h"
#include "Enemy.h"
#include "Owl.h"
#include "Spaceship.h"
#include "Projectile.h"

int PointInRectangle(int x,int y,int x1,int y1,int x2,int y2){
  	return ((( (x) >= (x1)) && ((y) >= (y1))) && (((x) <= (x2)) && ((y) <= (y2))));
}

int Collision(Sprite *s1, Sprite *s2)
{
	return (PointInRectangle(s1->x, s1->y, s2->x, s2->y, s2->x+s2->width, s2->y+s2->height) ||
		PointInRectangle(s1->x+s1->width, s1->y+s1->height, s2->x,s2->y, s2->x+s2->width, s2->y+s2->height) ||
		PointInRectangle(s1->x, s1->y+s1->height, s2->x, s2->y, s2->x+s2->width, s2->y+s2->height) ||
		PointInRectangle(s1->x+s1->width, s1->y, s2->x, s2->y, s2->x+s2->width, s2->y+s2->height));
}
unsigned char SpaceShip[] = {
BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,
BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,
BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,
BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,
BLACK,BLACK,BLACK,RED,RED,BLACK,WHITE,WHITE,WHITE,WHITE,BLACK,RED,RED,BLACK,BLACK,BLACK,
BLACK,BLACK,BLACK,RED,RED,BLACK,WHITE,WHITE,WHITE,WHITE,BLACK,RED,RED,BLACK,BLACK,BLACK,
BLACK,BLACK,BLACK,WHITE,WHITE,BLACK,WHITE,WHITE,WHITE,WHITE,BLACK,WHITE,WHITE,BLACK,BLACK,BLACK,
BLACK,BLACK,BLACK,WHITE,WHITE,BLACK,WHITE,RED,RED,WHITE,BLACK,WHITE,WHITE,BLACK,BLACK,BLACK,
RED,RED,BLACK,BLUE,BLUE,BLACK,WHITE,RED,RED,WHITE,BLACK,BLUE,BLUE,BLACK,RED,RED,
RED,RED,BLACK,BLUE,BLUE,BLACK,RED,RED,RED,RED,BLACK,BLUE,BLUE,BLACK,RED,RED,
WHITE,WHITE,BLACK,WHITE,WHITE,WHITE,RED,WHITE,WHITE,RED,WHITE,WHITE,WHITE,BLACK,WHITE,WHITE,
WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,RED,WHITE,WHITE,RED,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,
WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,
WHITE,WHITE,WHITE,WHITE,BLACK,RED,RED,WHITE,WHITE,RED,RED,BLACK,WHITE,WHITE,WHITE,WHITE,
WHITE,WHITE,WHITE,WHITE,BLACK,RED,RED,WHITE,WHITE,RED,RED,BLACK,WHITE,WHITE,WHITE,WHITE,
WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE
};

unsigned char projectileOwl[] = {
BLACK,YELLOW,BLACK,
BLACK,YELLOW,BLACK,
BLACK,YELLOW,BLACK,
RED,CYAN,RED,
RED,CYAN,RED,
BLACK,RED,BLACK
};

unsigned char Player2[256] ;

unsigned char Heart[]=
{
    GREEN,GREEN,BLACK,BLACK,GREEN,BLACK,BLACK,GREEN,GREEN,
    GREEN,BLACK,RED,RED,BLACK,RED,RED,BLACK,GREEN,
    BLACK,RED,RED,RED,RED,RED,RED,RED,BLACK,
    BLACK,RED,RED,RED,RED,RED,RED,RED,BLACK,
    GREEN,BLACK,RED,RED,RED,RED,RED,BLACK,GREEN,
    GREEN,GREEN,BLACK,RED,RED,RED,BLACK,GREEN,GREEN,
    GREEN,GREEN,GREEN,BLACK,RED,BLACK,GREEN,GREEN,GREEN,
    GREEN,GREEN,GREEN,GREEN,BLACK,GREEN,GREEN,GREEN,GREEN,
};

unsigned char bee[] = {BLACK, BLUE, BLACK, BLACK,BLACK, BLACK, YELLOW, BLACK, BLACK,BLACK, BLACK,BLUE, BLACK,
                          BLACK, BLACK, BLUE, BLACK,YELLOW, RED, YELLOW, RED, YELLOW,BLACK, BLUE,BLACK, BLACK,
                          BLACK, BLACK, BLACK, BLUE,RED, RED, YELLOW, RED, RED,BLUE, BLACK,BLACK, BLACK,
                          BLACK, BLACK, BLACK, BLACK,YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,BLACK, BLACK,BLACK, BLACK,
                          BLACK, BLACK, BLACK, BLUE,BLUE, YELLOW, YELLOW, YELLOW, BLUE,BLUE, BLACK,BLACK, BLACK,
                          BLACK, BLACK, BLUE, BLUE,BLUE, RED, RED, RED, BLUE,BLUE, BLUE,BLACK, BLACK,
                          BLACK, BLUE, BLUE, BLUE,BLACK, RED, RED, RED, BLACK,BLUE, BLUE,BLUE, BLACK,
                          BLUE, BLUE, BLUE, BLUE,BLACK, YELLOW, YELLOW, YELLOW, BLACK,BLUE, BLUE,BLUE, BLUE,
                          BLUE, BLUE, BLUE, BLACK,BLACK, RED, RED, RED, BLACK,BLACK, BLUE,BLUE, BLUE,
                          BLUE, BLUE, BLUE, BLACK,BLACK, BLACK, RED, BLACK, BLACK,BLACK, BLUE,BLUE, BLUE,};
                          
unsigned char enemySpaceship[] = {
BLACK,BLACK,YELLOW,YELLOW,BLACK,RED,RED,GREEN,GREEN,RED,RED,BLACK,YELLOW,YELLOW,BLACK,BLACK,
BLACK,GREEN,YELLOW,YELLOW,GREEN,RED,RED,GREEN,GREEN,RED,RED,GREEN,YELLOW,YELLOW,GREEN,BLACK,
BLACK,GREEN,YELLOW,YELLOW,GREEN,RED,RED,RED,RED,RED,RED,GREEN,YELLOW,YELLOW,GREEN,BLACK,
BLACK,GREEN,GREEN,GREEN,GREEN,RED,RED,RED,RED,RED,RED,GREEN,GREEN,GREEN,GREEN,BLACK,
BLACK,GREEN,GREEN,GREEN,GREEN,RED,RED,RED,RED,RED,RED,GREEN,GREEN,GREEN,GREEN,BLACK,
BLACK,GREEN,GREEN,GREEN,GREEN,RED,RED,RED,RED,RED,RED,GREEN,GREEN,GREEN,GREEN,BLACK,
BLACK,GREEN,GREEN,GREEN,GREEN,RED,RED,GREEN,GREEN,RED,RED,GREEN,GREEN,GREEN,GREEN,BLACK,
RED,RED,GREEN,BLACK,BLACK,RED,RED,GREEN,GREEN,RED,RED,BLACK,BLACK,GREEN,RED,RED,
RED,RED,RED,BLACK,BLACK,BLACK,GREEN,GREEN,GREEN,GREEN,BLACK,BLACK,BLACK,RED,RED,RED,
GREEN,RED,RED,BLACK,BLACK,BLACK,GREEN,GREEN,GREEN,GREEN,BLACK,BLACK,BLACK,RED,RED,GREEN,
GREEN,GREEN,BLACK,BLACK,BLACK,BLACK,GREEN,GREEN,GREEN,GREEN,BLACK,BLACK,BLACK,BLACK,GREEN,GREEN,
GREEN,GREEN,BLACK,BLACK,BLACK,BLACK,GREEN,GREEN,GREEN,GREEN,BLACK,BLACK,BLACK,BLACK,GREEN,GREEN,
GREEN,GREEN,BLACK,BLACK,BLACK,BLACK,GREEN,YELLOW,YELLOW,GREEN,BLACK,BLACK,BLACK,BLACK,GREEN,GREEN,
GREEN,GREEN,BLACK,BLACK,BLACK,BLACK,GREEN,YELLOW,YELLOW,GREEN,BLACK,BLACK,BLACK,BLACK,GREEN,GREEN,
GREEN,GREEN,BLACK,BLACK,BLACK,BLACK,BLACK,YELLOW,YELLOW,BLACK,BLACK,BLACK,BLACK,BLACK,GREEN,GREEN,
GREEN,GREEN,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,GREEN,GREEN
};

unsigned char owl[] = {
BLACK,BLACK,BLACK,BLUE,BLUE,BLUE,BLACK,BLACK,BLACK,BLACK,BLUE,BLUE,BLUE,BLACK,BLACK,BLACK,
BLACK,BLACK,BLACK,BLACK,BLUE,BLUE,BLACK,BLACK,BLACK,BLACK,BLUE,BLUE,BLACK,BLACK,BLACK,BLACK,
BLUE,BLUE,BLUE,RED,RED,RED,BLUE,BLUE,BLUE,BLUE,RED,RED,RED,BLUE,BLUE,BLUE,
BLUE,BLUE,BLUE,RED,RED,RED,BLUE,BLUE,BLUE,BLUE,RED,RED,RED,BLUE,BLUE,BLUE,
BLACK,BLUE,BLUE,RED,RED,RED,BLUE,BLUE,BLUE,BLUE,RED,RED,RED,BLUE,BLUE,BLACK,
BLACK,BLACK,BLACK,BLUE,BLUE,BLUE,BLUE,BLUE,BLUE,BLUE,BLUE,BLUE,BLUE,BLACK,BLACK,BLACK,
BLACK,BLACK,BLACK,GREEN,GREEN,GREEN,GREEN,BLUE,BLUE,GREEN,GREEN,GREEN,GREEN,BLACK,BLACK,BLACK,
BLACK,BLACK,BLUE,GREEN,GREEN,GREEN,GREEN,BLUE,BLUE,GREEN,GREEN,GREEN,GREEN,BLUE,BLACK,BLACK,
BLACK,BLUE,BLUE,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,BLUE,BLUE,BLACK,
BLUE,BLUE,BLUE,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,BLUE,BLUE,BLUE,
BLUE,BLUE,BLUE,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,BLUE,BLUE,BLUE,
BLUE,BLUE,BLUE,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,BLUE,BLUE,BLUE,
BLUE,BLUE,BLUE,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,BLUE,BLUE,BLUE,
BLUE,BLUE,BLUE,BLACK,YELLOW,YELLOW,BLACK,BLACK,BLACK,BLACK,YELLOW,YELLOW,BLACK,BLUE,BLUE,BLUE,
BLACK,BLUE,BLUE,BLACK,YELLOW,YELLOW,BLACK,BLACK,BLACK,BLACK,YELLOW,YELLOW,BLACK,BLUE,BLUE,BLACK,
BLACK,BLACK,BLUE,BLACK,YELLOW,YELLOW,BLACK,BLACK,BLACK,BLACK,YELLOW,YELLOW,BLACK,BLUE,BLACK,BLACK,
};

unsigned char projectile[] = {BLACK, BLUE, BLACK,BLUE,BLUE,BLUE,BLUE,WHITE,BLUE,BLACK,RED,BLACK,BLACK,RED,BLACK,BLACK,RED,BLACK};

Sprite enemies[10];
Enemy *bees[5];
Owl *owls[5];
int spawnTimer = 0;
int spawnTimerCooldown = (30*30);
Spaceship spaceship1(100,SpaceShip);
Spaceship spaceship2(40, Player2);
Renderer renderer;
Sprite* createEntity(int x, int y, char instanceOf)
{
    switch(instanceOf)
    {
      case 'B' :
        return new Enemy(x,y,bee);
        break;
      case 'O' :
        return new Owl(x,y,owl);
        break;
    }
}

void reactivateEntity(Sprite*sprite,int x, int y); 
 
void setup(){
  
  VGA.begin(VGAWISHBONESLOT(9),CHARMAPWISHBONESLOT(10));
  Serial.begin(9600);
  
  for(int i = 0; i<256; i++){
      if(SpaceShip[i] == WHITE)
        Player2[i] = RED;
      else if(SpaceShip[i] == RED)
        Player2[i] = BLUE;
      else if(SpaceShip[i] == BLUE)
        Player2[i] = YELLOW;
      else
        Player2[i] = SpaceShip[i];
  }
  for(int i = 0; i<5; i++){
    bees[i] = (Enemy*)createEntity(i*10,0,'B');
    owls[i] = (Owl*)createEntity(0,i*16,'O');
    owls[i]->initProjectile(projectileOwl);
  }
  spaceship1.initProjectiles(projectile);
  spaceship2.initProjectiles(projectile);
}
 

  void handleCollisions(int i);

void loop(){
  VGA.clear();
  char* scorePlayer1;
  char* scorePlayer2;
  VGA.printtext(0, 0, "P1:");
  itoa(spaceship1.Score,scorePlayer1,10);
  VGA.printtext(30, 0, scorePlayer1);
  VGA.printtext(100, 0, "P2:");
  itoa(spaceship2.Score,scorePlayer2,10);
  VGA.printtext(130, 0, scorePlayer2);
  VGA.setColor(WHITE);
  
  spaceship1.move();
  spaceship2.move();

  for(int i = 0; i<5; i++){
    bees[i]->move();
    owls[i]->move();
    renderer.render(bees[i]);
    renderer.render(owls[i]);
    
    if(spawnTimer <= 0)
    {  
      int horizontalCoordinate = (rand() % (9) + 0);
      horizontalCoordinate*=16;
      int verticalCoordinate = rand() % 20 + 0;    
      if(!bees[i]->active){
        reactivateEntity(bees[i],horizontalCoordinate,verticalCoordinate);
        spawnTimer = spawnTimerCooldown;
      }
      if(!owls[i]->active){
        reactivateEntity(owls[i],horizontalCoordinate,verticalCoordinate);
        spawnTimer = spawnTimerCooldown;
      }
    }
        
  handleCollisions(i);
  spawnTimer--;  
  
  
  renderer.render(&spaceship1);
  renderer.render(&spaceship2);
  }
  delay(2);
  if(digitalRead(FPGA_BTN_1))
  {
    spaceship1.setMovement('r');
  }
  else if(digitalRead(FPGA_BTN_0))
    spaceship1.setMovement('l');
   else{
     spaceship1.movement = false;
   }
    
  if(digitalRead(FPGA_BTN_3))
    spaceship2.setMovement('r');
  else if(digitalRead(FPGA_BTN_2))
    spaceship2.setMovement('l');
    else{
     spaceship2.movement = false;
   }
  if(digitalRead(FPGA_SW_0)){
    spaceship1.shoot();
    
  }
  if(digitalRead(FPGA_SW_7)){
    spaceship2.shoot(); 
  }
  
  if(digitalRead(FPGA_SW_6)){
    spaceship2.active = true;
    spaceship1.active = true; 
    
    spaceship2.Score =0;
    spaceship1.Score =0;
  }
}


 void handleCollisions(int i){
       int highscoreDelta = 1;
       if((Collision(&spaceship1, bees[i]) && bees[i]->active) || (Collision(&spaceship1, owls[i]->projectile) && owls[i]->active))
          spaceship1.active = false;
       if((Collision(&spaceship2, bees[i])&& bees[i]->active) || (Collision(&spaceship2,owls[i]->projectile) && owls[i]->active))
          spaceship2.active = false;
       for(int j = 0; j<5; j++){
      if(spaceship1.projectiles[j]->active){
        if(Collision(spaceship1.projectiles[j],bees[i]) && bees[i]->active)
        {
          bees[i]->active = false;
          spaceship1.projectiles[j]->active = false;
          spaceship1.Score += highscoreDelta;
        }
        if(Collision(spaceship1.projectiles[j],owls[i]) && owls[i]->active)
        {
          owls[i]->active = false;
          spaceship1.projectiles[j]->active = false;
          spaceship1.Score += highscoreDelta;
          
        }
      }
      if(spaceship2.projectiles[j]->active){
        if(Collision(spaceship2.projectiles[j],bees[i]) && bees[i]->active)
        {
          bees[i]->active = false;
          spaceship2.projectiles[j]->active = false;
          spaceship2.Score += highscoreDelta;
        }
        if(Collision(spaceship2.projectiles[j],owls[i]) && owls[i]->active)
        {
          owls[i]->active = false;
          spaceship2.projectiles[j]->active = false;
          spaceship2.Score += highscoreDelta;
        }
      }
    }
  }
  
  
void reactivateEntity(Sprite* sprite, int x, int y)
{
  sprite->active = true;
  sprite->x = x;
  sprite->y = y;
}


