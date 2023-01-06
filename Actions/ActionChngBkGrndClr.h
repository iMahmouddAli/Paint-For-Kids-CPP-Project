#ifndef ACTION_CHNG_BKGRND_CLR_H
#define ACTION_CHNG_BKGRND_CLR_H

#include "Action.h"
#include "../Figures/CFigure.h"

class ActionChngBkGrndClr : public Action {
	ActionType inputColorAction;
	color BkGrndClr;

	bool IsColor;
public:
	ActionChngBkGrndClr(ApplicationManager* pApp);

	//Changes current/selected figure draw color
	virtual void Execute();
};

#endif