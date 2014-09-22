#include "fadeanimation.h"

FadeAnimation::FadeAnimation()
{
    //ctor
}

FadeAnimation::~FadeAnimation()
{
    //dtor
}

void FadeAnimation::LoadContent(ALLEGRO_BITMAP *image,string text,float position[2])
{
    Animation::LoadContent(image,text,position);
    fadeSpeed=5.0f;
    increase=false;

}
void FadeAnimation::UnloadContent()
{
    Animation::UnloadContent();
    fadeSpeed=NULL;
}
void FadeAnimation::Update(InputManager input)
{
    if(isActive)
    {
        if(!increase)
        {
            alpha-=fadeSpeed;
        }
        else
        {
            alpha += fadeSpeed;
        }
        if(alpha <=0)
        {
            alpha=0;
            increase=true;
        }
        else if(alpha>=255)
        {
            alpha = 255;
            increase=false;
        }
    }
    else
    {
        alpha = 255;
    }
}

void FadeAnimation::Draw(ALLEGRO_DISPLAY *display)
{
    Animation::Draw(display);
}

void FadeAnimation::SetAlpha(int value)
{
    alpha=value;
    if(alpha=0)
    {
        increase=true;
    }
    else if(alpha == 255)
        increase = false;
}

