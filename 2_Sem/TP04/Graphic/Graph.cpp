#include "Graph.h"

Graph::Graph()
{
	leftBorder_ = 0;
	topBorder_ = 0;
	rightBorder_ = 0;
	bottomBorder_ = 0;
}

double Graph::getLeftBorder()
{
	return leftBorder_;
}

double Graph::getRightBorder()
{
	return rightBorder_;
}

double Graph::getTopBorder()
{
	return topBorder_;
}

double Graph::getBottomBorder()
{
	return bottomBorder_;
}

std::vector<int> Graph::getParams()
{
	return params_;
}

void Graph::setLeftBorder(double leftBorder)
{
	leftBorder_ = leftBorder;
}

void Graph::setRightBorder(double rightBorder)
{
	rightBorder_ = rightBorder;
}

void Graph::setTopBorder(double topBorder)
{
	topBorder_ = topBorder;
}

void Graph::setBottomBorder(double bottomBorder)
{
	bottomBorder_ = bottomBorder;
}

void Graph::setFunc(double(*func)(std::vector<int>, double))
{
	func_ = func;
}

void Graph::setParams(std::vector<int> params)
{
	params_.clear();
	for (std::vector<int>::iterator i = params.begin(); i != params.end(); i++) {
		params_.push_back(*i);
	}
}

double Graph::getValue(double x) {
	return func_(params_, x);
}