
// CursAWMDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CCursAWMDlg
class CCursAWMDlg : public CDialogEx
{
// Создание
public:
	CCursAWMDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CURSAWM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// операция на шине
	CComboBox operation;
	// разрядность передаваемого слова
	CComboBox word_lenght;
	// время доступа к информации
	CComboBox connect_time;
	// кол-во слов
	CString number_of_trans;
	int num;
	// 64 битный адрес
	BOOL adr_64;
	afx_msg void OnOperationChange();
	int operation_var;
	afx_msg void OnWordLenghtChange();
	afx_msg void OnConnectTimeChange();
	int word_lenght_var;
	int connect_time_var;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedStart();
	// кол-во транзакций
	CEdit number_trans;
	afx_msg void OnBnClickedCheck1();
};
