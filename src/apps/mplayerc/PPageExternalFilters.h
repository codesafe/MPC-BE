/*
 * (C) 2003-2006 Gabest
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

#pragma once

#include "PPageBase.h"
#include "controls/FloatEdit.h"

bool IsSupportedExternalVideoRenderer(CLSID clsid);

// CPPageExternalFilters dialog

class CPPageExternalFilters : public CPPageBase
{
	DECLARE_DYNAMIC(CPPageExternalFilters)

private:
	void StepUp(CCheckListBox& list);
	void StepDown(CCheckListBox& list);

	std::list<std::unique_ptr<FilterOverride>> m_ExtFilters;
	FilterOverride* m_pLastSelFilter = nullptr;
	FilterOverride* GetCurFilter();

public:
	CPPageExternalFilters();
	virtual ~CPPageExternalFilters();

	enum { IDD = IDD_PPAGEEXTERNALFILTERS };

	CCheckListBox m_filters;
	int m_iLoadType = FilterOverride::PREFERRED;
	CHexEdit m_dwMerit;
	CTreeCtrl m_tree;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();
	virtual BOOL OnApply();

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnUpdateFilter(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFilterUp(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFilterDown(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFilterMerit(CCmdUI* pCmdUI);
	afx_msg void OnUpdateSubType(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDeleteType(CCmdUI* pCmdUI);
	afx_msg void OnAddRegistered();
	afx_msg void OnRemoveFilter();
	afx_msg void OnMoveFilterUp();
	afx_msg void OnMoveFilterDown();
	afx_msg void OnLbnDblclkFilter();
	afx_msg int OnVKeyToItem(UINT nKey, CListBox* pListBox, UINT nIndex);
	afx_msg void OnAddMajorType();
	afx_msg void OnAddSubType();
	afx_msg void OnDeleteType();
	afx_msg void OnResetTypes();
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnCheckChangeList1();
	afx_msg void OnBnClickedRadio();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnNMDblclkTree2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTVNKeyDownTree2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDropFiles(HDROP hDropInfo);
};
