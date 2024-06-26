/*
 * (C) 2006-2024 see Authors.txt
 *
 * This file is part of MPC-BE.
 *
 * MPC-BE is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * MPC-BE is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "stdafx.h"
#include "MiniDump.h"
#include "MainFrm.h"
#include "PPageMisc.h"
#include "DSUtil/Filehandle.h"

// CPPageMisc dialog

IMPLEMENT_DYNAMIC(CPPageMisc, CPPageBase)
CPPageMisc::CPPageMisc()
	: CPPageBase(CPPageMisc::IDD, CPPageMisc::IDD)
{
}

CPPageMisc::~CPPageMisc()
{
}

void CPPageMisc::DoDataExchange(CDataExchange* pDX)
{
	__super::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT1, m_nJumpDistS);
	DDX_Text(pDX, IDC_EDIT2, m_nJumpDistM);
	DDX_Text(pDX, IDC_EDIT3, m_nJumpDistL);
	DDX_Check(pDX, IDC_CHECK6, m_fPreventMinimize);
	DDX_Check(pDX, IDC_CHECK7, m_fDontUseSearchInFolder);
	DDX_Check(pDX, IDC_CHECK5, m_bHideWindowedMousePointer);
	DDX_Check(pDX, IDC_CHECK8, m_bShowZeroHours);
	DDX_Text(pDX, IDC_EDIT5, m_nMinMPlsDuration);
	DDX_Control(pDX, IDC_SPIN2, m_spnMinMPlsDuration);
	DDX_Check(pDX, IDC_CHECK_LCD, m_fLCDSupport);
	DDX_Check(pDX, IDC_CHECK9, m_bWinMediaControls);
	DDX_Check(pDX, IDC_CHECK2, m_fMiniDump);
	DDX_Control(pDX, IDC_COMBO1, m_cbFFmpegExePath);
	DDX_Control(pDX, IDC_CHECK3, m_updaterAutoCheckCtrl);
	DDX_Control(pDX, IDC_EDIT4, m_updaterDelayCtrl);
	DDX_Control(pDX, IDC_SPIN1, m_updaterDelaySpin);
	DDX_Text(pDX, IDC_EDIT4, m_nUpdaterDelay);
}

BEGIN_MESSAGE_MAP(CPPageMisc, CPPageBase)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RESET_SETTINGS, OnResetSettings)
	ON_BN_CLICKED(IDC_EXPORT_SETTINGS, OnExportSettings)
	ON_UPDATE_COMMAND_UI(IDC_EDIT4, OnUpdateDelayEditBox)
	ON_UPDATE_COMMAND_UI(IDC_SPIN1, OnUpdateDelayEditBox)
	ON_UPDATE_COMMAND_UI(IDC_STATIC5, OnUpdateDelayEditBox)
	ON_UPDATE_COMMAND_UI(IDC_STATIC6, OnUpdateDelayEditBox)
END_MESSAGE_MAP()

// CPPageMisc message handlers

BOOL CPPageMisc::OnInitDialog()
{
	__super::OnInitDialog();

	SetCursor(m_hWnd, IDC_COMBO1, IDC_HAND);

	CAppSettings& s = AfxGetAppSettings();

	m_nJumpDistS = s.nJumpDistS;
	m_nJumpDistM = s.nJumpDistM;
	m_nJumpDistL = s.nJumpDistL;
	m_fPreventMinimize = s.fPreventMinimize;
	m_fDontUseSearchInFolder = s.fDontUseSearchInFolder;
	m_bHideWindowedMousePointer = s.bHideWindowedMousePointer;
	m_bShowZeroHours = s.bShowZeroHours;
	m_nMinMPlsDuration = s.nMinMPlsDuration;
	m_spnMinMPlsDuration.SetRange32(0, 20);
	m_fLCDSupport = s.fLCDSupport;
	m_bWinMediaControls = s.bWinMediaControls;
	m_fMiniDump = s.fMiniDump;

	m_cbFFmpegExePath.AddString(L"ffmpeg.exe");
	if (s.strFFmpegExePath.CompareNoCase(L"ffmpeg.exe") != 0) {
		m_cbFFmpegExePath.AddString(s.strFFmpegExePath);
	}
	m_cbFFmpegExePath.SelectString(0, s.strFFmpegExePath);

	m_updaterAutoCheckCtrl.SetCheck(s.bUpdaterAutoCheck);
	m_nUpdaterDelay = s.nUpdaterDelay;
	m_updaterDelaySpin.SetRange32(1, 365);

	UpdateData(FALSE);

	return TRUE;
}

BOOL CPPageMisc::OnApply()
{
	UpdateData();

	CAppSettings& s = AfxGetAppSettings();

	s.nJumpDistS = m_nJumpDistS;
	s.nJumpDistM = m_nJumpDistM;
	s.nJumpDistL = m_nJumpDistL;

	s.fPreventMinimize          = !!m_fPreventMinimize;
	s.fDontUseSearchInFolder    = !!m_fDontUseSearchInFolder;
	s.bHideWindowedMousePointer = !!m_bHideWindowedMousePointer;
	s.bShowZeroHours            = !!m_bShowZeroHours;
	s.nMinMPlsDuration          = (m_nMinMPlsDuration = std::clamp(m_nMinMPlsDuration, 0, 20));
	s.fLCDSupport               = !!m_fLCDSupport;
	s.bWinMediaControls         = !!m_bWinMediaControls;
	s.fMiniDump                 = !!m_fMiniDump;
	CMiniDump::SetState(s.fMiniDump);

    m_cbFFmpegExePath.GetWindowTextW(s.strFFmpegExePath);
	CleanPath(s.strFFmpegExePath);
	s.bUpdaterAutoCheck = !!m_updaterAutoCheckCtrl.GetCheck();
	s.nUpdaterDelay     = (m_nUpdaterDelay = std::clamp(m_nUpdaterDelay, 1, 365));

	return __super::OnApply();
}

void CPPageMisc::OnBnClickedButton1()
{
	m_nJumpDistS = DEFAULT_JUMPDISTANCE_1;
	m_nJumpDistM = DEFAULT_JUMPDISTANCE_2;
	m_nJumpDistL = DEFAULT_JUMPDISTANCE_3;

	UpdateData(FALSE);

	SetModified();
}

void CPPageMisc::OnUpdateDelayEditBox(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(m_updaterAutoCheckCtrl.GetCheck() == BST_CHECKED);
}

void CPPageMisc::OnResetSettings()
{
	if (MessageBoxW(ResStr(IDS_RESET_SETTINGS_WARNING), ResStr(IDS_RESET_SETTINGS), MB_ICONEXCLAMATION | MB_YESNO | MB_DEFBUTTON2) == IDYES) {
		AfxGetAppSettings().bResetSettings = true;
		AfxGetMainFrame()->m_wndPlaylistBar.TDeleteAllPlaylists();
		GetParent()->PostMessageW(WM_CLOSE);
	}
}

void CPPageMisc::OnExportSettings()
{
	if (GetParent()->GetDlgItem(ID_APPLY_NOW)->IsWindowEnabled()) {
		int ret = MessageBoxW(ResStr(IDS_EXPORT_SETTINGS_WARNING), ResStr(IDS_EXPORT_SETTINGS), MB_ICONEXCLAMATION | MB_YESNOCANCEL);

		if (ret == IDCANCEL) {
			return;
		} else if (ret == IDYES) {
			GetParent()->PostMessageW(PSM_APPLY);
		}
	}

	AfxGetMyApp()->ExportSettings();
	SetFocus();
}
