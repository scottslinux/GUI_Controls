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
    //SetWindowPosition(1800,1800);

    float winwidth=GetScreenWidth();
    float winheight=GetScreenHeight();
    float scale=1.0;

    Button pushbutton({400,400},0.15);
    Button push2({10,10},0.15);

    Slider slide_me({100,900},0.4,5,0,100);

    
    //  Create Test Window for the controls to run in

    while(!WindowShouldClose())
    {

        BeginDrawing();



        ClearBackground(LIGHTGRAY);

        pushbutton.update();
        push2.update();

        pushbutton.draw();
        push2.draw();

        slide_me.draw();

     


        EndDrawing();


    }
    
    return 0;
    
}