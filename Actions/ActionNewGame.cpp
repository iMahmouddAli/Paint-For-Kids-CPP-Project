
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
	pGUI->CreateDrawToolBar();
	UI.InterfaceMode = MODE_DRAW;
	pManager->restoreFigList();

}