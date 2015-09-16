#ifndef SPRITE_H
#define SPRITE_H

 

class Sprite
{
    public:
        int width;
        int height;
        int x;
        int y;
        bool movement;
        bool active;
        char instanceOf;
        char direction;
        int movementRate;
        int movementCounter;
        unsigned char* PixelMap;
        int shootingCooldownRate;
        int shootingCooldownTime;
        
        Sprite();
        virtual ~Sprite();
        
        virtual void processMovementPattern();
        virtual void shoot();
        void move();
        void setMovement(char direction);
    protected:
    private:
};

#endif // SPRITE_H
