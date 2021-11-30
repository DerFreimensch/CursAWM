
// CursAWM.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CCursAWMApp:
// Сведения о реализации этого класса: CursAWM.cpp
//

class CCursAWMApp : public CWinApp
{
public:
	CCursAWMApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CCursAWMApp theApp;
