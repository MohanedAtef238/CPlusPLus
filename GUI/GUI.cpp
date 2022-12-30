#include "GUI.h"
#include "../Shapes/Shape.h"

GUI::GUI()
{
	//Initialize user interface parameters
	InterfaceMode = MODE_DRAW;

	width = 1300;
	height = 700;
	wx = 5;
	wy = 5;


	StatusBarHeight = 50;
	ToolBarHeight = 50;
	MenuIconWidth = 80;

	DrawColor = BLUE;	//default Drawing color
	FillColor = YELLOW;	//default Filling color
	MsgColor = BLACK;		//Messages color
	BkGrndColor = MOCCASIN;	//Background color
	HighlightColor = MAGENTA;	//This color should NOT be used to draw shapes. use if for highlight only
	StatusBarColor = LIGHTSEAGREEN;
	PenWidth = 3;	//default width of the shapes frames
	IsShapeFilled = 0;


	//Create the output window
	pWind = CreateWind(width, height, wx, wy);
	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - PAINT ^ ^ PLAY - - - - - - - - - -");

	CreateDrawToolBar();
	CreateStatusBar();
}




//======================================================================================//
//								Input Functions										//
//======================================================================================//
void GUI::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string GUI::GetSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if( Label.size() > 0)	
				Label.resize(Label.size() - 1);
			else
				Key = '\0';		
		else
			Label += Key;
		PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired operation
