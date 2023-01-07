#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"

class Action;	//Forward Declaration


//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures

	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)


	int selectedCount;					//Number of selected figures
	CFigure* SelectedFigures[MaxFigCount];	//List of all selected figures

	int FigCountBackup;		//Actual number of figures
	CFigure* FigListBackup[MaxFigCount];	//Clone version of FigList (Array of pointers)
	CFigure* selectedfigure; //The Selected Figure

	//Pointers to Input and Output classes
	GUI* pGUI;
	

public:	
	ApplicationManager(); 
	~ApplicationManager();

	void Run();		//to run the application
	
	// -- Action-Related Functions
	Action* CreateAction(ActionType);
	void ExecuteAction(Action*&) ; //Execute an action
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
		
	// -- Interface Management Functions	
	GUI *GetGUI() const; //Return pointer to the interface
	void UpdateInterface() const;	//Redraws all the drawing window


	// Bring back and forward functions
	int GetSelectedFigureIndex();
	void BringToFront(int);
	void SendToBack(int);

	//Select Functions 
	 CFigure* const* ApplicationManager::GetSelectedFigures() const;
	int ApplicationManager::GetSelectedCount() const;
	void ApplicationManager::AddSelectedFigure(CFigure* sf);
	void RemoveSelectedFigure(CFigure* sf);
	void setselectedfigure(CFigure* pFig);
	CFigure* getselectedfigure() const;
	void UnselectAll();

	//Delete Functions 
	void ApplicationManager::RemoveFig(int ID);
	void ApplicationManager::ClearSelectedFigs();


	//Colors Functions 
	bool ApplicationManager::GetColor(color& inputColor);
	void ApplicationManager::changeFillColor(color FillClr);
	bool ApplicationManager::AnySelected();
	void ApplicationManager::changeDrawColor(color drawClr);

	//save and load functions
	string ApplicationManager::colorToString(color c);
	void ApplicationManager::SaveFile(ofstream& outputfile);
	void ApplicationManager::deleteALLFig();
	color ApplicationManager::stringToColor(string);



	//play mode functions
	void ApplicationManager::backupFigList();
	void ApplicationManager::restoreFigList();
	void ApplicationManager::clearFigListBackup();
	int ApplicationManager::numberOfShapes();
	int ApplicationManager::countByType(string type);
	int ApplicationManager::countByColor(string color);
	string ApplicationManager::getRandomExistingType();
	int ApplicationManager::getFigCount() const;
	string ApplicationManager::getRandomExistingColor();
	void ApplicationManager::singleFigureDeleted();
	void ApplicationManager::shiftFigList(int _figCount);
	int ApplicationManager::countByTypeAndColor(string type, string color);
	void ApplicationManager::getRandomColorAndType(string& type, string& color);

	color getColorFromString(string s);
	string getColorName(color c);
	int getSelectedFigure();
	CFigure* GetSelectedFigure() const;
};

#endif