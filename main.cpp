#include <iostream>
#include <iostream>
#include <vector>
#include <string>
#include <raylib.h>

#include "Button.h"
#include "Slider.h"
#include "recButton.h"
#include "textButton.h"


using namespace std;

int main()
{
    InitWindow(900,900,"GUI Control Test Bed");
    InitAudioDevice();

    SetTargetFPS(60);

    float winwidth=GetScreenWidth();
    float winheight=GetScreenHeight();
    float scale=1.0;
    int greencolor=0;
    int redcolor=90;
    int bluecolor=120;

    Button pushbutton({420,200},0.1);
    Button push2({400,400},0.1);

    recButton newRecButton(200,100,0.3);

    textButton txtButton("PUSH TO EXPLODE",{150,500},20);


    

    Slider slide_red({150,600},0.2,5,0,10);
    Slider slide_green({150,700},0.2,5,0,255);
    Slider slide_blue({150,800},0.2,5,0,10000);



    
    //  Create Test Window for the controls to run in

    while(!WindowShouldClose())
    {

        BeginDrawing();



        //ClearBackground(Color{redcolor,greencolor,bluecolor});
        ClearBackground(BLUE);

        pushbutton.update();
        push2.update();
        txtButton.update();

        newRecButton.update();

        greencolor=slide_green.update();
        redcolor=slide_red.update();
        bluecolor=slide_blue.update();

        pushbutton.draw();
        push2.draw();
        txtButton.draw();

        newRecButton.draw();

        slide_blue.draw();
        slide_red.draw();
        slide_green.draw();



        EndDrawing();


    }
    CloseAudioDevice();
    return 0;
    
}