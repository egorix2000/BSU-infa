#pragma once
#include <vector>

class Graph {
private:
	std::vector<int> params_;
	double leftBorder_;
	double topBorder_;
	double rightBorder_;
	double bottomBorder_;
	double (*func_)(std::vector<int>, double);
public:
	Graph();
	double getLeftBorder();
	double getRightBorder();
	double getTopBorder();
	double getBottomBorder();
	std::vector<int> getParams();
	void setLeftBorder(double leftBorder);
	void setRightBorder(double rightBorder);
	void setTopBorder(double topBorder);
	void setBottomBorder(double bottomBorder);
	void setFunc(double (*func)(std::vector<int>, double));
	void setParams(std::vector<int> params);
	double getValue(double x);
};

