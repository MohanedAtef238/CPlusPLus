#include "opSave.h"
#include "../Shapes/Line.h"
#include "../Shapes/Circle.h"
#include "../Shapes/Rect.h"
#include "../controller.h"
#include "../GUI/GUI.h"
#include "..\CMUgraphicsLib\colors.h"
#include "..\shapes/Shape.h"
#include "..\CMUgraphicsLib\auxil.h"	// where Pause is found
opSave::opSave(controller* pCont) :operation(pCont)
{
}

void opSave::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	
	GUI* pIn = pControl->GetUI();
	
	pIn->PrintMessage("Enter filename ");

		filename = pIn->GetSrting();
		filename += ".txt";
		//filename = "Graph.san";
		pIn->PrintMessage("Graph will be saved to .. ");
		Pause(500);

		pIn->PrintMessage(filename);

		Pause(500);
	pIn->ClearStatusBar();
}

string opSave::getFilename()
{
	return filename;
}

void opSave::Execute()
{

	GUI* pIn = pControl->GetUI();
	ReadActionParameters();
	ofstream file1(filename);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the rectangle to the list of shapes
	pGr->Save(file1);

}
