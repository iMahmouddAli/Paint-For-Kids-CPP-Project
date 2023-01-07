#include "ActionToPlay.h"
#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionToPlay::ActionToPlay(ApplicationManager* pApp) :Action(pApp)
{

}

void ActionToPlay::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	pGUI->CreatePlayToolBar();
	pManager->backupFigList();
	UI.InterfaceMode = MODE_PLAY;
}