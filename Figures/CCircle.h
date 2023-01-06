#ifndef CCIRCLE_H
#define CCIRCLE_H

#include "CFigure.h"

class CCircle :public CFigure
{
private:
	Point center;
	int radius;
public:
	CCircle(Point, int, GfxInfo FigureGfxInfo);
	CCircle();
	virtual void DrawMe(GUI* pOut) const;
	bool insideFigure(int x, int y);
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
};

#endif

