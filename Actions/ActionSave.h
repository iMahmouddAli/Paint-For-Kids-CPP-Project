

#ifndef ACTION_SAVE
#define ACTION_SAVE

#include "Action.h"


class ActionSave :public Action {
private:
	//make file name
	string fileName;
	int count;

public:
	ActionSave(ApplicationManager* pApp, int _figcount);

	virtual void Execute();

};

#endif