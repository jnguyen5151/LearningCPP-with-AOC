#include "MainFrame.h"
#include "utility_functions.h"
#include "OperationFactory.h"

// Operation creates/calls
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

	if (part == "Part 2")
	{
		result.first = 0;
		result.second = op->run(infile, part);
		return result;
	}

	if (part == "Both")
	{
		std::string part1{ "Part 1" };
		std::string part2{ "Part 2" };
		result.first = op->run(infile, part1);
		infile.clear();
		infile.seekg(0, std::ios::beg);
		result.second = op->run(infile, part2);
		return result;
	}

	return result;
}

// Main
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

// wxEvent functions
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

	std::stringstream buffer;
	buffer << file.rdbuf();
	fileText->SetValue(buffer.str());
	file.clear();
	file.seekg(0, std::ios::beg);

	std::string selectedDay{ selectDay->GetStringSelection() };
	std::string selectedPart{ selectPart->GetStringSelection() };

	std::pair<int, int> result{ doAction(selectedDay, selectedPart, file) };

	std::string resultString{};

	if (result.first)
	{
		resultString += "Part 1: ";
		resultString += std::to_string(result.first);
	}

	if (result.second)
	{
		resultString += " Part 2: ";
		resultString += std::to_string(result.second);
	}

	wxString mystring(resultString);

	wxLogStatus(resultString);

	file.close();

}