#pragma once

#include "../ECS/ECS.h"

class Entity
{
public:

	Entity()
	{
		for (int i = 0; i < MAX_COMPONENTS; i++)
		{
			this->componentBitset[i] = false;
			this->componentList[i] = nullptr;
		}
	}

	virtual ~Entity() = default;

	template<typename T>
	inline void AddComponent(T* component)
	{
		this->componentBitset[GetComponentTypeID<T>()] = true;
		this->componentList[GetComponentTypeID<T>()] = component;

		component->entity = this;
	}

	template<typename T>
	inline void DeleteComponent()
	{
		this->componentBitset[GetComponentTypeID<T>()] = false;
		this->componentList[GetComponentTypeID<T>()] = nullptr;
	}

	template<typename T>
	inline T* GetComponent() const
	{
		return this->componentList[GetComponentTypeID<T>()];
	}

private:

	ComponentBitset componentBitset;
	ComponentList componentList;
};