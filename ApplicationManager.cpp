#include "ApplicationManager.h"
#include "Actions\ActionAddSquare.h"
#include "Actions\ActionAddCircle.h"
#include "Actions\ActionAddEllipse.h"
#include "Actions\ActionSelect.h"
#include "Actions\ActionBringToFront.h"
#include "Actions\ActionSendToBack.h"
#include "Actions\ActionDelete.h"
#include "Actions\ActionAddHexagon.h"
#include "Actions\ActionAddTriangle.h"
#include "Actions\ActionChngBkGrndClr.h"
#include "Actions\ActionChangeDrawColor.h"
#include "Actions\ActionChangeFillColor.h"
#include "Actions\ActionSave.h"
#include "Actions\ActionLoad.h"
#include "Actions\ActionToDraw.h"
#include "Actions\ActionToPlay.h"
#include "Actions\ActionPlayByFill.h"
#include "Actions\ActionPlayByType.h"
#include "Actions\ActionNewGame.h"
#include "Actions\ActionPlayByFILLTYPE.h"
#include "Actions\ActionExit.h"
#include "Actions\ActionResize.h"
#include "Actions\ActionSwitchToDrawMode.h"
#include "Figures\CFigure.h"
#include "Helpers.h"
#include <string>
#include <string.h>
#include <iostream>
#include<sstream>
#include <iostream>
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pGUI = new GUI;	
	
	
	FigCount = 0;


	//initialise selectedCount to 0
	selectedCount = 0;
	selectedfigure = NULL;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++) {
		FigList[i] = NULL;
		SelectedFigures[i] = NULL;
	}
}

void ApplicationManager::Run()
{
	ActionType ActType;
	do
	{		
		//1- Read user action
		ActType = pGUI->MapInputToActionType();

		//2- Create the corresponding Action
		Action *pAct = CreateAction(ActType);
		
		//3- Execute the action
		ExecuteAction(pAct);

		//4- Update the interface
		UpdateInterface();	

	}while(ActType != EXIT);
	
}


//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
//Creates an action
Action* ApplicationManager::CreateAction(ActionType ActType) 
{
	Action* newAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_SQUARE:
			newAct = new ActionAddSquare(this);
			break;

		case DRAW_CIRC:
			newAct = new ActionAddCircle(this);

			break;
		case DRAW_ELLIP:
			newAct = new ActionAddEllipse(this);

			break;
		case DRAW_HEXA:
			newAct = new ActionAddHexagon(this);

			break;
		case DRAW_TRA:
			newAct = new ActionAddTriangle(this);

			break;
		case CHNG_DRAW_CLR:
			newAct = new ActionChangeDrawColor(this);
			break;

		case CHNG_BK_CLR:
			newAct = new ActionChngBkGrndClr(this);
			break;
		case CHNG_FILL_CLR:
			newAct = new ActionChangeFillColor(this);
			break;
		case SELECT:
			newAct = new ActionSelect(this);

			break;
		case FRONT:
			newAct = new ActionBringToFront(this);
			break;

		case BACK:
			newAct = new ActionSendToBack(this);
			break;

		case Delete:
			newAct = new ActionDelete (this);
			break;
		case SAVE:
			newAct = new ActionSave(this, FigCount);
			break;
		case LOAD:
			newAct = new ActionLoad(this);
			break;
		case ACTION_TO_PLAY:
			newAct = new ActionToPlay(this);
			break;
		case ACTION_TO_DRAW:
			newAct = new ActionToDraw(this);
			break;
		case ACTION_PLAY_TYPE:
			newAct = new ActionPlayByType(this);
			break;
		case ACTION_PLAY_RESET:
			newAct = new ActionNewGame(this);
			break;
		case ACTION_PLAY_FILL:
			newAct = new ActionPlayByFill(this);
			break;
		case ACTION_PLAY_TYPEFILL:
			newAct = new ActionPlayByFILLTYPE(this);
			break;
		case RESIZE:
			newAct = new ActionResize(this, selectedfigure);
			break;
		case GO_BACK:
			newAct = new ActionSwitchToDrawMode(this);
			break;
		case EXIT:
			newAct = new ActionExit(this);
			break;
		case STATUS:	//a click on the status bar ==> no action
			return NULL;
			break;

		default:
			newAct = new ActionSelect(this);
			break;
	}	
	return newAct;
}
//////////////////////////////////////////////////////////////////////
//Executes the created Action
void ApplicationManager::ExecuteAction(Action* &pAct) 
{	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//  // add ID For every figure
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
	{
		FigList[FigCount] = pFig;
		FigList[FigCount] ->SetID(FigCount);
		FigCount++;
	}

}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	///Add your code here to search for a figure given a point x,y	
	for (int i = FigCount - 1; i >= 0; i--)
	{
		if (FigList[i]->insideFigure(x, y))
			return FigList[i];

	}
	return NULL;

}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pGUI->ClearDrawArea();
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->HiddenStatus() == false)
			FigList[i]->DrawMe(pGUI);		//Call Draw function (virtual member fn)

	}
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the interface
GUI *ApplicationManager::GetGUI() const
{	return pGUI; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pGUI;
	
}

