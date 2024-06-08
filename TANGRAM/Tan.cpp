#include "Tan.h"
#include "GUIMyFrame1.h"

Tan::Tan()
{
	visibleInTray = true;
	isHeld = false;
	angle = 0.;
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

void Tan::rotate()
{
	// x = xcos - ysin
	// y = xsin + ycos
	double RadAngle = angle * M_PI / 180;
	for (int i = 0; i < nOfVertices; i++)
	{

		int tempx = rotatedVertices[i].x - centerOfMass.x;
		int tempy = rotatedVertices[i].y - centerOfMass.y;

		rotatedVertices[i].x = tempx * cos(RadAngle) - tempy * sin(RadAngle) + centerOfMass.x;
		rotatedVertices[i].y = tempx * sin(RadAngle) + tempy * cos(RadAngle) + centerOfMass.y;
	}
}

void Tan::drawInWorkspace(wxDC* dc, wxPoint MousePosition, int scale)
{
	centerOfMass = wxPoint(0, 0);
	for (int i = 0; i < nOfVertices; i++)
	{
		centerOfMass.x += vertices[i].x;
		centerOfMass.y += vertices[i].y;

		rotatedVertices[i].x = vertices[i].x;
		rotatedVertices[i].y = vertices[i].y;
	}
	centerOfMass.x /= nOfVertices;
	centerOfMass.y /= nOfVertices;


	if (GUIMyFrame1::QPressed && isHeld)
		angle += -0.5;
	if (GUIMyFrame1::EPressed && isHeld)
		angle += 0.5;
	rotate();
	if (isHeld)
	{
		
		

		tileOffset.x -= centerOfMass.x;
		tileOffset.y -= centerOfMass.y;
		for (int i = 0; i < nOfVertices; i++)
		{
			//vertices[i].x *= scale * workspaceWidth / 721;
			//vertices[i].y *= scale * workspaceHeight / 577;
			vertices[i].x += tileOffset.x;
			vertices[i].y += tileOffset.y;

			rotatedVertices[i].x += tileOffset.x;
			rotatedVertices[i].y += tileOffset.y;

		}
	}
	region = wxRegion(nOfVertices, rotatedVertices);
	dc->DrawPolygon(nOfVertices, rotatedVertices);
	dc->SetBrush(wxBrush(wxColor(255, 0, 0)));
	dc->DrawCircle(centerOfMass, 5);
	dc->DrawText(std::to_string(angle), centerOfMass);
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