#pragma once
#include <windows.h>
#include <tchar.h>
#include <string>
#include <iostream>
#include "resource.h"
#include "List.h"
#include "ListIterator.h"
#include "SumVisitor.h"
#include "Model.h"
#include "View.h"

INT_PTR CALLBACK Controller(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
