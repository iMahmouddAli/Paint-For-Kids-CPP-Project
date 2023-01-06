#include "ActionSelect.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"
#include <math.h>

ActionSelect::ActionSelect(ApplicationManager * pApp):Action(pApp)
{}

void ActionSelect::Execute()
{
	Point P1;

	GUI* pGUI = pManager->GetGUI();
	ApplicationManager* pAPP = pManager;

	pGUI->PrintMessage("Click at any point");
	pGUI->GetPointClicked(P1.x, P1.y);
	pGUI->ClearStatusBar();

	CFigure* r = pManager->GetFigure(P1.x, P1.y);
	if (r) {
		r->SetSelected(!r->IsSelected());
		if (r->IsSelected())
		{
			pManager->AddSelectedFigure(r); //Add the figure to ApplicationManager's SelectedFigures array
		}
		else
		{  
			pManager->RemoveSelectedFigure(r); // to remove the unselected from SelectedFigures array
		}
	}
}

