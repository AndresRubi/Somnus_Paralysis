#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <allegro5/allegro.h>
#include <allegro5/keyboard.h>
#include <vector>
#include <string>
using namespace std;


class InputManager
{
    public:
        InputManager();
        virtual ~InputManager();
        bool IsKeyPressed(ALLEGRO_EVENT ev, int key);
        bool IsKeyPressed(ALLEGRO_EVENT ev, vector<int>keys);

        bool IsKeyRelease(ALLEGRO_EVENT ev, int key);
        bool IsKeyRelease(ALLEGRO_EVENT ev, vector<int>keys);

    protected:


    private:
    ALLEGRO_KEYBOARD_STATE keyState;

};

#endif // INPUTMANAGER_H
