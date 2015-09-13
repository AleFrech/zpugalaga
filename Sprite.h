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
        char instanceOf;
        char direction;
        int movementRate;
        int movementCounter;
        unsigned char* PixelMap;
        
        Sprite();
        virtual ~Sprite();
        
        virtual void processMovementPattern();
        void move();
        void setMovement(char direction);
    protected:
    private:
};

#endif // SPRITE_H
