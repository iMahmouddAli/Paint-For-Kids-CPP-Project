
#include "ActionNewGame.h"
#include "../ApplicationManager.h"
#include "../GUI/GUI.h"
ActionNewGame::ActionNewGame(ApplicationManager* pApp) :Action(pApp)
{

}


void ActionNewGame::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	pGUI->ClearStatusBar();
	pManager->restoreFigList();

}