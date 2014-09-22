#include "splashscreen.h"

SplashScreen::SplashScreen()
{
    //ctor
}

SplashScreen::~SplashScreen()
{
    //dtor
}

void SplashScreen::LoadContent()
{
    font=al_load_font("blade.ttf",30,NULL);
    fileManager.LoadContent("Load/splash.cme",attributes,contents);


    for(int i=0; i<attributes.size(); i++)
    {
        for(int j=0; j<attributes[i].size(); j++)
        {
            if(attributes[i][j] == "Image")
            {

                float position[2] ={0,0};
                images.push_back(al_load_bitmap(contents[i][j].c_str()));
                fade.push_back(new FadeAnimation);
                fade[fade.size()-1]->LoadContent(images[fade.size()-1],"", position);
                fade[fade.size()-1]->SetIsActive(true);


            }


        }
    }


}
void SplashScreen::Unload()
{
    al_destroy_font(font);
    for(int i=0; i<fade.size();i++)
    delete fade[i];

}
void SplashScreen::Update(ALLEGRO_EVENT ev)
{
    if(fade[imageNumber]->GetAlpha() == 0)
    {
        imageNumber++;
    }
    if(imageNumber>= fade.size()-1|| input.IsKeyPressed(ev,ALLEGRO_KEY_ENTER))
        ScreenManager::GetInstance().AddScreen(new TitleScreen);


    fade[imageNumber]->Update(input);
}
void SplashScreen::Draw(ALLEGRO_DISPLAY *display)
{
    //al_draw_text(font, al_map_rgb(0,0,255),100,100, NULL,"Splash Screen");
    fade[imageNumber]->Draw(display);
}
