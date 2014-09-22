#ifndef FADEANIMATION_H
#define FADEANIMATION_H
#include "animation.h"

class FadeAnimation : public Animation
{
    public:
        FadeAnimation();
        virtual ~FadeAnimation();

        void LoadContent(ALLEGRO_BITMAP *image,string text,float position[2]);
        void UnloadContent();
        void Update(InputManager input);
        void Draw(ALLEGRO_DISPLAY *display);
        void SetAlpha(int value);
    protected:


    private:
        float fadeSpeed;
        bool increase;

};

#endif // FADEANIMATION_H
