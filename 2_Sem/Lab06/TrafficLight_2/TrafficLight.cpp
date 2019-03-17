#include "TrafficLight.h"
#include "LightFactory.h"


TrafficLight::TrafficLight(std::vector<Light*> lights, int timeFlicker) {
	for (std::vector<Light*>::iterator i = lights.begin(); i != lights.end(); i++) {
		lights_.push_back(&(LightFactory::createLight(*(*i))));
	}
	isMainColor_ = true;
	timeFlicker_ = timeFlicker;
	currentColor_ = 0;
}

TrafficLight & TrafficLight::switchColor() {
	currentColor_++;
	currentColor_ %= lights_.size();
	return *this;
}

int TrafficLight::getTimeFlicker() const
{
	return timeFlicker_;
}

Light& TrafficLight::getCurrentLight() const
{
	return *lights_[currentColor_];
}

bool TrafficLight::getIsMainColor() const
{
	return isMainColor_;
}

Light & TrafficLight::operator[](int index) const
{
	return *lights_[index];
}

TrafficLight & TrafficLight::switchIsMainColor()
{
	isMainColor_ = !isMainColor_;
	return *this;
}

void TrafficLight::setIsMainColor(bool isMainColor)
{
	isMainColor_ = isMainColor;
}

std::vector<Light*>& TrafficLight::getLights()
{
	return lights_;
}

TrafficLight::~TrafficLight() 
{
	for (std::vector<Light*>::iterator i = lights_.begin(); i != lights_.end(); i++) {
		delete *i;
	}
}
