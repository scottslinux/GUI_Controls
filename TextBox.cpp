#include <iostream>
#include <vector>
#include <string>
#include <raylib.h>

#include "TextBox.h"


Font TextBox::boxfont{0};
int TextBox::resourcecounter3=0;
bool TextBox::resourceguard3=false;

//---------------------------------------------------------
TextBox::TextBox(Vector2 dim, Vector2 loc): size{dim},locationxy{loc}
{
    resourcecounter3++; //count for each attempt to load
    if (!resourceguard3)
    {
        
        boxfont=LoadFontEx("./resources/Inter.ttf",50,0,0);
        resourceguard3=true;
        
        if (boxfont.texture.id !=0)
            cout<<" Font loaded successfully for textbox...\n";

        
    }

    boxstring="*************";
    Vector2 messagesize=MeasureTextEx(boxfont,boxstring.c_str(),50,0);
    size={messagesize.x*1.1,messagesize.y*1.25};




}
//---------------------------------------------------------

TextBox::~TextBox()
{
    resourcecounter3--;

    if (resourcecounter3==0)
    {
        UnloadFont(boxfont);
        boxfont={0};
    
    }




}
//---------------------------------------------------------
void TextBox::update()
{
    


    return;
}
//---------------------------------------------------------
void TextBox::draw()
{
    DrawRectangle(locationxy.x,locationxy.y,size.x,size.y,background);
    DrawTextEx(boxfont,boxstring.c_str(),{locationxy.x+5,locationxy.y+5},50,0,fntcolor);

    return;
}
//---------------------------------------------------------
void TextBox::print(string content)
{
    boxstring=content;

    return;
}
//-----------------------------------------------------------
void TextBox::print(int content)
{
    boxstring=to_string(content);

    return;
}
//-----------------------------------------------------------
void TextBox::print(float content)
{
    char buffer[20];    //display string of float with 2 decimal points
    snprintf(buffer,sizeof(buffer),"%.2f",content);

    boxstring=to_string(content);

    return;
}
//-----------------------------------------------------------
