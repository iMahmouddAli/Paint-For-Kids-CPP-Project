#include "ActionPlayByType.h"
#include "../ApplicationManager.h"
#include "../GUI/GUI.h"
#include "../Figures/CFigure.h"
ActionPlayByType::ActionPlayByType(ApplicationManager* pApp) :Action(pApp)
{
	correct = wrong = 0;
}


void ActionPlayByType::Execute()
{
	UI.InterfaceMode = MODE_PLAY;
	GUI* pGUI = pManager->GetGUI();
	if (pManager->numberOfShapes() > 0) {
		string type = pManager->getRandomExistingType();
		int numberOfShapesOfType = pManager->countByType(type);

		pGUI->PrintMessage("Pick All Shapes of type " + type);
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

			if (fig != NULL && fig->getShapeType() == type) {
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