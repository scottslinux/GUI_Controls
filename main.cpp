#include <iostream>
#include <iostream>
#include <vector>
#include <string>
#include <raylib.h>

#include "Button.h"
#include "Slider.h"


using namespace std;

int main()
{
    InitWindow(1800,1800,"GUI Control Test Bed");
    InitAudioDevice();

    SetTargetFPS(60);

    float winwidth=GetScreenWidth();
    float winheight=GetScreenHeight();
    float scale=1.0;
    float greencolor=0;
    float redcolor=90;
    float bluecolor=120;

    Button pushbutton({420,200},0.15);
    Button push2({400,400},0.25);

    //Slider slide_red({150,900},0.4,5,0,100);
    Slider slide_green({150,900},0.4,5,0,100);
    //Slider slide_blue({150,900},0.4,5,0,100);



    
    //  Create Test Window for the controls to run in

    while(!WindowShouldClose())
    {

        BeginDrawing();



        ClearBackground(Color{redcolor,greencolor,bluecolor,255});

        pushbutton.update();
        push2.update();

        greencolor=slide_green.update();
        //redcolor=slide_red.update();
        //bluecolor=slide_blue.update();

        pushbutton.draw();
        push2.draw();

        //slide_blue.draw();
        //slide_red.draw();
        slide_green.draw();



        EndDrawing();


    }
    CloseAudioDevice();
    return 0;
    
}