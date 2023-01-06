#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contais some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_SQUARE,	//Draw a Square
	DRAW_CIRC,		//Draw an Circle
	DRAW_ELLIP,		//Draw an Ellipse
	DRAW_HEXA ,		//Draw Hexagon
	DRAW_TRA,		//Draw Triangle
	SELECT,		//SELECT
	FRONT,   // BRING TO FRONT
	BACK,   //SEND TO BACK
	Delete,  // Delete Figures
	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR,	//Change the filling color
	CHNG_BK_CLR,	//Change background color
	DEL,			//Delete a figure(s)
	MOVE,			//Move a figure(s)
	RESIZE,			//Resize a figure(s)
	ROTATE,			//Rotate a figure(s)
	SEND_BACK,		//Send a figure to the back of all figures
	BRNG_FRNT,		//Bring a figure to the front of all figures
	SAVE,			//Save the whole graph to a file
	LOAD,			//Load a graph from a file
	EXIT,			//Exit the application

	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar

	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,			//Switch interface to Play mode

	SET_RED,		//pick red color
	SET_GREEN,		//pick green color
	SET_BLUE,		//pick blue color
	SET_PINK,		//pick pink color
	SET_MAROON,		//pick maroon color
	SET_PURPLE,		//pick purple color
	SET_BLACK,		// Pick Black color
	SET_WHITE,		//Pick Gray color
	SET_ORANGE,		//Pick navy color
	SET_LIGHT_BLUE,	//Pick LightBlue Color
	SET_YELLOW,
	///TODO: Add more action types (if needed)
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif