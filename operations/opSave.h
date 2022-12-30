

#pragma once
#include "operation.h"
#include "..\CMUgraphicsLib\colors.h"
#include "..\shapes/Shape.h"
class opSave : public operation
{
	int selectSave;
	string filename;

public:
	opSave(controller* pCont);
	virtual void ReadActionParameters();
	string getFilename();
	//Add rectangle to the controller
	virtual void Execute();

};