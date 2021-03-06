///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Aug  2 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "widgets/text_ctrl_eval.h"
#include "widgets/wx_grid.h"

#include "dialog_edit_footprint_for_fp_editor_base.h"

///////////////////////////////////////////////////////////////////////////

DIALOG_FOOTPRINT_FP_EDITOR_BASE::DIALOG_FOOTPRINT_FP_EDITOR_BASE( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : DIALOG_SHIM( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	m_GeneralBoxSizer = new wxBoxSizer( wxVERTICAL );
	
	m_NoteBook = new wxNotebook( this, ID_NOTEBOOK, wxDefaultPosition, wxDefaultSize, 0 );
	m_PanelGeneral = new wxPanel( m_NoteBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* m_PanelPropertiesBoxSizer;
	m_PanelPropertiesBoxSizer = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerTexts;
	sbSizerTexts = new wxStaticBoxSizer( new wxStaticBox( m_PanelGeneral, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	m_itemsGrid = new WX_GRID( sbSizerTexts->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxBORDER_SIMPLE );
	
	// Grid
	m_itemsGrid->CreateGrid( 2, 11 );
	m_itemsGrid->EnableEditing( true );
	m_itemsGrid->EnableGridLines( true );
	m_itemsGrid->EnableDragGridSize( false );
	m_itemsGrid->SetMargins( 0, 0 );
	
	// Columns
	m_itemsGrid->SetColSize( 0, 116 );
	m_itemsGrid->SetColSize( 1, 53 );
	m_itemsGrid->SetColSize( 2, 96 );
	m_itemsGrid->SetColSize( 3, 96 );
	m_itemsGrid->SetColSize( 4, 96 );
	m_itemsGrid->SetColSize( 5, 53 );
	m_itemsGrid->SetColSize( 6, 106 );
	m_itemsGrid->SetColSize( 7, 80 );
	m_itemsGrid->SetColSize( 8, 48 );
	m_itemsGrid->SetColSize( 9, 96 );
	m_itemsGrid->SetColSize( 10, 96 );
	m_itemsGrid->EnableDragColMove( false );
	m_itemsGrid->EnableDragColSize( false );
	m_itemsGrid->SetColLabelSize( 22 );
	m_itemsGrid->SetColLabelValue( 0, _("Text Items") );
	m_itemsGrid->SetColLabelValue( 1, _("Show") );
	m_itemsGrid->SetColLabelValue( 2, _("Width") );
	m_itemsGrid->SetColLabelValue( 3, _("Height") );
	m_itemsGrid->SetColLabelValue( 4, _("Thickness") );
	m_itemsGrid->SetColLabelValue( 5, _("Italic") );
	m_itemsGrid->SetColLabelValue( 6, _("Layer") );
	m_itemsGrid->SetColLabelValue( 7, _("Orientation") );
	m_itemsGrid->SetColLabelValue( 8, _("Unconstrained") );
	m_itemsGrid->SetColLabelValue( 9, _("X Offset") );
	m_itemsGrid->SetColLabelValue( 10, _("Y Offset") );
	m_itemsGrid->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_itemsGrid->EnableDragRowSize( false );
	m_itemsGrid->SetRowLabelSize( 80 );
	m_itemsGrid->SetRowLabelValue( 0, _("Reference") );
	m_itemsGrid->SetRowLabelValue( 1, _("Value") );
	m_itemsGrid->SetRowLabelAlignment( wxALIGN_LEFT, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_itemsGrid->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	m_itemsGrid->SetMinSize( wxSize( 724,140 ) );
	
	sbSizerTexts->Add( m_itemsGrid, 1, wxEXPAND|wxBOTTOM, 5 );
	
	wxBoxSizer* bButtonSize;
	bButtonSize = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpAdd = new wxBitmapButton( sbSizerTexts->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	bButtonSize->Add( m_bpAdd, 0, 0, 5 );
	
	m_bpDelete = new wxBitmapButton( sbSizerTexts->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	bButtonSize->Add( m_bpDelete, 0, wxRIGHT|wxLEFT, 5 );
	
	
	bButtonSize->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	sbSizerTexts->Add( bButtonSize, 0, wxEXPAND, 5 );
	
	
	m_PanelPropertiesBoxSizer->Add( sbSizerTexts, 1, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	wxFlexGridSizer* fgSizerFPID;
	fgSizerFPID = new wxFlexGridSizer( 4, 2, 0, 0 );
	fgSizerFPID->AddGrowableCol( 1 );
	fgSizerFPID->SetFlexibleDirection( wxBOTH );
	fgSizerFPID->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticText* staticLibraryLabel;
	staticLibraryLabel = new wxStaticText( m_PanelGeneral, wxID_ANY, _("Library:"), wxDefaultPosition, wxDefaultSize, 0 );
	staticLibraryLabel->Wrap( -1 );
	fgSizerFPID->Add( staticLibraryLabel, 0, wxALL, 5 );
	
	m_libraryName = new wxStaticText( m_PanelGeneral, wxID_ANY, _("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_libraryName->Wrap( -1 );
	fgSizerFPID->Add( m_libraryName, 0, wxEXPAND|wxALL, 5 );
	
	wxStaticText* staticFPNameLabel;
	staticFPNameLabel = new wxStaticText( m_PanelGeneral, wxID_ANY, _("Footprint name:"), wxDefaultPosition, wxDefaultSize, 0 );
	staticFPNameLabel->Wrap( -1 );
	fgSizerFPID->Add( staticFPNameLabel, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5 );
	
	m_FootprintNameCtrl = new wxTextCtrl( m_PanelGeneral, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizerFPID->Add( m_FootprintNameCtrl, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticText* staticDescriptionLabel;
	staticDescriptionLabel = new wxStaticText( m_PanelGeneral, wxID_ANY, _("Description:"), wxDefaultPosition, wxDefaultSize, 0 );
	staticDescriptionLabel->Wrap( -1 );
	fgSizerFPID->Add( staticDescriptionLabel, 0, wxRIGHT|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_DocCtrl = new wxTextCtrl( m_PanelGeneral, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizerFPID->Add( m_DocCtrl, 0, wxALL|wxEXPAND, 5 );
	
	staticKeywordsLabel = new wxStaticText( m_PanelGeneral, wxID_ANY, _("Keywords:"), wxDefaultPosition, wxDefaultSize, 0 );
	staticKeywordsLabel->Wrap( -1 );
	fgSizerFPID->Add( staticKeywordsLabel, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_KeywordCtrl = new wxTextCtrl( m_PanelGeneral, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizerFPID->Add( m_KeywordCtrl, 0, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	
	m_PanelPropertiesBoxSizer->Add( fgSizerFPID, 0, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	wxBoxSizer* bSizerProperties;
	bSizerProperties = new wxBoxSizer( wxHORIZONTAL );
	
	wxString m_AutoPlaceCtrlChoices[] = { _("Free"), _("Lock footprint") };
	int m_AutoPlaceCtrlNChoices = sizeof( m_AutoPlaceCtrlChoices ) / sizeof( wxString );
	m_AutoPlaceCtrl = new wxRadioBox( m_PanelGeneral, wxID_ANY, _("Move and Place"), wxDefaultPosition, wxDefaultSize, m_AutoPlaceCtrlNChoices, m_AutoPlaceCtrlChoices, 1, wxRA_SPECIFY_COLS );
	m_AutoPlaceCtrl->SetSelection( 0 );
	bSizerProperties->Add( m_AutoPlaceCtrl, 1, wxRIGHT|wxLEFT, 5 );
	
	wxStaticBoxSizer* sbSizerAP;
	sbSizerAP = new wxStaticBoxSizer( new wxStaticBox( m_PanelGeneral, wxID_ANY, _("Auto-placement Rules") ), wxVERTICAL );
	
	wxBoxSizer* bSizerRotOpt;
	bSizerRotOpt = new wxBoxSizer( wxVERTICAL );
	
	m_allow90Label = new wxStaticText( sbSizerAP->GetStaticBox(), wxID_ANY, _("Allow 90 degree rotated placement:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_allow90Label->Wrap( -1 );
	m_allow90Label->SetFont( wxFont( 11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	
	bSizerRotOpt->Add( m_allow90Label, 0, 0, 5 );
	
	m_CostRot90Ctrl = new wxSlider( sbSizerAP->GetStaticBox(), wxID_ANY, 0, 0, 10, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS|wxSL_HORIZONTAL|wxSL_LABELS );
	bSizerRotOpt->Add( m_CostRot90Ctrl, 0, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	
	sbSizerAP->Add( bSizerRotOpt, 1, wxEXPAND|wxTOP, 5 );
	
	wxBoxSizer* bSizerMoveOpt;
	bSizerMoveOpt = new wxBoxSizer( wxVERTICAL );
	
	m_allow180Label = new wxStaticText( sbSizerAP->GetStaticBox(), wxID_ANY, _("Allow 180 degree rotated placement:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_allow180Label->Wrap( -1 );
	m_allow180Label->SetFont( wxFont( 11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	
	bSizerMoveOpt->Add( m_allow180Label, 0, wxTOP, 5 );
	
	m_CostRot180Ctrl = new wxSlider( sbSizerAP->GetStaticBox(), wxID_ANY, 0, 0, 10, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS|wxSL_HORIZONTAL|wxSL_LABELS );
	bSizerMoveOpt->Add( m_CostRot180Ctrl, 0, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	
	sbSizerAP->Add( bSizerMoveOpt, 1, wxEXPAND|wxTOP, 5 );
	
	
	bSizerProperties->Add( sbSizerAP, 1, wxEXPAND, 10 );
	
	wxString m_AttributsCtrlChoices[] = { _("Through hole"), _("Surface mount"), _("Virtual") };
	int m_AttributsCtrlNChoices = sizeof( m_AttributsCtrlChoices ) / sizeof( wxString );
	m_AttributsCtrl = new wxRadioBox( m_PanelGeneral, wxID_ANY, _("Fabrication Attributes"), wxDefaultPosition, wxDefaultSize, m_AttributsCtrlNChoices, m_AttributsCtrlChoices, 1, wxRA_SPECIFY_COLS );
	m_AttributsCtrl->SetSelection( 1 );
	bSizerProperties->Add( m_AttributsCtrl, 1, wxRIGHT|wxLEFT, 5 );
	
	
	m_PanelPropertiesBoxSizer->Add( bSizerProperties, 0, wxEXPAND|wxTOP|wxBOTTOM, 5 );
	
	
	m_PanelGeneral->SetSizer( m_PanelPropertiesBoxSizer );
	m_PanelGeneral->Layout();
	m_PanelPropertiesBoxSizer->Fit( m_PanelGeneral );
	m_NoteBook->AddPage( m_PanelGeneral, _("General"), false );
	m_PanelClearances = new wxPanel( m_NoteBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizerPanelClearances;
	bSizerPanelClearances = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerLocalProperties;
	sbSizerLocalProperties = new wxStaticBoxSizer( new wxStaticBox( m_PanelClearances, wxID_ANY, _("Clearances") ), wxVERTICAL );
	
	m_staticTextInfo = new wxStaticText( sbSizerLocalProperties->GetStaticBox(), wxID_ANY, _("Set values to 0 to use netclass values."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextInfo->Wrap( -1 );
	m_staticTextInfo->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	
	sbSizerLocalProperties->Add( m_staticTextInfo, 0, wxRIGHT, 10 );
	
	m_staticTextInfoValPos = new wxStaticText( sbSizerLocalProperties->GetStaticBox(), wxID_ANY, _("Positive clearance means area bigger than the pad (usual for mask clearance)."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextInfoValPos->Wrap( -1 );
	m_staticTextInfoValPos->SetFont( wxFont( 12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	
	sbSizerLocalProperties->Add( m_staticTextInfoValPos, 0, wxTOP|wxRIGHT, 10 );
	
	m_staticTextInfoValNeg = new wxStaticText( sbSizerLocalProperties->GetStaticBox(), wxID_ANY, _("Negative clearance means area smaller than the pad (usual for paste clearance)."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextInfoValNeg->Wrap( -1 );
	m_staticTextInfoValNeg->SetFont( wxFont( 12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	
	sbSizerLocalProperties->Add( m_staticTextInfoValNeg, 0, wxBOTTOM|wxRIGHT, 10 );
	
	wxFlexGridSizer* fgSizerClearances;
	fgSizerClearances = new wxFlexGridSizer( 5, 3, 0, 0 );
	fgSizerClearances->AddGrowableCol( 1 );
	fgSizerClearances->SetFlexibleDirection( wxBOTH );
	fgSizerClearances->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_NetClearanceLabel = new wxStaticText( sbSizerLocalProperties->GetStaticBox(), wxID_ANY, _("Pad clearance:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_NetClearanceLabel->Wrap( -1 );
	m_NetClearanceLabel->SetToolTip( _("This is the local net clearance for all pad of this footprint\nIf 0, the Netclass values are used\nThis value can be superseded by a pad local value.") );
	
	fgSizerClearances->Add( m_NetClearanceLabel, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_NetClearanceCtrl = new wxTextCtrl( sbSizerLocalProperties->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizerClearances->Add( m_NetClearanceCtrl, 1, wxEXPAND|wxALL, 5 );
	
	m_NetClearanceUnits = new wxStaticText( sbSizerLocalProperties->GetStaticBox(), wxID_ANY, _("unit"), wxDefaultPosition, wxDefaultSize, 0 );
	m_NetClearanceUnits->Wrap( -1 );
	fgSizerClearances->Add( m_NetClearanceUnits, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_SolderMaskMarginLabel = new wxStaticText( sbSizerLocalProperties->GetStaticBox(), wxID_ANY, _("Solder mask clearance:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_SolderMaskMarginLabel->Wrap( -1 );
	m_SolderMaskMarginLabel->SetToolTip( _("This is the local clearance between pads and the solder mask\nfor this footprint\nThis value can be superseded by a pad local value.\nIf 0, the global value is used") );
	
	fgSizerClearances->Add( m_SolderMaskMarginLabel, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_SolderMaskMarginCtrl = new wxTextCtrl( sbSizerLocalProperties->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizerClearances->Add( m_SolderMaskMarginCtrl, 1, wxALL|wxEXPAND, 5 );
	
	m_SolderMaskMarginUnits = new wxStaticText( sbSizerLocalProperties->GetStaticBox(), wxID_ANY, _("unit"), wxDefaultPosition, wxDefaultSize, 0 );
	m_SolderMaskMarginUnits->Wrap( -1 );
	fgSizerClearances->Add( m_SolderMaskMarginUnits, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_SolderPasteMarginLabel = new wxStaticText( sbSizerLocalProperties->GetStaticBox(), wxID_ANY, _("Solder paste clearance:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_SolderPasteMarginLabel->Wrap( -1 );
	m_SolderPasteMarginLabel->SetToolTip( _("This is the local clearance between pads and the solder paste\nfor this footprint.\nThis value can be superseded by a pad local values.\nThe final clearance value is the sum of this value and the clearance value ratio\nA negative value means a smaller mask size than pad size") );
	
	fgSizerClearances->Add( m_SolderPasteMarginLabel, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5 );
	
	m_SolderPasteMarginCtrl = new wxTextCtrl( sbSizerLocalProperties->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizerClearances->Add( m_SolderPasteMarginCtrl, 1, wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
	m_SolderPasteMarginUnits = new wxStaticText( sbSizerLocalProperties->GetStaticBox(), wxID_ANY, _("unit"), wxDefaultPosition, wxDefaultSize, 0 );
	m_SolderPasteMarginUnits->Wrap( -1 );
	fgSizerClearances->Add( m_SolderPasteMarginUnits, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5 );
	
	m_staticTextRatio = new wxStaticText( sbSizerLocalProperties->GetStaticBox(), wxID_ANY, _("Solder paste ratio clearance:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextRatio->Wrap( -1 );
	m_staticTextRatio->SetToolTip( _("This is the local clearance ratio in per cent between pads and the solder paste\nfor this footprint.\nA value of 10 means the clearance value is 10 per cent of the pad size\nThis value can be superseded by a pad local value.\nThe final clearance value is the sum of this value and the clearance value\nA negative value means a smaller mask size than pad size.") );
	
	fgSizerClearances->Add( m_staticTextRatio, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_SolderPasteMarginRatioCtrl = new TEXT_CTRL_EVAL( sbSizerLocalProperties->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizerClearances->Add( m_SolderPasteMarginRatioCtrl, 1, wxALL|wxEXPAND, 5 );
	
	m_SolderPasteRatioMarginUnits = new wxStaticText( sbSizerLocalProperties->GetStaticBox(), wxID_ANY, _("%"), wxDefaultPosition, wxDefaultSize, 0 );
	m_SolderPasteRatioMarginUnits->Wrap( -1 );
	fgSizerClearances->Add( m_SolderPasteRatioMarginUnits, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	
	sbSizerLocalProperties->Add( fgSizerClearances, 1, wxEXPAND, 5 );
	
	m_staticTextInfoCopper = new wxStaticText( sbSizerLocalProperties->GetStaticBox(), wxID_ANY, _("Note: solder mask and paste values are used only for pads on copper layers."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextInfoCopper->Wrap( -1 );
	m_staticTextInfoCopper->SetFont( wxFont( 12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	
	sbSizerLocalProperties->Add( m_staticTextInfoCopper, 0, wxEXPAND|wxTOP|wxBOTTOM|wxRIGHT, 10 );
	
	
	bSizerPanelClearances->Add( sbSizerLocalProperties, 0, wxEXPAND|wxALL, 10 );
	
	wxStaticBoxSizer* sbSizer5;
	sbSizer5 = new wxStaticBoxSizer( new wxStaticBox( m_PanelClearances, wxID_ANY, _("Connection to Copper Zones") ), wxHORIZONTAL );
	
	m_staticText16 = new wxStaticText( sbSizer5->GetStaticBox(), wxID_ANY, _("Pad connection to zones:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	sbSizer5->Add( m_staticText16, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT, 5 );
	
	wxString m_ZoneConnectionChoiceChoices[] = { _("Use zone setting"), _("Solid"), _("Thermal relief"), _("None") };
	int m_ZoneConnectionChoiceNChoices = sizeof( m_ZoneConnectionChoiceChoices ) / sizeof( wxString );
	m_ZoneConnectionChoice = new wxChoice( sbSizer5->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_ZoneConnectionChoiceNChoices, m_ZoneConnectionChoiceChoices, 0 );
	m_ZoneConnectionChoice->SetSelection( 0 );
	sbSizer5->Add( m_ZoneConnectionChoice, 1, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	
	bSizerPanelClearances->Add( sbSizer5, 0, wxALL|wxEXPAND, 10 );
	
	
	m_PanelClearances->SetSizer( bSizerPanelClearances );
	m_PanelClearances->Layout();
	bSizerPanelClearances->Fit( m_PanelClearances );
	m_NoteBook->AddPage( m_PanelClearances, _("Local Clearance and Settings"), false );
	m_Panel3D = new wxPanel( m_NoteBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	bSizerMain3D = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( m_Panel3D, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	m_modelsGrid = new wxGrid( sbSizer3->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE );
	
	// Grid
	m_modelsGrid->CreateGrid( 3, 2 );
	m_modelsGrid->EnableEditing( true );
	m_modelsGrid->EnableGridLines( false );
	m_modelsGrid->EnableDragGridSize( false );
	m_modelsGrid->SetMargins( 0, 0 );
	
	// Columns
	m_modelsGrid->SetColSize( 0, 650 );
	m_modelsGrid->SetColSize( 1, 65 );
	m_modelsGrid->EnableDragColMove( false );
	m_modelsGrid->EnableDragColSize( false );
	m_modelsGrid->SetColLabelSize( 22 );
	m_modelsGrid->SetColLabelValue( 0, _("3D Model(s)") );
	m_modelsGrid->SetColLabelValue( 1, _("Preview") );
	m_modelsGrid->SetColLabelAlignment( wxALIGN_LEFT, wxALIGN_CENTRE );
	
	// Rows
	m_modelsGrid->EnableDragRowSize( false );
	m_modelsGrid->SetRowLabelSize( 0 );
	m_modelsGrid->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_modelsGrid->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	sbSizer3->Add( m_modelsGrid, 1, wxEXPAND|wxRIGHT, 5 );
	
	wxBoxSizer* bSizer3DButtons;
	bSizer3DButtons = new wxBoxSizer( wxHORIZONTAL );
	
	m_button3DShapeAdd = new wxBitmapButton( sbSizer3->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	bSizer3DButtons->Add( m_button3DShapeAdd, 0, wxTOP|wxBOTTOM, 5 );
	
	m_button3DShapeBrowse = new wxBitmapButton( sbSizer3->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	bSizer3DButtons->Add( m_button3DShapeBrowse, 0, wxALL, 5 );
	
	
	bSizer3DButtons->Add( 0, 0, 0, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	m_button3DShapeRemove = new wxBitmapButton( sbSizer3->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	bSizer3DButtons->Add( m_button3DShapeRemove, 0, wxTOP|wxBOTTOM, 5 );
	
	
	bSizer3DButtons->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_buttonConfig3DPaths = new wxButton( sbSizer3->GetStaticBox(), wxID_ANY, _("Configure Paths..."), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3DButtons->Add( m_buttonConfig3DPaths, 0, wxALL, 5 );
	
	
	sbSizer3->Add( bSizer3DButtons, 0, wxEXPAND, 5 );
	
	
	bSizerMain3D->Add( sbSizer3, 5, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	bLowerSizer3D = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerMain3D->Add( bLowerSizer3D, 10, wxEXPAND, 5 );
	
	
	m_Panel3D->SetSizer( bSizerMain3D );
	m_Panel3D->Layout();
	bSizerMain3D->Fit( m_Panel3D );
	m_NoteBook->AddPage( m_Panel3D, _("3D Settings"), true );
	
	m_GeneralBoxSizer->Add( m_NoteBook, 1, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );
	
	m_sdbSizerStdButtons = new wxStdDialogButtonSizer();
	m_sdbSizerStdButtonsOK = new wxButton( this, wxID_OK );
	m_sdbSizerStdButtons->AddButton( m_sdbSizerStdButtonsOK );
	m_sdbSizerStdButtonsCancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizerStdButtons->AddButton( m_sdbSizerStdButtonsCancel );
	m_sdbSizerStdButtons->Realize();
	
	bSizer16->Add( m_sdbSizerStdButtons, 1, wxEXPAND|wxALL, 5 );
	
	
	m_GeneralBoxSizer->Add( bSizer16, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( m_GeneralBoxSizer );
	this->Layout();
	m_GeneralBoxSizer->Fit( this );
	
	// Connect Events
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( DIALOG_FOOTPRINT_FP_EDITOR_BASE::OnInitDlg ) );
	this->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( DIALOG_FOOTPRINT_FP_EDITOR_BASE::OnUpdateUI ) );
	m_itemsGrid->Connect( wxEVT_SIZE, wxSizeEventHandler( DIALOG_FOOTPRINT_FP_EDITOR_BASE::OnGridSize ), NULL, this );
	m_bpAdd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_FOOTPRINT_FP_EDITOR_BASE::OnAddField ), NULL, this );
	m_bpDelete->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_FOOTPRINT_FP_EDITOR_BASE::OnDeleteField ), NULL, this );
	m_modelsGrid->Connect( wxEVT_GRID_CELL_CHANGED, wxGridEventHandler( DIALOG_FOOTPRINT_FP_EDITOR_BASE::On3DModelCellChanged ), NULL, this );
	m_modelsGrid->Connect( wxEVT_GRID_SELECT_CELL, wxGridEventHandler( DIALOG_FOOTPRINT_FP_EDITOR_BASE::On3DModelSelected ), NULL, this );
	m_button3DShapeAdd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_FOOTPRINT_FP_EDITOR_BASE::OnAdd3DRow ), NULL, this );
	m_button3DShapeBrowse->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_FOOTPRINT_FP_EDITOR_BASE::OnAdd3DModel ), NULL, this );
	m_button3DShapeRemove->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_FOOTPRINT_FP_EDITOR_BASE::OnRemove3DModel ), NULL, this );
	m_buttonConfig3DPaths->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_FOOTPRINT_FP_EDITOR_BASE::Cfg3DPath ), NULL, this );
}

DIALOG_FOOTPRINT_FP_EDITOR_BASE::~DIALOG_FOOTPRINT_FP_EDITOR_BASE()
{
	// Disconnect Events
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( DIALOG_FOOTPRINT_FP_EDITOR_BASE::OnInitDlg ) );
	this->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( DIALOG_FOOTPRINT_FP_EDITOR_BASE::OnUpdateUI ) );
	m_itemsGrid->Disconnect( wxEVT_SIZE, wxSizeEventHandler( DIALOG_FOOTPRINT_FP_EDITOR_BASE::OnGridSize ), NULL, this );
	m_bpAdd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_FOOTPRINT_FP_EDITOR_BASE::OnAddField ), NULL, this );
	m_bpDelete->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_FOOTPRINT_FP_EDITOR_BASE::OnDeleteField ), NULL, this );
	m_modelsGrid->Disconnect( wxEVT_GRID_CELL_CHANGED, wxGridEventHandler( DIALOG_FOOTPRINT_FP_EDITOR_BASE::On3DModelCellChanged ), NULL, this );
	m_modelsGrid->Disconnect( wxEVT_GRID_SELECT_CELL, wxGridEventHandler( DIALOG_FOOTPRINT_FP_EDITOR_BASE::On3DModelSelected ), NULL, this );
	m_button3DShapeAdd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_FOOTPRINT_FP_EDITOR_BASE::OnAdd3DRow ), NULL, this );
	m_button3DShapeBrowse->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_FOOTPRINT_FP_EDITOR_BASE::OnAdd3DModel ), NULL, this );
	m_button3DShapeRemove->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_FOOTPRINT_FP_EDITOR_BASE::OnRemove3DModel ), NULL, this );
	m_buttonConfig3DPaths->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_FOOTPRINT_FP_EDITOR_BASE::Cfg3DPath ), NULL, this );
	
}
