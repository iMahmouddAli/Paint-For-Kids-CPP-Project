#include "ActionPlayByFill.h"
#include "../ApplicationManager.h"
#include "../GUI/GUI.h"
#include "../Helpers.h"
#include "../Figures/CFigure.h"

ActionPlayByFill::ActionPlayByFill(ApplicationManager* pApp) :Action(pApp)
{
	correct = wrong = 0;
}
void ActionPlayByFill::Execute()
{
	UI.InterfaceMode = MODE_PLAY;
	GUI* pGUI = pManager->GetGUI();
	if (pManager->numberOfShapes() > 0) {
		string color = pManager->getRandomExistingColor();
		int numberOfShapesOfColor = pManager->countByColor(color);

		pGUI->PrintMessage("Pick All " + color + " Shapes");
		for (int i = 0; i < numberOfShapesOfColor; i++) {
			int x, y;
			pGUI->getPointInsideDrawArea(x, y);
			CFigure* fig = pManager->GetFigure(x, y);
			while (fig == NULL) {
				pGUI->PrintMessage("No Shape Found, Please Click on shape");
				pGUI->getPointInsideDrawArea(x, y);
				fig = pManager->GetFigure(x, y);
			}
			if (fig != NULL && pManager->getColorName(fig->getFillColor()) == color) {
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
