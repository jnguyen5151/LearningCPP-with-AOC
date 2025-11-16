#include "MainFrame.h"
#include "aoc.h"
#include "utility_functions.h"
#include "OperationFactory.h"

std::pair<int, int> doAction(std::string& mode, std::string& part, std::ifstream& infile)
{
	auto op = makeOperation(mode);

	if (!op)
	{
		return { 0, 0 };
	}
	
	std::pair<int, int> result{};
	if (part == "Part 1")
	{
		result.first = op->run(infile, part);
		result.second = 0;
		return result;
	}

	return result;
}

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	
	wxArrayString dayChoices;
	dayChoices.Add("Day 1");
	dayChoices.Add("Day 2");
	dayChoices.Add("Day 3");

	wxArrayString partChoices;
	partChoices.Add("Part 1");
	partChoices.Add("Part 2");
	partChoices.Add("Both");

	wxPanel* panel = new wxPanel(this);

// input controls
	selectDay = new wxRadioBox(panel, wxID_ANY, "Select Which Day to Solve", wxDefaultPosition, wxDefaultSize,
		dayChoices);
	selectPart = new wxRadioBox(panel, wxID_ANY, "Select Which Part to Solve", wxDefaultPosition, wxDefaultSize,
		partChoices);
	fileButton = new wxButton(panel, wxID_ANY, "Select Input File", wxDefaultPosition, wxDefaultSize, 
                              wxBU_LEFT | wxBU_EXACTFIT);
	solveButton = new wxButton(panel, wxID_ANY, "Solve", wxDefaultPosition, wxDefaultSize, 
	                          wxBU_LEFT | wxBU_EXACTFIT);
	fileText = new wxTextCtrl(panel, wxID_ANY, "Input File Contents", wxDefaultPosition, wxDefaultSize,
                              wxTE_MULTILINE | wxTE_READONLY);

// Sizer
	wxBoxSizer* fileSizer = new wxBoxSizer(wxVERTICAL);
	fileSizer->Add(selectDay, 0, wxALL, 5);
	fileSizer->Add(selectPart, 0, wxALL, 5);
	fileSizer->Add(fileButton, 0, wxALL, 5);
	fileSizer->Add(fileText, 1, wxALL | wxEXPAND, 5);

	panel->SetSizer(fileSizer);
	fileSizer->SetSizeHints(this);

// Event Binds
	fileButton->Bind(wxEVT_BUTTON, &MainFrame::SubmitFile, this);

	CreateStatusBar();

}

void MainFrame:: SubmitFile(wxCommandEvent& evt)
{

	wxFileDialog openFileDialog(this, "Open Text File", "", "", "Text files(*.txt) | *.txt | ALL files(*.*) | *.*",
				 wxFD_OPEN | wxFD_FILE_MUST_EXIST);

	if (openFileDialog.ShowModal() != wxID_OK)
	{
		return;
	}

	wxString path = openFileDialog.GetPath();
	std::ifstream file(path.ToStdString());

	if (!file.is_open())
	{
		wxLogError("Error opening file '%s'.", path);
		return;
	}

	std::string selectedDay{ selectDay->GetStringSelection() };
	std::string selectedPart{ selectPart->GetStringSelection() };

	std::pair<int, int> result{ doAction(selectedDay, selectedPart, file) };

	std::string resultPart1{ std::to_string(result.first) };
	wxString mystring(resultPart1);

	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();

	fileText->SetValue(buffer.str());
	wxLogStatus(resultPart1);

}