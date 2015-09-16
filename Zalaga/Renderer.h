#ifndef RENDERER_H
#define RENDERER_H
#include "VGA.h"
#include "Sprite.h"

class Renderer
{
    public:
        Renderer();
        virtual ~Renderer();
        
        
        unsigned char* enemyImage;
        
        void render(Sprite* sprite);
        void clear();
    protected:
    private:
};

#endif // RENDERER_H
