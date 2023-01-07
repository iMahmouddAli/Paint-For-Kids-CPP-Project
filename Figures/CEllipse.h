#ifndef CELLIPSE_H
#define CELLIPSE_H

#include "CFigure.h"

class CEllipse :public CFigure
{
private:
	Point P1,P2;

public:
	CEllipse(Point, Point, GfxInfo FigureGfxInfo);
	CEllipse();
	virtual void DrawMe(GUI* pOut) const;
	bool insideFigure(int x, int y);
	void Save(ofstream& File);
	void Load(ifstream& file);
	CFigure* Clone();
	string getShapeType();
	virtual void Resize(GUI* pGUI, float size);
};

#endif




