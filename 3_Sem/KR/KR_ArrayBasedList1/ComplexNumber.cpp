#include "ComplexNumber.h"

ComplexNumber::ComplexNumber() {
	re_ = 0;
	im_ = 0;
}

ComplexNumber::ComplexNumber(double re, double im) {
	re_ = re;
	im_ = im;
}

double ComplexNumber::getRe() {
	return re_;
}

double ComplexNumber::getIm() {
	return im_;
}

void ComplexNumber::setRe(double re) {
	re_ = re;
}

void ComplexNumber::setIm(double im) {
	im_ = im;
}

std::ostream& operator<<(std::ostream& stream, ComplexNumber number) {
	stream << number.getRe();
	if (number.getIm() >= 0) {
		stream << "+";
	}
	stream << number.getIm() << "i";
	return stream;
}