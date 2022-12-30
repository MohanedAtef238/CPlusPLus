#include "controller.h"

//Constructor
controller::controller()
{
	pGraph = new Graph;
	pGUI = new GUI;	//Create GUI object
}

//==================================================================================//
//								operations-Related Functions							//
//==================================================================================//
operationType controller::GetUseroperation() const
{
	//Ask the input to get the operation from the user.
	return pGUI->GetUseroperation();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an operation and executes it
operation* controller::createOperation(operationType OpType)
{
	operation* pOp = nullptr;
	
	//According to operation Type, create the corresponding operation object
	switch (OpType)
	{

	case DRAW_RECT:
			pOp = new opAddRect(this);
			break;

		case DRAW_CIRC:
			pOp = new opAddCircle(this);
			break;
		
		case DRAW_TRI:
			pOp = new opAddTriangle(this);
			break;

		case DRAW_LINE:
			pOp = new opAddLine(this);
			break;
		case Change_Draw_Color:
			pOp = new opChangeDrawColor(this);
			break;
		case Change_Fill_Color:
			pOp = new opChangeFillColor(this);
			break;
		case SELECT:
			pOp = new opSelectShape(this);
			break;
		case Delete:
			pOp = new opDeleteShape(this);
			break;
		case DRAW_POLYGON:
			pOp = new opAddPolygon(this);
			break;
		case Draw_Square:
			pOp = new opAddSquare(this);
			break;
		case SAVE:
			pOp = new opSave(this);
			break;
		case LOAD:
			pOp = new opLoad(this);
			break;
		case TO_PLAY:
			pOp = new opToPlayMode(this);

			break;
		
		case EXIT:
			pOp = new opExit(this);
			
			break;
		
		case STATUS:	//a click on the status bar ==> no operation
			break;
	}

	return pOp;
	
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all shapes on the user interface

void controller::ChangeCDrawingColor(color SelectedColor)
{
	pGUI->changeCrntDrawColor(SelectedColor);
}


void controller::ChangeCFillColor(color selectedColor)
{
	pGUI->changeCrntFillColor(selectedColor);
}

shape* controller::GetSelectedFig()
{
	return SelectedFig[0];
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the UI
GUI *controller::GetUI() const
{	return pGUI; }
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the Graph
Graph* controller::getGraph() const
{
	return pGraph;
}

void controller::UpdateInterface() const
{
	pGraph->Draw(pGUI);
}

//Destructor
controller::~controller()
{
	delete pGUI;
	delete pGraph;
	
}



//==================================================================================//
//							Run function											//
//==================================================================================//
void controller::Run()
{
	operationType OpType;
	do
	{
		//1. Ask the GUI to read the required operation from the user
		OpType = GetUseroperation();

		//2. Create an operation coresspondingly
		operation* pOpr = createOperation(OpType);
		 
		//3. Execute the created operation
		if (pOpr)
		{
			pOpr->Execute();//Execute
			delete pOpr;	//operation is not needed any more ==> delete it
			pOpr = nullptr;
		}

		//Update the interface
		UpdateInterface();

	} while (OpType != DONNOT);

}