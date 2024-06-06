#include "Tan.h"
#include "GUIMyFrame1.h"

Tan::Tan()
{
	visibleInTray = true;
	isHeld = false;
}

void Tan::addPoints(wxPoint p1, wxPoint p2, wxPoint p3)
{
	nOfVertices = 3;
	if (vertices != nullptr) delete[] vertices;
	vertices = new wxPoint[nOfVertices];
	vertices[0] = p1;
	vertices[1] = p2;
	vertices[2] = p3;
}

void Tan::addPoints(wxPoint p1, wxPoint p2, wxPoint p3, wxPoint p4)
{
	nOfVertices = 4;
	if (vertices != nullptr) delete[] vertices;
	vertices = new wxPoint[nOfVertices];
	vertices[0] = p1;
	vertices[1] = p2;
	vertices[2] = p3;
	vertices[3] = p4;
}

void Tan::rotate(wxPoint& point, double angle)
{
	// x = xcos - ysin
	// y = xsin + ycos
	angle *= M_PI / 180;
	double tempx = point.x - centerOfMass.x;
	double tempy = point.y - centerOfMass.y;
	point.x = tempx * cos(angle) - tempy * sin(angle) + centerOfMass.x;
	point.y = tempx * sin(angle) + tempy * cos(angle) + centerOfMass.y;
}

void Tan::drawInWorkspace(wxDC* dc, wxPoint MousePosition, int scale, bool QPressed, bool EPressed)
{

	centerOfMass = wxPoint(0, 0);
	for (int i = 0; i < nOfVertices; i++)
	{
		centerOfMass.x += vertices[i].x;
		centerOfMass.y += vertices[i].y;
	}
	centerOfMass.x /= nOfVertices;
	centerOfMass.y /= nOfVertices;

	tileOffset.x -= isHeld ? centerOfMass.x : 0;
	tileOffset.y -= isHeld ? centerOfMass.y : 0;

	for (int i = 0; i < nOfVertices; i++)
	{
		
		if(isHeld) rotate(vertices[i], angle);
		vertices[i].x += isHeld ? tileOffset.x : 0;
		vertices[i].y += isHeld ? tileOffset.y : 0;
		//vertices[i].x *= scale * workspaceWidth / 721;
		//vertices[i].y *= scale * workspaceHeight / 519;
		if (isHeld)
		{
			if (QPressed)
				angle -= 0.5;
			if (EPressed)
				angle += 0.5;
		}
	}
	region = wxRegion(nOfVertices, vertices);
	dc->DrawPolygon(nOfVertices, vertices);
	 //dc->SetBrush(wxBrush(wxColor(255, 0, 0)));
	 //dc->DrawCircle(centerOfMass, 5);
}

void Tan::drawInTray(wxDC* dc, wxPoint MousePosition, int scale)
{

	for (int i = 0; i < nOfVertices; i++)
	{
		vertices[i].x *= scale;
		vertices[i].y *= scale;
	}
	region = wxRegion(nOfVertices, vertices);
	dc->DrawPolygon(nOfVertices, vertices);
}

bool Tan::checkMousePosition(wxPoint mousePosition)
{
	if (region.Contains(mousePosition) == wxInRegion)
		return true;
	else
	{
		return false;
	}
}

Tan::~Tan()
{
	delete vertices;
}