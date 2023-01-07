#ifndef CHexagon_H
#define CHexagon_H

#include "CFigure.h"

class CHexagon : public CFigure
{
private:
	Point TopLeftCorner;
	Point BottomRightCorner;
	int VerticalLen;
	int HorizentalLen;
public:
	CHexagon(Point, Point, GfxInfo FigureGfxInfo);
	CHexagon();
	virtual void DrawMe(GUI* pOut) const;
	bool insideFigure(int x, int y);
	void Save(ofstream& File);
	void Load(ifstream& file);
	CFigure* Clone();
	string getShapeType();
	virtual void Resize(GUI* pGUI, float size);
};

#endif