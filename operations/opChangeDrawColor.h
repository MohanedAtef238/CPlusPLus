#pragma once
#include "operation.h"
#include "..\CMUgraphicsLib\colors.h"
#include "..\shapes/Shape.h"
class opChangeDrawColor : public operation
{
	int SelectedColorIndex;
	color SelectedColor;
	bool IsSelected;
	shape* SelectedFigure;
public:
	opChangeDrawColor(controller* pCont);
	virtual void ReadActionParameters();

	//Add rectangle to the controller
	virtual void Execute();

};