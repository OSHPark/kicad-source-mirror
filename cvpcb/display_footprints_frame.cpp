/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2018 Jean-Pierre Charras, jp.charras at wanadoo.fr
 * Copyright (C) 2015 Wayne Stambaugh <stambaughw@gmail.com>
 * Copyright (C) 2007-2018 KiCad Developers, see AUTHORS.txt for contributors.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, you may find one here:
 * http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
 * or you may search the http://www.gnu.org website for the version 2 license,
 * or you may write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

/**
 * @file display_footprints_frame.cpp
 */

#include <fctsys.h>
#include <common.h>
#include <gal/graphics_abstraction_layer.h>
#include <class_drawpanel.h>
#include <class_draw_panel_gal.h>
#include <pcb_draw_panel_gal.h>
#include <confirm.h>
#include <macros.h>
#include <bitmaps.h>
#include <msgpanel.h>
#include <wildcards_and_files_ext.h>
#include <lib_id.h>
#include <fp_lib_table.h>

#include <io_mgr.h>
#include <class_module.h>
#include <class_board.h>
#include <pcb_painter.h>

#include <cvpcb_mainframe.h>
#include <display_footprints_frame.h>
#include <cvpcb_id.h>
#include <listboxes.h>

#include <3d_viewer/eda_3d_viewer.h>
#include <view/view.h>

#include <tool/tool_manager.h>
#include <tool/tool_dispatcher.h>
#include <tool/common_tools.h>
#include "tools/cvpcb_actions.h"

// Colors for layers and items
COLORS_DESIGN_SETTINGS g_ColorsSettings( FRAME_CVPCB_DISPLAY );


BEGIN_EVENT_TABLE( DISPLAY_FOOTPRINTS_FRAME, PCB_BASE_FRAME )
    EVT_CLOSE( DISPLAY_FOOTPRINTS_FRAME::OnCloseWindow )
    EVT_TOOL( ID_OPTIONS_SETUP, DISPLAY_FOOTPRINTS_FRAME::InstallOptionsDisplay )
    EVT_TOOL( ID_CVPCB_SHOW3D_FRAME, DISPLAY_FOOTPRINTS_FRAME::Show3D_Frame )

    /*
    EVT_TOOL  and EVT_UPDATE_UI for:
      ID_TB_OPTIONS_SHOW_MODULE_TEXT_SKETCH,
      ID_TB_OPTIONS_SHOW_MODULE_EDGE_SKETCH,
      ID_TB_OPTIONS_SHOW_PADS_SKETCH
      are managed in PCB_BASE_FRAME
    */
END_EVENT_TABLE()


