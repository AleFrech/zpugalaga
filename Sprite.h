#ifndef SPRITE_H
#define SPRITE_H


class Sprite
{
    public:
        int width;
        int height;
        int x;
        int y;
        Sprite();
        virtual ~Sprite();

        unsigned char* PixelMap;
    protected:
    private:
};

#endif // SPRITE_H
