#include "GreenLight.h"

GreenLight::GreenLight(int time) : Light(time) {
	type_ = GREEN;
	mainColor_ = RGB(0, 255, 0);
	darkColor_ = RGB(10, 135, 10);
}
