#include "ActionPlayByFILLTYPE.h"
#include "../ApplicationManager.h"
#include "../GUI/GUI.h"
#include "../Helpers.h"
#include "../Figures/CFigure.h"
#include "ActionPlayByFILLTYPE.h"

ActionPlayByFILLTYPE::ActionPlayByFILLTYPE(ApplicationManager* pApp) :Action(pApp)
{
	correct = wrong = 0;
}


void ActionPlayByFILLTYPE::Execute()
{
	UI.InterfaceMode = MODE_PLAY;
	GUI* pGUI = pManager->GetGUI();
	if (pManager->numberOfShapes() > 0) {
		string type, color;
		pManager->getRandomColorAndType(type, color);

		int numberOfShapesOfType = pManager->countByTypeAndColor(type, color);

		pGUI->PrintMessage("Pick All " + color + " " + type);
		for (int i = 0; i < numberOfShapesOfType; i++) {
			int x, y;

			//wait for user mouse click and make sure it's inside draw area
			pGUI->getPointInsideDrawArea(x, y);
			CFigure* fig = pManager->GetFigure(x, y);
			while (fig == NULL) {
				pGUI->PrintMessage("No Shape Found, Please Click on shape");
				pGUI->getPointInsideDrawArea(x, y);
				fig = pManager->GetFigure(x, y);
			}

			if (fig != NULL && fig->getShapeType() == type && fig->getShapeType() == type && pManager->getColorName(fig->getFillColor()) == color) {
				correct++;
				//delete figure on click
				pManager->UnselectAll();
				fig->SetSelected(true);
				pManager->singleFigureDeleted();
				pManager->UpdateInterface();
			}
			else {
				wrong++;
			}
			pGUI->PrintMessage("Correct: " + to_string(correct) + " || Wrong:" + to_string(wrong));
		}
		if (correct > wrong) {
			pGUI->PrintMessage("You Won ^_^ " + to_string(correct) + " / " + to_string(wrong));
		}
		else {
			pGUI->PrintMessage("You Lost :(" + to_string(correct) + " / " + to_string(wrong));
		}
	}
	else {
		pGUI->PrintMessage("There is no shapes");
	}
	pGUI->CreatePlayToolBar();
}
