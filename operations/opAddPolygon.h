#pragma once

#include "operation.h"

//Add Rectangle operation class
class opAddPolygon : public operation
{
public:
	opAddPolygon(controller* pCont);
	virtual ~opAddPolygon();

	//Add rectangle to the controller
	virtual void Execute();
};
