#include "Graph.h"
#include "../GUI/GUI.h"
#include <vector>
#include "Graph.h"
#include "../GUI/GUI.h"
#include <sstream>
#include "..\controller.h"
#include "..\Shapes\Circle.h"
#include "..\Shapes\Line.h"
#include "..\Shapes\Rect.h"
#include "..\Shapes\Triangle.h"
#include"..\Shapes\Polygon.h"
#include"..\Shapes\Square.h"
#include "Shape.h"
#include <iostream>
Graph::Graph()
{
	selectedShape = nullptr;
}

Graph::~Graph()
{
}

//==================================================================================//
//						shapes Management Functions								//
//==================================================================================//

//Add a shape to the list of shapes
void Graph::Addshape(shape* pShp)
{
	//Add a new shape to the shapes vector
	shapesList.push_back(pShp);	
}
////////////////////////////////////////////////////////////////////////////////////
//Draw all shapes on the user interface
void Graph::Draw(GUI* pUI) const
{
	pUI->ClearDrawArea();
	for (auto shapePointer : shapesList)
		shapePointer->Draw(pUI);
}

void Graph::DeleteShapeFromList()
{
	int size, count;
	size = shapesList.size();
	count = 0;
	for (auto &shapePointer : shapesList)
	{
		
		if (shapePointer->IsSelected())
		{
			//delete &shapePointer;
			shapesList.erase(shapesList.begin()+count);
			count--;
		}
		count++;
	}
}


shape* Graph::Getshape(int x, int y) const
{
	//If a shape is found return a pointer to it.
	//if this point (x,y) does not belong to any shape return NULL
	for (shape* aShape : shapesList) {
		if (aShape->ClickedInside(x, y))
		{
			return aShape;

		}
	}
	///Add your code here to search for a shape given a point x,y	
	return nullptr;
}

void Graph::SelectaShape(shape* Selected, color oldColor)
{
	if (Selected->IsSelected())
	{
		selectedShape = Selected;
		Selected->SetSelected(false);
		Selected->ChngDrawClr(oldColor);
	}
	else
	{
		Selected->SetSelected(true);
		Selected->ChngDrawClr(MAGENTA);
	}
}
void Graph::Save(ofstream& outfile)
{
	outfile << shapesList.size() << endl;
	for (auto& shapePointer : shapesList)
	{
		shapePointer->Save(outfile);
		//outfile<<GetshapeInfo(shapePointer)<<endl;
		shapePointer->setSaved();

	}

	outfile.close();
}

void Graph::load(ifstream& inputfile, GUI* pUI, Graph* pGr)
{
	string x;
	string type;
	int noOfShapes;

	inputfile >> noOfShapes;
	int y = 0;
	shape* p;

	for (int i = 0; i < noOfShapes; i++)
	{
		y++;
		/*stringstream ss(x);
		vector<string> v;
		while (ss.good()) {
			string substr;
			getline(ss, substr, ',');
			v.push_back(substr);
		}*/

		string z;
		inputfile >> type;
		if (type == "Line")
		{
			p = new Line();
			p->Load(inputfile);
			Addshape(p);
		}
		else if (type == "Circle")
		{
			p = new Circle();

			p->Load(inputfile);

			Addshape(p);
		}
		else if (type == "Triangle")
		{
			p = new Triangle();
			p->Load(inputfile);
			Addshape(p);
		}
		else if (type == "Rect")
		{

			p = new Rect();
			p->Load(inputfile);
			Addshape(p);
		}
		else if (type == "RegPoly")
		{
			p = new RegPolygon();
			p->Load(inputfile);
			Addshape(p);

		}
		else if (type =="Square")
		{
			p = new Square();
			p->Load(inputfile);
			Addshape(p);
		}




	}

	inputfile.close();
}

bool Graph::CanExit()
{
	if (shapesList.size() > 0) {
		for (auto* shape : shapesList) {
			if ((shape->IsSaved()) == true)
				return true;
		}
	}
	else
		return false;
}


