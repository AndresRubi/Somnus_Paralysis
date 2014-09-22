#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H
#include <iostream>
#include <string>


#include "gamescreen.h"
#include "splashscreen.h"
#include "titlescreen.h"
#include "fadeanimation.h"
//alegro inits
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>



#define ScreenWidth 800
#define ScreenHeight 600

using namespace std;


class ScreenManager
{
    public:

        virtual ~ScreenManager();
        static ScreenManager &GetInstance();

        void AddScreen(GameScreen *screen);

        void Initialize();
        void LoadContent();
        void UnloadContent();
        void Update(ALLEGRO_EVENT ev);
        void Draw(ALLEGRO_DISPLAY *display);




    protected:

    private:
    ScreenManager();
    ScreenManager(ScreenManager const&);
    void operator=(ScreenManager const&);
    string text;



    GameScreen *currentScreen, *newScreen;

    ALLEGRO_BITMAP *transitionImage;

    FadeAnimation transition;
    void Transition();
    bool startTransition;

};

#endif // SCREENMANAGER_H
