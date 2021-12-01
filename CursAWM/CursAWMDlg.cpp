
// CursAWMDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "CursAWM.h"
#include "CursAWMDlg.h"
#include "afxdialogex.h"
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "logic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedStart();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CAboutDlg::OnBnClickedStart)
END_MESSAGE_MAP()


// Диалоговое окно CCursAWMDlg



CCursAWMDlg::CCursAWMDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CURSAWM_DIALOG, pParent)
	, number_of_trans(_T(""))
	, adr_64(FALSE)
	, operation_var(0)
	, word_lenght_var(0)
	, connect_time_var(0)
	, num(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCursAWMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, operation);
	DDX_Control(pDX, IDC_COMBO2, word_lenght);
	DDX_Control(pDX, IDC_COMBO3, connect_time);
	DDX_Text(pDX, IDC_EDIT1, number_of_trans);
	DDX_Check(pDX, IDC_CHECK1, adr_64);
	DDX_CBIndex(pDX, IDC_COMBO1, operation_var);
	DDX_CBIndex(pDX, IDC_COMBO2, word_lenght_var);
	DDX_CBIndex(pDX, IDC_COMBO3, connect_time_var);
	DDX_Control(pDX, IDC_EDIT1, number_trans);
}

BEGIN_MESSAGE_MAP(CCursAWMDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CCursAWMDlg::OnOperationChange)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CCursAWMDlg::OnWordLenghtChange)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CCursAWMDlg::OnConnectTimeChange)
	ON_EN_CHANGE(IDC_EDIT1, &CCursAWMDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CCursAWMDlg::OnBnClickedStart)
END_MESSAGE_MAP()


// Обработчики сообщений CCursAWMDlg

BOOL CCursAWMDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
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

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	operation.AddString(L"Чтение из памяти");
	operation.AddString(L"Запись в память");
	operation.AddString(L"Чтение с УВВ");
	operation.AddString(L"Запись в УВВ");

	word_lenght.AddString(L"64 бита");
	word_lenght.AddString(L"32 бита");
	word_lenght.AddString(L"16 бита");
	word_lenght.AddString(L"8 бита");

	connect_time.AddString(L"30 нс");
	connect_time.AddString(L"70 нс");
	connect_time.AddString(L"100 нс");
	connect_time.AddString(L"200 нс");
	connect_time.AddString(L"3-1-1-1, 1~25 нс");
	connect_time.AddString(L"3-1-1-1, 1~20 нс");
	connect_time.AddString(L"4-1-4-1, 1~20 нс");
	connect_time.AddString(L"5-2-2-2, 1~20 нс");
	connect_time.AddString(L"3-2-2-2, 1~15 нс");

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CCursAWMDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CCursAWMDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CCursAWMDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCursAWMDlg::OnOperationChange()
{
	// TODO: добавьте свой код обработчика уведомлений
	operation_var = operation.GetCurSel();
}


void CCursAWMDlg::OnWordLenghtChange()
{
	// TODO: добавьте свой код обработчика уведомлений
	word_lenght_var = word_lenght.GetCurSel();
}


void CCursAWMDlg::OnConnectTimeChange()
{
	// TODO: добавьте свой код обработчика уведомлений
	connect_time_var = connect_time.GetCurSel();

}


void CCursAWMDlg::OnEnChangeEdit1()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
	number_trans.GetWindowTextW(number_of_trans);
	num = _wtoi(number_of_trans);
}

void CAboutDlg::OnBnClickedStart() {

}
void CCursAWMDlg::OnBnClickedStart()
{
	logic it(adr_64, operation_var, word_lenght_var, connect_time_var, num);
	it.create_mas();
	// TODO: добавьте свой код обработчика уведомлений
	sf::RenderWindow window(sf::VideoMode(1080, 720), "SFML works!");
	sf::CircleShape shape(100.f);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color(255,255,255,0));
		window.display();
	}
}
