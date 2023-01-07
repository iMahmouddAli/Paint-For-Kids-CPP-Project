#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\GUI.h"
static int newID = 0;
//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	bool PlayHidden;
	/// Add more parameters if needed.

public:
	CFigure();
	CFigure(GfxInfo FigureGfxInfo);
	void SetSelected(bool );	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	void Hide();
	void Show();
	bool HiddenStatus() const;
	virtual void DrawMe(GUI*) const  = 0 ;		//Draw the figure
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	virtual bool insideFigure(int, int) = 0; // select

	//ID Setter / Getter
	int CFigure::GetID() const;
	color StringToColor(string s);
	string ColorToString(color c);
	void CFigure::SetID(int id);
	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file
	virtual string getShapeType() = 0;  // to get type of the shape
	virtual CFigure* Clone() = 0;
	 color getFillColor();
	 virtual void Resize(GUI* pGUI, float size) = 0;
};

#endif