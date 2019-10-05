#pragma once
#include <ostream>

class ComplexNumber
{
	double re_;
	double im_;
public:
	ComplexNumber();
	ComplexNumber(double re, double im);
	double getRe();
	double getIm();
	void setRe(double re);
	void setIm(double im);
	friend std::ostream& operator<<(std::ostream& stream, ComplexNumber number);
};

