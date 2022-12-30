#include "opSelectShape.h"
opSelectShape::opSelectShape(controller* pCont) :operation(pCont)
{}

void opSelectShape::ReadParameters()
{
	//Get a Pointer to the Input 
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage(" Selected a Figure ");
	pUI->GetPointClicked(P1.x, P1.y);
	pUI->ClearStatusBar();
}

//Execute the action
void opSelectShape::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	color Color = pUI->getCrntDrawColor();
	ReadParameters();
	shape* Selected = pGraph->Getshape(P1.x, P1.y);

	if (Selected == NULL)
	{
		pUI->PrintMessage("No figure has been selected");
	}
	else pGraph->SelectaShape(Selected, Color);
}