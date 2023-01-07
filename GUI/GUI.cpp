#include "GUI.h"
#include <iostream>
//constructor make necessary initializations
GUI::GUI()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1300;
	UI.height = 700;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 60;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = BLACK;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.ColorBarColor = BLACK;
	UI.PenWidth = 4;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
	CreateColorBar();
}


//======================================================================================//
//								Input Functions										    //
//======================================================================================//


void GUI::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string GUI::GetSrting() const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if(Key == 8 )	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label+= Key;
		PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType GUI::MapInputToActionType() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
				
			case ITM_SQUR: return DRAW_SQUARE;
			case ITM_CIRC: return DRAW_CIRC;
			case ITM_ELLIP: return DRAW_ELLIP;
			case ITM_HEXA: return DRAW_HEXA;
			case ITM_TRNG: return DRAW_TRA;
			case ITM_SELECT: return SELECT;
			case ITM_FRONT: return FRONT;
			case ITM_BACK: return BACK;
			case ITM_DELETE : return Delete;
			case ITM_FILL_COLOR: return CHNG_FILL_CLR;
			case ITM_BG_COLOR_CHANGE: return CHNG_BK_CLR;
			case ITM_CHNG_DRAW_COLOR: return CHNG_DRAW_CLR;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD: return LOAD;
			case ITM_PLAY:return ACTION_TO_PLAY;
			case ITM_RESIZE:return RESIZE;
			case ITM_EXIT: return EXIT;	
				
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_COLOR)
	{

		if (x >= 0 && x < UI.MenuItemWidth&&y>UI.ToolBarHeight)
		{
			//Check whick Color was clicked
			//==> This assumes that Color images are lined up Vertically <==
			int ClickedItemOrder = (y / 50);
			cout << ClickedItemOrder << "color mode" << endl;
			switch (ClickedItemOrder)
			{
			case ITM_RED: return SET_RED;
			case ITM_GREEN: return SET_GREEN;
			case ITM_BLUE: return SET_BLUE;
			case ITM_PINK: return SET_PINK;
			case ITM_MAROON: return SET_MAROON;
			case ITM_PURPLE: return SET_PURPLE;
			case ITM_BLACK: return SET_BLACK;
			case ITM_WHITE: return SET_WHITE;
			case ITM_ORANGE: return SET_ORANGE;
			case ITM_LIGHT_BLUE: return SET_LIGHT_BLUE;
			case ITM_YELLOW: return SET_YELLOW;
			default: return EMPTY;
			}
		}
		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_PLAY)	//GUI is in PLAY mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			switch (ClickedItemOrder)
			{
			case PLAY_TYPE: return ACTION_PLAY_TYPE;
			case PLAY_FILL: return ACTION_PLAY_FILL;
			case PLAY_TYPEFILL: return ACTION_PLAY_TYPEFILL;
			case PLAY_RESET: return ACTION_PLAY_RESET;
			case PLAY_BACK: return ACTION_TO_DRAW;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}
		//[3] User clicks on the status bar
		return STATUS;
		//return TO_PLAY;	//just for now. This should be updated
	}
	else if (UI.InterfaceMode == MODE_SIZE)
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//If division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItemOrder)
			{
			case ITM_HALF: return HALF;
			case ITM_QUARTER: return QUARTER;
			case ITM_DOUBLE:   return DOUBLE1;
			case ITM_QUADRUPLE: return QUADRUPLE;
			case ITM_BACK2:  return BACK2;
			}
		}
	}

}
//======================================================================================//
//								Output Functions										//
//======================================================================================//

