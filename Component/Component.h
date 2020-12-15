#pragma once

class Entity;

class Component
{
public:

	Component() = default;
	virtual ~Component() = default;

	virtual inline bool Initialize()
	{
		return true;
	}

	Entity* entity;

private:

};