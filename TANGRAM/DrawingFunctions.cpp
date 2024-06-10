#include "GUIMyFrame1.h"

void GUIMyFrame1::setTray()
{

	//int w = panelTray->GetSize().x;
	int h = panelTray->GetSize().y;
	tan1.addPoints(
		wxPoint(-h / 3, h / 3),
		wxPoint(-h / 3, -h / 3),
		wxPoint(0, 0));
	tan2.addPoints(
		wxPoint(-h / 3, -h / 3),
		wxPoint(h / 3, -h / 3),
		wxPoint(0, 0));
	tan3.addPoints(
		wxPoint(0, 0),
		wxPoint(h / 6, h / 6),
		wxPoint(h / 6, -h / 6));
	tan4.addPoints(
		wxPoint(h / 6, h / 6),
		wxPoint(h / 3, 0),
		wxPoint(h / 3, -h / 3),
		wxPoint(h / 6, -h / 6));
	tan5.addPoints(
		wxPoint(0, h / 3),
		wxPoint(h / 3, h / 3),
		wxPoint(h / 3, 0));
	tan6.addPoints(
		wxPoint(0, h / 3),
		wxPoint(h / 6, h / 6),
		wxPoint(0, 0),
		wxPoint(-h / 6, h / 6));
	tan7.addPoints(
		wxPoint(-h / 3, h / 3),
		wxPoint(0, h / 3),
		wxPoint(-h / 6, h / 6));
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
			tan->drawInWorkspace(&dc, tan->tileOffset, 1);
	}
}

void GUIMyFrame1::pickUp()
{
	for (Tan* tan : TanTiles)
	{
		if (tan->checkMousePosition(MousePositionInWorkspace) && MouseClickedInWorkspace)
		{
			tan->isHeld = true;
			isAnyTanHeld = true;
			break;
		}
		else
			tan->isHeld = false;
	}
}

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
		if (tan->checkMousePosition(MousePositionInTray) && MouseClickedInTray)
		{
			tan->visibleInTray = false;
		}
		if (tan->visibleInTray)
			tan->drawInTray(&dc, wxPoint(0, 0), 1);
	}
}

void cat(wxDC* dc, int height) {
	int w = height;
	int h = -height;
	int scaleX = w / 3;
	int scaleY =h / 3;
	wxPoint t1[3] = {
		wxPoint(0, 0), 
		wxPoint((sqrt(2)/2)* scaleX, 0),
		wxPoint((sqrt(2) / 2) * scaleX, (sqrt(2) / 2) * scaleY)
	};
	wxPoint t2[3] = {
		wxPoint((sqrt(2)-1) / 2 * scaleX,(sqrt(2) - 1) / 2 * scaleY),
		wxPoint(sqrt(2) / 2 * scaleX, sqrt(2) / 2 * scaleY),
		wxPoint((sqrt(2) - 1) / 2 * scaleX, (sqrt(2) + 1) / 2 * scaleY)
	};
	wxPoint t3[3] = {
		wxPoint((4 * sqrt(2) - 3) / 8 * scaleX, (4 * sqrt(2) + 5) / 8 * scaleY),
		wxPoint((4 * sqrt(2) - 3) / 8 * scaleX, (4 * sqrt(2) + 9) / 8 * scaleY),
		wxPoint((4 * sqrt(2) - 5) / 8 * scaleX, (4 * sqrt(2) + 7) / 8 * scaleY)
	};
	wxPoint t4[4] = {
		wxPoint(sqrt(2)/2* scaleX,  0),
		wxPoint(1.047*scaleX,  0.098*scaleY),
		wxPoint(1.286*scaleX,0.538 *scaleY),
		wxPoint(0.946*scaleX, 0.44 *scaleY)
	};
	wxPoint t5[3] = {
		wxPoint((sqrt(2) - 1) / 2 * scaleX, 1. / 2 * scaleY),
		wxPoint((sqrt(2) - 2) / 4 * scaleX, (sqrt(2) + 2) / 4 * scaleY),
		wxPoint((sqrt(2) - 1) / 2 * scaleX, (sqrt(2) + 1) / 2 * scaleY),
	};
	wxPoint t6[4] = {
		wxPoint((4 * sqrt(2) - 5) / 8 * scaleX, (4 * sqrt(2) + 3) / 8 * scaleY),
		wxPoint((4 * sqrt(2) - 3) / 8 * scaleX, (4 * sqrt(2) + 5) / 8 * scaleY),
		wxPoint((4 * sqrt(2) - 5) / 8 * scaleX, (4 * sqrt(2) + 7) / 8 * scaleY),
		wxPoint((4 * sqrt(2) - 7) / 8 * scaleX, (4 * sqrt(2) + 5) / 8 * scaleY)
	};
	wxPoint t7[3] = {
		wxPoint((4 * sqrt(2) - 5) / 8 * scaleX, (4 * sqrt(2) + 7) / 8 * scaleY),
		wxPoint((4 * sqrt(2) - 7) / 8 * scaleX, (4 * sqrt(2) + 9) / 8 * scaleY),
		wxPoint((4 * sqrt(2) - 7) / 8 * scaleX, (4 * sqrt(2) + 5) / 8 * scaleY)
	};
	dc->DrawPolygon(3, t1);
	dc->DrawPolygon(3, t2);
	dc->DrawPolygon(3, t3);
	dc->DrawPolygon(4, t4);
	dc->DrawPolygon(3, t5);
	dc->DrawPolygon(4, t6);
	dc->DrawPolygon(3, t7);
	/*std::vector<wxPoint*> Tiles;
	Tiles.clear();
	Tiles.insert(Tiles.end(), { t1, t2, t3, t4, t5, t6, t7 });
	for (wxPoint* tile : Tiles) dc->DrawPolygon(sizeof(tile), tile);*/
}

void GUIMyFrame1::DrawImage() {
	wxClientDC dc1(panelImage);
	wxBufferedDC dc(&dc1);
	dc.SetBackground(wxColor(255, 255, 255));
	dc.SetBrush((wxBrush(wxColor(200, 200, 200))));
	dc.SetPen((wxPen(wxColor(0, 0, 0))));
	dc.Clear();
	dc.SetDeviceOrigin(panelImage->GetSize().x / 2, 5*panelImage->GetSize().y/7);
	//dc.DrawCircle(wxPoint(0,0), 5);

	cat(&dc, panelImage->GetSize().y);
}
