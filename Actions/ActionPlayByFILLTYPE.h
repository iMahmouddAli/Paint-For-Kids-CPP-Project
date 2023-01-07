
#pragma once

#include "Action.h"

class ActionPlayByFILLTYPE : public Action
{
	int correct;
	int wrong;
public:
	ActionPlayByFILLTYPE(ApplicationManager* pApp);
	void Execute();
};

