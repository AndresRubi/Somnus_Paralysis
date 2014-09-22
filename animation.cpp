#include "animation.h"

Animation::Animation()
{
    //ctor
}

Animation::~Animation()
{
    //dtor
}

void Animation::LoadContent(ALLEGRO_BITMAP *image,string text,float position[2])
{
    this->image=image;
    this->text=text;
    this->position[0]=position[0];
    this->position[1]=position[1];

    alpha =255;
    font = al_load_font("blade.ttf",30,NULL);
    sourceRect=image;
    isActive=false;

}

void Animation::UnloadContent()
{
//    al_destroy_bitmap(image);
//    al_destroy_bitmap(sourceRect);
    al_destroy_font(font);
    alpha=NULL;
    position[0]=position[1]= NULL;
}
void Animation::Update(InputManager input)
{

}

void Animation::Draw(ALLEGRO_DISPLAY *display)
{

//    al_set_blender(ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA);

    if(sourceRect != NULL)
        al_draw_tinted_bitmap(sourceRect,al_map_rgba(255,255,255,alpha),
            position[0], position[1], NULL);
    else if(image != NULL)
        al_draw_tinted_bitmap(image,al_map_rgba(0,0,0,alpha),
            position[0], position[1], NULL);

    if(text != "")
        al_draw_text(font, al_map_rgba(255,0,0,alpha),position[0],
            position[1], NULL, text.c_str());
}

void Animation::SetAlpha(float alpha)
{
    this->alpha=alpha;
}

float Animation::GetAlpha()
{
    return alpha;
}

void Animation::SetIsActive(bool value)
{
    isActive=value;
}

bool Animation::GetIsActive()
{
    return isActive;
}
