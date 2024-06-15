///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.1.0-0-g733bf3d)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer(wxVERTICAL);

	panelWorkspace = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	panelWorkspace->SetBackgroundColour(wxColour(255, 255, 255));

	bSizer8->Add(panelWorkspace, 1, wxEXPAND | wxALL, 5);


	bSizer7->Add(bSizer8, 8, wxEXPAND, 5);

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer(wxVERTICAL);

	panelImage = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	panelImage->SetBackgroundColour(wxColour(255, 255, 255));

	bSizer10->Add(panelImage, 1, wxEXPAND | wxALL, 5);


	bSizer9->Add(bSizer10, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer(wxHORIZONTAL);

	buttonClear = new wxButton(this, wxID_ANY, wxT("Wyczysc"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer11->Add(buttonClear, 1, wxALL, 5);

	buttonNew = new wxButton(this, wxID_ANY, wxT("Nowy obrazek"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer11->Add(buttonNew, 1, wxALL, 5);

	buttonSolve = new wxButton(this, wxID_ANY, wxT("Rozwiazanie"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer11->Add(buttonSolve, 0, wxALL, 5);


	bSizer9->Add(bSizer11, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer(wxVERTICAL);

	panelTray = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	panelTray->SetBackgroundColour(wxColour(255, 255, 255));

	bSizer12->Add(panelTray, 1, wxEXPAND | wxALL, 5);


	bSizer9->Add(bSizer12, 1, wxEXPAND, 5);


	bSizer7->Add(bSizer9, 3, wxEXPAND, 5);


	this->SetSizer(bSizer7);
	this->Layout();

	this->Centre(wxBOTH);

	// Connect Events
	this->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(MyFrame1::MyFrame1OnKeyDown));
	this->Connect(wxEVT_KEY_UP, wxKeyEventHandler(MyFrame1::MyFrame1OnKeyUp));
	this->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MyFrame1::MyFrame1OnUpdateUI));
	panelWorkspace->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(MyFrame1::panelWorkspaceOnKeyDown), NULL, this);
	panelWorkspace->Connect(wxEVT_KEY_UP, wxKeyEventHandler(MyFrame1::panelWorkspaceOnKeyUp), NULL, this);
	panelWorkspace->Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Connect(wxEVT_LEFT_UP, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Connect(wxEVT_MIDDLE_DOWN, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Connect(wxEVT_MIDDLE_UP, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Connect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Connect(wxEVT_RIGHT_UP, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Connect(wxEVT_AUX1_DOWN, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Connect(wxEVT_AUX1_UP, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Connect(wxEVT_AUX2_DOWN, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Connect(wxEVT_AUX1_UP, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Connect(wxEVT_MOTION, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Connect(wxEVT_LEFT_DCLICK, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Connect(wxEVT_MIDDLE_DCLICK, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Connect(wxEVT_RIGHT_DCLICK, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Connect(wxEVT_AUX1_DCLICK, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Connect(wxEVT_AUX2_DCLICK, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Connect(wxEVT_LEAVE_WINDOW, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Connect(wxEVT_ENTER_WINDOW, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Connect(wxEVT_MOUSEWHEEL, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Connect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(MyFrame1::panelWorkspaceOnRightDown), NULL, this);
	panelWorkspace->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MyFrame1::panelWorkspaceOnUpdateUI), NULL, this);
	panelImage->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(MyFrame1::panelImageOnKeyDown), NULL, this);
	panelImage->Connect(wxEVT_KEY_UP, wxKeyEventHandler(MyFrame1::panelImageOnKeyUp), NULL, this);
	panelImage->Connect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(MyFrame1::panelImageOnRightDown), NULL, this);
	buttonClear->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::buttonClearOnButtonClick), NULL, this);
	buttonClear->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(MyFrame1::buttonClearOnKeyDown), NULL, this);
	buttonClear->Connect(wxEVT_KEY_UP, wxKeyEventHandler(MyFrame1::buttonClearOnKeyUp), NULL, this);
	buttonClear->Connect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(MyFrame1::buttonClearOnRightDown), NULL, this);
	buttonNew->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::buttonNewOnButtonClick), NULL, this);
	buttonNew->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(MyFrame1::buttonNewOnKeyDown), NULL, this);
	buttonNew->Connect(wxEVT_KEY_UP, wxKeyEventHandler(MyFrame1::buttonNewOnKeyUp), NULL, this);
	buttonNew->Connect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(MyFrame1::buttonNewOnRightDown), NULL, this);
	buttonSolve->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::buttonSolveOnButtonClick), NULL, this);
	buttonSolve->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(MyFrame1::buttonSolveOnKeyDown), NULL, this);
	buttonSolve->Connect(wxEVT_KEY_UP, wxKeyEventHandler(MyFrame1::buttonSolveOnKeyUp), NULL, this);
	panelTray->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(MyFrame1::panelTrayOnKeyDown), NULL, this);
	panelTray->Connect(wxEVT_KEY_UP, wxKeyEventHandler(MyFrame1::panelTrayOnKeyUp), NULL, this);
	panelTray->Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Connect(wxEVT_LEFT_UP, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Connect(wxEVT_MIDDLE_DOWN, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Connect(wxEVT_MIDDLE_UP, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Connect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Connect(wxEVT_RIGHT_UP, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Connect(wxEVT_AUX1_DOWN, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Connect(wxEVT_AUX1_UP, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Connect(wxEVT_AUX2_DOWN, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Connect(wxEVT_AUX1_UP, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Connect(wxEVT_MOTION, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Connect(wxEVT_LEFT_DCLICK, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Connect(wxEVT_MIDDLE_DCLICK, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Connect(wxEVT_RIGHT_DCLICK, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Connect(wxEVT_AUX1_DCLICK, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Connect(wxEVT_AUX2_DCLICK, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Connect(wxEVT_LEAVE_WINDOW, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Connect(wxEVT_ENTER_WINDOW, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Connect(wxEVT_MOUSEWHEEL, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Connect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(MyFrame1::panelTrayOnRightDown), NULL, this);
	panelTray->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MyFrame1::panelTrayOnUpdateUI), NULL, this);
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	this->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(MyFrame1::MyFrame1OnKeyDown));
	this->Disconnect(wxEVT_KEY_UP, wxKeyEventHandler(MyFrame1::MyFrame1OnKeyUp));
	this->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MyFrame1::MyFrame1OnUpdateUI));
	panelWorkspace->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(MyFrame1::panelWorkspaceOnKeyDown), NULL, this);
	panelWorkspace->Disconnect(wxEVT_KEY_UP, wxKeyEventHandler(MyFrame1::panelWorkspaceOnKeyUp), NULL, this);
	panelWorkspace->Disconnect(wxEVT_LEFT_DOWN, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Disconnect(wxEVT_LEFT_UP, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Disconnect(wxEVT_MIDDLE_DOWN, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Disconnect(wxEVT_MIDDLE_UP, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Disconnect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Disconnect(wxEVT_RIGHT_UP, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Disconnect(wxEVT_AUX1_DOWN, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Disconnect(wxEVT_AUX1_UP, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Disconnect(wxEVT_AUX2_DOWN, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Disconnect(wxEVT_AUX1_UP, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Disconnect(wxEVT_MOTION, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Disconnect(wxEVT_LEFT_DCLICK, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Disconnect(wxEVT_MIDDLE_DCLICK, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Disconnect(wxEVT_RIGHT_DCLICK, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Disconnect(wxEVT_AUX1_DCLICK, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Disconnect(wxEVT_AUX2_DCLICK, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Disconnect(wxEVT_LEAVE_WINDOW, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Disconnect(wxEVT_ENTER_WINDOW, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Disconnect(wxEVT_MOUSEWHEEL, wxMouseEventHandler(MyFrame1::panelWorkspaceOnMouseEvents), NULL, this);
	panelWorkspace->Disconnect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(MyFrame1::panelWorkspaceOnRightDown), NULL, this);
	panelWorkspace->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MyFrame1::panelWorkspaceOnUpdateUI), NULL, this);
	panelImage->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(MyFrame1::panelImageOnKeyDown), NULL, this);
	panelImage->Disconnect(wxEVT_KEY_UP, wxKeyEventHandler(MyFrame1::panelImageOnKeyUp), NULL, this);
	panelImage->Disconnect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(MyFrame1::panelImageOnRightDown), NULL, this);
	buttonClear->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::buttonClearOnButtonClick), NULL, this);
	buttonClear->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(MyFrame1::buttonClearOnKeyDown), NULL, this);
	buttonClear->Disconnect(wxEVT_KEY_UP, wxKeyEventHandler(MyFrame1::buttonClearOnKeyUp), NULL, this);
	buttonClear->Disconnect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(MyFrame1::buttonClearOnRightDown), NULL, this);
	buttonNew->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::buttonNewOnButtonClick), NULL, this);
	buttonNew->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(MyFrame1::buttonNewOnKeyDown), NULL, this);
	buttonNew->Disconnect(wxEVT_KEY_UP, wxKeyEventHandler(MyFrame1::buttonNewOnKeyUp), NULL, this);
	buttonNew->Disconnect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(MyFrame1::buttonNewOnRightDown), NULL, this);
	buttonSolve->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::buttonSolveOnButtonClick), NULL, this);
	buttonSolve->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(MyFrame1::buttonSolveOnKeyDown), NULL, this);
	buttonSolve->Disconnect(wxEVT_KEY_UP, wxKeyEventHandler(MyFrame1::buttonSolveOnKeyUp), NULL, this);
	panelTray->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(MyFrame1::panelTrayOnKeyDown), NULL, this);
	panelTray->Disconnect(wxEVT_KEY_UP, wxKeyEventHandler(MyFrame1::panelTrayOnKeyUp), NULL, this);
	panelTray->Disconnect(wxEVT_LEFT_DOWN, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Disconnect(wxEVT_LEFT_UP, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Disconnect(wxEVT_MIDDLE_DOWN, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Disconnect(wxEVT_MIDDLE_UP, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Disconnect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Disconnect(wxEVT_RIGHT_UP, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Disconnect(wxEVT_AUX1_DOWN, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Disconnect(wxEVT_AUX1_UP, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Disconnect(wxEVT_AUX2_DOWN, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Disconnect(wxEVT_AUX1_UP, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Disconnect(wxEVT_MOTION, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Disconnect(wxEVT_LEFT_DCLICK, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Disconnect(wxEVT_MIDDLE_DCLICK, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Disconnect(wxEVT_RIGHT_DCLICK, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Disconnect(wxEVT_AUX1_DCLICK, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Disconnect(wxEVT_AUX2_DCLICK, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Disconnect(wxEVT_LEAVE_WINDOW, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Disconnect(wxEVT_ENTER_WINDOW, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Disconnect(wxEVT_MOUSEWHEEL, wxMouseEventHandler(MyFrame1::panelTrayOnMouseEvents), NULL, this);
	panelTray->Disconnect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(MyFrame1::panelTrayOnRightDown), NULL, this);
	panelTray->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MyFrame1::panelTrayOnUpdateUI), NULL, this);

}