window* GUI::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(UI.MenuItemWidth, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white Square
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_SQUR] = "images\\MenuItems\\square.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\circle.jpg";
	MenuItemImages[ITM_ELLIP] = "images\\MenuItems\\elsipse.jpg";
	MenuItemImages[ITM_HEXA] = "images\\MenuItems\\polign.jpg";
	MenuItemImages[ITM_TRNG] = "images\\MenuItems\\triangle.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Menu_Select.jpg";
	MenuItemImages[ITM_FRONT] = "images\\MenuItems\\Bring_To_Front.jpg";
	MenuItemImages[ITM_BACK] = "images\\MenuItems\\Send_to_Back.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\Delete.jpg";
	MenuItemImages[ITM_BG_COLOR_CHANGE] = "images\\MenuItems\\BGC.jpg";
	MenuItemImages[ITM_CHNG_DRAW_COLOR] = "images\\MenuItems\\DrawColorIcon.jpg";
	MenuItemImages[ITM_FILL_COLOR] = "images\\MenuItems\\FillColor.jpg";
	MenuItemImages[ITM_PLAY] = "images\\MenuItems\\index.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\Save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\load.jpg";
	MenuItemImages[ITM_RESIZE] = "images\\MenuItems\\Resize.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth,0,UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreatePlayToolBar() const
{
	
	ClearToolBarArea();
	UI.InterfaceMode = MODE_PLAY;
	string PlayMenuImages[PLAY_ITM_COUNT];
	PlayMenuImages[PLAY_TYPE] = "images\\MenuItems\\type.jpg";
	PlayMenuImages[PLAY_FILL] = "images\\MenuItems\\fill.jpg";
	PlayMenuImages[PLAY_TYPEFILL] = "images\\MenuItems\\typeandfill.jpg";
	PlayMenuImages[PLAY_RESET] = "images\\MenuItems\\newgame.jpg";
	PlayMenuImages[PLAY_BACK] = "images\\MenuItems\\back.jpg";

	//TODO: Prepare images for each menu item and add it to the list
	//Draw menu item one image at a time
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(PlayMenuImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateColorBar() const
{
	pWind->SetPen(BLACK, 2);
	pWind->SetBrush(UI.ColorBarColor);
	pWind->DrawLine(UI.MenuItemWidth + 2, UI.ToolBarHeight, UI.MenuItemWidth + 2, UI.height - UI.StatusBarHeight);
	string MenuItemImages[COLOR_ITM_COUNT];
	MenuItemImages[ITM_RED] = "images\\MenuItems\\Green.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\Blue.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\Pink.jpg";
	MenuItemImages[ITM_PINK] = "images\\MenuItems\\Nbiti.jpg";
	MenuItemImages[ITM_MAROON] = "images\\MenuItems\\Light_blue.jpg";
	MenuItemImages[ITM_PURPLE] = "images\\MenuItems\\Black.jpg";
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\White.jpg";
	MenuItemImages[ITM_WHITE] = "images\\MenuItems\\Orange.jpg";
	MenuItemImages[ITM_ORANGE] = "images\\MenuItems\\Light_Blue.jpg";
	MenuItemImages[ITM_LIGHT_BLUE] = "images\\MenuItems\\Yellow.jpg";
	MenuItemImages[ITM_YELLOW] = "images\\MenuItems\\Red.jpg";
	//Drawing Color image

	//Draw color item one image at a time
	for (int i = 0; i < COLOR_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], 0, (i * 50) + (UI.ToolBarHeight + 7), UI.MenuItemWidth, 50);

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateResizeToolBar() const
{

	UI.InterfaceMode = MODE_SIZE;

	string MenuItemImages[SIZE_ITM_COUNT];
	MenuItemImages[ITM_HALF] = "images\\MenuItems\\Halfx.jpg";
	MenuItemImages[ITM_QUARTER] = "images\\MenuItems\\QX.jpg";
	MenuItemImages[ITM_DOUBLE] = "images\\MenuItems\\X2.jpg";
	MenuItemImages[ITM_QUADRUPLE] = "images\\MenuItems\\X4.jpg";
	MenuItemImages[ITM_BACK2] = "images\\MenuItems\\BackToDraw.jpg";

	for (int i = 0; i < SIZE_ITM_COUNT; i++)
		for (int i = 0; i < SIZE_ITM_COUNT; i++)
			pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(CORNFLOWERBLUE, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}


///////////////////////////////////////////////////////////////////////////////////////////////

void GUI::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(UI.MenuItemWidth, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);	
	
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::ClearToolBarArea() const
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}

/////////////////////////////////////////////////////////////////////////////////////////////

void GUI::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntDrawColor() const	//get current drwawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int GUI::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}


void GUI::setCrntBKGrandColor(color c) {
	UI.BkGrndColor = c;
}
void GUI::setCrntFillColor(color c) {
	UI.FillColor = c;
}

void GUI::setIsFilled(bool isF) {
	UI.isFilled = isF;
}
void GUI::setCrntDrawColor(color c) {
	UI.DrawColor = c;
}
bool GUI::getIsFilled() const {
	return UI.isFilled;
}////////////////////////////////////////////////////////////////////////////////////////////
void GUI::getPointInsideDrawArea(int& x, int& y)
{
	GetPointClicked(x, y);
	while ((y < UI.StatusBarHeight || y > UI.height - UI.StatusBarHeight))
	{
		PrintMessage("Please, Choose a valid Point");
		GetPointClicked(x, y);
	}
}
//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//


void GUI::DrawCircle(Point P1, int _radius, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawCircle(P1.x, P1.y, _radius, style);


}

void GUI::DrawSquare(Point P1, int length, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width
	
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P1.x +length, P1.y+length, style);
}


void GUI::DrawEllipse(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawEllipse(P1.x, P1.y, P2.x, P2.y, style);


}

void GUI::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo ElpsGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = ElpsGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, ElpsGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (ElpsGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(ElpsGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}



void GUI::DrawHexagon(Point P1, Point P2, GfxInfo HexGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = HexGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, HexGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (HexGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HexGfxInfo.FillClr);
	}
	else
		style = FRAME;

	int lengthx = abs(P1.x - P2.x);
	int lengthy = abs(P1.y - P2.y);

	int arrx[6] = { P1.x,P1.x + lengthx, P1.x + 1.5 * lengthx,P1.x + lengthx,P1.x,P1.x - 0.5 * lengthx };
	int arry[6] = { P1.y,P1.y,P1.y + 0.5 * lengthy,P1.y + lengthy,P1.y + lengthy,P1.y + 0.5 * lengthy };

	pWind->DrawPolygon(arrx, arry, 6, style);

}
//////////////////////////////////////////////////////////////////////////////////////
string GUI::GetString(GUI* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			Label.size() > 0 ? Label.resize(Label.size() - 1) : Label.resize(0);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}
//////////////////////////////////////////////////////////////////////////////////////////
GUI::~GUI()
{
	delete pWind;
}