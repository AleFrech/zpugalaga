#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "Sprite.h"

class Spaceship: public Sprite
{
    public:
        Spaceship();
        virtual ~Spaceship();
        
        int Lives;
    protected:
    private:
};

#endif // SPACESHIP_H
