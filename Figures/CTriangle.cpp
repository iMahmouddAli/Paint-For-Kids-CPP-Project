#include "CTriangle.h"
#include <fstream>
#include <iostream>

CTriangle::CTriangle(Point v1, Point v2, Point v3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo){
	P1 = v1;
	P2 = v2;
	P3 = v3;
	ID = newID++;
}
CTriangle::CTriangle() {}

void CTriangle::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawTriangle(P1, P2, P3, FigGfxInfo, Selected);		 
	
}

bool CTriangle::insideFigure(int x, int y)
{

	/* Calculate area of triangle ABC */
	float A = 0.5 * abs(P1.x * (P2.y - P3.y) + P2.x * (P3.y - P1.y) + P3.x * (P1.y - P2.y)); //a,b,c

	/* Calculate area of triangle PBC */
	float A1 = 0.5 * abs(x * (P2.y - P3.y) + P2.x * (P3.y - y) + P3.x * (y - P2.y)); //x,a,b
	/* Calculate area of triangle PAC */
	float A2 = 0.5 * abs(P1.x * (y - P3.y) + x * (P3.y - P1.y) + P3.x * (P1.y - y)); //x,a,c
	/* Calculate area of triangle PAB */
	float A3 = 0.5 * abs(P1.x * (P2.y - y) + P2.x * (y - P1.y) + x * (P1.y - P2.y)); //x,b,c

	/* Check if sum of A1, A2 and A3 is same as A */
	return (A == A1 + A2 + A3);
}

void CTriangle::Save(ofstream& File)
{
	File << "Triangle\t"
		<< ID << "\t"
		<< P1.x << "\t"
		<< P1.y << "\t"
		<< P2.x << "\t"
		<< P2.y << "\t"
		<< P3.x << "\t"
		<< P3.y << "\t"
		<< ColorToString(FigGfxInfo.DrawClr) << "\t";
	if (this->FigGfxInfo.isFilled)
		File << this->ColorToString(this->FigGfxInfo.FillClr) << "\n";
	else
		File << "No-Fill-color\n";

}
void CTriangle::Load(ifstream& file)
{
	string temp;
	file >> this->ID >>
		this->P1.x >>
		this->P1.y >>
		this->P2.x >>
		this->P2.y >>
		this->P3.x >>
		this->P3.y;
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

CFigure* CTriangle::Clone()
{
	return new CTriangle(*this);
}

string CTriangle::getShapeType()
{
	return "Triangle";
}

void CTriangle::Resize(GUI* pGUI, float size)
{
	if (size == 0.5) size = -1;
	else if (size == 0.25) size = -(4.0 / 3);

	Point O;
	O.x = (P1.x + P2.x + P3.x) / 3;
	O.y = (P1.y + P2.y + P3.y) / 3;
	if (P1.x <= O.x)
		P1.x -= (O.x - P1.x) * size / 2;
	else
		P1.x += (P1.x - O.x) * size / 2;

	if (P2.x <= O.x)
		P2.x -= (O.x - P2.x) * size / 2;
	else
		P2.x += (P2.x - O.x) * size / 2;

	if (P3.x <= O.x)
		P3.x -= (O.x - P3.x) * size / 2;
	else
		P3.x += (P3.x - O.x) * size / 2;

	if (P1.y <= O.y)
		P1.y -= (O.y - P1.y) * size / 2;
	else
		P1.y += (P1.y - O.y) * size / 2;

	if (P2.y <= O.y)
		P2.y -= (O.y - P2.y) * size / 2;
	else
		P2.y += (P2.y - O.y) * size / 2;

	if (P3.y <= O.y)
		P3.y -= (O.y - P3.y) * size / 2;
	else
		P3.y += (P3.y - O.y) * size / 2;


}