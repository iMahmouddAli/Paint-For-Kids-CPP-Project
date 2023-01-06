#ifndef ACTION_CHANGE_FILL_COLOR_H
#define ACTION_CHANGE_FILL_COLOR_H
#include "Action.h"

class ActionChangeFillColor : public Action {
	ActionType inputColorAction;
	color FillClr;

	bool IsColor;
	bool IsSelected;
public:
	ActionChangeFillColor(ApplicationManager* pApp);

	//Changes current/selected figure draw color
	virtual void Execute();
};

#endif