#pragma once

#include "shape.h"

class Line : public shape
{
private:
	Point point1;
	Point point2;
	
public:
	Line();
	Line(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Line();
	virtual void Draw(GUI* pUI) const;
	virtual bool ClickedInside(int x, int y) const;

	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Outfile);
};

