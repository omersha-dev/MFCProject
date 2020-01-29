
// MFCApplication1Dlg.h : header file
//

#pragma once
#include <vector>
#include <stack>
#include "MyShape.h"
#include "MyFactory.h"
#include "MyEllipseFactory.h"
#include "MyLineFactory.h"
#include "MyRectangleFactory.h"
#include "Command.h"
#include "afxcolorbutton.h"
#include "afxwin.h"

using namespace std;


// CMFCApplication1Dlg dialog
class CMFCApplication1Dlg : public CDialogEx
{
// Construction
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	vector<MyShape*> shapes;
	stack<Command*> done, undone;
	bool isPressed, isDraged;
	MyFactory *factory;
	int function;
	int bitmap;
	int dragIndex;
	int dragX, dragY;
	CBitmap Bmp1, Bmp2, Bmp3, Bmp4;
	int kind;
	int isDelete = 0;
	int Select;


public:
	COLORREF curColor;
	CMFCColorButton ConColorbutt;
	int m_Figsbox;
	int m_Funcbox;
	CComboBox m_ChoseP;
	afx_msg void OnBnClickedLineb();
	afx_msg void OnBnClickedRectancgleb();
	afx_msg void OnBnClickedEllipseb();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedUndobutton();
	afx_msg void OnBnClickedRedobutton();
	afx_msg void OnBnClickedSavebotton();
	afx_msg void OnBnClickedOpenbotton();
	afx_msg void OnBnClickedMfccolorbutton3();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();

	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
};
