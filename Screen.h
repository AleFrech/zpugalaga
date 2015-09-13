#ifndef SCREEN_H
#define SCREEN_H
#include "Renderer.h"
#include "Sprite.h"
#include "Enemy.h"
#include "Owl.h"
#include "Spaceship.h"

class Screen
{
    public:
        const static int WIDTH = 160;
        const static int HEIGHT = 120;
        Renderer renderer;
        Spaceship *spaceship1;
        Spaceship *spaceship2;
        Screen();
        virtual ~Screen();
        
        void executeScreen();
        void render();
        void handleInput();
        int PointInRectangle(int x,int y,int x1,int y1,int x2,int y2);
        int Collision(Sprite *s1, Sprite *s2);
        unsigned char ViewPort[WIDTH][HEIGHT];
    protected:
    private:
};

#endif // SCREEN_H
