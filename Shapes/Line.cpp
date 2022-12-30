#include "Line.h"

Line::Line()
{

}

Line::Line(Point p1, Point p2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	point1 = p1;
	point2 = p2;
	type = "Line";
}

Line::~Line()
{}

void Line::Draw(GUI* pUI) const
{
	pUI->DrawLine(point1, point2, ShpGfxInfo);
}

bool Line::ClickedInside(int x, int y) const
{
	int maxx, minx, maxy, miny;
	if (point1.x > point2.x) { maxx = point1.x; minx = point2.x; }
	else { maxx = point2.x; minx = point1.x; }
	if (point1.y > point2.y) { maxy = point1.y; miny = point2.y; }
	else { maxy = point2.y; miny = point1.y; }

	if (point1.x != point2.x && point1.y != point2.y)
	{
		float m = float(point1.y - point2.y) / (point1.x - point2.x);
		int c = (point1.y) - (m * point1.x);


		if (int(y - (m * x)) <= c + 5 && int(y - (m * x)) >= c - 5 && x <= maxx && x >= minx && y >= miny && y <= maxy) { return true; }
		else { return false; }

	}
	if (point1.x == point2.x) {
		if (y <= maxy && y >= miny && x > point1.x - 4 && x < point1.x + 4) { return true; }
		else return false;
	}

	if (point1.y == point2.y) {
		if (x <= maxx && x >= minx && y > point1.y - 4 && y < point1.y + 4) { return true; }
		else return false;
	}
}
void Line::Save(ofstream& OutFile)
{


	OutFile << type << " " << point1.x << " " << point1.y << " " << point2.x << " " << point2.y << " " << (ShpGfxInfo.isFilled) << " " << to_string(ShpGfxInfo.FillClr.ucRed) << " " << to_string(ShpGfxInfo.FillClr.ucGreen) << " " << to_string(ShpGfxInfo.FillClr.ucBlue) << " " << to_string(ShpGfxInfo.DrawClr.ucRed) << " " << to_string(ShpGfxInfo.DrawClr.ucGreen) << " " << to_string(ShpGfxInfo.DrawClr.ucBlue) << " " << (ShpGfxInfo.BorderWdth) << endl;

}

void Line::Load(ifstream& inFile)
{
	type = "line";
	int x;
	string jump;

	inFile >> x;
	point1.x = x;

	inFile >> x;
	point1.y = x;

	inFile >> x;

	point2.x = x;

	inFile >> x;
	point2.y = x;

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





