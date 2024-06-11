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
	int scaleX = w / 3 * 1.2;
	int scaleY = h / 3 * 1.2;
	wxPoint offset = wxPoint(-w / 6, -1.8 * h / 5);
	wxPoint t1[3] = {
		wxPoint(0, 0),
		wxPoint((sqrt(2) / 2) * scaleX, 0),
		wxPoint((sqrt(2) / 2) * scaleX, (sqrt(2) / 2) * scaleY)
	};
	wxPoint t2[3] = {
		wxPoint((sqrt(2) - 1) / 2 * scaleX,(sqrt(2) - 1) / 2 * scaleY),
		wxPoint(sqrt(2) / 2 * scaleX, sqrt(2) / 2 * scaleY),
		wxPoint((sqrt(2) - 1) / 2 * scaleX, (sqrt(2) + 1) / 2 * scaleY)
	};
	wxPoint t3[3] = {
		wxPoint((4 * sqrt(2) - 3) / 8 * scaleX, (4 * sqrt(2) + 5) / 8 * scaleY),
		wxPoint((4 * sqrt(2) - 3) / 8 * scaleX, (4 * sqrt(2) + 9) / 8 * scaleY),
		wxPoint((4 * sqrt(2) - 5) / 8 * scaleX, (4 * sqrt(2) + 7) / 8 * scaleY)
	};
	wxPoint t4[4] = {
		wxPoint(sqrt(2) / 2 * scaleX,  0),
		wxPoint(1.047 * scaleX,  0.098 * scaleY),
		wxPoint(1.286 * scaleX,0.538 * scaleY),
		wxPoint(0.946 * scaleX, 0.44 * scaleY)
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
	dc->DrawPolygon(3, t1, offset.x, offset.y);
	dc->DrawPolygon(3, t2, offset.x, offset.y);
	dc->DrawPolygon(3, t3, offset.x, offset.y);
	dc->DrawPolygon(4, t4, offset.x, offset.y);
	dc->DrawPolygon(3, t5, offset.x, offset.y);
	dc->DrawPolygon(4, t6, offset.x, offset.y);
	dc->DrawPolygon(3, t7, offset.x, offset.y);
}

void house(wxDC* dc, int height) {
	int w = height;
	int h = -height;
	int scaleX = w / 3 * 1.5;
	int scaleY = h / 3 * 1.5;
	wxPoint offset = wxPoint(-w / 5, -1.4 * h / 5);
	wxPoint t1[3] = {
		wxPoint((sqrt(2)+8)/8 * scaleX, 1./2 * scaleY),
		wxPoint((sqrt(2)) / 8 * scaleX, 1. / 2 * scaleY),
		wxPoint((sqrt(2) + 4) / 8 * scaleX, 1 * scaleY)

	};
	wxPoint t2[3] = {
		wxPoint(1. / 2 * scaleX, 0 * scaleY),
		wxPoint(1 * scaleX, 1. / 2 * scaleY),
		wxPoint(0 * scaleX, 1. / 2 * scaleY)
	};
	wxPoint t3[3] = {
		wxPoint(0 * scaleX, 0 * scaleY),
		wxPoint(1. / 4 * scaleX, 1. / 4 * scaleY),
		wxPoint(0 * scaleX, 1. / 2 * scaleY)
	};
	wxPoint t4[4] = {
		wxPoint((sqrt(2))/8 * scaleX, 1./2 * scaleY),
		wxPoint((3*sqrt(2)) / 8 * scaleX, (sqrt(2)+2)/4 * scaleY),
		wxPoint((sqrt(2) ) / 8 * scaleX, (sqrt(2)+2)/4 * scaleY),
		wxPoint(( - sqrt(2)) / 8 * scaleX, 1. / 2 * scaleY)


	};
	wxPoint t5[3] = {
		wxPoint(1. / 2 * scaleX, 0 * scaleY),
		wxPoint(1 * scaleX, 0 * scaleY),
		wxPoint(1 * scaleX, 1. / 2 * scaleY)
	};
	wxPoint t6[4] = {
		wxPoint((3 * sqrt(2)) / 8 * scaleX, (sqrt(2) + 2) / 4 * scaleY),
		wxPoint((sqrt(2)) / 8 * scaleX, (sqrt(2) + 2) / 4 * scaleY),
		wxPoint((sqrt(2)) / 8 * scaleX, (2 * sqrt(2) + 2) / 4 * scaleY),
		wxPoint((3 * sqrt(2)) / 8 * scaleX, (2*sqrt(2) + 2) / 4 * scaleY)
		

	};
	wxPoint t7[3] = {
		wxPoint(0 * scaleX, 0 * scaleY),
		wxPoint(1. / 2 * scaleX, 0 * scaleY),
		wxPoint(1. / 4 * scaleX, 1. / 4 * scaleY)

	};
	dc->DrawPolygon(3, t1, offset.x, offset.y);
	dc->DrawPolygon(3, t2, offset.x, offset.y);
	dc->DrawPolygon(3, t3, offset.x, offset.y);
	dc->DrawPolygon(4, t4, offset.x, offset.y);
	dc->DrawPolygon(3, t5, offset.x, offset.y);
	dc->DrawPolygon(4, t6, offset.x, offset.y);
	dc->DrawPolygon(3, t7, offset.x, offset.y);
}

void GUIMyFrame1::DrawImage() {
	wxClientDC dc1(panelImage);
	wxBufferedDC dc(&dc1);
	dc.SetBackground(wxColor(255, 255, 255));
	dc.SetPen((wxPen(wxColor(0, 0, 0))));
	dc.Clear();
	dc.SetDeviceOrigin(panelImage->GetSize().x / 2, panelImage->GetSize().y / 2);
	//dc.DrawCircle(wxPoint(0,0), 5);

	void (*shapes[2])(wxDC * dc, int height) = { cat, house };
	std::srand((unsigned)time(NULL));


	if (showSolution) {
		dc.SetBrush((wxBrush(wxColor(200, 200, 200))));
		shapes[random_number](&dc, panelImage->GetSize().y);
	}
	else {
		dc.SetBrush((wxBrush(wxColor(0, 0, 0))));
		int previous = random_number;
		while (previous == random_number) previous = std::rand() % (sizeof(shapes) / sizeof(shapes[0]));
		random_number = previous;
		//dc.DrawText(std::to_string(random_number), wxPoint(0, 0));
		shapes[random_number](&dc, panelImage->GetSize().y);
	}
}
