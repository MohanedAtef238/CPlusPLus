#include "shape.h"

shape::shape() {};
shape::shape(GfxInfo shapeGfxInfo)
{ 
	ShpGfxInfo = shapeGfxInfo;	//Default status is non-filled.
}

void shape::SetSelected(bool s)
{	ShpGfxInfo.isSelected = s; }

bool shape::IsSelected() const
{	return ShpGfxInfo.isSelected; }

GfxInfo shape::getShpGfx() const
{
	return ShpGfxInfo;
}


bool shape::ClickedInside(int x, int y) const
{
	return false;
}

void shape::ChngDrawClr(color Dclr)
{	ShpGfxInfo.DrawClr = Dclr; }

void shape::ChngFillClr(color Fclr)
{	
	ShpGfxInfo.isFilled = true;
	ShpGfxInfo.FillClr = Fclr; 
}

void shape::setSaved()
{
	ShpGfxInfo.isSaved = true;
}

bool shape::IsSaved()
{
	return ShpGfxInfo.isSaved;
}

