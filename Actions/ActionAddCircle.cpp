#include "ActionAddCircle.h"
#include "..\Figures\CCircle.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

ActionAddCircle::ActionAddCircle(ApplicationManager* pApp) : Action(pApp)
{}

//Execute the action
void ActionAddCircle::Execute()
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

	pGUI->PrintMessage("New Circle: Click at Center point");
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);
	if (P1.y < UI.ToolBarHeight || P1.y > UI.height - UI.StatusBarHeight|| P1.x <UI.MenuItemWidth)
	{
		bool flag = false; //false as long as the click is in wrong place
		pGUI->PrintMessage("Please, Choose a valid Point");
		while (!flag)
		{
			pGUI->GetPointClicked(P1.x, P1.y); //Get Pasting Point
			if (!(P1.y < UI.ToolBarHeight || P1.y > UI.height - UI.StatusBarHeight|| P1.x < UI.MenuItemWidth))
				flag = 1;
		}
	}

	pGUI->PrintMessage("New Circle: Click at second point");
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


	//Step 2 - prepare Circle data
	Point center;
	center.x = P1.x < P2.x ? P1.x : P2.x;
	center.y = P1.y < P2.y ? P1.y : P2.y;

	//2.2- Calcuate Circle Radius
	int radius = max(abs(P1.x - P2.x), abs(P1.y - P2.y));


	//Step 3 - Create a Circle with the parameters read from the user
	CCircle* R = new CCircle(center, radius, SqrGfxInfo);

	//Step 4 - Add the Circle to the list of figures
	pManager->AddFigure(R);
}





