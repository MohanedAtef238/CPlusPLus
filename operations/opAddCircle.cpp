#include "opAddCircle.h"
#include "..\shapes\Circle.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opAddCircle::opAddCircle(controller* pCont) :operation(pCont)
{}
opAddCircle::~opAddCircle()
{}

//Execute the operation
void opAddCircle::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();
	pUI->PrintMessage("New Circle: Click at center");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "Center is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at radius";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();

	//Preapre all rectangle parameters
	GfxInfo CircGfxInfo;

	//get drawing, filling colors and pen width from the interface
	CircGfxInfo.DrawClr = pUI->getCrntDrawColor();
	CircGfxInfo.FillClr = pUI->getCrntFillColor();
	CircGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	CircGfxInfo.isFilled = pUI->isFilled();
	//default is not filled
	CircGfxInfo.isSelected = false;	//defualt is not selected

	//Create a rectangle with the above parameters
	Circle* R = new Circle(P1, P2, CircGfxInfo);

	

	//Add the rectangle to the list of shapes
	pGr->Addshape(R);

}
