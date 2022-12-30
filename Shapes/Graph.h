#pragma once
#include "Shape.h"
#include <fstream>
#include <vector>
using namespace std;

//forward decl
class GUI;	

//A class that is responsible on everything related to shapes
class Graph
{
private:
	vector <shape*> shapesList; //a container to hold all shapes							   
	shape* selectedShape;	//pointer to the currently selected shape
public:										
	Graph();
	~Graph();
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	void Draw(GUI* pUI) const;			//Draw the graph (draw all shapes)
	void DeleteShapeFromList();
	shape* Getshape(int x, int y) const; //Search for a shape given a point inside the shape
	void SelectaShape(shape* Selected, color oldColor);
	void Save(ofstream& outfile);	//Save all shapes to a file
	void load(ifstream& inputfile, GUI* pUI, Graph* pGr);	//Load all shapes from a file
	bool CanExit();
};
