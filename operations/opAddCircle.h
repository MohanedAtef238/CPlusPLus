#pragma once

#include "operation.h"
#include "../CMUgraphicsLib/colors.h"

//Add Rectangle operation class
class opAddCircle : public operation
{
public:
	opAddCircle(controller* pCont);
	virtual ~opAddCircle();

	//Add rectangle to the controller
	virtual void Execute();

};