DISPLAY_FOOTPRINTS_FRAME::DISPLAY_FOOTPRINTS_FRAME( KIWAY* aKiway, wxWindow* aParent ) :
    PCB_BASE_FRAME( aKiway, aParent, FRAME_CVPCB_DISPLAY, _( "Footprint Viewer" ),
                    wxDefaultPosition, wxDefaultSize,
                    KICAD_DEFAULT_DRAWFRAME_STYLE, FOOTPRINTVIEWER_FRAME_NAME )
{
    m_showAxis = true;         // true to draw axis.

    // Give an icon
    wxIcon  icon;
    icon.CopyFromBitmap( KiBitmap( icon_cvpcb_xpm ) );
    SetIcon( icon );

    SetBoard( new BOARD() );
    SetScreen( new PCB_SCREEN( GetPageSizeIU() ) );

    LoadSettings( config() );

    // Initialize grid id to a default value if not found in config or incorrect:
    if( !( GetScreen()->GridExists( m_LastGridSizeId + ID_POPUP_GRID_LEVEL_1000 ) ) )
        m_LastGridSizeId = ID_POPUP_GRID_LEVEL_500 - ID_POPUP_GRID_LEVEL_1000;

    GetScreen()->SetGrid( m_LastGridSizeId + ID_POPUP_GRID_LEVEL_1000 );

    // Initialize some display options
    auto displ_opts = (PCB_DISPLAY_OPTIONS*)GetDisplayOptions();
    displ_opts->m_DisplayPadIsol = false;      // Pad clearance has no meaning here

    // Track and via clearance has no meaning here.
    displ_opts->m_ShowTrackClearanceMode = PCB_DISPLAY_OPTIONS::DO_NOT_SHOW_CLEARANCE;

    SetSize( m_FramePos.x, m_FramePos.y, m_FrameSize.x, m_FrameSize.y );
    ReCreateHToolbar();
    ReCreateVToolbar();
    ReCreateOptToolbar();

    // Create GAL canvas
    EDA_DRAW_PANEL_GAL::GAL_TYPE backend = EDA_DRAW_PANEL_GAL::GAL_TYPE_CAIRO;
    //EDA_DRAW_PANEL_GAL::GAL_TYPE backend = EDA_DRAW_PANEL_GAL::GAL_TYPE_NONE;
    PCB_DRAW_PANEL_GAL* gal_drawPanel = new PCB_DRAW_PANEL_GAL( this, -1, wxPoint( 0, 0 ), m_FrameSize,
                                                            GetGalDisplayOptions(), backend );
    SetGalCanvas( gal_drawPanel );

    m_auimgr.SetManagedWindow( this );

    EDA_PANEINFO horiz;
    horiz.HorizontalToolbarPane();

    EDA_PANEINFO vert;
    vert.VerticalToolbarPane();

    EDA_PANEINFO mesg;
    mesg.MessageToolbarPane();

    m_auimgr.AddPane( m_mainToolBar,
                      wxAuiPaneInfo( horiz ).Name( wxT( "m_mainToolBar" ) ).Top(). Row( 0 ) );

    if( m_drawToolBar )    // Currently, no vertical right toolbar.
        m_auimgr.AddPane( m_drawToolBar,
                          wxAuiPaneInfo( vert ).Name( wxT( "m_drawToolBar" ) ).Right() );

    if( m_canvas )
        m_auimgr.AddPane( m_canvas,
                      wxAuiPaneInfo().Name( wxT( "DrawFrame" ) ).CentrePane() );

    if( GetGalCanvas() )
        m_auimgr.AddPane( (wxWindow*) GetGalCanvas(),
                          wxAuiPaneInfo().Name( wxT( "DrawFrameGal" ) ).CentrePane().Hide() );

    m_auimgr.AddPane( m_messagePanel,
                      wxAuiPaneInfo( mesg ).Name( wxT( "MsgPanel" ) ).Bottom().Layer(10) );

    m_auimgr.AddPane( m_optionsToolBar,
                      wxAuiPaneInfo( vert ).Name( wxT( "m_optionsToolBar" ) ).Left() );

    m_auimgr.Update();

    // Create the manager and dispatcher & route draw panel events to the dispatcher
    m_toolManager = new TOOL_MANAGER;
    m_toolManager->SetEnvironment( GetBoard(), gal_drawPanel->GetView(),
                                   gal_drawPanel->GetViewControls(), this );
    m_actions = new CVPCB_ACTIONS();
    m_toolDispatcher = new TOOL_DISPATCHER( m_toolManager, m_actions );
    gal_drawPanel->SetEventDispatcher( m_toolDispatcher );

    m_actions->RegisterAllTools( m_toolManager );
    m_toolManager->InitTools();

    // Run the control tool, it is supposed to be always active
    m_toolManager->InvokeTool( "cvpcb.InteractiveSelection" );

    auto& galOpts = GetGalDisplayOptions();
    galOpts.m_fullscreenCursor = true;
    galOpts.m_forceDisplayCursor = true;
    galOpts.m_axesEnabled = true;

    UseGalCanvas( backend != EDA_DRAW_PANEL_GAL::GAL_TYPE_NONE );
    updateView();


    Show( true );
}


DISPLAY_FOOTPRINTS_FRAME::~DISPLAY_FOOTPRINTS_FRAME()
{
    if( IsGalCanvasActive() )
        GetGalCanvas()->StopDrawing();

    delete GetScreen();
    SetScreen( NULL );      // Be sure there is no double deletion
}


void DISPLAY_FOOTPRINTS_FRAME::OnCloseWindow( wxCloseEvent& event )
{
    // Currently, do nothing
    event.Skip();
}


void DISPLAY_FOOTPRINTS_FRAME::ReCreateVToolbar()
{
    // Currently, no vertical right toolbar.
    // So do nothing
}


