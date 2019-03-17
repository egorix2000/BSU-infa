#include "RedLight.h"

RedLight::RedLight(int time) : Light(time) {
	type_ = RED;
	mainColor_ = RGB(255, 0, 0);
	darkColor_ = RGB(135, 20, 20);
}
