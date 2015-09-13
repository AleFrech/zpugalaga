#ifndef OWL_H
#define OWL_H
#include "Sprite.h"

class Owl : public Sprite
{
    public:
        Owl(int x, int y, unsigned char *enemyImage);
        virtual ~Owl();
        
        int goalX;
        int goalY;
        bool axisToggle;
        
        void processMovementPattern();
    protected:
    private:
};

#endif // OWL_H
