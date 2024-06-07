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

void Tan::rotate(wxPoint* vertices, int nOfVertices, double angle)
{
	// x = xcos - ysin
	// y = xsin + ycos
	angle *= M_PI / 180;
	for (int i = 0; i < nOfVertices; i++)
	{
		int tempx = vertices[i].x - centerOfMass.x;
		int tempy = vertices[i].y - centerOfMass.y;

		vertices[i].x = tempx * cos(angle) - tempy * sin(angle) + centerOfMass.x;
		vertices[i].y = tempx * sin(angle) + tempy * cos(angle) + centerOfMass.y;
	}

}

void Tan::drawInWorkspace(wxDC* dc, wxPoint MousePosition, int scale, bool QPressed, bool EPressed)
{
	angle = 0;
	centerOfMass = wxPoint(0, 0);
	for (int i = 0; i < nOfVertices; i++)
	{
		centerOfMass.x += vertices[i].x;
		centerOfMass.y += vertices[i].y;
	}
	centerOfMass.x /= nOfVertices;
	centerOfMass.y /= nOfVertices;


	if (isHeld)
	{
		tileOffset.x -= centerOfMass.x;
		tileOffset.y -= centerOfMass.y;
		if (GUIMyFrame1::QPressed)
			angle = -1;
		if (GUIMyFrame1::EPressed)
			angle = 1;
		rotate(vertices, nOfVertices, angle);
		for (int i = 0; i < nOfVertices; i++)
		{
			//vertices[i].x *= scale * workspaceWidth / 721;
			//vertices[i].y *= scale * workspaceHeight / 577;
			vertices[i].x += tileOffset.x;
			vertices[i].y += tileOffset.y;
		}
	}
	region = wxRegion(nOfVertices, vertices);
	dc->DrawPolygon(nOfVertices, vertices);
	dc->SetBrush(wxBrush(wxColor(255, 0, 0)));
	dc->DrawCircle(centerOfMass, 5);
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