//==================================================================================//
//								Select Functions		     						//
//==================================================================================//


//Returns the number of selected figures
int ApplicationManager::GetSelectedCount() const {
	return selectedCount;
}
////////////////////////////////////////////////////////////////////////////////////
//Returns a pointer to SelectedFigs array
CFigure* const* ApplicationManager::GetSelectedFigures() const {
	return SelectedFigures;
}

///////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::AddSelectedFigure(CFigure* sf) {

	SelectedFigures[selectedCount] = sf;
	selectedCount++;
}
 
void ApplicationManager::RemoveSelectedFigure(CFigure* sf) {

	for (int i = 0; i < selectedCount; i++) {
		if (SelectedFigures[i] == sf) {
			SelectedFigures[i] = SelectedFigures[selectedCount - 1];
			SelectedFigures[selectedCount - 1] = NULL;
			selectedCount--;

		}
	}
}
///  set selected figure For the select Action
void ApplicationManager::setselectedfigure(CFigure* pFig)
{
	selectedfigure = pFig;
}

CFigure* ApplicationManager::getselectedfigure() const
{
	return selectedfigure;
}


// Changing the Array Order to Send back and front
int ApplicationManager::GetSelectedFigureIndex() {
	for (int i = FigCount - 1; i >= 0; i--) {
		if (FigList[i] != NULL) {
			if (FigList[i]->IsSelected())
				return i;
		}
	}
	return -1;

}

void ApplicationManager::BringToFront(int index) {
	CFigure* SelectedFigure = FigList[index];
	for (int i = index; i < FigCount - 1; i++)
		FigList[i] = FigList[i + 1];

	FigList[FigCount - 1] = SelectedFigure;
}

void ApplicationManager::SendToBack(int index) {
	CFigure* SelectedFigure = FigList[index];
	for (int i = index; i > 0; i--)
		FigList[i] = FigList[i - 1];

	FigList[0] = SelectedFigure;
}



//==================================================================================//
//						Delete Functions		     		                        //
//==================================================================================//

void ApplicationManager::RemoveFig(int ID) {
	//Loops on all figures ,starting at the index of the deleted one, shifting them back 1 element and setting their ID
	for (int i = ID; i < FigCount - 1; i++) {
		FigList[i] = FigList[i + 1];
		FigList[i]->SetID(i);
	}
	//Reduce FigCount by 1 and nullify the extra pointer (used to point at the deleted figure)
	FigCount--;
	FigList[FigCount] = NULL;
}

// To empty the selected figures array
void ApplicationManager::ClearSelectedFigs() {
	for (int i = 0; i < selectedCount; i++)
	{
		SelectedFigures[i] = NULL;
	}
	selectedCount = 0;
}




//==================================================================================//
//						Colors Functions		     		                        //
//==================================================================================//


