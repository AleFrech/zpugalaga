#ifndef RENDERER_H
#define RENDERER_H
#include "Screen.h"
#include "VGA.h"


class Renderer
{
    public:
        Renderer(Screen* screen);
        virtual ~Renderer();
    protected:
    private:
        Screen* screen;
};

#endif // RENDERER_H
