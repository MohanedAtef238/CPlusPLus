#include "opAddPolygon.h"
#include "..\shapes\Polygon.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opAddPolygon::opAddPolygon(controller* pCont) :operation(pCont)
{}
opAddPolygon::~opAddPolygon()
{}

//Execute the operation
void opAddPolygon::Execute()
{
	Point P1;
	Point P2;
	int sides;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Polygon: Click at center");
	//Read center and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);
	string msg1 = "center is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();
	string msg2 = "What is the number of vertices";
	sides= stoi(pUI->GetSrting());
	pUI->ClearStatusBar();
	//Preapre all Polygon parameters
	GfxInfo PolyGfxInfo;

	//get drawing, filling colors and pen width from the interface
	PolyGfxInfo.DrawClr = pUI->getCrntDrawColor();
	PolyGfxInfo.FillClr = pUI->getCrntFillColor();
	PolyGfxInfo.BorderWdth = pUI->getCrntPenWidth();

	PolyGfxInfo.isFilled = pUI->isFilled();	//default is not filled
	PolyGfxInfo.isSelected = false;	//defualt is not selected


	//Create a rectangle with the above parameters
	RegPolygon* P = new RegPolygon(P1, P2, sides, PolyGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the rectangle to the list of shapes
	pGr->Addshape(P);

}
