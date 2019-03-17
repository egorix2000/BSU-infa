#include "draw.h"

BOOL DrawLesson(HDC hDC, RECT lessonRect, const CHAR* lessonType, const CHAR* subject, 
	const CHAR* auditorium, COLORREF brushColor) {
	SelectObject(hDC, CreateSolidBrush(brushColor));
	FillRect(hDC, &lessonRect, NULL);
	SetRect(&lessonRect, lessonRect.left,
		lessonRect.top + 5,
		lessonRect.right,
		lessonRect.bottom - 5);
	DeleteObject(SelectObject(hDC, GetStockObject(BLACK_BRUSH)));
	DrawText(hDC, lessonType, -1, &lessonRect, DT_SINGLELINE | DT_CENTER | DT_TOP);
	DrawText(hDC, subject, -1, &lessonRect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	DrawText(hDC, auditorium, -1, &lessonRect, DT_SINGLELINE | DT_CENTER | DT_BOTTOM);
	return true;
}