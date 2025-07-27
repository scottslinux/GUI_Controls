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


}
//**************************************************** */
void Slider::draw()
{
    int offset=200;
    DrawTextureEx(plate_on,location,0,scale,WHITE);
    DrawTextureEx(knob,{location.x+offset,location.y},0,scale,WHITE);




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