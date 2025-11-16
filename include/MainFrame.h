#pragma once
#include <wx/wx.h>
#include <wx/filedlg.h>
#include <fstream>
#include <sstream>

class MainFrame : public wxFrame
{
public: 
	MainFrame(const wxString& title);
private:
	wxButton* fileButton;
	wxButton* solveButton;
	wxTextCtrl* fileText;
	wxRadioBox* selectPart;
	wxRadioBox* selectDay;
	void SubmitFile(wxCommandEvent& evt);
};