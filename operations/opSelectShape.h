#pragma once
#include "operation.h"
#include "opSelectShape.h"
#include "../GUI/GUI.h"
#include "../controller.h"
#include "../Shapes/Graph.h"
#include "../Shapes/Circle.h"
#include "../Shapes/Rect.h"
#include "../Shapes/Triangle.h"
#include "../Shapes/Line.h"

class opSelectShape : public operation
{
private:
	Point P1;
public:
	opSelectShape(controller* pCont);
	virtual void ReadParameters();
	virtual void Execute();
};