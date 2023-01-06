#include "ActionChangeFillColor.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionChangeFillColor::ActionChangeFillColor(ApplicationManager* pApp) :Action(pApp)
{}

void ActionChangeFillColor::Execute() {
	//Get a Pointer to the Input / Output Interfaces
	GUI* pGUI = pManager->GetGUI();
	IsSelected = pManager->AnySelected();
	pGUI->PrintMessage("Choose FILL Color");
	UI.InterfaceMode = MODE_COLOR;
	//Reads the input draw color
	if (!pManager->GetColor(FillClr))
		IsColor = false;
	else
		IsColor = true;

	if (IsColor) {
		if (IsSelected)
		{
			pManager->changeFillColor(FillClr);
		}
		else
		{
			pGUI->setIsFilled(true);
			pGUI->setCrntFillColor(FillClr);
		}
	}
}

