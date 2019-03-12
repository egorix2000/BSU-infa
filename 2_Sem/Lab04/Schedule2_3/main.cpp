#undef UNICODE
#include <windows.h>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include "KWnd.h"
#include "Day.h"
#include "Lesson.h"
#include "FileLib.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


Day& parseDayString(std::string s, Day& day) {
	Lesson lesson;
	std::string dayName;
	std::string lessonType;
	std::string subject;
	std::string auditorium;
	std::stringstream ss;
	ss << s;
	ss >> dayName;
	day.setDayName(dayName);
	while (ss >> lessonType) {
		if (lessonType == "PC") {
			ss >> auditorium;
			subject = "";
		}
		else {
			ss >> subject >> auditorium;
		}
		lesson.setLessonType(lessonType);
		lesson.setSubject(subject);
		lesson.setAuditorium(auditorium);
		day.addLesson(Lesson(lesson));
	}
	return day;
}

COLORREF getColor(std::string lessonType) {
	if (lessonType == "PC") {
		return RGB(211, 235, 202);
	}
	else if (lessonType == "Lecture") {
		return RGB(240, 202, 206);
	}
	else {
		return RGB(201, 218, 240);
	}
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	MSG msg;
	
	KWnd mainWnd("Window 2_3", hInstance, nCmdShow, WndProc);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT ps;
	RECT clientRect;
	RECT currentLessonRect;
	static std::vector<Day> days;
	static int maxNumberOfLessons;
	Day day;
	std::string error;
	std::string line;
	std::ifstream fin;

	switch (message) {
	case WM_CREATE:
		fin.open("input.txt");

		if (validateFile(fin, error)) {

			while (std::getline(fin, line)) {
				day.clear();
				parseDayString(line, day);
				days.push_back(day);
			}
			maxNumberOfLessons = (*std::max_element(days.begin(), days.end(), [](const Day &day1, const Day &day2) {
				return day1.getNumberOfLessons() < day2.getNumberOfLessons();
			})).getNumberOfLessons();
		}
		else {
			MessageBox(hWnd, error.c_str(), "Error", MB_OK);
		}

		fin.close();
		return 0;
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);
		GetClientRect(hWnd, &clientRect);
		SetBkMode(hDC, TRANSPARENT);

		for (int i = 0; i < days.size(); i++) {
			MoveToEx(hDC, 0, i * clientRect.bottom / days.size(), nullptr);
			LineTo(hDC, clientRect.right, i * clientRect.bottom / days.size());

			SetRect(&currentLessonRect,0,
				i * clientRect.bottom / days.size(),
				clientRect.right / (maxNumberOfLessons + 1),
				(i + 1) * clientRect.bottom / days.size());
			DrawText(hDC, days[i].getDayName().c_str(), -1, &currentLessonRect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

			for (int j = 0; j < days[i].getNumberOfLessons(); j++) {
				MoveToEx(hDC, (j+1) * clientRect.right / (maxNumberOfLessons+1), 0, nullptr);
				LineTo(hDC, (j+1) * clientRect.right / (maxNumberOfLessons+1), clientRect.bottom);
				SetRect(&currentLessonRect, (j+1) * clientRect.right / (maxNumberOfLessons+1)+1, 
					i * clientRect.bottom / days.size() + 1,
					(j+2) * clientRect.right / (maxNumberOfLessons+1),
					(i+1) * clientRect.bottom / days.size()) - 1;
				SelectObject(hDC, CreateSolidBrush(getColor(days[i][j].getLessonType())));
				FillRect(hDC, &currentLessonRect, NULL);
				SetRect(&currentLessonRect, (j + 1) * clientRect.right / (maxNumberOfLessons + 1),
					i * clientRect.bottom / days.size() + 5,
					(j + 2) * clientRect.right / (maxNumberOfLessons + 1),
					(i + 1) * clientRect.bottom / days.size() - 5);
				DeleteObject(SelectObject(hDC, GetStockObject(BLACK_BRUSH)));
				DrawText(hDC, days[i][j].getLessonType().c_str(), -1, &currentLessonRect, DT_SINGLELINE | DT_CENTER | DT_TOP);
				DrawText(hDC, days[i][j].getSubject().c_str(), -1, &currentLessonRect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
				DrawText(hDC, days[i][j].getAuditorium().c_str(), -1, &currentLessonRect, DT_SINGLELINE | DT_CENTER | DT_BOTTOM);
			}

			for (int j = days[i].getNumberOfLessons(); j <= maxNumberOfLessons; j++) {
				MoveToEx(hDC, (j+1) * clientRect.right / (maxNumberOfLessons+1), 0, nullptr);
				LineTo(hDC, (j+1) * clientRect.right / (maxNumberOfLessons+1), clientRect.bottom);
			}
		}
		MoveToEx(hDC, 0, clientRect.bottom, nullptr);
		LineTo(hDC, clientRect.right, clientRect.bottom);

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}