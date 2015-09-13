#ifndef SCREEN_H
#define SCREEN_H


class Screen
{
    public:
        const static int WIDTH = 160;
        const static int HEIGHT = 120;
        Screen();
        virtual ~Screen();

        void render();
        void handleInput();

        unsigned char ViewPort[WIDTH][HEIGHT];
    protected:
    private:
};

#endif // SCREEN_H
