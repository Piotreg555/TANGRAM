#include "GUIMyFrame1.h"

bool GUIMyFrame1::isAnyTanHeld = false;

GUIMyFrame1::GUIMyFrame1(wxWindow* parent): MyFrame1(parent)
{
	setTray();
}

void GUIMyFrame1::MyFrame1OnUpdateUI(wxUpdateUIEvent& event)
{
	setTray();
}

void GUIMyFrame1::panelWorkspaceOnKeyDown(wxKeyEvent& event)
{
	if (event.GetKeyCode() == 69)
		EPressed = true;
	if (event.GetKeyCode() == 81)
		QPressed = true;
}

void GUIMyFrame1::panelWorkspaceOnKeyUp(wxKeyEvent& event)
{
	if (event.GetKeyCode() == 69)
		EPressed = false;
	if (event.GetKeyCode() == 81)
		QPressed = false;
}

void GUIMyFrame1::panelWorkspaceOnMouseEvents(wxMouseEvent& event)
{
	MousePositionInWorkspace = wxPoint(event.m_x - panelWorkspace->GetSize().x / 2, event.m_y - panelWorkspace->GetSize().y / 2);
	if (event.LeftIsDown())
		MouseClicked = true;
	else
	{
		MouseClicked = false;
		isAnyTanHeld = false;
	}
	if (!isAnyTanHeld)
		pickUp();
}

void GUIMyFrame1::panelWorkspaceOnRightDown(wxMouseEvent& event)
{
	for (Tan* tan : TanTiles)
	{
		if (tan->checkMousePosition(MousePositionInWorkspace))
		{
			tan->visibleInTray = true;
			tan->isHeld = false;
			tan->tileOffset = wxPoint(0, 0);
			tan->angle = 0;
		}
	}
}

void GUIMyFrame1::panelWorkspaceOnUpdateUI(wxUpdateUIEvent& event)
{
	for (auto& tan : TanTiles)
	{
		tan->workspaceWidth = panelWorkspace->GetSize().x;
		tan->workspaceHeight = panelWorkspace->GetSize().y;
	}
	DrawWorkspace();
}

void GUIMyFrame1::panelImageOnKeyDown(wxKeyEvent& event)
{
	if (event.GetKeyCode() == 69)
		EPressed = true;
	if (event.GetKeyCode() == 81)
		QPressed = true;
}

void GUIMyFrame1::panelImageOnKeyUp(wxKeyEvent& event)
{
	if (event.GetKeyCode() == 69)
		EPressed = false;
	if (event.GetKeyCode() == 81)
		QPressed = false;
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
		tan->angle = 0;
	}
	setTray();
	DrawTray();
}

void GUIMyFrame1::buttonClearOnKeyDown(wxKeyEvent& event)
{
	if (event.GetKeyCode() == 69)
		EPressed = true;
	if (event.GetKeyCode() == 81)
		QPressed = true;
}

void GUIMyFrame1::buttonClearOnKeyUp(wxKeyEvent& event)
{
	if (event.GetKeyCode() == 69)
		EPressed = false;
	if (event.GetKeyCode() == 81)
		QPressed = false;
}

void GUIMyFrame1::buttonClearOnRightDown(wxMouseEvent& event)
{
	// TODO: Implement buttonClearOnRightDown
}

void GUIMyFrame1::buttonNewOnButtonClick(wxCommandEvent& event)
{
	// TODO: Implement buttonNewOnButtonClick
}

void GUIMyFrame1::buttonNewOnKeyDown(wxKeyEvent& event)
{
	if (event.GetKeyCode() == 69)
		EPressed = true;
	if (event.GetKeyCode() == 81)
		QPressed = true;
}

void GUIMyFrame1::buttonNewOnKeyUp(wxKeyEvent& event)
{
	if (event.GetKeyCode() == 69)
		EPressed = false;
	if (event.GetKeyCode() == 81)
		QPressed = false;
}

void GUIMyFrame1::buttonNewOnRightDown(wxMouseEvent& event)
{
	// TODO: Implement buttonNewOnRightDown
}

void GUIMyFrame1::panelTrayOnKeyDown(wxKeyEvent& event)
{
	if (event.GetKeyCode() == 69)
		EPressed = true;
	if (event.GetKeyCode() == 81)
		QPressed = true;
}

void GUIMyFrame1::panelTrayOnKeyUp(wxKeyEvent& event)
{
	if (event.GetKeyCode() == 69)
		EPressed = false;
	if (event.GetKeyCode() == 81)
		QPressed = false;
}

void GUIMyFrame1::panelTrayOnMouseEvents(wxMouseEvent& event)
{
	MousePositionInTray = wxPoint(event.m_x - panelTray->GetSize().x / 2, event.m_y - panelTray->GetSize().y / 2);
	if (event.LeftIsDown())
		MouseClicked = true;
	else
		MouseClicked = false;
}

void GUIMyFrame1::panelTrayOnRightDown(wxMouseEvent& event)
{
	// TODO: Implement panelTrayOnRightDown
}

void GUIMyFrame1::panelTrayOnUpdateUI(wxUpdateUIEvent& event)
{
	// this->SetTitle("mouse position in workspace" + std::to_string(MousePositionInWorkspace.x) + " " + std::to_string(MousePositionInWorkspace.y));
	/*this->SetTitle(std::to_string(panelWorkspace->GetSize().x) + ", " + std::to_string(panelWorkspace->GetSize().y));*/
	DrawTray();
}
