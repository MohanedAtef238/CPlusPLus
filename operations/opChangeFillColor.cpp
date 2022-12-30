#include "opChangeFillColor.h"
#include "../Shapes/Line.h"
#include "../Shapes/Circle.h"
#include "../Shapes/Rect.h"
#include "../controller.h"
#include "../GUI/GUI.h"
#include "..\CMUgraphicsLib\colors.h"
#include "..\shapes/Shape.h"

opChangeFillColor::opChangeFillColor(controller* pCont) :operation(pCont)
{
	IsSelected = false;
}

void opChangeFillColor::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	SelectedFigure = pControl->GetSelectedFig();
	if (SelectedFigure == NULL)
	{
		pUI->PrintMessage("Select Color to Change Current Fill Color");
	}
	else
	{
		pUI->PrintMessage("Select Color to Change Fill Color of Selected Figure");
	}
	SelectedColorIndex = pControl->GetUseroperation();
	pUI->ClearStatusBar();
}

void opChangeFillColor::Execute()
{
	GUI* pUI = pControl->GetUI();
	ReadActionParameters();
	if (SelectedColorIndex == 9)
	{
		SelectedColor = RED;
		IsSelected = true;
		pUI->PrintMessage("Current Drawing Color changed to RED");
	}
	else if (SelectedColorIndex == 10)
	{
		SelectedColor = GREEN;
		IsSelected = true;
		pUI->PrintMessage("Current Drawing Color changed to GREEN");
	}
	else if (SelectedColorIndex == 11)
	{
		SelectedColor = BLACK;

		IsSelected = true;
		pUI->PrintMessage("Current Drawing Color changed to BLACK");
	}
	else if (SelectedColorIndex == 12)
	{
		SelectedColor = BLUE;
		IsSelected = true;
		pUI->PrintMessage("Current Drawing Color changed to BLUE");
	}
	else if (SelectedColorIndex == 13)
	{
		SelectedColor = YELLOW;
		IsSelected = true;
		pUI->PrintMessage("Current Drawing Color changed to YELLOW");
	}
	else if (SelectedColorIndex == 14)
	{
		SelectedColor = VIOLET;
		IsSelected = true;
		pUI->PrintMessage("Current Drawing Color changed to VIOLET");
	}
	else if (SelectedColorIndex == 15)
	{
		SelectedColor = TURQUOISE;
		IsSelected = true;
		pUI->PrintMessage("Current Drawing Color changed to TURQUOISE");
	}
	else if (SelectedColorIndex == 16)
	{
		SelectedColor = WHITE;
		IsSelected = true;
		pUI->PrintMessage("Current Drawing Color changed to WHITE");
	}
	else
	{
		pUI->PrintMessage("No Color has been selected");
	}

	if (IsSelected)
	{
		pControl->ChangeCFillColor(SelectedColor);
		//if (!SelectedColor) pOut->PrintMessage("Current Fill Color changed to No Fill");
	}
}
