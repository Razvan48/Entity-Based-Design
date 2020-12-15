#pragma once

#include <bitset>
#include <array>

class Entity;
class Component;

using ComponentTypeID = int;

inline ComponentTypeID GetComponentID()
{
	static ComponentTypeID lastID = 0;
	return lastID++;
}

template<typename T>
inline ComponentTypeID GetComponentTypeID()
{
	static const ComponentTypeID typeID = GetComponentID();
	return typeID;
}

const int MAX_ENTITIES = 5000;
const int MAX_COMPONENTS = 32;

using ComponentBitset = std::bitset<MAX_COMPONENTS>;
using ComponentList = std::array<Component*, MAX_COMPONENTS>;

