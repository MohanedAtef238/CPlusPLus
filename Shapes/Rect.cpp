#include "Rect.h"

Rect::Rect()
{

}

Rect::Rect(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	type = "Rect";
}

Rect::~Rect()
{}

void Rect::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawRect(Corner1, Corner2, ShpGfxInfo);
}

bool Rect::ClickedInside(int x, int y) const
{
	float Minx = min(Corner1.x, Corner2.x);
	float Maxx = max(Corner1.x, Corner2.x);
	float Miny = min(Corner1.y, Corner2.y);
	float Maxy = max(Corner1.y, Corner2.y);

	if (x<Maxx && x >Minx && y<Maxy && y >Miny)
	{
		return true;
	}
	else
	{
		return false;
	}

}

void Rect::Save(ofstream& OutFile)
{
	OutFile << type << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << (ShpGfxInfo.isFilled) << " " << to_string(ShpGfxInfo.FillClr.ucRed) << " " << to_string(ShpGfxInfo.FillClr.ucGreen) << " " << to_string(ShpGfxInfo.FillClr.ucBlue) << " " << to_string(ShpGfxInfo.DrawClr.ucRed) << " " << to_string(ShpGfxInfo.DrawClr.ucGreen) << " " << to_string(ShpGfxInfo.DrawClr.ucBlue) << " " << (ShpGfxInfo.BorderWdth) << endl;

}

void Rect::Load(ifstream& inFile)
{
	type = "Rect";
	int x;
	string jump;

	inFile >> x;
	Corner1.x = x;

	inFile >> x;
	Corner1.y = x;

	inFile >> x;

	Corner2.x = x;

	inFile >> x;
	Corner2.y = x;

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
