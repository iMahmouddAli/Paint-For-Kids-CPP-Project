#include "ActionExit.h"
#include "../GUI/GUI.h"
ActionExit::ActionExit(ApplicationManager* pApp) :Action(pApp)
{

}
void ActionExit::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage("Before leaving us Do You Want to Save you Work?! Click Y or N ^_^");
	string userInput = pGUI->GetString(pGUI);
	if (userInput == "Y" || userInput == "y")
	{
		//2- Create the corresponding Action
		Action* pAct = pManager->CreateAction(SAVE);

		//3- Execute the action
		pManager->ExecuteAction(pAct);

	}
	else
	{
		pGUI->PrintMessage("Goodbye see you soon ... ");
	}
}
