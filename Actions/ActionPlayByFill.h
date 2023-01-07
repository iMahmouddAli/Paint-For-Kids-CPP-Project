
#pragma once

#include "Action.h"

class ActionPlayByFill : public Action
{
	int correct;
	int wrong;
public:
	ActionPlayByFill(ApplicationManager* pApp);
	void Execute();
};