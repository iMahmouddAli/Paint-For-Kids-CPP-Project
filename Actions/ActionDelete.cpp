#include "ActionDelete.h"

#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"


ActionDelete::ActionDelete(ApplicationManager* pApp) :Action(pApp)
{}

void ActionDelete::Execute() {
	//Get a Pointer to the GUI 
	GUI* pGUI = pManager->GetGUI();

	//Initialise local SelectedFigs and selectedCount 
	SelectedFigures = pManager->GetSelectedFigures();
	selectedCount = pManager->GetSelectedCount();
	

	//Check if a figure is selected
	if (SelectedFigures[0] == NULL)
		pGUI->PrintMessage("Delete figure : Select a figure first");
	else {
		for (int i = 0; i < selectedCount; i++) {
			//Gets the deleted figure ID
			DeletedID = SelectedFigures[i]->GetID();

			//Remove the figure from the FigList by ID
			pManager->RemoveFig(DeletedID);

			//Delete the selected figure
			delete SelectedFigures[i];
		}

		//pManager->ClearSelectedFigs();
		pGUI->ClearDrawArea();  //To Remove the Drawing from the toolbar "ReDraw the window"
		pGUI->PrintMessage("Figure(s) Deleted");
	}
}
