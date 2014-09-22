#ifndef ANIMATION_H
#define ANIMATION_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <string>
#include "inputmanager.h"
using namespace std;

class Animation
{
    public:
        Animation();
        virtual ~Animation();

        virtual void LoadContent(ALLEGRO_BITMAP *image,string text,float position[2]);
        virtual void UnloadContent();
        virtual void Update(InputManager input);
        void Draw(ALLEGRO_DISPLAY *display);

        virtual void SetAlpha(float value);
        float GetAlpha();

        void SetIsActive(bool value);
        bool GetIsActive();

    protected:
        ALLEGRO_BITMAP *image, *sourceRect;
        string text;
        ALLEGRO_FONT *font;
        float position[2];
        float alpha;
        bool isActive;

    private:


};

#endif // ANIMATION_H
