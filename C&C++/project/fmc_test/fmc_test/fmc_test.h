
// fmc_test.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cfmc_testApp:
// �йش����ʵ�֣������ fmc_test.cpp
//

class Cfmc_testApp : public CWinApp
{
public:
	Cfmc_testApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cfmc_testApp theApp;