void DISPLAY_FOOTPRINTS_FRAME::ReCreateOptToolbar()
{
    if( m_optionsToolBar )
        return;

    // Create options tool bar.
    m_optionsToolBar = new wxAuiToolBar( this, ID_OPT_TOOLBAR, wxDefaultPosition, wxDefaultSize,
                                         KICAD_AUI_TB_STYLE | wxAUI_TB_VERTICAL );

    m_optionsToolBar->AddTool( ID_TB_OPTIONS_SHOW_GRID, wxEmptyString, KiBitmap( grid_xpm ),
                               _( "Hide grid" ), wxITEM_CHECK );

    m_optionsToolBar->AddTool( ID_TB_OPTIONS_SHOW_POLAR_COORD, wxEmptyString,
                               KiBitmap( polar_coord_xpm ),
                               _( "Display polar coordinates" ), wxITEM_CHECK );

    m_optionsToolBar->AddTool( ID_TB_OPTIONS_SELECT_UNIT_INCH, wxEmptyString,
                               KiBitmap( unit_inch_xpm ),
                               _( "Set units to inches" ), wxITEM_CHECK );

    m_optionsToolBar->AddTool( ID_TB_OPTIONS_SELECT_UNIT_MM, wxEmptyString,
                               KiBitmap( unit_mm_xpm ),
                               _( "Set units to millimeters" ), wxITEM_CHECK );

#ifndef __APPLE__
    m_optionsToolBar->AddTool( ID_TB_OPTIONS_SELECT_CURSOR, wxEmptyString,
                               KiBitmap( cursor_shape_xpm ),
                               _( "Change cursor shape" ), wxITEM_CHECK  );
#else
    m_optionsToolBar->AddTool( ID_TB_OPTIONS_SELECT_CURSOR, wxEmptyString,
                               KiBitmap( cursor_shape_xpm ),
                               _( "Change cursor shape (not supported in Legacy Toolset)" ),
                               wxITEM_CHECK  );
#endif

    m_optionsToolBar->AddSeparator();
    m_optionsToolBar->AddTool( ID_TB_OPTIONS_SHOW_PADS_SKETCH, wxEmptyString,
                               KiBitmap( pad_sketch_xpm ),
                               _( "Show pads in outline mode" ), wxITEM_CHECK  );

    m_optionsToolBar->AddTool( ID_TB_OPTIONS_SHOW_MODULE_TEXT_SKETCH, wxEmptyString,
                               KiBitmap( text_sketch_xpm ),
                               _( "Show texts in line mode" ), wxITEM_CHECK  );

    m_optionsToolBar->AddTool( ID_TB_OPTIONS_SHOW_MODULE_EDGE_SKETCH, wxEmptyString,
                               KiBitmap( show_mod_edge_xpm ),
                               _( "Show outlines in line mode" ), wxITEM_CHECK  );

    m_optionsToolBar->Realize();
}


void DISPLAY_FOOTPRINTS_FRAME::ReCreateHToolbar()
{
    if( m_mainToolBar != NULL )
        return;

    m_mainToolBar = new wxAuiToolBar( this, ID_H_TOOLBAR, wxDefaultPosition, wxDefaultSize,
                                      KICAD_AUI_TB_STYLE | wxAUI_TB_HORZ_LAYOUT );

    m_mainToolBar->AddTool( ID_OPTIONS_SETUP, wxEmptyString, KiBitmap( display_options_xpm ),
                            _( "Display options" ) );

    m_mainToolBar->AddSeparator();

    m_mainToolBar->AddTool( ID_ZOOM_IN, wxEmptyString, KiBitmap( zoom_in_xpm ),
                            _( "Zoom in (F1)" ) );

    m_mainToolBar->AddTool( ID_ZOOM_OUT, wxEmptyString, KiBitmap( zoom_out_xpm ),
                            _( "Zoom out (F2)" ) );

    m_mainToolBar->AddTool( ID_ZOOM_REDRAW, wxEmptyString, KiBitmap( zoom_redraw_xpm ),
                            _( "Redraw view (F3)" ) );

    m_mainToolBar->AddTool( ID_ZOOM_PAGE, wxEmptyString, KiBitmap( zoom_fit_in_page_xpm ),
                            _( "Zoom to fit footprint (Home)" ) );

    m_mainToolBar->AddSeparator();
    m_mainToolBar->AddTool( ID_CVPCB_SHOW3D_FRAME, wxEmptyString, KiBitmap( three_d_xpm ),
                            _( "3D Display (Alt+3)" ) );

    // after adding the buttons to the toolbar, must call Realize() to reflect
    // the changes
    m_mainToolBar->Realize();
}


