
// MFCApplication1Dlg.cpp : implementation file
//


#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include "MyEllipse.h"
#include "MyRectangle.h"
#include "MyLine.h"
#include "AddCommand.h"
#include "afxdialogex.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg dialog



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)

{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CMFCApplication1Dlg message handlers

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnBnClickedLineb()	//line
{
	static MyLineFactory lineFactory;
	factory = &lineFactory;
	kind = 0;
}


void CMFCApplication1Dlg::OnBnClickedRectancgleb() //rectangle
{
	static MyRectangleFactory rectangleFactory;
	factory = &rectangleFactory;
	kind = 1;
}


void CMFCApplication1Dlg::OnBnClickedEllipseb() //elipse
{
	static MyEllipseFactory ellipseFactory;
	factory = &ellipseFactory;
	kind = 2;
}


void CMFCApplication1Dlg::OnMouseMove(UINT nFlags, CPoint point) // Move Mouse
{
	if (point.x >= 420 && point.y >= 80 && point.x <= 1528 && point.y <= 1090) // CRect(420, 80, 1528, 1090)
	{
		if (isPressed)
		{
			CClientDC dc(this);
			shapes[shapes.size() - 1]->setEnd(Point(point.x, point.y));
			CPen pen(PS_SOLID, 2, curColor);
			CBrush brush(curColor);
			CBrush *old = dc.SelectObject(&brush);
			CPen *oldPen = dc.SelectObject(&pen);

			switch (kind)
			{
			case 0: // Line
				dc.MoveTo(shapes[shapes.size() - 1]->getBegin().getX(), shapes[shapes.size() - 1]->getBegin().getY());
				dc.LineTo(point.x, point.y);
				break;
			case 1: // Rectangle
				dc.Rectangle(shapes[shapes.size() - 1]->getBegin().getX(), shapes[shapes.size() - 1]->getBegin().getY(), point.x, point.y);
				break;
			case 2: // Ellipse
				dc.Ellipse(shapes[shapes.size() - 1]->getBegin().getX(), shapes[shapes.size() - 1]->getBegin().getY(), point.x, point.y);
				break;
			default:
				break;
			}
			dc.SelectObject(oldPen);
			dc.SelectObject(old);
			//InvalidateRect(CRect(420, 80, 1528, 1090));
		}
	}
	CDialog::OnMouseMove(nFlags, point);
}


void CMFCApplication1Dlg::OnLButtonDown(UINT nFlags, CPoint point) // Left Click Mouse
{
	MyShape *s = NULL;
	Command *command;

	if (point.x >= 420 && point.y >= 80 && point.x <= 1528 && point.y <= 1090) // CRect(420, 80, 1528, 1090)
	{
		switch (function)
		{
		case 1: // Draw Shape
			s = factory->create();
			s->setSelectBackground(m_ChoseP.GetCurSel());
			command = new AddCommand(shapes, s);
			done.push(command);
			command->perform();
			s->setBegin(Point(point.x, point.y));
			s->setBg(curColor);
			isPressed = true;
			break;
		case 2: // Fill Shape

			for (int i = shapes.size() - 1; i >= 0; i--)
			{
				if (point.x >= shapes[i]->getBegin().getX() && point.y >= shapes[i]->getBegin().getY() &&
					point.x <= shapes[i]->getEnd().getX() && point.y <= shapes[i]->getEnd().getY())
				{
					shapes[i]->setLastColor(shapes[i]->getBg());
					shapes[i]->setBg(curColor);
					InvalidateRect(CRect(shapes[i]->getBegin().getX(), shapes[i]->getBegin().getY(), shapes[i]->getEnd().getX(), shapes[i]->getEnd().getY()));
					//InvalidateRect(CRect(420, 80, 1528, 1090));
					break;
				}
			}
			//Invalidate();

			break;
		case 3: // Delete

			for (int i = shapes.size() - 1; i >= 0; i--)
			{
				if (point.x >= shapes[i]->getBegin().getX() && point.y >= shapes[i]->getBegin().getY() &&
					point.x <= shapes[i]->getEnd().getX() && point.y <= shapes[i]->getEnd().getY())
				{
					command = new AddCommand(shapes, shapes[i]);
					done.push(command);
					command->rollback();
					break;
				}
			}
			InvalidateRect(CRect(420, 80, 1528, 1090));
			//	Invalidate();
			break;
		case 4: // Drag
			for (size_t i = 0; i < shapes.size(); i++)
			{
				if (point.x >= shapes[i]->getBegin().getX() && point.y >= shapes[i]->getBegin().getY() &&
					point.x <= shapes[i]->getEnd().getX() && point.y <= shapes[i]->getEnd().getY())
				{
					dragIndex = i;
					isDraged = true;
					dragX = (shapes[i]->getEnd().getX()) - (shapes[i]->getBegin().getX());
					dragY = (shapes[i]->getEnd().getY()) - (shapes[i]->getBegin().getY());
				}
			}
			break;
		default:
			break;
		}
	}

	CDialog::OnLButtonDown(nFlags, point);

}


void CMFCApplication1Dlg::OnLButtonUp(UINT nFlags, CPoint point) // Relese Mouse
{
	if (point.x >= 420 && point.y >= 80 && point.x <= 1528 && point.y <= 1090) // CRect(420, 80, 1528, 1090)
	{
		switch (function)
		{
		case 1: // Draw
			isPressed = false;
			shapes[shapes.size() - 1]->setEnd(Point(point.x, point.y));
			InvalidateRect(CRect(420, 80, 1528, 1090));
			//Invalidate();
			break;
		case 2:
			break; // fill - do nothing
		case 3:
			break; // delete - do nothing
		case 4: // Drag
			if (isDraged == true)
			{
				isDraged = false;
				shapes[dragIndex]->setBegin(Point(point.x, point.y));
				shapes[dragIndex]->setEnd(Point((point.x + dragX), (point.y + dragY)));
				InvalidateRect(CRect(420, 80, 1528, 1090));
				//	Invalidate();
			}
			break;
		default:
			break;
		}
	}

	CDialog::OnLButtonUp(nFlags, point);
}

void CMFCApplication1Dlg::OnBnClickedUndobutton() //Undo
{
	if (done.empty())
		return;

	Command *command = done.top();
	done.pop();
	undone.push(command);

	if (command->getIsDelete() == 1)//אם נמחקה צורה
	{
		command->perform();
		InvalidateRect(CRect(420, 80, 1528, 1090));
		return;
	}


	command->rollback();
	InvalidateRect(CRect(420, 80, 1528, 1090));
	//Invalidate();
}


void CMFCApplication1Dlg::OnBnClickedRedobutton() //Redo
{
	if (undone.empty())
		return;
	Command *command = undone.top();
	undone.pop();
	done.push(command);

	if (command->getIsDelete() == 0)
	{
		command->rollback();
		InvalidateRect(CRect(420, 80, 1528, 1090));
		return;
	}

	command->perform();
	//Invalidate();
	InvalidateRect(CRect(420, 80, 1528, 1090));
}


void CMFCApplication1Dlg::OnBnClickedSavebotton() // Save File
{
	CFile file(L"shapes.bin", CFile::modeCreate | CFile::modeWrite);
	CArchive archive(&file, CArchive::store);
	archive << shapes.size();
	for (size_t i = 0; i < shapes.size(); i++)
		archive << shapes[i];
}


void CMFCApplication1Dlg::OnBnClickedOpenbotton() // Open File
{
	CFile file(L"shapes.bin", CFile::modeRead);
	CArchive archive(&file, CArchive::load);
	int count;
	archive >> count;
	for (int i = 0; i < count; ++i)
	{
		MyShape *s;
		archive >> s;
		shapes.push_back(s);
	}
	Select = shapes[count - 1]->getSelectBackground();
	switch (Select)
	{
	case 0:
		bitmap = IDB_BITMAP5;
		Invalidate();
		break;
	case 1:
		bitmap = IDB_BITMAP2;
		Invalidate();
		break;
	case 2:
		bitmap = IDB_BITMAP4;
		Invalidate();
		break;
	case 3:
		bitmap = IDB_BITMAP3;
		Invalidate();
		break;
	default:
		break;
	}
	Invalidate();

}


void CMFCApplication1Dlg::OnBnClickedMfccolorbutton3()
{
	curColor = ConColorbutt.GetColor();
}


void CMFCApplication1Dlg::OnBnClickedRadio1()
{
	function = 1;
}


void CMFCApplication1Dlg::OnBnClickedRadio2()
{
	function = 2;
}




void CMFCApplication1Dlg::OnCbnSelchangeCombo1()
{
	Select = m_ChoseP.GetCurSel();
	switch (Select)
	{
	case 0:
		bitmap = IDB_BITMAP5;
		Invalidate();
		break;
	case 1:
		bitmap = IDB_BITMAP2;
		Invalidate();
		break;
	case 2:
		bitmap = IDB_BITMAP4;
		Invalidate();
		break;
	case 3:
		bitmap = IDB_BITMAP3;
		Invalidate();
		break;
	default:
		break;
	}
	if (shapes.size() != 0)
	{
		vector<MyShape*>::iterator it;
		it = shapes.end() - 1;
		(*it)->setSelectBackground(Select);
	}
	// TODO: Add your control notification handler code here
}


void CMFCApplication1Dlg::OnBnClickedRadio3() // delete object
{
	function = 3;
}


void CMFCApplication1Dlg::OnBnClickedRadio4() // Drag
{
	function = 4;
}

