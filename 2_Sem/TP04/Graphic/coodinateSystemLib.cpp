#include "coodinateSystemLib.h"

void doubleToStringWithPrecision(std::string& s, double doubleNumber, int precision) {
	s = std::to_string(doubleNumber);
	s.erase(s.find('.') + precision + 1,
		std::string::npos);
}

void normalizeRect(RECT& rect) {
	if (rect.right < rect.left) {
		int temp = rect.right;
		rect.right = rect.left;
		rect.left = temp;
	}
	if (rect.bottom > rect.top) {
		int temp = rect.bottom;
		rect.bottom = rect.top;
		rect.top = temp;
	}
}

void resizeAxes(RECT rect, RECT selection, Graph& graph) {
	normalizeRect(selection);
	DoublePoint start, end;
	start = pointToGraphPoint(selection.left, selection.top, rect, graph);
	end = pointToGraphPoint(selection.right, selection.bottom, rect, graph);
	graph.setLeftBorder(start.x);
	graph.setTopBorder(start.y);
	graph.setRightBorder(end.x);
	graph.setBottomBorder(end.y);
}

POINT getOriginAtWindow(RECT rect, Graph& graph, int scaleSize) {
	POINT origin = graphPointToPoint(0, 0, rect, graph);
	if (origin.y < scaleSize || origin.y > rect.bottom - scaleSize) {
		origin.y = scaleSize;
	}
	if (origin.x < scaleSize || origin.x > rect.right - scaleSize) {
		origin.x = scaleSize;
	}
	return origin;
}

POINT graphPointToPoint(double x, double y, RECT rect, Graph& graph) {
	POINT point;
	point.x = (rect.right / (graph.getRightBorder() - graph.getLeftBorder())) * (x - graph.getLeftBorder());
	point.y = (rect.bottom / (graph.getBottomBorder() - graph.getTopBorder())) * (graph.getBottomBorder() - y);
	return point;
}

DoublePoint pointToGraphPoint(int x, int y, RECT rect, Graph& graph) {
	DoublePoint graphpoint;
	graphpoint.x = graph.getLeftBorder() +
		((graph.getRightBorder() - graph.getLeftBorder()) / ((double)rect.right)) * x;
	graphpoint.y = graph.getBottomBorder() -
		((graph.getBottomBorder() - graph.getTopBorder()) / ((double)rect.bottom)) * y;
	return graphpoint;
}

