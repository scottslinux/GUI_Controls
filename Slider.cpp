#include <iostream>
#include <vector>
#include <string>
#include <raylib.h>
#include "Slider.h"

using namespace std;

Texture2D Slider::plate_on{0};
Texture2D Slider::plate_off{0};
Texture2D Slider::knob{0};


Sound Slider::slide{0};
Font Slider::pencil{0};
bool Slider::resourceguard{false};



//**************************************************** */

Slider::Slider(Vector2 loc, float sliderscale,int detnts,int minim,int maxi)
{
    if(!resourceguard)  //only load resources once for class
    {
        plate_on=LoadTexture("./resources/plate_on.png");
        plate_off=LoadTexture("./resources/plate_off.png");
        knob=LoadTexture("./resources/knob.png");
        pencil=LoadFontEx("./resources/Inter.ttf",100,0,0);
        //slide=LoadSound("./resources/slide");

        resourceguard=true; //lock it up!

    }
    //initialize all of the instance specific variables
    location=loc;
    scale=sliderscale;
    min=minim;
    max=maxi+1;
    detents=detnts;

    knobrect=Rectangle{location.x,location.y,knob.width*scale,
            knob.height*scale};


}

//**************************************************** */

Slider::~Slider()
{
    
    unloadResources();



}

//**************************************************** */
void Slider::unloadResources()
{
    if (resourceguard)
    {
        UnloadTexture (plate_off);
        UnloadTexture (plate_on);
        UnloadTexture (knob);
        UnloadSound (slide);
        UnloadFont (pencil);
    }
    

    return;
}
//**************************************************** */
int Slider::update()
{   //the 0.8 is to shrink the rectangle around the knob image
    //knobrect={location.x,location.y,knob.width*scale*.8,knob.height*scale*.8};

    if(CheckCollisionPointRec(GetMousePosition(),knobrect)&& (IsMouseButtonDown(MOUSE_BUTTON_LEFT)))
    {
        if(GetMousePosition().x-40>=location.x && GetMousePosition().x-40<=location.x+plate_off.width*scale*.8)
        {
            knobrect.x=GetMousePosition().x-40;

            float percentage=(knobrect.x-location.x)/((plate_off.width)*scale*0.8);
            //percent= amount knob has traveled / total potential travel 

            cout<<"percentage= "<<percentage<<endl;

            value=max*percentage;




            

        }
    }





    return value;
}
//**************************************************** */
void Slider::draw()
{
    int offset=200;
    DrawTextureEx(plate_on,location,0,scale,WHITE);

    //DrawRectangleLines(knobrect.x,knobrect.y,knob.width*scale*.8,knob.height*scale*.8,GREEN);

    DrawTextureEx(knob,{knobrect.x,knobrect.y},0,scale,WHITE);

    char buffer[50];
            snprintf(buffer,sizeof(buffer),"Value: %d",value);

            DrawTextEx(pencil,buffer,{location.x,location.y+plate_off.height*scale+50},50,0,BLACK);




    return;
}
//**************************************************** */
//   Generates a delay of given duration (seconds)
//   for timing animations

bool Slider::sltimer()
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