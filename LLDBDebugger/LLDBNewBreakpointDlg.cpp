#include "LLDBNewBreakpointDlg.h"

LLDBNewBreakpointDlg::LLDBNewBreakpointDlg(wxWindow* parent)
    : LLDBNewBreakpointDlgBase(parent)
{
    m_checkBoxFileLine->SetValue(true);
}

LLDBNewBreakpointDlg::~LLDBNewBreakpointDlg()
{
}

void LLDBNewBreakpointDlg::OnFileLineEnabledUI(wxUpdateUIEvent& event)
{
    event.Enable(m_checkBoxFileLine->IsChecked());
}

void LLDBNewBreakpointDlg::OnFuncNameUI(wxUpdateUIEvent& event)
{
    event.Enable(m_checkBoxFuncName->IsChecked());
}

void LLDBNewBreakpointDlg::OnCheckFileAndLine(wxCommandEvent& event)
{
    m_checkBoxFuncName->SetValue( !event.IsChecked() );
}

void LLDBNewBreakpointDlg::OnCheckFuncName(wxCommandEvent& event)
{
    m_checkBoxFileLine->SetValue( !event.IsChecked() );
}

LLDBBreakpoint LLDBNewBreakpointDlg::GetBreakpoint()
{
    if ( m_checkBoxFileLine->IsChecked() ) {
        
        long nLine = 0;
        wxString strLine( m_textCtrlLine->GetValue() );
        strLine.ToCLong( &nLine );
        LLDBBreakpoint bp(m_textCtrlFile->GetValue(), nLine);
        return bp;
        
    } else if ( m_checkBoxFuncName->IsChecked() ) {
        LLDBBreakpoint bp(m_textCtrlFunctionName->GetValue());
        return bp;
        
    } else {
        return LLDBBreakpoint();
    }
}