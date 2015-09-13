#ifndef ENEMY_H
#define ENEMY_H
#include "Sprite.h"

class Enemy : public Sprite
{
    public:
        Enemy(int x, int y, unsigned char *enemyImage);
        virtual ~Enemy();
        
        void processMovementPattern();
    protected:
    private:
};

#endif // ENEMY_H
