#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1(wxWindow* parent)
	:
	MyFrame1(parent)
{
	setTray();
	for (int i = 0; i < 7; i++) {
		TanTiles[i]->number = i + 1;
	}
}

void GUIMyFrame1::MyFrame1OnKeyDown(wxKeyEvent& event)
{
	if (event.GetKeyCode() == 69)
		GUIMyFrame1::EPressed = true;
	if (event.GetKeyCode() == 81)
		GUIMyFrame1::QPressed = true;
}

void GUIMyFrame1::MyFrame1OnKeyUp(wxKeyEvent& event)
{
	if (event.GetKeyCode() == 69)
		GUIMyFrame1::EPressed = false;
	if (event.GetKeyCode() == 81)
		GUIMyFrame1::QPressed = false;
}

void GUIMyFrame1::MyFrame1OnUpdateUI(wxUpdateUIEvent& event)
{
}

void GUIMyFrame1::panelWorkspaceOnKeyDown(wxKeyEvent& event)
{
	if (event.GetKeyCode() == 69)
		GUIMyFrame1::EPressed = true;
	if (event.GetKeyCode() == 81)
		GUIMyFrame1::QPressed = true;
}

void GUIMyFrame1::panelWorkspaceOnKeyUp(wxKeyEvent& event)
{
	if (event.GetKeyCode() == 69)
		GUIMyFrame1::EPressed = false;
	if (event.GetKeyCode() == 81)
		GUIMyFrame1::QPressed = false;
}

void GUIMyFrame1::panelWorkspaceOnMouseEvents(wxMouseEvent& event)
{
	MousePositionInWorkspace = wxPoint(event.m_x - Tan::workspaceWidth / 2, event.m_y - Tan::workspaceHeight / 2);
	if (event.LeftIsDown())
		MouseClickedInWorkspace = true;
	else
	{
		MouseClickedInWorkspace = false;
		isAnyTanHeld = false;
	}
	if (!isAnyTanHeld)
		pickUp();
}

void GUIMyFrame1::panelWorkspaceOnRightDown(wxMouseEvent& event)
{
	int h = panelTray->GetSize().y;
	for (Tan* tan : TanTiles)
	{
		if (tan->checkMousePosition(MousePositionInWorkspace))
		{
			tan->visibleInTray = true;
			tan->isHeld = false;
			tan->tileOffset = wxPoint(0, 0);
			tan->angle = 0.;
			switch (tan->number)
			{
			case 1:
				tan->addPoints(wxPoint(-h / 3, h / 3), wxPoint(-h / 3, -h / 3), wxPoint(0, 0));
				break;
			case 2:
				tan->addPoints(wxPoint(-h / 3, -h / 3), wxPoint(h / 3, -h / 3), wxPoint(0, 0));
				break;
			case 3:
				tan->addPoints(wxPoint(0, 0), wxPoint(h / 6, h / 6), wxPoint(h / 6, -h / 6));
				break;
			case 4:
				tan->addPoints(wxPoint(h / 6, h / 6), wxPoint(h / 3, 0), wxPoint(h / 3, -h / 3), wxPoint(h / 6, -h / 6));
				break;
			case 5:
				tan->addPoints(wxPoint(0, h / 3), wxPoint(h / 3, h / 3), wxPoint(h / 3, 0));
				break;
			case 6:
				tan->addPoints(wxPoint(0, h / 3), wxPoint(h / 6, h / 6), wxPoint(0, 0), wxPoint(-h / 6, h / 6));
				break;
			case 7:
				tan->addPoints(wxPoint(-h / 3, h / 3), wxPoint(0, h / 3), wxPoint(-h / 6, h / 6));
				break;
			default:
				break;
			}
		}
	}
}

void GUIMyFrame1::panelWorkspaceOnUpdateUI(wxUpdateUIEvent& event)
{
	Tan::workspaceWidth = panelWorkspace->GetSize().x;
	Tan::workspaceHeight = panelWorkspace->GetSize().y;
	DrawWorkspace();
}

void GUIMyFrame1::panelImageOnKeyDown(wxKeyEvent& event)
{
	if (event.GetKeyCode() == 69)
		GUIMyFrame1::EPressed = true;
	if (event.GetKeyCode() == 81)
		GUIMyFrame1::QPressed = true;
}

void GUIMyFrame1::panelImageOnKeyUp(wxKeyEvent& event)
{
	if (event.GetKeyCode() == 69)
		GUIMyFrame1::EPressed = false;
	if (event.GetKeyCode() == 81)
		GUIMyFrame1::QPressed = false;
}

