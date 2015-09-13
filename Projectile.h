#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "Sprite.h"


class Projectile : public Sprite
{
    public:
        Projectile(int x, int y, unsigned char *image);
        virtual ~Projectile();
    protected:
    private:
};

#endif // PROJECTILE_H
