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

    Button pushbutton({400,400},0.15);
    Button push2({10,10},0.15);

    Slider slide_me({100,900},0.6,5,0,100);

    
    //  Create Test Window for the controls to run in

    while(!WindowShouldClose())
    {

        BeginDrawing();



        ClearBackground(Color{92,149,130,255});

        pushbutton.update();
        push2.update();
        slide_me.update();

        pushbutton.draw();
        push2.draw();

        slide_me.draw();



        EndDrawing();


    }
    CloseAudioDevice();
    return 0;
    
}