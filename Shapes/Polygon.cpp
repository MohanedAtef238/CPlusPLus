#include "Polygon.h"
#include <cmath>

RegPolygon::RegPolygon()
{

}

RegPolygon::RegPolygon(Point p1, Point p2, int nsides, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	center = p1;
    StPt = p2;
    sides = nsides;
    SetVertices();
    type = "RegPoly";
}

RegPolygon::~RegPolygon()
{}

void RegPolygon::SetVertices()
{
    float pi = 3.14159265358979323846;
    vector<int> VerX = { (StPt.x - center.x) };
    vector<int> VerY = { (StPt.y - center.y) };
    for (int i = 0; i < sides; i++)
    {
        int vx = ceil((VerX[i] * cos((2 * pi) / sides)) - (VerY[i] * sin((2 * pi) / sides))); //Matrix transofmation after translating to origin
        int vy = ceil((VerX[i] * sin((2 * pi) / sides)) + (VerY[i] * cos((2 * pi) / sides)));

        VerX.push_back(vx);
        VerY.push_back(vy);
    }
    for (int i = 0; i < sides; i++) { VerX[i] += center.x; VerY[i] += center.y; }
    Vertexx = VerX;
    Vertexy = VerY;

}

void RegPolygon::Draw(GUI* pUI) const
{
	pUI->DrawPolygon(Vertexx, Vertexy,sides, ShpGfxInfo);
}

bool RegPolygon::ClickedInside(int x, int y) const
{

        int i, j, c = 0;
        for (i = 0, j = sides - 1; i < sides; j = i++) {
            if (((Vertexy[i] > y) != (Vertexy[j] > y)) &&
                (x < (Vertexx[j] - Vertexx[i]) * (y - Vertexy[i]) / (Vertexy[j] - Vertexy[i]) + Vertexx[i]))
                c = !c;
        }
        return c;
}

void RegPolygon::Save(ofstream& OutFile)
{
    OutFile << type << " " <<sides<<" "<<center.x << " " << center.y << " " << StPt.x << " " << StPt.y << " " << ShpGfxInfo.isFilled;
    OutFile << " " << to_string(ShpGfxInfo.FillClr.ucRed) << " " << to_string(ShpGfxInfo.FillClr.ucGreen) << " " << to_string(ShpGfxInfo.FillClr.ucBlue) << " " << to_string(ShpGfxInfo.DrawClr.ucRed) << " " << to_string(ShpGfxInfo.DrawClr.ucGreen) << " " << to_string(ShpGfxInfo.DrawClr.ucBlue) << " " << (ShpGfxInfo.BorderWdth) << endl;
}

void RegPolygon::Load(ifstream& inFile)
{
	type = "RegPoly";
	int x;
	string jump;

	inFile >> x;
	sides = x;
	inFile >> x;
	center.x = x;

	inFile >> x;
	center.y = x;

	inFile >> x;

	StPt.x = x;

	inFile >> x;
	StPt.y = x;

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
	SetVertices();



}


