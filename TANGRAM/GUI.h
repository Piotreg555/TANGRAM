///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.1.0-0-g733bf3d)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame
{
private:

protected:
	wxPanel* panelWorkspace;
	wxPanel* panelImage;
	wxButton* buttonClear;
	wxButton* buttonNew;
	wxButton* buttonSolve;
	wxPanel* panelTray;

	// Virtual event handlers, override them in your derived class
	virtual void MyFrame1OnKeyDown(wxKeyEvent& event) { event.Skip(); }
	virtual void MyFrame1OnKeyUp(wxKeyEvent& event) { event.Skip(); }
	virtual void MyFrame1OnUpdateUI(wxUpdateUIEvent& event) { event.Skip(); }
	virtual void panelWorkspaceOnKeyDown(wxKeyEvent& event) { event.Skip(); }
	virtual void panelWorkspaceOnKeyUp(wxKeyEvent& event) { event.Skip(); }
	virtual void panelWorkspaceOnMouseEvents(wxMouseEvent& event) { event.Skip(); }
	virtual void panelWorkspaceOnRightDown(wxMouseEvent& event) { event.Skip(); }
	virtual void panelWorkspaceOnUpdateUI(wxUpdateUIEvent& event) { event.Skip(); }
	virtual void panelImageOnKeyDown(wxKeyEvent& event) { event.Skip(); }
	virtual void panelImageOnKeyUp(wxKeyEvent& event) { event.Skip(); }
	virtual void panelImageOnRightDown(wxMouseEvent& event) { event.Skip(); }
	virtual void buttonClearOnButtonClick(wxCommandEvent& event) { event.Skip(); }
	virtual void buttonClearOnKeyDown(wxKeyEvent& event) { event.Skip(); }
	virtual void buttonClearOnKeyUp(wxKeyEvent& event) { event.Skip(); }
	virtual void buttonClearOnRightDown(wxMouseEvent& event) { event.Skip(); }
	virtual void buttonNewOnButtonClick(wxCommandEvent& event) { event.Skip(); }
	virtual void buttonNewOnKeyDown(wxKeyEvent& event) { event.Skip(); }
	virtual void buttonNewOnKeyUp(wxKeyEvent& event) { event.Skip(); }
	virtual void buttonNewOnRightDown(wxMouseEvent& event) { event.Skip(); }
	virtual void buttonSolveOnButtonClick(wxCommandEvent& event) { event.Skip(); }
	virtual void buttonSolveOnKeyDown(wxKeyEvent& event) { event.Skip(); }
	virtual void buttonSolveOnKeyUp(wxKeyEvent& event) { event.Skip(); }
	virtual void panelTrayOnKeyDown(wxKeyEvent& event) { event.Skip(); }
	virtual void panelTrayOnKeyUp(wxKeyEvent& event) { event.Skip(); }
	virtual void panelTrayOnMouseEvents(wxMouseEvent& event) { event.Skip(); }
	virtual void panelTrayOnRightDown(wxMouseEvent& event) { event.Skip(); }
	virtual void panelTrayOnUpdateUI(wxUpdateUIEvent& event) { event.Skip(); }


public:

	MyFrame1(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("44 - TANGRAM"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(1024, 632), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

	~MyFrame1();

};

