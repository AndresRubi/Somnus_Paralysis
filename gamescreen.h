#ifndef GAMESCREEN_H
#define GAMESCREEN_H
#include <allegro5/allegro.h>
#include "inputmanager.h"


class GameScreen
{
    public:
        GameScreen();
        virtual ~GameScreen();

        virtual void LoadContent();
        virtual void Unload();
        virtual void Update(ALLEGRO_EVENT ev);
        virtual void Draw(ALLEGRO_DISPLAY *display);
        InputManager GetInput();

    protected:
        InputManager input;
        vector <vector<string> >contents;
        vector <vector<string> >attributes;
    private:


};

#endif // GAMESCREEN_H
