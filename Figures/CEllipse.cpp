#include "CEllipse.h"
#include <fstream>
#include <iostream>

CEllipse::CEllipse(Point _P1, Point _P2, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	P1 = _P1;
	P2 = _P2;
	ID = newID++;
}
CEllipse::CEllipse(){}

void CEllipse::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawCircle to draw a Circle on the screen	
	pGUI->DrawEllipse(P1 , P2 , FigGfxInfo, Selected);




}

bool CEllipse::insideFigure(int x, int y)
{
	Point center;
	center.x = 0.5 * (P2.x + P1.x);
	center.y = 0.5 * (P2.y + P1.y);
	float a = abs(P2.x - P1.x) / 2;
	float b = abs(P2.y - P1.y) / 2;
	float check = (pow(x - center.x, 2) / pow(a, 2)) + (pow(y - center.y, 2) / pow(b, 2));
	if (check <= 1)
		return true;

	return false;

	return false;

/*	if ((P1.x <= x && P2.x >= x) && (P1.y <= y && P2.y >= y)) {
		return true;
	}
	return false;  */
}
void CEllipse::Save(ofstream& File)
{
	File << "Elipse \t"
		<< ID << "\t"
		<< P1.x << "\t"
		<< P1.y << "\t"
		<< P2.x << "\t"
		<< P2.y << "\t"
		<< ColorToString(FigGfxInfo.DrawClr) << "\t";
	if (this->FigGfxInfo.isFilled)
		File << this->ColorToString(this->FigGfxInfo.FillClr) << "\n";
	else
		File << "No-Fill-color\n";
}

void CEllipse::Load(ifstream& file)
{
	string temp;
	file >> this->ID >>
		this->P1.x >>
		this->P1.y >>
		this->P2.x >>
		this->P2.y;
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
CFigure* CEllipse::Clone()
{
	return new CEllipse(*this);
}

string CEllipse::getShapeType()
{
	return "Ellipse";
}

void CEllipse::Resize(GUI* pGUI, float size) {
	Point test1 = P1, test2 = P2;
	if (size == .5) size = -0.5;
	else if (size == .25) size = -(4.0 / 3);
	else if (size == 2) size = 1;
	else size = 3;

	// half radius (horizontal x && vertical y)
	float deltaX, deltaY;
	deltaX = 0.5 * (P2.x - P1.x);
	deltaY = 0.5 * (P2.y - P1.y);



	test1.x -= deltaX * size;
	test2.x += deltaX * size;
	test1.y -= deltaY * size;
	test2.y += deltaY * size;

	if (test1.y < UI.ToolBarHeight || test2.y > UI.height - UI.StatusBarHeight
		|| test2.x > UI.width || test1.x < 1)
	{
		pGUI->PrintMessage("Ellips size will be more than Drawing Area");
		Sleep(1000);
	}
	else if (((test2.x - test1.x) / 2) < 15 || ((test2.y - test1.y) / 2) < 10)
	{
		pGUI->PrintMessage("Ellips size will be very small");
		Sleep(1000);
	}

	P1 = test1;
	P2 = test2;

}

