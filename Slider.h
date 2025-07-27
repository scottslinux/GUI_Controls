#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <raylib.h>

class Slider
{
private:

    float scale=1.0;
    float timer=0.0;    //use for animation timing
    Rectangle knobrect;
    int knoboffset=0;
    
    bool timerflag=false;
    bool animationflag=false;

    Vector2 location;

    static Texture2D plate_off;
    static Texture2D knob;
    static Texture2D plate_on;

                            //instance specific



    static Font pencil;
    static Sound slide;

    static bool resourceguard;



   


    public:
    int value=0;   //starting value of slider
    int detents=2; //number of detents along slider
    int min=0;
    int max=10;
    

    Slider(Vector2 location,float scale,int detnts, int min,int max);
    ~Slider();

    int update();
    void draw();
    int getSliderValue();
    void unloadResources();
    bool slidetimer();
    bool sltimer();



};










    




