#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include "animation.h"
#include "fadeanimation.h"
#include "filemanager.h"
#include "sstream"
#include "inputmanager.h"

#include <allegro5/allegro.h>
#include <vector>
#include <string>

using namespace std;

class MenuManager
{
    public:
        MenuManager();
        virtual ~MenuManager();

        void LoadContent(string id);
        void UnloadContent();
        void Update(ALLEGRO_EVENT ev,InputManager &input);
        void Draw(ALLEGRO_DISPLAY *display);

    protected:


    private:
    vector <vector<string> >contents;
    vector <vector<string> >attributes;
    vector<string> animationTypes;

    FileManager fileManager;

    vector <string>menuItems;
    vector <ALLEGRO_BITMAP*> menuImages;

    vector< vector<Animation*> >animation;
    int itemNumber;

    float position[2];
    int axis;
    string align;
    ALLEGRO_FONT *font;
    vector<Animation*> tempAnimation;
    void SetMenuItems();
    void SetAnimations();

};

#endif // MENUMANAGER_H
