#include "screenmanager.h"



ScreenManager &ScreenManager::GetInstance()
{
    static ScreenManager instance;
    return instance;
}

ScreenManager::ScreenManager()
{
    //ctor
}

ScreenManager::~ScreenManager()
{
    //dtor
}


void ScreenManager::AddScreen(GameScreen *screen)
{
    transition.SetAlpha(0);
    startTransition=true;
    newScreen=screen;
    transition.SetIsActive(true);

}


void ScreenManager::Initialize()
{
    currentScreen=new SplashScreen();
}



void ScreenManager::LoadContent()
{
    float position[2]={0,0};
    currentScreen->LoadContent();
    transitionImage=al_load_bitmap("transitionImage.png");
    transition.LoadContent(transitionImage,"",position);
    startTransition=false;
}

void ScreenManager::UnloadContent()
{
    al_destroy_bitmap(transitionImage);
    currentScreen->Unload();
    transition.UnloadContent();
}
void ScreenManager::Update(ALLEGRO_EVENT ev)
{
    if(!startTransition)
    {
        currentScreen->Update(ev);
    }
    else
    {
    Transition();
    }

}

void ScreenManager::Draw(ALLEGRO_DISPLAY *display)
{

    currentScreen->Draw(display);
    if(startTransition)
    {
        transition.Draw(display);
    }
}

void ScreenManager::Transition()
{
    transition.Update(currentScreen->GetInput());
    if(transition.GetAlpha()>=255)
    {
        transition.SetAlpha(255);

        currentScreen->Unload();
        delete currentScreen;
        currentScreen= newScreen;
        currentScreen->LoadContent();

        al_rest(1.0);
    }
    else if(transition.GetAlpha() <= 0)
    {
        startTransition = false;
        transition.SetIsActive(false);
    }
}
