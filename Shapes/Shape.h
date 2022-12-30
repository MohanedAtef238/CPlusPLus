#pragma once
#include "..\defs.h"
#include "..\GUI\GUI.h"
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include<fstream>



//Base class for all shapes
class shape
{
protected:
	int ID;		//Each shape has an ID
	GfxInfo ShpGfxInfo;	//shape graphis info
	
	/// Add more parameters if needed.

public:
	string type;

	shape();
	shape(GfxInfo shapeGfxInfo);
	virtual ~shape() {}
	void SetSelected(bool s);	//select/unselect the shape
	bool IsSelected() const;	//check whether fig is selected
	GfxInfo getShpGfx()const;
	virtual void Draw(GUI* pUI) const  = 0 ;		//Draw the shape
	virtual bool ClickedInside(int x, int y) const;
	void ChngDrawClr(color Dclr);	//changes the shape's drawing color
	void ChngFillClr(color Fclr);	//changes the shape's filling color
	void setSaved();
	bool IsSaved();
	///The following functions should be supported by the shape class
	///It should be overridden by each inherited shape

	///Decide the parameters that you should pass to each function	


	//virtual void Rotate() = 0;	//Rotate the shape
	//virtual void Resize() = 0;	//Resize the shape
	//virtual void Move() = 0;		//Move the shape

	virtual void Save(ofstream &OutFile) = 0;	//Save the shape parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the shape parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all shape info on the status bar
};

//struct Edge {
//    const Point a, b;
//    const double epsilon = numeric_limits<float>().epsilon();
//    const numeric_limits<double> DOUBLE;
//    const double MIN = DOUBLE.min();
//    const double MAX = DOUBLE.max();
//
//    bool operator()(const Point& p) const
//    {
//        if (a.y > b.y) return Edge{ b, a }(p);
//        if (p.y == a.y || p.y == b.y) return operator()({ p.x, p.y + epsilon });
//        if (p.y > b.y || p.y < a.y || p.x > max(a.x, b.x)) return false;
//        if (p.x < min(a.x, b.x)) return true;
//        auto blue = abs(a.x - p.x) > MIN ? (p.y - a.y) / (p.x - a.x) : MAX;
//        auto red = abs(a.x - b.x) > MIN ? (b.y - a.y) / (b.x - a.x) : MAX;
//        return blue >= red;
//    }
//};
//
//struct Figure {
//    const string  name;
//    const initializer_list<Edge> edges;
//
//    bool contains(const Point& p) const
//    {
//        auto c = 0;
//        for (auto e : edges) if (e(p)) c++;
//        return c % 2 != 0;
//    }
//
//    template<unsigned char W = 3>
//    void check(const initializer_list<Point>& points, ostream& os) const
//    {
//        os << "Is point inside figure " << name << '?' << endl;
//        for (auto p : points)
//            os << "  (" << setw(W) << p.x << ',' << setw(W) << p.y << "): " << boolalpha << contains(p) << endl;
//        os << endl;
//    }
//};
