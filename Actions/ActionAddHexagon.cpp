#include "ActionAddHexagon.h"
#include "..\Figures\CHexagon.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionAddHexagon::ActionAddHexagon(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionAddHexagon::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo HexGfxInfo;
	HexGfxInfo.isFilled = pGUI->getIsFilled();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	HexGfxInfo.FillClr = pGUI->getCrntFillColor();
	HexGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read ellipse data from the user

	pGUI->PrintMessage("New Hexagon: Click at first point");
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);
	if (P1.y < UI.ToolBarHeight || P1.y > UI.height - UI.StatusBarHeight || P1.x < UI.MenuItemWidth)
	{
		bool flag = false; //false as long as the click is in wrong place
		pGUI->PrintMessage("Please, Choose a valid Point");
		while (!flag)
		{
			pGUI->GetPointClicked(P1.x, P1.y); //Get Pasting Point
			if (!(P1.y < UI.ToolBarHeight || P1.y > UI.height - UI.StatusBarHeight || P1.x < UI.MenuItemWidth))
				flag = 1;
		}
	}

	pGUI->PrintMessage("New Hexagon: Click at second point");
	//Read 2nd point and store in point P2
	pGUI->GetPointClicked(P2.x, P2.y);
	if (P2.y < UI.ToolBarHeight || P2.y > UI.height - UI.StatusBarHeight || P2.x < UI.MenuItemWidth)
	{
		bool flag = false; //false as long as the click is in wrong place
		pGUI->PrintMessage("Please, Choose a valid Point");
		while (!flag)
		{
			pGUI->GetPointClicked(P2.x, P2.y); //Get Pasting Point
			if (!(P2.y < UI.ToolBarHeight || P2.y > UI.height - UI.StatusBarHeight || P2.x < UI.MenuItemWidth))
				flag = 1;
		}
	}

	pGUI->ClearStatusBar();


	//Step 2 - prepare Hexagon data
	
	Point topLeft;
	topLeft.x = P1.x < P2.x ? P1.x : P2.x;
	topLeft.y = P1.y < P2.y ? P1.y : P2.y;

	//2.2- Identify the bottom right corner of the Hexagon
	Point bottomright;
	bottomright.x = P1.x > P2.x ? P1.x : P2.x;
	bottomright.y = P1.y > P2.y ? P1.y : P2.y;

	//Step 3 - Create a Hexagon with the parameters read from the user
	CHexagon* H = new CHexagon(topLeft, bottomright, HexGfxInfo);

	//Step 4 - Add the Hexagon to the list of figures
	pManager->AddFigure(H);
}