void GUIMyFrame1::panelImageOnRightDown(wxMouseEvent& event)
{
	// TODO: Implement panelImageOnRightDown
}

void GUIMyFrame1::buttonClearOnButtonClick(wxCommandEvent& event)
{
	GUIMyFrame1::isAnyTanHeld = false;
	for (Tan* tan : TanTiles)
	{
		tan->visibleInTray = true;
		tan->isHeld = false;
		tan->tileOffset = wxPoint(0, 0);
		tan->angle = 0.;
	}
	setTray();
	DrawTray();
}

void GUIMyFrame1::buttonClearOnKeyDown(wxKeyEvent& event)
{
	if (event.GetKeyCode() == 69)
		GUIMyFrame1::EPressed = true;
	if (event.GetKeyCode() == 81)
		GUIMyFrame1::QPressed = true;
}

void GUIMyFrame1::buttonClearOnKeyUp(wxKeyEvent& event)
{
	if (event.GetKeyCode() == 69)
		GUIMyFrame1::EPressed = false;
	if (event.GetKeyCode() == 81)
		GUIMyFrame1::QPressed = false;
}

void GUIMyFrame1::buttonClearOnRightDown(wxMouseEvent& event)
{
	// TODO: Implement buttonClearOnRightDown
}

void GUIMyFrame1::buttonNewOnButtonClick(wxCommandEvent& event)
{
	showSolution = false;
	DrawImage();
}

void GUIMyFrame1::buttonNewOnKeyDown(wxKeyEvent& event)
{
	if (event.GetKeyCode() == 69)
		GUIMyFrame1::EPressed = true;
	if (event.GetKeyCode() == 81)
		GUIMyFrame1::QPressed = true;
}

void GUIMyFrame1::buttonNewOnKeyUp(wxKeyEvent& event)
{
	if (event.GetKeyCode() == 69)
		GUIMyFrame1::EPressed = false;
	if (event.GetKeyCode() == 81)
		GUIMyFrame1::QPressed = false;
}

void GUIMyFrame1::buttonNewOnRightDown(wxMouseEvent& event)
{
	// TODO: Implement buttonNewOnRightDown
}

void GUIMyFrame1::buttonSolveOnButtonClick(wxCommandEvent& event)
{
	if (random_number != -1)
	{
		showSolution = true;
		DrawImage();
	}
}

void GUIMyFrame1::buttonSolveOnKeyDown(wxKeyEvent& event)
{
	if (event.GetKeyCode() == 69)
		GUIMyFrame1::EPressed = true;
	if (event.GetKeyCode() == 81)
		GUIMyFrame1::QPressed = true;
}

void GUIMyFrame1::buttonSolveOnKeyUp(wxKeyEvent& event)
{
	if (event.GetKeyCode() == 69)
		GUIMyFrame1::EPressed = false;
	if (event.GetKeyCode() == 81)
		GUIMyFrame1::QPressed = false;
}

void GUIMyFrame1::panelTrayOnKeyDown(wxKeyEvent& event)
{
	if (event.GetKeyCode() == 69)
		GUIMyFrame1::EPressed = true;
	if (event.GetKeyCode() == 81)
		GUIMyFrame1::QPressed = true;
}

void GUIMyFrame1::panelTrayOnKeyUp(wxKeyEvent& event)
{
	if (event.GetKeyCode() == 69)
		GUIMyFrame1::EPressed = false;
	if (event.GetKeyCode() == 81)
		GUIMyFrame1::QPressed = false;
}

void GUIMyFrame1::panelTrayOnMouseEvents(wxMouseEvent& event)
{
	MousePositionInTray = wxPoint(event.m_x - panelTray->GetSize().x / 2, event.m_y - panelTray->GetSize().y / 2);
	if (event.LeftIsDown())
		MouseClickedInTray = true;
	else
		MouseClickedInTray = false;
}

void GUIMyFrame1::panelTrayOnRightDown(wxMouseEvent& event)
{
	// TODO: Implement panelTrayOnRightDown
}

void GUIMyFrame1::panelTrayOnUpdateUI(wxUpdateUIEvent& event)
{
	// this->SetTitle("mouse position in workspace" + std::to_string(MousePositionInWorkspace.x) + " " + std::to_string(MousePositionInWorkspace.y));
	//this->SetTitle(std::to_string(GUIMyFrame1::QPressed) + ", " + std::to_string(GUIMyFrame1::EPressed));
	DrawTray();
}

bool GUIMyFrame1::isAnyTanHeld = false;
bool GUIMyFrame1::QPressed = false;
bool GUIMyFrame1::EPressed = false;
int Tan::workspaceWidth = 721;
int Tan::workspaceHeight = 577;