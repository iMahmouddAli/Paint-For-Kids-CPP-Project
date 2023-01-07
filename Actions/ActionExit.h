
#ifndef ACTION_EXIT_H
#define ACTION_EXIT_H
#include "Action.h"
#include "../ApplicationManager.h"
#include"ActionLoad.h"
#include "ActionSave.h"
class ActionExit : public Action
{
public:
	ActionExit(ApplicationManager* pApp);
	void Execute();
};
#endif
