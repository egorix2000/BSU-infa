#undef UNICODE
#include <windows.h>
#include "coodinateSystemLib.h"
#include "KWnd.h"
#include "Graph.h"
#include "draw.h"
#include "resource.h"

bool doesMousePressed;
bool doesPointOnGraphDisplayed;
RECT selection;
POINT mousePosition;
Graph graph;

std::vector<int> params;

double quadraticEquation(std::vector<int> params, double x) {
	return params[0] * x* x + params[1] * x + params[2];
}
double sinEquation(std::vector<int> params, double x) {
	return cos(params[0]*x) + params[1];
}

const int MIN_SELECTION_SIZE = 10;
const int PRECISION = 2;
const int NUMBER_OF_SCALES_ON_AXE = 11;
const int SCALE_LENGTH = 2;
const double FAULT = 0.5;
const double START_LEFT_BORDER = -5;
const double START_RIGHT_BORDER = 5;
const double START_TOP_BORDER = -10;
const double START_BOTTOM_BORDER = 10;
const int A = 1;
const int B = 1;
const int C = 1;

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ChangeGraphicDlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

void create();
void paint(HWND hwnd, HDC hdc);
void onLButtonDown(HWND& hwnd, LPARAM lParam);
void onLButtonUp(HWND& hwnd, LPARAM lParam);
void onMouseMove(HWND& hwnd, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	MSG msg;

	KWnd mainWnd("Window", hInstance, nCmdShow, WndProc, MAKEINTRESOURCE(IDR_MENU1));

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT ps;
	static HDC hdc;
	static HINSTANCE hInst;

	switch (message) {
	case WM_CREATE:
		hInst = GetModuleHandle(NULL);
		create();
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		paint(hwnd, hdc);
		EndPaint(hwnd, &ps);
		break;
	case WM_MOUSEMOVE:
		onMouseMove(hwnd, lParam);
		break;
	case WM_LBUTTONDOWN:
		onLButtonDown(hwnd, lParam);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_GRAPHIC_CHANGEGRAPHIC:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG), hwnd, ChangeGraphicDlgProc);
			InvalidateRect(hwnd, NULL, true);
			break;
		case ID_SETTINGS_DEFAULT:
			graph.setLeftBorder(START_LEFT_BORDER);
			graph.setRightBorder(START_RIGHT_BORDER);
			graph.setTopBorder(START_TOP_BORDER);
			graph.setBottomBorder(START_BOTTOM_BORDER);
			InvalidateRect(hwnd, NULL, true);
			break;
		default:
			break;
		}
		break;
	case WM_LBUTTONUP:
		onLButtonUp(hwnd, lParam);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}

void create() {
	doesMousePressed = false;
	doesPointOnGraphDisplayed = false;
	graph.setLeftBorder(START_LEFT_BORDER);
	graph.setRightBorder(START_RIGHT_BORDER);
	graph.setTopBorder(START_TOP_BORDER);
	graph.setBottomBorder(START_BOTTOM_BORDER);
	graph.setFunc(&quadraticEquation);
	params.push_back(A);
	params.push_back(B);
	params.push_back(C);
	graph.setParams(params);
}

void paint(HWND hwnd, HDC hdc) {
	RECT clientRect;
	GetClientRect(hwnd, &clientRect);
	if (doesMousePressed) {
		drawRect(hdc, selection);
	}
	POINT origin = getOriginAtWindow(clientRect, graph, SCALE_LENGTH);
	drawAxes(hdc, clientRect, origin);
	drawScalesOfAxes(hdc, clientRect, origin, graph, NUMBER_OF_SCALES_ON_AXE,
		SCALE_LENGTH, PRECISION);
	drawFunction(hdc, clientRect, graph);
	if (doesPointOnGraphDisplayed) {
		drawPointAtGraph(hdc, clientRect, origin, mousePosition, graph, PRECISION);
	}
}

void onLButtonDown(HWND& hwnd, LPARAM lParam) {
	doesMousePressed = true;
	selection.left = LOWORD(lParam);
	selection.top = HIWORD(lParam);
}

void onLButtonUp(HWND& hwnd, LPARAM lParam) {
	if (doesMousePressed) {
		RECT clientRect;
		GetClientRect(hwnd, &clientRect);
		selection.right = LOWORD(lParam);
		selection.bottom = HIWORD(lParam);
		if (abs(selection.right - selection.left) >= MIN_SELECTION_SIZE
			&& abs(selection.bottom - selection.top) >= MIN_SELECTION_SIZE) {
			resizeAxes(clientRect, selection, graph);
		}
		doesMousePressed = false;
		InvalidateRect(hwnd, NULL, TRUE);
	}
}

void onMouseMove(HWND& hwnd, LPARAM lParam) {
	bool doesUpdateNeeded = false;
	RECT clientRect;
	GetClientRect(hwnd, &clientRect);
	if (doesMousePressed) {
		selection.right = LOWORD(lParam);
		selection.bottom = HIWORD(lParam);
		doesUpdateNeeded = true;
	}
	mousePosition.x = LOWORD(lParam);
	mousePosition.y = HIWORD(lParam);
	DoublePoint graphMousePosition = pointToGraphPoint(mousePosition.x, mousePosition.y, clientRect, graph);
	if (abs(graph.getValue(graphMousePosition.x) - graphMousePosition.y) <= FAULT) {
		doesUpdateNeeded = true;
		doesPointOnGraphDisplayed = true;
	}
	else if (doesPointOnGraphDisplayed) {
		doesUpdateNeeded = true;
		doesPointOnGraphDisplayed = false;
	}
	if (doesUpdateNeeded) {
		InvalidateRect(hwnd, NULL, TRUE);
	}
}

BOOL CALLBACK ChangeGraphicDlgProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HWND hWndEdit;
	switch (uMsg) {
	case WM_INITDIALOG:
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case IDC_RADIO1:
			ShowWindow(GetDlgItem(hDlg, IDC_EDIT3), SW_SHOW);
			ShowWindow(GetDlgItem(hDlg, IDC_STATIC3), SW_SHOW);
			break;
		case IDC_RADIO2:
			ShowWindow(GetDlgItem(hDlg, IDC_EDIT3), SW_HIDE);
			ShowWindow(GetDlgItem(hDlg, IDC_STATIC3), SW_HIDE);
			break;
		case IDOK:
			if (IsDlgButtonChecked(hDlg, IDC_RADIO1)) {
				graph.setFunc(&quadraticEquation);
				params.clear();
				params.push_back(GetDlgItemInt(hDlg, IDC_EDIT1, NULL, FALSE));
				params.push_back(GetDlgItemInt(hDlg, IDC_EDIT2, NULL, FALSE));
				params.push_back(GetDlgItemInt(hDlg, IDC_EDIT3, NULL, FALSE));
				graph.setParams(params);
			}
			else if (IsDlgButtonChecked(hDlg, IDC_RADIO2)) {
				graph.setFunc(&sinEquation);
				params.clear();
				params.push_back(GetDlgItemInt(hDlg, IDC_EDIT1, NULL, FALSE));
				params.push_back(GetDlgItemInt(hDlg, IDC_EDIT2, NULL, FALSE));
				graph.setParams(params);
			}
			EndDialog(hDlg, 0);
			return TRUE;
		case IDCANCEL:
			EndDialog(hDlg, 0);
			return TRUE;
		}
		break;
	}
	return FALSE;
}