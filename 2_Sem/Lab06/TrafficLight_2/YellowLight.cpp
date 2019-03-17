#include "YellowLight.h"

YellowLight::YellowLight(int time) : Light(time) {
	type_ = YELLOW;
	mainColor_ = RGB(255, 255, 0);
	darkColor_ = RGB(160, 160, 20);
}
