#include <iostream>
#include <iostream>
#include <vector>
#include <string>
#include <raylib.h>

#include "Button.h"
#include "Slider.h"
#include "recButton.h"
#include "textButton.h"
#include "TextBox.h"
#include "InputBox.h"


using namespace std;

int main()
{
    InitWindow(2000,2000,"GUI Control Test Bed");
    InitAudioDevice();

    SetTargetFPS(60);

    float winwidth=GetScreenWidth();
    float winheight=GetScreenHeight();
    float scale=1.0;
    int greencolor=0;
    int redcolor=90;
    int bluecolor=120;

    float neg=1.0;


    // ⁡⁣⁢⁣​‌‍‌𝗖𝗿𝗲𝗮𝘁𝗶𝗻𝗴 𝗢𝗯𝗷𝗲𝗰𝘁𝘀 𝗳𝗿𝗼𝗺 𝘁𝗵𝗲 𝘁𝗼𝗼𝗹𝗯𝗼𝘅​⁡
    
    Button pushbutton({420,200},0.2);
    Button push2({400,400},0.2);

    recButton newRecButton(200,100,0.3);

    textButton txtButton("Rectangle Button",{800,1200},50);
    TextBox mybox(70,10,{800,800});  //font, digits, location


    Slider slide_red({150,900},0.5,5,0,10);
    Slider slide_green({150,1200},0.5,5,0,255);
    Slider slide_blue({150,1500},0.5,5,0,1000000);

    InputBox msgbox(20,5,60,{1200,1700});
    




    
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

        msgbox.Update();

        
        mybox.update();

        greencolor=slide_green.update();
        redcolor=slide_red.update();
        bluecolor=slide_blue.update();

        float result=(225);
        cout<<"*****Result: "<<result<<endl;

        mybox.print(12345*greencolor*redcolor);

        pushbutton.draw();
        push2.draw();
        txtButton.draw();
        mybox.draw();

        newRecButton.draw();

        slide_blue.draw();
        slide_red.draw();
        slide_green.draw();

        msgbox.Draw();




        EndDrawing();


    }
    CloseAudioDevice();
    return 0;
    
}