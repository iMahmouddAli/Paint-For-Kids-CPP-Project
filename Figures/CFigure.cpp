#include "CFigure.h"
#include <ostream>
#include <iostream>
CFigure::CFigure()
{}
CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
    ID = 0;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

void CFigure::SetID(int id)
{
	ID = id;
}

//Gets the figure ID

int CFigure::GetID() const
{
	return ID;
}

void CFigure::Load(ifstream& File) {};
//void CFigure::Save(ofstream& OutFile){};

color CFigure::StringToColor(string s) {
    if (s == "GREEN")
        return GREEN;
    if (s == "BLUE")
        return BLUE;
    if (s == "WHITE")
        return WHITE;
    if (s == "PINK")
        return PINK;
    if (s == "YELLOW")
        return YELLOW;
    if (s == "ORANGE")
        return ORANGE;
    if (s == "MAROON")
        return MAROON;
    if (s == "PURPLE")
        return PURPLE;
    if (s == "TURQUOISE")
        return TURQUOISE;
    if (s == "SKYBLUE")
        return SKYBLUE;
    if (s == "LIGHTBLUE")
        return LIGHTBLUE;
    if (s == "IVORY")
        return IVORY;
    return BLACK;
}

string CFigure::ColorToString(color c)
{
    if ((c.ucBlue == BLACK.ucBlue) && (c.ucGreen == BLACK.ucGreen) && (c.ucRed == BLACK.ucRed))
        return "BLACK";
    if ((c.ucBlue == PINK.ucBlue) && (c.ucGreen == PINK.ucGreen) && (c.ucRed == PINK.ucRed))
        return "PINK";
    if ((c.ucBlue == LIGHTBLUE.ucBlue) && (c.ucGreen == LIGHTBLUE.ucGreen) && (c.ucRed == LIGHTBLUE.ucRed))
        return "LIGHTBLUE";
    if ((c.ucBlue == MAROON.ucBlue) && (c.ucGreen == MAROON.ucGreen) && (c.ucRed == MAROON.ucRed))
        return "MAROON";
    if ((c.ucBlue == ORANGE.ucBlue) && (c.ucGreen == ORANGE.ucGreen) && (c.ucRed == ORANGE.ucRed))
        return "ORANGE";
    if ((c.ucBlue == BLUE.ucBlue) && (c.ucGreen == BLUE.ucGreen) && (c.ucRed == BLUE.ucRed))
        return "BLUE";
    if ((c.ucBlue == WHITE.ucBlue) && (c.ucGreen == WHITE.ucGreen) && (c.ucRed == WHITE.ucRed))
        return "WHITE";
    if ((c.ucBlue == RED.ucBlue) && (c.ucGreen == RED.ucGreen) && (c.ucRed == RED.ucRed))
        return "RED";
    if ((c.ucBlue == YELLOW.ucBlue) && (c.ucGreen == YELLOW.ucGreen) && (c.ucRed == YELLOW.ucRed))
        return "YELLOW";
    if ((c.ucBlue == GREEN.ucBlue) && (c.ucGreen == GREEN.ucGreen) && (c.ucRed == GREEN.ucRed))
        return "GREEN";
    if ((c.ucBlue == LIGHTGOLDENRODYELLOW.ucBlue) && (c.ucGreen == LIGHTGOLDENRODYELLOW.ucGreen) && (c.ucRed == LIGHTGOLDENRODYELLOW.ucRed))
        return "LIGHTGOLDENRODYELLOW";
    if ((c.ucBlue == MAGENTA.ucBlue) && (c.ucGreen == MAGENTA.ucGreen) && (c.ucRed == MAGENTA.ucRed))
        return "MAGENTA";
    if ((c.ucBlue == TURQUOISE.ucBlue) && (c.ucGreen == TURQUOISE.ucGreen) && (c.ucRed == TURQUOISE.ucRed))
        return "TURQUOISE";
    if ((c.ucBlue == SKYBLUE.ucBlue) && (c.ucGreen == SKYBLUE.ucGreen) && (c.ucRed == SKYBLUE.ucRed))
        return "SKYBLUE";
    if ((c.ucBlue == LIGHTSTEELBLUE.ucBlue) && (c.ucGreen == LIGHTSTEELBLUE.ucGreen) && (c.ucRed == LIGHTSTEELBLUE.ucRed))
        return "LIGHTSTEELBLUE";
    if ((c.ucBlue == IVORY.ucBlue) && (c.ucGreen == IVORY.ucGreen) && (c.ucRed == IVORY.ucRed))
        return"IVORY";
    return "NO-FILL";

}

