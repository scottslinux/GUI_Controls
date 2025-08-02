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





recButton::recButton(int locx,int locy, float scale) : Button({500,500},0.5)
{
    location.x=locx;
    location.y=locy;
    buttonscale=scale;


    if(!resourceguard2) //only load once
    {
        cout<<"loading the rec buttons....\n";
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
bool recButton::update()

{
    //Define the buttons rectange

    Rectangle collisRec={location.x,location.y
        ,recButton_down.width*buttonscale,recButton_down.height*buttonscale};

    


    if (CheckCollisionPointRec(GetMousePosition(),collisRec)
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

//-------------------------------------------------
void recButton::draw()
{


    Texture2D& activetexture=(!value ? recButton_up:recButton_down);
    
    DrawTextureEx(activetexture,{location.x,location.y},0,buttonscale,WHITE);
    
    if(value)
        DrawTextEx(pencil,"rectangle",{location.x+recButton_down.width*buttonscale,location.y},70,0,BLACK);
        else
            DrawTextEx(pencil,"press me...",{location.x+recButton_down.width*buttonscale,location.y},70,0,BLACK);


    

    DrawTextEx(pencil,"A",{location.x+(recButton_down.width*buttonscale)/3,location.y+(recButton_down.height*buttonscale)/7},
        50,0,WHITE);


    return;






}