void DISPLAY_FOOTPRINTS_FRAME::UseGalCanvas( bool aEnable )
{
    PCB_BASE_FRAME::UseGalCanvas( aEnable );
}


void DISPLAY_FOOTPRINTS_FRAME::applyDisplaySettingsToGAL()
{
        auto view = GetGalCanvas()->GetView();
        auto painter = static_cast<KIGFX::PCB_PAINTER*>( view->GetPainter() );
        KIGFX::PCB_RENDER_SETTINGS* settings = painter->GetSettings();
        settings->LoadDisplayOptions( &m_DisplayOptions, false );

        view->MarkTargetDirty( KIGFX::TARGET_NONCACHED );
}


void DISPLAY_FOOTPRINTS_FRAME::OnLeftClick( wxDC* DC, const wxPoint& MousePos )
{
}


void DISPLAY_FOOTPRINTS_FRAME::OnLeftDClick( wxDC* DC, const wxPoint& MousePos )
{
}


bool DISPLAY_FOOTPRINTS_FRAME::OnRightClick( const wxPoint& MousePos, wxMenu* PopMenu )
{
    return true;
}


bool DISPLAY_FOOTPRINTS_FRAME::GeneralControl( wxDC* aDC, const wxPoint& aPosition,
        EDA_KEY aHotKey )
{
    bool eventHandled = true;

    // Filter out the 'fake' mouse motion after a keyboard movement
    if( !aHotKey && m_movingCursorWithKeyboard )
    {
        m_movingCursorWithKeyboard = false;
        return false;
    }

    wxCommandEvent cmd( wxEVT_COMMAND_MENU_SELECTED );
    cmd.SetEventObject( this );

    wxPoint pos = aPosition;
    wxPoint oldpos = GetCrossHairPosition();
    GeneralControlKeyMovement( aHotKey, &pos, true );

    switch( aHotKey )
    {
    case WXK_F1:
        cmd.SetId( ID_KEY_ZOOM_IN );
        GetEventHandler()->ProcessEvent( cmd );
        break;

    case WXK_F2:
        cmd.SetId( ID_KEY_ZOOM_OUT );
        GetEventHandler()->ProcessEvent( cmd );
        break;

    case WXK_F3:
        cmd.SetId( ID_ZOOM_REDRAW );
        GetEventHandler()->ProcessEvent( cmd );
        break;

    case WXK_F4:
        cmd.SetId( ID_POPUP_ZOOM_CENTER );
        GetEventHandler()->ProcessEvent( cmd );
        break;

    case WXK_HOME:
        cmd.SetId( ID_ZOOM_PAGE );
        GetEventHandler()->ProcessEvent( cmd );
        break;

    case ' ':
        GetScreen()->m_O_Curseur = GetCrossHairPosition();
        break;

    case GR_KB_ALT + '3':
        cmd.SetId( ID_CVPCB_SHOW3D_FRAME );
        GetEventHandler()->ProcessEvent( cmd );
        break;

    default:
        eventHandled = false;
    }

    SetCrossHairPosition( pos );
    RefreshCrossHair( oldpos, aPosition, aDC );

    UpdateStatusBar();    /* Display new cursor coordinates */

    return eventHandled;
}


void DISPLAY_FOOTPRINTS_FRAME::Show3D_Frame( wxCommandEvent& event )
{
    bool forceRecreateIfNotOwner = true;
    CreateAndShow3D_Frame( forceRecreateIfNotOwner );
}


/**
 * Virtual function needed by the PCB_SCREEN class derived from BASE_SCREEN
 * this is a virtual pure function in BASE_SCREEN
 * do nothing in Cvpcb
 * could be removed later
 */
void PCB_SCREEN::ClearUndoORRedoList( UNDO_REDO_CONTAINER&, int )
{
}


bool DISPLAY_FOOTPRINTS_FRAME::IsGridVisible() const
{
    return m_drawGrid;
}


void DISPLAY_FOOTPRINTS_FRAME::SetGridVisibility(bool aVisible)
{
    m_drawGrid = aVisible;
}


COLOR4D DISPLAY_FOOTPRINTS_FRAME::GetGridColor()
{
    return COLOR4D( DARKGRAY );
}


