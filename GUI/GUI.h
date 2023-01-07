#ifndef GUI_H
#define GUI_H

#include "..\DEFS.h"
#include "UI_Info.h" 
#include "..\CMUgraphicsLib\CMUgraphics.h"


//This class is responsible for Grphical User Interface handling
//All user input and program outputs MUST be done through this class
//No other class is allowed to perform direct i/o
class GUI	
{
public:	
	window* pWind;	//Pointer to the Graphics Window
public:
	GUI();	
	~GUI();	
	window* CreateWind(int, int, int , int) const; //creates the application window

	/////////// Input Functoinality  /////////////////
	void GetPointClicked(int &x, int &y) const;//Get coordinate where user clicks
	string GetSrting() const ;	 //Returns a string entered by the user
	ActionType MapInputToActionType() const; //Read the user click and map to an action
	void getPointInsideDrawArea(int& x, int& y); // get point inside draw area

	/////////// Output Functoinality  ////////////////
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	void CreateColorBar() const; //create Color Bar
	void CreateResizeToolBar() const;
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	void GUI::ClearToolBarArea() const; //Clear Tool bar area
	// -- Figures Drawing functions
	void DrawSquare(Point P1, int length, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a Square
	void DrawCircle(Point P1, int _radius, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a Circle
	void DrawEllipse(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const;  //Draw an Ellipse
	void DrawTriangle(Point P1, Point P2, Point P3, GfxInfo ElpsGfxInfo, bool selected) const; 
	void DrawHexagon(Point P1, Point P2, GfxInfo HexGfxInfo, bool selected) const;


	
	///TODO: Make similar functions for drawing all other figures.
	
	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width
	void setCrntBKGrandColor(color c);
	void GUI::setCrntFillColor(color c);
	void GUI::setIsFilled(bool isF);
	void GUI::setCrntDrawColor(color c);
	bool GUI::getIsFilled() const;


	//exit function 
	string GUI::GetString(GUI* pO) const;
};


#endif