bool ApplicationManager::GetColor(color& inputColor)
{

	bool isColor = true;

	ActionType inputColorAction = pGUI->MapInputToActionType();
	cout << inputColorAction << endl;
	switch (inputColorAction) {

	case SET_RED:
		inputColor = RED;
		break;

	case SET_GREEN:
		inputColor = GREEN;
		break;

	case SET_BLUE:
		inputColor = BLUE;
		break;

	case SET_PINK:
		inputColor = PINK;
		break;

	case SET_MAROON:
		inputColor = MAROON;
		break;

	case SET_PURPLE:
		inputColor = PURPLE;
		break;
	case SET_BLACK:
		inputColor = BLACK;
		break;
	case SET_WHITE:
		inputColor = WHITE;
		break;
	case SET_ORANGE:
		inputColor = ORANGE;
		break;
	case SET_LIGHT_BLUE:
		inputColor = LIGHTBLUE;
		break;
	case SET_YELLOW:
		inputColor = YELLOW;
		break;
	default:
		isColor = false;
	}

	return isColor;
}

void ApplicationManager::changeFillColor(color FillClr)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			FigList[i]->ChngFillClr(FillClr);
		}
	}
}
bool ApplicationManager::AnySelected()
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			return true;
		}
	}
	return false;
}

void ApplicationManager::changeDrawColor(color drawClr)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			FigList[i]->ChngDrawClr(drawClr);
		}
	}
}

//==================================================================================//
//						Save & Load Functions		     		                        //
//==================================================================================//


string ApplicationManager::colorToString(color c)
{
	cout << "color";
	std::ostringstream os;
	os << int(c.ucRed) << "\t";
	os << int(c.ucGreen) << "\t";
	os << int(c.ucBlue);

	std::string s = os.str();

	return s;
}

void ApplicationManager::SaveFile(ofstream& outputfile)
{

	for (int i = 0; i < FigCount; ++i)
	{
		cout << "nnnnnnn";
		FigList[i]->Save(outputfile);
	}



}//-----------


void ApplicationManager::deleteALLFig()
{
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i] = NULL;

	}

	FigCount = 0;

}

color ApplicationManager::stringToColor(string)
{
	return color();
}

//==================================================================================//
//									Play Mode										//
//==================================================================================//
void ApplicationManager::backupFigList()
{
	for (int i = 0; i < FigCount; i++) {
		FigListBackup[i] = FigList[i]->Clone();
	}
	FigCountBackup = FigCount;
}
void ApplicationManager::restoreFigList()
{
	for (int i = 0; i < FigCountBackup; i++) {
		FigList[i] = FigListBackup[i]->Clone();
	}
	FigCount = FigCountBackup;
	UpdateInterface();

}

void ApplicationManager::clearFigListBackup() {
	for (int i = 0; i < FigCountBackup; i++) {
		delete FigListBackup[i];
	}
	FigCountBackup = 0;

}
int ApplicationManager::numberOfShapes()
{
	return FigCount;
}


int ApplicationManager::countByType(string type) {
	int count = 0;
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->getShapeType() == type)
			count++;
	return count;
}

int ApplicationManager::countByColor(string color) {
	int count = 0;
	for (int i = 0; i < FigCount; i++)
		if (getColorName(FigList[i]->getFillColor()) == color)
			count++;
	return count;
}


int ApplicationManager::countByTypeAndColor(string type, string color) {
	int count = 0;
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->getShapeType() == type && getColorName(FigList[i]->getFillColor()) == color)
			count++;
	return count;
}


CFigure* ApplicationManager::DrawnFigs(int i) const
{
	return FigList[i];
}

int ApplicationManager::getFigCount() const
{
	return FigCount;

}

string ApplicationManager::getRandomExistingColor()
{
	//generating Random index 
	int RandomIndex = rand() % FigCount;

	color tempClr = FigList[RandomIndex]->getFillColor();

	return getColorName(tempClr);

}


void ApplicationManager::getRandomColorAndType(string& type, string& color)
{
	//generating Random index
	int RandomIndex = rand() % FigCount;
	type = FigList[RandomIndex]->getShapeType();
	color = getColorName(FigList[RandomIndex]->getFillColor());
}

