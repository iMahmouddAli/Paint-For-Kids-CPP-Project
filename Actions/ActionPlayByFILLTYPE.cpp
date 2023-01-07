#include "ActionPlayByFILLTYPE.h"
#include "../ApplicationManager.h"
#include "../GUI/GUI.h"
ActionPlayByFILLTYPE::ActionPlayByFILLTYPE(ApplicationManager* pApp) :Action(pApp)
{
	correct = wrong = 0;
}


void ActionPlayByFILLTYPE::Execute()
{

	GUI* pGUI = pManager->GetGUI();
	if (pManager->numberOfShapes() > 0) {
		string type, color;
		pManager->getRandomColorAndType(type, color);
		int numberOfShapesOfType = pManager->countByTypeAndColor(type, color);
		pGUI->PrintMessage("Pick All " + color + " " + type);
		while (numberOfShapesOfType > 0) {
			int x, y;
			pGUI->getPointInsideDrawArea(x, y);
			CFigure* fig = pManager->GetFigure(x, y);
			while (fig == NULL) {
				pGUI->PrintMessage("No Shape Found, Please Click on shape");
				pGUI->getPointInsideDrawArea(x, y);
				fig = pManager->GetFigure(x, y);
			}

			if (fig != NULL && fig->getShapeType() == type && fig->getShapeType() == type && pManager->getColorName(fig->getFillColor()) == color) {
				correct++;
				numberOfShapesOfType--;

				//delete figure on 
				fig->Hide();
				pManager->UpdateInterface();

			}
			else {
				wrong++;
				fig->Hide();
			}
			pGUI->PrintMessage("Correct: " + to_string(correct) + " || Wrong:" + to_string(wrong));
			if (numberOfShapesOfType == 0) {
				pGUI->PrintMessage("You Won ^_^ " + to_string(correct) + " / " + to_string(wrong));
			}
		}
	}
	else {
		pGUI->PrintMessage("There is no shapes");
	}
	for (int i = 0; i < pManager->getFigCount(); i++)
		pManager->DrawnFigs(i)->Show();
	pManager->UpdateInterface();
}
