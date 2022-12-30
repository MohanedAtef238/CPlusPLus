#pragma once
#pragma once
#include "../controller.h"
#include "operation.h"
#include "../GUI/GUI.h"
#include "../controller.h"
#include "../Shapes/Graph.h"
#include "../Shapes/Graph.h"

class opToPlayMode : public operation
{
public:
	opToPlayMode(controller* pCont);
	~opToPlayMode();
	//Add rectangle to the controller
	void Execute();

};