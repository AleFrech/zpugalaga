#ifndef SPRITE_H
#define SPRITE_H


class Sprite
{
    public:
        const static int WIDTH = 64;
        const static int HEIGHT = 64;
        int x;
        int y;
        Sprite();
        virtual ~Sprite();

        unsigned char PixelMap[WIDTH][HEIGHT];
    protected:
    private:
};

#endif // SPRITE_H
