#include "ActionAddEllipse.h"
#include "..\Figures\CEllipse.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

ActionAddEllipse::ActionAddEllipse(ApplicationManager* pApp) : Action(pApp)
{}

//Execute the action
void ActionAddEllipse::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo SqrGfxInfo;
	SqrGfxInfo.isFilled = pGUI->getIsFilled();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	SqrGfxInfo.FillClr = pGUI->getCrntFillColor();
	SqrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read Circle data from the user

	pGUI->PrintMessage("New Ellipse: Click at first point");
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

	pGUI->PrintMessage("New Ellipse: Click at second point");
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


	//Step 2 - prepare Ellipse data
	//User has entered two points P1&P2
	//2.1- Identify the Top left corner of the square


	//Step 3 - Create a Ellipse with the parameters read from the user
	CEllipse* R = new CEllipse ( P1, P2, SqrGfxInfo);

	//Step 4 - Add the Ellipse to the list of figures
	pManager->AddFigure(R);
}