MODULE* DISPLAY_FOOTPRINTS_FRAME::Get_Module( const wxString& aFootprintName )
{
    MODULE* footprint = NULL;

    try
    {
        LIB_ID fpid;

        if( fpid.Parse( aFootprintName, LIB_ID::ID_PCB ) >= 0 )
        {
            DisplayInfoMessage( this, wxString::Format( _( "Footprint ID \"%s\" is not valid." ),
                                                        GetChars( aFootprintName ) ) );
            return NULL;
        }

        std::string nickname = fpid.GetLibNickname();
        std::string fpname   = fpid.GetLibItemName();

        wxLogDebug( wxT( "Load footprint \"%s\" from library \"%s\"." ),
                    fpname.c_str(), nickname.c_str()  );

        footprint = Prj().PcbFootprintLibs( Kiway() )->FootprintLoad(
                FROM_UTF8( nickname.c_str() ), FROM_UTF8( fpname.c_str() ) );
    }
    catch( const IO_ERROR& ioe )
    {
        DisplayError( this, ioe.What() );
        return NULL;
    }

    if( footprint )
    {
        footprint->SetParent( (EDA_ITEM*) GetBoard() );
        footprint->SetPosition( wxPoint( 0, 0 ) );
        return footprint;
    }

    wxString msg = wxString::Format( _( "Footprint \"%s\" not found" ), aFootprintName.GetData() );
    DisplayError( this, msg );
    return NULL;
}


void DISPLAY_FOOTPRINTS_FRAME::InitDisplay()
{
    CVPCB_MAINFRAME*      parentframe = (CVPCB_MAINFRAME *) GetParent();
    MODULE*               module = nullptr;
    const FOOTPRINT_INFO* module_info = nullptr;

    if( GetBoard()->m_Modules.GetCount() )
        GetBoard()->m_Modules.DeleteAll();

    wxString footprintName = parentframe->GetSelectedFootprint();

    if( footprintName.IsEmpty() )
    {
        COMPONENT* comp = parentframe->GetSelectedComponent();

        if( comp )
            footprintName = comp->GetFPID().GetUniStringLibId();
    }

    if( !footprintName.IsEmpty() )
    {
        SetTitle( wxString::Format( _( "Footprint: %s" ), footprintName ) );

        module = Get_Module( footprintName );

        module_info = parentframe->m_FootprintsList->GetModuleInfo( footprintName );
    }

    if( module )
        GetBoard()->m_Modules.PushBack( module );

    if( module_info )
        SetStatusText( wxString::Format( _( "Lib: %s" ), module_info->GetLibNickname() ), 0 );
    else
        SetStatusText( wxEmptyString, 0 );

    updateView();

    UpdateStatusBar();
    Zoom_Automatique( false );
    GetCanvas()->Refresh();
    Update3DView();
}


void DISPLAY_FOOTPRINTS_FRAME::updateView()
{
    if( IsGalCanvasActive() )
    {
        PCB_DRAW_PANEL_GAL* dp = static_cast<PCB_DRAW_PANEL_GAL*>( GetGalCanvas() );
        dp->UseColorScheme( &Settings().Colors() );
        dp->DisplayBoard( GetBoard() );
        m_toolManager->ResetTools( TOOL_BASE::MODEL_RELOAD );
        m_toolManager->RunAction( ACTIONS::zoomFitScreen, true );
        UpdateMsgPanel();
    }
}


void DISPLAY_FOOTPRINTS_FRAME::UpdateMsgPanel()
{
    MODULE* footprint = GetBoard()->m_Modules;
    MSG_PANEL_ITEMS items;

    if( footprint )
    {
        footprint->GetMsgPanelInfo( m_UserUnits, items );
    }

    SetMsgPanel( items );
}


void DISPLAY_FOOTPRINTS_FRAME::RedrawActiveWindow( wxDC* DC, bool EraseBg )
{
    if( !GetBoard() )
        return;

    m_canvas->DrawBackGround( DC );
    GetBoard()->Draw( m_canvas, DC, GR_COPY );

    UpdateMsgPanel();

    m_canvas->DrawCrossHair( DC );
}


/*
 * Redraw the BOARD items but not cursors, axis or grid.
 */
void BOARD::Draw( EDA_DRAW_PANEL* aPanel, wxDC* aDC,
                  GR_DRAWMODE aDrawMode, const wxPoint& aOffset )
{
    if( m_Modules )
    {
        m_Modules->Draw( aPanel, aDC, GR_COPY );
    }
}
