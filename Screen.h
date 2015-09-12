#ifndef SCREEN_H
#define SCREEN_H


class Screen
{
    public:
        const static int WIDTH = 960;
        const static int HEIGHT = 960;
        Screen();
        virtual ~Screen();

        void render();
        void handleInput();

        unsigned char ViewPort[WIDTH][HEIGHT];
    protected:
    private:
};

#endif // SCREEN_H