//==================================================================================//
//							For Single Figure Deleted								//
//==================================================================================//
void ApplicationManager::singleFigureDeleted()
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			delete FigList[i];
			FigList[i] = NULL;
			FigCount--;
			shiftFigList(i);
			break;
		}
	}
}


//==================================================================================//
//			  to shift all next item in FigList and remove null items				//
//==================================================================================//
void ApplicationManager::shiftFigList(int _figCount)
{
	for (int j = _figCount; j < FigCount; j++)
	{
		FigList[j] = FigList[j + 1];
	}
}


void ApplicationManager::UnselectAll()
{
	for (int i = 0; i < FigCount; i++)
		FigList[i]->SetSelected(false);		//Call Draw function (virtual member fn)
}
string ApplicationManager::getRandomExistingType()
{
	//generating Random index 
	int RandomIndex = rand() % FigCount;
	return FigList[RandomIndex]->getShapeType();
}
/////////////////////////////////////////////////////////////////////////////////////////////

color ApplicationManager::getColorFromString(string s)
{
	if (s == "GREEN")
		return GREEN;
	if (s == "BLUE")
		return BLUE;
	if (s == "WHITE")
		return WHITE;
	if (s == "PINK")
		return PINK;
	if (s == "YELLOW")
		return YELLOW;
	if (s == "ORANGE")
		return ORANGE;
	if (s == "MAROON")
		return MAROON;
	if (s == "PURPLE")
		return PURPLE;
	return BLACK;
}

string ApplicationManager::getColorName(color c)
{
	if ((c.ucBlue == BLACK.ucBlue) && (c.ucGreen == BLACK.ucGreen) && (c.ucRed == BLACK.ucRed))
		return "BLACK";
	if ((c.ucBlue == PINK.ucBlue) && (c.ucGreen == PINK.ucGreen) && (c.ucRed == PINK.ucRed))
		return "PINK";
	if ((c.ucBlue == LIGHTBLUE.ucBlue) && (c.ucGreen == LIGHTBLUE.ucGreen) && (c.ucRed == LIGHTBLUE.ucRed))
		return "LIGHTBLUE";
	if ((c.ucBlue == MAROON.ucBlue) && (c.ucGreen == MAROON.ucGreen) && (c.ucRed == MAROON.ucRed))
		return "MAROON";
	if ((c.ucBlue == ORANGE.ucBlue) && (c.ucGreen == ORANGE.ucGreen) && (c.ucRed == ORANGE.ucRed))
		return "ORANGE";
	if ((c.ucBlue == BLUE.ucBlue) && (c.ucGreen == BLUE.ucGreen) && (c.ucRed == BLUE.ucRed))
		return "BLUE";
	if ((c.ucBlue == WHITE.ucBlue) && (c.ucGreen == WHITE.ucGreen) && (c.ucRed == WHITE.ucRed))
		return "WHITE";
	if ((c.ucBlue == RED.ucBlue) && (c.ucGreen == RED.ucGreen) && (c.ucRed == RED.ucRed))
		return "RED";
	if ((c.ucBlue == YELLOW.ucBlue) && (c.ucGreen == YELLOW.ucGreen) && (c.ucRed == YELLOW.ucRed))
		return "YELLOW";
	if ((c.ucBlue == GREEN.ucBlue) && (c.ucGreen == GREEN.ucGreen) && (c.ucRed == GREEN.ucRed))
		return "GREEN";	
	return "NO-FILL";
}

///////////////////////////////////////////////////////////////////////////////
//                                 Resize Functions							//
//////////////////////////////////////////////////////////////////////////////


int ApplicationManager::getSelectedFigure()
{

	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->IsSelected())
			return i;
	return -1;
}
CFigure* ApplicationManager::GetSelectedFigure() const
{
	//check if a figure selected
	for (int i = (FigCount - 1); i >= 0; i--) {
		if (FigList[i]->IsSelected()) return FigList[i];
	}
	return NULL;
}