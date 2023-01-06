#include "ActionAddTriangle.h"
#include "..\Figures\CTriangle.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

ActionAddTriangle::ActionAddTriangle(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionAddTriangle::Execute()
{
	Point P1, P2, P3;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo TriGfxInfo;
	TriGfxInfo.isFilled = pGUI->getIsFilled();
	//get drawing, filling colors and pen width from the interface
	TriGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	TriGfxInfo.FillClr = pGUI->getCrntFillColor();
	TriGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read ellipse data from the user

	pGUI->PrintMessage("New Triangle: Click at first point");
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

	pGUI->PrintMessage("New Triangle: Click at second point");
	//Read 2nd point and store in point P2
	pGUI->GetPointClicked(P2.x, P2.y);
	if (P2.y < UI.ToolBarHeight || P2.y > UI.height - UI.StatusBarHeight||P2.x < UI.MenuItemWidth)
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

	pGUI->PrintMessage("New Triangle: Click at third point");
	//Read 2nd point and store in point P3
	pGUI->GetPointClicked(P3.x, P3.y);
	if (P3.y < UI.ToolBarHeight || P3.y > UI.height - UI.StatusBarHeight || P3.x < UI.MenuItemWidth)
	{
		bool flag = false; //false as long as the click is in wrong place
		pGUI->PrintMessage("Please, Choose a valid Point");
		while (!flag)
		{
			pGUI->GetPointClicked(P3.x, P3.y); //Get Pasting Point
			if (!(P3.y < UI.ToolBarHeight || P3.y > UI.height - UI.StatusBarHeight || P3.x < UI.MenuItemWidth))
				flag = 1;
		}
	}

	pGUI->ClearStatusBar();

	//Step 3 - Create a ellipse with the parameters read from the user
	CTriangle* T = new CTriangle(P1, P2, P3, TriGfxInfo);

	//Step 4 - Add the ellipse to the list of figures
	pManager->AddFigure(T);
}
