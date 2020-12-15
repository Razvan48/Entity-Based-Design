#pragma once

#include "../Component/Component.h"

class Transform2DComponent : public Component
{
public:

	Transform2DComponent(double xCenter, double yCenter, double width, double height) : xCenter(xCenter), yCenter(yCenter), width(width), height(height) {};
	~Transform2DComponent() = default;

public:

	double xCenter;
	double yCenter;

	double width;
	double height;

private:

};