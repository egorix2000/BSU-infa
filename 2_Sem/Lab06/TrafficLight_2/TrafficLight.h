#pragma once
#include <vector>
#include "Light.h"

class TrafficLight
{
private:
	std::vector<Light*> lights_;
	int timeFlicker_;
	int currentColor_;
	bool isMainColor_;
public:
	TrafficLight(std::vector<Light*> lights, int timeFlicker);
	TrafficLight& switchColor();
	int getTimeFlicker() const;
	Light& getCurrentLight() const;
	bool getIsMainColor() const;
	Light& operator [](int index) const;
	TrafficLight& switchIsMainColor();
	void setIsMainColor(bool isMainColor);
	std::vector<Light*>& getLights();
	~TrafficLight();
};

