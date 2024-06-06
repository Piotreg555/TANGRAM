#include "GUIMyFrame1.h"

void GUIMyFrame1::setTray()
{

	int w = panelTray->GetSize().x;
	int h = -panelTray->GetSize().y;
	tan1.addPoints(
		wxPoint(-w / 3, h / 3),
		wxPoint(-w / 3, -h / 3),
		wxPoint(0, 0));
	tan2.addPoints(
		wxPoint(-w / 3, h / 3),
		wxPoint(w / 3, h / 3),
		wxPoint(0, 0));
	tan3.addPoints(
		wxPoint(0, 0),
		wxPoint(w / 6, -h / 6),
		wxPoint(w / 6, h / 6));
	tan4.addPoints(
		wxPoint(w / 6, -h / 6),
		wxPoint(w / 3, 0),
		wxPoint(w / 3, h / 3),
		wxPoint(w / 6, h / 6));
	tan5.addPoints(
		wxPoint(0, -h / 3),
		wxPoint(w / 3, -h / 3),
		wxPoint(w / 3, 0));
	tan6.addPoints(
		wxPoint(0, -h / 3),
		wxPoint(w / 6, -h / 6),
		wxPoint(0, 0),
		wxPoint(-w / 6, -h / 6));
	tan7.addPoints(
		wxPoint(-w / 3, -h / 3),
		wxPoint(0, -h / 3),
		wxPoint(-w / 6, -h / 6));
	TanTiles.clear();
	TanTiles.insert(TanTiles.end(), { &tan1, &tan2, &tan3, &tan4, &tan5, &tan6, &tan7 });
}

void GUIMyFrame1::DrawWorkspace()
{
	wxClientDC dc1(panelWorkspace);
	wxBufferedDC dc(&dc1);
	dc.SetBackground(wxColor(255, 255, 255));
	dc.SetBrush((wxBrush(wxColor(200, 200, 200))));
	dc.SetPen((wxPen(wxColor(0, 0, 0))));
	dc.Clear();
	dc.SetDeviceOrigin(panelWorkspace->GetSize().x / 2, panelWorkspace->GetSize().y / 2);

	for (Tan* tan : TanTiles)
	{
		if (tan->isHeld)
		{
			dc.SetBrush(wxBrush(wxColor(0, 255, 0)));
			tan->tileOffset = MousePositionInWorkspace;
		}
		else
			dc.SetBrush((wxBrush(wxColor(200, 200, 200))));
		if (!tan->visibleInTray)
			tan->drawInWorkspace(&dc, tan->tileOffset, 1, QPressed, EPressed);
	}
}

void GUIMyFrame1::pickUp()
{
	for (Tan* tan : TanTiles)
	{
		if (tan->checkMousePosition(MousePositionInWorkspace) && MouseClicked)
		{
			tan->isHeld = true;
			isAnyTanHeld = true;
			break;
		}
		else
			tan->isHeld = false;
	}
}
//test
void GUIMyFrame1::DrawTray()
{
	wxClientDC dc1(panelTray);
	wxBufferedDC dc(&dc1);
	dc.SetBackground(wxColor(255, 255, 255));
	dc.SetBrush((wxBrush(wxColor(200, 200, 200))));
	dc.SetPen((wxPen(wxColor(0, 0, 0))));
	dc.Clear();
	dc.SetDeviceOrigin(panelTray->GetSize().x / 2, panelTray->GetSize().y / 2);

	for (Tan* tan : TanTiles)
	{
		if (tan->checkMousePosition(MousePositionInTray) && MouseClicked)
		{
			tan->visibleInTray = false;
		}
		if (tan->visibleInTray)
			tan->drawInTray(&dc, wxPoint(0, 0), 1);
	}
}