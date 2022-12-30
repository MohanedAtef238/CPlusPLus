#include "opToPlayMode.h"

opToPlayMode::opToPlayMode(controller* pCont) :operation(pCont)
{}
opToPlayMode::~opToPlayMode() {}

void opToPlayMode::Execute() {
	GUI* pUI = pControl->GetUI();
	Graph* pGrp = pControl->getGraph();
	pUI->CreatePlayToolBar();
}