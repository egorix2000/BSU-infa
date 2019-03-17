#pragma once
#include "Light.h"
#include "RedLight.h"
#include "YellowLight.h"
#include "GreenLight.h"

class LightFactory {
public:
	static Light& createLight(const Light& light);
};

Light& LightFactory::createLight(const Light& light) {
	Light* result = nullptr;
	switch (light.getType()) {
	case RED:
		result = new RedLight(light.getTime());
		break;
	case YELLOW:
		result = new YellowLight(light.getTime());
		break;
	case GREEN:
		result = new GreenLight(light.getTime());
		break;
	}
	return *result;
}