#ifndef ACTION_CHANGE_DRAW_COLOR_H
#define ACTION_CHANGE_DRAW_COLOR_H
#include "Action.h"
#include "../Figures/CFigure.h"

class ActionChangeDrawColor : public Action {
	ActionType inputColorAction;
	color DrawClr;

	bool IsColor;
	bool IsSelected;
public:
	ActionChangeDrawColor(ApplicationManager* pApp);

	//Changes current/selected figure draw color
	virtual void Execute();
};

#endif