#include "Button.h"

#include <iostream>
#include <vector>
#include <string>
#include <raylib.h>

Texture2D Button::button_off{0};
Texture2D Button::button_on{0};

Font Button::pencil{0};
Sound Button::click{0};
bool Button::resourceguard{false};

using namespace std;

//**************************************************** */

Button::Button(Vector2 loc, float scale)
{
    if (!resourceguard) //only once
    {
        cout<<"Loading the resources.....\n";

        button_off=LoadTexture("./resources/button_up.png");
        button_on=LoadTexture("./resources/button_pressed.png");
        pencil=LoadFontEx("./resources/Pencil.ttf",50,0,0);
        click=LoadSound("./resources/click.wav");

        resourceguard=true;
    }
    location=loc;
    buttonscale=scale;



    std::cout<<"in the constructor...\n";
    std::cout<<"location: "<<location.x<<","<<location.y<<std::endl;

    return;
}
//----------------------------------------------
Button::~Button()
{
    if(resourceguard)
    {
        cout<<"unloading the resources....\n";
        unloadResources();
        resourceguard=false;
    }

}
//-----------------------------------------------
bool Button::update()
{
    //find the center of the scaled button for clicking purposes
    Vector2 center;
    center.x=(buttonscale*button_off.width)/2+location.x;
    center.y=(buttonscale*button_off.width)/2+location.y;


    if (CheckCollisionPointCircle(GetMousePosition(),center,100)
            && IsMouseButtonDown(MOUSE_BUTTON_LEFT)&& !timerflag)
                {
                    value=true;
                    if(!IsSoundPlaying(click))
                        PlaySound(click);
                    timerflag=true;

                }
                    else    
                    if (!timerflag)
                    {
                        value=false;
                    }

    if (timerflag)
            clicktimer();

    return value;
}
//-----------------------------------------------
void Button::draw()
{
    Texture2D& activetexture=(!value ? button_off:button_on);
    
    DrawTextureEx(activetexture,{location.x,location.y},0,buttonscale,WHITE);
    
    if(value)
        DrawTextEx(pencil,"PRESSED!!!",{location.x+button_off.width*buttonscale,location.y},100,0,BLACK);
        else
            DrawTextEx(pencil,"press me...",{location.x+button_off.width*buttonscale,location.y},100,0,BLACK);

Vector2 center;
    center.x=button_off.width/2+location.x;
    center.y=button_off.height/2+location.y;


    //DrawRectangleLines(location.x,location.y,
     //       buttonscale*button_off.width,buttonscale*button_off.height,BLUE);


    return;
}
//-----------------------------------------------
bool Button::getbuttonval()
{


return true;
}
//-----------------------------------------------
void Button::unloadResources()
{

    UnloadTexture(button_off);
    UnloadTexture(button_on);
    UnloadFont(pencil);






}
//-----------------------------------------------
bool Button::clicktimer()
{

    if(timer<0.4)
    {
            timer+=GetFrameTime();

    }
        else
            {
                timer=0;
                timerflag=false;
            }

return false;


}