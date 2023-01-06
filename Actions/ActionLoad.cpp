#include "ActionLoad.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CEllipse.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CFigure.h"

#include<fstream>
#include <iostream>

ActionLoad::ActionLoad(ApplicationManager* pApp) :Action(pApp)
{
}

void ActionLoad::Execute()
{
	int r, g, b;
	ifstream File;
	bool flag = false;
	string figName, drawclr, fillclr;
	int figcount;
	CFigure* fig;
	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage("please write the file name -->");
	FileName = pGUI->GetSrting();


	File.open(FileName + ".txt");


	if (File.fail())
	{
		pGUI->PrintMessage("invalid name");
		return;
	}
	pGUI->ClearDrawArea();
	pManager->deleteALLFig();

	File >> r >> g >> b;
	color drawClr(r, g, b);
	File >> r >> g >> b;
	color FillClr(r, g, b);

	File >> r >> g >> b;
	color bkgclr(r, g, b);
	File >> figcount;

	while (figcount)
	{
		cout << figcount;
		File >> figName;
		if (figName == "circle")
		{
			fig = new CCircle();
			cout << "circle" << endl;
		}
		else if (figName == "Elipse")
		{
			fig = new CEllipse();
			cout << "Elipse" << endl;
		}
		else if (figName == "Square") {
			fig = new CSquare();
			cout << "Square" << endl;
		}
		else if (figName == "Triangle")
		{
			fig = new CTriangle();
			cout << "Triangle" << endl;
		}
		else if (figName == "Hexagon") {
			fig = new CHexagon();
			cout << "Hexagon" << endl;
		}

		fig->Load(File);
		pManager->AddFigure(fig);

		figcount--;
	}
	pManager->UpdateInterface();    //draw the figure list
	pGUI->PrintMessage("Done successfully..");
	pGUI->ClearStatusBar();
}
