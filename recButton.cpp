#include <raylib.h>
#include <iostream>
#include <vector>
#include <string>

#include "recButton.h"

using namespace std;

Texture2D recButton::recButton_up{0};
Texture2D recButton::recButton_down{0};

int recButton::resourcecounter2{0};     //2 so you don't shadow the resource counter in base class
bool recButton::resourceguard2{false};





recButton::recButton() : Button({500,500},0.5)
{
    if(!resourceguard) //only load once
    {
        recButton_up=LoadTexture("./resources/RectangleButton_up.png");
            
        recButton_down=LoadTexture("./resources/RectangleButton_down.png");

        resourceguard=true;
        


    }

    
    resourcecounter2++;

    return;
}
//-------------------------------------------------
recButton::~recButton()
{
    resourcecounter2--;

    if (resourcecounter2==0)
    {
        if (recButton_up.id!=0)
        {
            UnloadTexture(recButton_up);
            recButton_up=Texture2D{0};
        }
        if (recButton_down.id!=0)
        {
            UnloadTexture(recButton_down);
            recButton_down=Texture2D{0};
        }
        


    }






}
//-------------------------------------------------
void recButton::draw()
{
    Texture2D& activetexture=(!value ? recButton_up:recButton_down);
    
    DrawTextureEx(activetexture,{location.x,location.y},0,buttonscale,WHITE);
    
    if(value)
        DrawTextEx(pencil,"rectangle",{location.x+button_off.width*buttonscale,location.y},100,0,BLACK);
        else
            DrawTextEx(pencil,"press me...",{location.x+button_off.width*buttonscale,location.y},100,0,BLACK);

Vector2 center;
    center.x=button_off.width/2+location.x;
    center.y=button_off.height/2+location.y;


    //DrawRectangleLines(location.x,location.y,
     //       buttonscale*button_off.width,buttonscale*button_off.height,BLUE);


    return;






}
//-------------------------------------------------
void recButton::uniqueFunction()
{
    cout<<"in the unique function....\n";


    return;
}
