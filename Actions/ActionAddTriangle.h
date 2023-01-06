#ifndef ACTION_ADD_Triangle_H
#define ACTION_ADD_Triangle_H

#include "Action.h"

//Add ellipse Action class
class ActionAddTriangle : public Action
{
public:
	ActionAddTriangle(ApplicationManager* pApp);

	//Add Triangle to the ApplicationManager
	virtual void Execute();

};

#endif