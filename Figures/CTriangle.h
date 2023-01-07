#ifndef CTriangle_H
#define CTriangle_H

#include "CFigure.h"

class CTriangle : public CFigure
{
	Point P1;
	Point P2;
	Point P3;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	CTriangle();
	virtual void DrawMe(GUI* pOut) const;
	bool insideFigure(int x, int y);
	void Save(ofstream& File);
	void Load(ifstream& file);
	CFigure* Clone();
	string getShapeType();
	virtual void Resize(GUI* pGUI, float size);
};

#endif