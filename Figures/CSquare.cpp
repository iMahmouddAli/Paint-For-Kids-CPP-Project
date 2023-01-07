#include "CSquare.h"
#include <fstream>
#include <iostream>

CSquare::CSquare(Point P1, int len, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	length = len;
	ID = newID++;
}
CSquare::CSquare(){}

void CSquare::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawSquare(TopLeftCorner, length, FigGfxInfo, Selected);
	

}

bool CSquare::insideFigure(int x, int y)
{
	if (x >= TopLeftCorner.x && x <= (TopLeftCorner.x + length) && y >= TopLeftCorner.y && y <= (TopLeftCorner.y + length))
	{
		return true;
	}
	return false;
}

void CSquare::Save(ofstream& File)
{
	File << "Square\t"
		<< ID << "\t"
		<< TopLeftCorner.x << "\t"
		<< TopLeftCorner.y << "\t"
		<< length << "\t"
		<< ColorToString(FigGfxInfo.DrawClr) << "\t";
	if (this->FigGfxInfo.isFilled)
		File << this->ColorToString(this->FigGfxInfo.FillClr) << "\n";
	else
		File << "No-Fill-color\n";
}
void CSquare::Load(ifstream& file)
{
	string temp;
	file >> this->ID >>
		this->TopLeftCorner.x >>
		this->TopLeftCorner.y >>
		this->length;
	file >> temp;
	this->FigGfxInfo.DrawClr = StringToColor(temp);
	file >> temp;
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

CFigure* CSquare::Clone()
{
	return new CSquare(*this);
}

string CSquare::getShapeType()
{
	return "Square";
}

void CSquare::Resize(GUI* pGUI, float size) {
	Point test1 = TopLeftCorner;

	if (test1.y < UI.ToolBarHeight || test1.x > UI.width)
	{
		pGUI->PrintMessage("square size will be more than Drawing Area");
		Sleep(1000);
	}
	else if (((test1.x - length) / 2) < 15 || ((test1.y - length) / 2) < 10)
	{
		pGUI->PrintMessage("square size will be very small");
		Sleep(1000);
	}

	this->length = this->length * size;



}