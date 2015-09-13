#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "Sprite.h"
#include "Projectile.h"
class Spaceship: public Sprite
{
    public:
        Spaceship(int x, unsigned char *enemyImage);
        virtual ~Spaceship();
        
        int Lives;
        int Score;
        void shoot();
        void processMovementPattern();
        void initProjectiles(unsigned char * image);
        Projectile* projectiles[5];
    protected:
    private:
};

#endif // SPACESHIP_H
