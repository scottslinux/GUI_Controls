#include <iostream>
#include <vector>
#include <string>
#include <raylib.h>
#include "Slider.h"

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
        //slide=LoadSound("./resources/slide");

        resourceguard=true; //lock it up!

    }
    //initialize all of the instance specific variables
    location=loc;
    scale=sliderscale;
    min=minim;
    max=maxi;
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
{

    return 0;
}
//**************************************************** */
void Slider::draw()
{
    int offset=200;
    DrawTextureEx(plate_on,location,0,scale,WHITE);

    //DrawRectanglePro(knobrect,{0,0},0,RED);

    DrawTextureEx(knob,{knobrect.x,knobrect.y},0,scale,WHITE);
    DrawCircle(knobrect.x+(knob.width/2*scale),knobrect.y+knob.height/2*scale,70*scale,BLUE);



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