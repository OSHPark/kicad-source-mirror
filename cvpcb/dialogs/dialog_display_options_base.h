///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jul 11 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __DIALOG_DISPLAY_OPTIONS_BASE_H__
#define __DIALOG_DISPLAY_OPTIONS_BASE_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include "dialog_shim.h"
#include <wx/string.h>
#include <wx/checkbox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

#define ID_PADFILL_OPT 1000

///////////////////////////////////////////////////////////////////////////////
/// Class DIALOG_FOOTPRINTS_DISPLAY_OPTIONS_BASE
///////////////////////////////////////////////////////////////////////////////
class DIALOG_FOOTPRINTS_DISPLAY_OPTIONS_BASE : public DIALOG_SHIM
{
	private:
	
	protected:
		wxCheckBox* m_EdgesDisplayOption;
		wxCheckBox* m_TextDisplayOption;
		wxCheckBox* m_ShowPadSketch;
		wxCheckBox* m_ShowPadNum;
		wxCheckBox* m_enableZoomNoCenter;
		wxCheckBox* m_enableMousewheelPan;
		wxCheckBox* m_enableAutoPan;
		wxStaticLine* m_staticline1;
		wxStdDialogButtonSizer* m_sdbSizer;
		wxButton* m_sdbSizerOK;
		wxButton* m_sdbSizerApply;
		wxButton* m_sdbSizerCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnApplyClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		DIALOG_FOOTPRINTS_DISPLAY_OPTIONS_BASE( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Display Options"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER ); 
		~DIALOG_FOOTPRINTS_DISPLAY_OPTIONS_BASE();
	
};

#endif //__DIALOG_DISPLAY_OPTIONS_BASE_H__
