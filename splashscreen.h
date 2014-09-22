#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include "filemanager.h"
#include "gamescreen.h"
#include "inputmanager.h"
#include "screenmanager.h"
#include "fadeanimation.h"

#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class SplashScreen:public GameScreen
{
    public:
        SplashScreen();
        virtual ~SplashScreen();

        void LoadContent();
        void Unload();
        void Update(ALLEGRO_EVENT ev);
        void Draw(ALLEGRO_DISPLAY *display);

    protected:


    private:
    ALLEGRO_FONT *font;
    FileManager fileManager;
    vector <ALLEGRO_BITMAP*> images;
    vector <FadeAnimation*> fade;
    float imageNumber;

};

#endif // SPLASHSCREEN_H
