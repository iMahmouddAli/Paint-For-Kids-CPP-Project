
#ifndef ACTION_NEW_GAME_H
#define ACTION_NEW_GAME_H
#include "Action.h"

class ActionNewGame : public Action
{

public:
	ActionNewGame(ApplicationManager* pApp);
	void Execute();
};
#endif
