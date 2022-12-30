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
#include "../Shapes/Graph.h"

class opDeleteShape : public operation
{
public:
	opDeleteShape(controller* pCont);
	virtual void Execute();
};