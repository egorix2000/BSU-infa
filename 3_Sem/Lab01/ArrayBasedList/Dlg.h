#pragma once
#include <windows.h>
#include <tchar.h>
#include <string>
#include <iostream>
#include "resource.h"
#include "List.h"
#include "ListIterator.h"
#include "SumVisitor.h"

INT_PTR CALLBACK DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);
