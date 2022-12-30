#pragma once

#include "shape.h"

class Rect : public shape
{
private:
	Point Corner1;	
	Point Corner2;
public:
	Rect();
	Rect(Point , Point, GfxInfo shapeGfxInfo );
	virtual ~Rect();
	virtual void Draw(GUI* pUI) const;
	virtual bool ClickedInside(int x, int y) const;

	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Outfile);
};

