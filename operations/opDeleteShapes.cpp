#include "opDeleteShape.h"
opDeleteShape::opDeleteShape(controller* pCont) :operation(pCont){}
void opDeleteShape::Execute()
{
	Graph* pGraph = pControl->getGraph();
	pGraph->DeleteShapeFromList();
}