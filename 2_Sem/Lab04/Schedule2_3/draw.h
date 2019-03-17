#pragma once
#include <windows.h>

BOOL DrawLesson(HDC hDC, RECT lessonRect, const CHAR* lessonType, const CHAR* subject, 
	const CHAR* auditorium, COLORREF brushColor);