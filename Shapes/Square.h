#pragma once
#include "Shape.h"
#include <vector>
#include <cmath>
#include <algorithm>
class Square : public shape
{
private:
	Point center;
	Point StPt;
	int sides;
	vector <int> Vertexx;
	vector <int> Vertexy;
public:
	Square();
	Square(Point , Point, GfxInfo );
	virtual ~Square();
	void SetVertices();
	virtual void Draw(GUI* pUI) const;
	virtual bool ClickedInside(int x, int y) const;

	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Outfile);
};
