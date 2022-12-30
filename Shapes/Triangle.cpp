#include "Triangle.h"

Triangle::Triangle()
{

}

Triangle::Triangle(Point p1, Point p2, Point p3, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	corner1 = p1;
	corner2 = p2;
	corner3 = p3;
	type = "Triangle";
}

Triangle::~Triangle()
{}

bool Triangle::ClickedInside(int x, int y) const
{
		int as_x = x - corner1.x;
		int as_y = y - corner1.y;

		bool s_ab = (corner2.x - corner1.x) * as_y - (corner2.y - corner1.y) * as_x > 0;

		if ((corner3.x - corner1.x) * as_y - (corner3.y - corner1.y) * as_x > 0 == s_ab) return false;

		if ((corner3.x - corner2.x) * (y - corner2.y) - (corner3.y - corner2.y) * (x - corner2.x) > 0 != s_ab) return false;

		return true;
}

void Triangle::Draw(GUI * pUI) const
{
	pUI->DrawTriangle(corner1, corner2, corner3, ShpGfxInfo);
}
void Triangle::Save(ofstream& OutFile)
{
	OutFile << type << " " << corner1.x << " " << corner1.y << " " << corner2.x << " " << corner2.y << " " << corner3.x << " " << corner3.y << " " << (ShpGfxInfo.isFilled) << " " << to_string(ShpGfxInfo.FillClr.ucRed) << " " << to_string(ShpGfxInfo.FillClr.ucGreen) << " " << to_string(ShpGfxInfo.FillClr.ucBlue) << " " << to_string(ShpGfxInfo.DrawClr.ucRed) << " " << to_string(ShpGfxInfo.DrawClr.ucGreen) << " " << to_string(ShpGfxInfo.DrawClr.ucBlue) << " " << (ShpGfxInfo.BorderWdth) << endl;

}

void Triangle::Load(ifstream& inFile)
{
	type = "Triangle";
	int x;
	string jump;

	inFile >> x;
	corner1.x = x;

	inFile >> x;
	corner1.y = x;

	inFile >> x;

	corner2.x = x;

	inFile >> x;
	corner2.y = x;

	inFile >> x;
	corner3.x = x;

	inFile >> x;
	corner3.y = x;
	inFile >> x;
	if (x == 0)
	{
		ShpGfxInfo.isFilled = FALSE;

	}
	else if (x == 1)
	{
		ShpGfxInfo.isFilled = TRUE;

	}
	inFile >> jump;

	ShpGfxInfo.FillClr.ucRed = stoi(jump);
	inFile >> jump;

	ShpGfxInfo.FillClr.ucGreen = stoi(jump);
	inFile >> jump;

	ShpGfxInfo.FillClr.ucBlue = stoi(jump);
	inFile >> jump;

	ShpGfxInfo.DrawClr.ucRed = stoi(jump);
	inFile >> jump;

	ShpGfxInfo.DrawClr.ucGreen = stoi(jump);
	inFile >> jump;

	ShpGfxInfo.DrawClr.ucBlue = stoi(jump);
	inFile >> x;

	ShpGfxInfo.BorderWdth = x;

	ShpGfxInfo.isSelected = FALSE;
}
