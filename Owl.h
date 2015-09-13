#ifndef OWL_H
#define OWL_H
#include "Sprite.h"
#include "Projectile.h"

class Owl : public Sprite
{
    public:
        Owl(int x, int y, unsigned char *enemyImage);
        virtual ~Owl();
        
        int goalX;
        int goalY;
        bool axisToggle;
        Projectile* projectile;
        
        void processMovementPattern();
        void initProjectile(unsigned char * image);
        void shoot();
    protected:
    private:
};

#endif // OWL_H
