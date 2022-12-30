#pragma once

#include "DEFS.h"
#include "Shapes/Shape.h"
#include "Shapes\Graph.h"
#include "GUI\GUI.h"
#include "operations/operation.h"
#include "operations\opAddRect.h"
#include "operations\opAddCircle.h"
#include "operations/opAddTriangle.h"
#include "operations/opAddLine.h"
#include "operations/opAddPolygon.h"
#include "operations/opChangeDrawColor.h"
#include "operations/opChangeFillColor.h"
#include "operations/opSelectShape.h"
#include "operations/opDeleteShape.h"
#include "operations/opAddSquare.h"
#include "operations/opLoad.h"
#include "operations/opSave.h"
#include "operations/opExit.h"
#include "operations/opToPlayMode.h"
class operation; //forward declaration

//Main class that manages everything in the application.
class controller
{
	enum { MaxFigCount = 200 };
	int SelectedCount;
	Graph* pGraph;	//pointe to the grapg
	GUI* pGUI;		//Pointer to UI class
	shape* SelectedFig[MaxFigCount];
	

public:	
	controller(); 
	~controller();
	
	// -- operation-Related Functions
	//Reads the input command from the user and returns the corresponding operation type
	operationType GetUseroperation() const;
	operation* createOperation(operationType) ; //Creates an operation
	void Run();
	
	Graph* getGraph() const;
	
	// -- Interface Management Functions
	GUI *GetUI() const; //Return pointer to the UI

	void ChangeCDrawingColor(color);
	void ChangeCFillColor(color);
	shape* GetSelectedFig();
	void UpdateInterface() const;	//Redraws all the drawing window	
};

