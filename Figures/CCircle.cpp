#include "CCircle.h"
#include <fstream>
#include <iostream>


CCircle::CCircle(Point P1, int _radius, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	center = P1;
	radius = _radius;
	ID = newID++;
}
CCircle::CCircle(){}


void CCircle::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawCircle to draw a Circle on the screen	
	pGUI->DrawCircle(center,radius, FigGfxInfo, Selected);

	


}

bool CCircle::insideFigure(int x, int y)
{
	float dx = pow(x - center.x, 2);
	float dy = pow(y - center.y, 2);
	if (dx + dy < radius * radius)
		return true;
	return false;
}

void CCircle::Save(ofstream& OutFile)
{

	OutFile << "circle \t" << ID
		<< "\t" << center.x
		<< "\t" << center.y
		<< "\t" << radius << "\t"
		<< ColorToString(this->FigGfxInfo.DrawClr);

	if (!this->FigGfxInfo.isFilled) {
		cout << "fff";

		OutFile << "\t" << "No-Fill-color\n";

	}
	else {
		OutFile << "\t" << ColorToString(this->FigGfxInfo.FillClr)<<"\n";
	}
}


void CCircle::Load(ifstream& Infile)
{
	string temp;
	Infile >> this->ID >>
		this->center.x >>
		this->center.y >>
		this->radius;
	Infile >> temp;
	this->FigGfxInfo.DrawClr = StringToColor(temp);
	Infile >> temp;
	if (temp == "No-Fill-color") {
		this->FigGfxInfo.isFilled = false;
	}
	else
	{
		this->FigGfxInfo.FillClr = StringToColor(temp);
		this->FigGfxInfo.isFilled = true;
		cout << "fail";
	}
	this->Selected = false;
	this->FigGfxInfo.BorderWdth = 3;
}