#pragma once
#include "operation.h"
#include "..\CMUgraphicsLib\colors.h"
#include "..\shapes/Shape.h"
class opChangeFillColor : public operation
{
	int SelectedColorIndex;
	color SelectedColor;
	bool IsSelected;
	shape* SelectedFigure;
public:
	opChangeFillColor(controller* pCont);
	virtual void ReadActionParameters();

	virtual void Execute();

};