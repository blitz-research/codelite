#ifndef LLDBNEWBREAKPOINTDLG_H
#define LLDBNEWBREAKPOINTDLG_H

#include "UI.h"
#include "LLDBBreakpoint.h"

class LLDBNewBreakpointDlg : public LLDBNewBreakpointDlgBase
{
public:
    LLDBNewBreakpointDlg(wxWindow* parent);
    virtual ~LLDBNewBreakpointDlg();
    LLDBBreakpoint GetBreakpoint();
    
protected:
    virtual void OnCheckFileAndLine(wxCommandEvent& event);
    virtual void OnCheckFuncName(wxCommandEvent& event);
    virtual void OnFileLineEnabledUI(wxUpdateUIEvent& event);
    virtual void OnFuncNameUI(wxUpdateUIEvent& event);
};
#endif // LLDBNEWBREAKPOINTDLG_H
