#include "opExit.h"

opExit::opExit(controller* pCont):operation(pCont)
{}
opExit::~opExit() {}

void opExit::Execute() {
	GUI* pUI = pControl->GetUI();
	Graph* pGrp = pControl->getGraph();
	cout << pGrp->CanExit();
	if (pGrp->CanExit()){
		exit(0);
	
	}else{
		pUI->PrintMessage("you can not exit");
	}
}