operationType GUI::GetUseroperation() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < ToolBarHeight)
		{
			//Check whick Menu icon was clicked
			//==> This assumes that menu icons are lined up horizontally <==
			int ClickedIconOrder = (x / MenuIconWidth);
			//Divide x coord of the point clicked by the menu icon width (int division)
			//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

			switch (ClickedIconOrder)
			{
			case ICON_CHANGE_COLOR: return Change_Draw_Color;
			case ICON_CHANGE_FILL_COLOR: return Change_Fill_Color;
			case ICON_RECT: return DRAW_RECT;
			case ICON_CIRC: return DRAW_CIRC;
			case ICON_TRI: return DRAW_TRI;
			case ICON_LINE: return DRAW_LINE;
			case ICON_POLYGON: return DRAW_POLYGON;
			case ICON_SQUARE: return Draw_Square;
			case ICON_Save: return SAVE;
			case ICON_PLAY: return TO_PLAY;
			case ICON_Load: return LOAD;
			case ICON_Select: return SELECT;
			case ICON_DELETE: return Delete;
			case ICON_EXIT: return EXIT;
			case ICON_PALETTE: if (x > 630 & x < (630 + 10))
			{
				return COLOR_RED;
			}
							 else if (x > (630 + 10+80) & x < (630 + 20+80))
			{
				return COLOR_GREEN;
			}
							 else if (x > (630 + 20+80) & x < (630 + 30+80))
			{
				return COLOR_BLACK;
			}
							 else if (x > (630 + 30+80) & x < (630 + 40+80))
			{
				return COLOR_BLUE;
			}
							 else if (x > (630 + 40+80) & x < (630 + 50+80))
			{
				return COLOR_YELLOW;
			}
							 else if (x > (630 + 50+80) & x < (630 + 60+80))
			{
				return COLOR_VIOLET;
			}
							 else if (x > (630 + 60+80) & x < (630 + 70+80))
			{
				return COLOR_TURQUOISE;
			}
							 else if (x > (630 + 70+80) & x < (630 + 80+80))
			{
				return COLOR_WHITE;
			}
							 else { return COLOR_MOCASSIN; }
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding operation
		//just for now. This should be updated
		if (y >= 0 && y < ToolBarHeight)
		{
			//Check whick Menu icon was clicked
			//==> This assumes that menu icons are lined up horizontally <==
			int ClickedIconOrder = (x / MenuIconWidth);
			//Divide x coord of the point clicked by the menu icon width (int division)
			//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

			switch (ClickedIconOrder)
			{
			case ICONEXIT: return EXIT;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	}


////////////////////////////////////////////////////



//======================================================================================//
//								Output Functions										//
//======================================================================================//

window* GUI::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(BkGrndColor);
	pW->SetPen(BkGrndColor, 1);
	pW->DrawRectangle(0, ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateStatusBar() const
{
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}
void GUI::ClearToolBar() const
{
	pWind->SetPen(BkGrndColor, 2);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(0, 0, width, ToolBarHeight + 1);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateDrawToolBar() 
{
	InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu icon
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuIcon
	string MenuIconImages[DRAW_ICON_COUNT];
	MenuIconImages[ICON_CHANGE_COLOR] = "images\\MenuIcons\\Change_Draw_Color.jpg";
	MenuIconImages[ICON_CHANGE_FILL_COLOR] = "images\\MenuIcons\\Change_Fill_Color.jpg";
	MenuIconImages[ICON_Select] = "images\\MenuIcons\\Icon_Select.jpg";
	MenuIconImages[ICON_DELETE] = "images\\MenuIcons\\DeleteIcon.jpg";
	MenuIconImages[ICON_RECT] = "images\\MenuIcons\\Menu_Rect.jpg";
	MenuIconImages[ICON_CIRC] = "images\\MenuIcons\\Menu_Circ.jpg";
	MenuIconImages[ICON_TRI] = "images\\MenuIcons\\Menu_TRI.jpg";
	MenuIconImages[ICON_LINE] = "images\\MenuIcons\\Menu_Line.jpg";
	MenuIconImages[ICON_Save] = "images\\MenuIcons\\Menu_Save.jpg";
	MenuIconImages[ICON_Load] = "images\\MenuIcons\\Menu_Load.jpg";
	MenuIconImages[ICON_POLYGON] = "images\\MenuIcons\\Menu_POLYGON.jpg";
	MenuIconImages[ICON_SQUARE] = "images\\MenuIcons\\Square.jpg";
	MenuIconImages[ICON_EXIT] = "images\\MenuIcons\\Menu_Exit.jpg";
	MenuIconImages[ICON_PALETTE] = "images\\MenuIcons\\Menu_Palette.jpg";
	MenuIconImages[ICON_PLAY] = "images\\MenuIcons\\playmode.jpg";

	//TODO: Prepare images for each menu icon and add it to the list

	//Draw menu icon one image at a time
	for (int i = 0; i < DRAW_ICON_COUNT; i++)
		pWind->DrawImage(MenuIconImages[i], i * MenuIconWidth, 0, MenuIconWidth, ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::CreatePlayToolBar() 
{
	InterfaceMode = MODE_PLAY;
	ClearToolBar();
	string MenuIconImages[PLAY_ICON_COUNT];
	MenuIconImages[ICONSELECT] = "images\\MenuIcons\\Change_Fill_Color.jpg";
	MenuIconImages[ICONEXIT] = "images\\MenuIcons\\Menu_Exit.jpg";
	for (int i = 0; i < PLAY_ICON_COUNT; i++)
		pWind->DrawImage(MenuIconImages[i], i * MenuIconWidth, 0, MenuIconWidth, ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::ClearDrawArea() const
{
	pWind->SetPen(BkGrndColor, 1);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(0, ToolBarHeight, width, height - StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(MsgColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, height - (int)(0.75 * StatusBarHeight), msg);
}
bool GUI::isFilled()
{
	return IsShapeFilled;
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntDrawColor() const	//get current drwawing color
{
	return DrawColor;
}
//void GUI::DrawPolygon(Point P1, int vertices, GfxInfo RectGfxInfo) const
//{
//}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntFillColor() const	//get current filling color
{
	return FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int GUI::getCrntPenWidth() const		//get current pen width
{
	return PenWidth;
}

void GUI::changeCrntDrawColor(color SelectedColor)
{
	DrawColor = SelectedColor;
}
void GUI::changeCrntFillColor(color selectedColor)
{
	IsShapeFilled = true;
	FillColor = selectedColor;
}


//======================================================================================//
//								shapes Drawing Functions								//
//======================================================================================//

void GUI::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const
{
	color DrawingClr;
	if (RectGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

void GUI::DrawCircle(Point P1, Point P2, GfxInfo RectGfxInfo) const
	{
		color DrawingClr;
		if (RectGfxInfo.isSelected)	//shape is selected
			DrawingClr = HighlightColor; //shape should be drawn highlighted
		else
			DrawingClr = RectGfxInfo.DrawClr;

		pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

		drawstyle style;
		if (RectGfxInfo.isFilled)
		{
			style = FILLED;
			pWind->SetBrush(RectGfxInfo.FillClr);
		}
		else
			style = FRAME;
		double radius = sqrt(pow((P1.x - P2.x), 2) + pow((P1.y - P2.y), 2));
		pWind->DrawCircle(P1.x, P1.y, radius, style);
}

void GUI::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo RectGfxInfo) const
{
	color DrawingClr;
	if (RectGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}


void GUI::DrawLine(Point P1, Point P2, GfxInfo RectGfxInfo) const
{
	color DrawingClr;
	if (RectGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);
}

void GUI::DrawPolygon(vector<int>  xx, vector<int> yy, int vertices, GfxInfo PolyGfxInfo) const
{
	color DrawingClr;

	DrawingClr = PolyGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, PolyGfxInfo.BorderWdth);    //Set Drawing color & width

	drawstyle style;
	if (PolyGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(PolyGfxInfo.FillClr);
	}
	else
	style = FRAME;
	int *x = &xx[0];
	int *y = &yy[0];
	pWind->DrawPolygon(x, y, vertices, style);

}



//////////////////////////////////////////////////////////////////////////////////////////
GUI::~GUI()
{
	delete pWind;
}

