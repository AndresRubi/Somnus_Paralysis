#include "inputmanager.h"

InputManager::InputManager()
{
    //ctor
}

InputManager::~InputManager()
{
    //dtor
}

bool InputManager::IsKeyPressed(ALLEGRO_EVENT ev, int key)
{
    if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
    {
        if(ev.keyboard.keycode == key)
        return true;
    }
    return false;
}

bool InputManager::IsKeyPressed(ALLEGRO_EVENT ev, vector<int>keys)
{
    if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
    {
        for(int i=0;i < keys.size(); i++)
        {
            if(ev.keyboard.keycode == keys [i])
            return true;
        }
    }
    return false;
}

bool InputManager::IsKeyRelease(ALLEGRO_EVENT ev, int key)
{
    if(ev.type == ALLEGRO_EVENT_KEY_UP)
    {
        if(ev.keyboard.keycode == key)
        return true;
    }
    return false;
}

bool InputManager::IsKeyRelease(ALLEGRO_EVENT ev, vector<int>keys)
{
    if(ev.type == ALLEGRO_EVENT_KEY_UP)
    {
        for(int i=0;i < keys.size(); i++)
        {
            if(ev.keyboard.keycode ==keys [i])
            return true;
        }
    }
    return false;
}
