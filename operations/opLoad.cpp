
#include "opLoad.h"
#include "../Shapes/Line.h"
#include "../Shapes/Circle.h"
#include "../Shapes/Rect.h"
#include "../controller.h"
#include "../GUI/GUI.h"
#include "..\CMUgraphicsLib\colors.h"
#include "..\shapes/Shape.h"
#include "..\CMUgraphicsLib\auxil.h"	// where Pause is found
opLoad::opLoad(controller* pCont) :operation(pCont)
{
}

void opLoad::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	GUI* pIn = pControl->GetUI();
	pIn->PrintMessage("Enter filename");
	Pause(500);
	filename = pIn->GetSrting();
	filename += ".txt";
	//opSave* s;
	//string file = "Graph.san";
		//s->getFilename();
	setFilename(filename);
	pIn->PrintMessage("Loading... ");


	Pause(500);
	pIn->ClearStatusBar();
}



void opLoad::Execute()
{
	GUI* pOut = pControl->GetUI();
	ReadActionParameters();

	ifstream file1(filename);
	if (file1) {
		//Get a pointer to the graph
		Graph* pGr = pControl->getGraph();
		//Add the rectangle to the list of shapes
		pGr->load(file1, pOut, pGr);
	}
	else {
		string error = "hmmm no such file as " + filename;
		pOut->PrintMessage(error);
		Pause(500);

	}
}

void opLoad::setFilename(string f)
{
	filename = f;
}
