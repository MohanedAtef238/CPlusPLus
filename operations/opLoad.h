

#pragma once
#include "operation.h"
#include "..\CMUgraphicsLib\colors.h"
#include "..\shapes/Shape.h"
#include "..\Shapes\Graph.h"
#include "opSave.h"
class opLoad : public operation
{
	int selectSave;
	string filename;
public:
	opLoad(controller* pCont);
	virtual void ReadActionParameters();
	void setFilename(string f);
	//Add rectangle to the controller
	virtual void Execute();

};