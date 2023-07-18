#pragma once

#include "aepch.h"
#include "../Core.h"

namespace Aperture
{

	enum class ComponentType
	{
		None = 0, 
		Position, Velocity, Name
	};

	class AE_API Component
	{
	public:
		virtual ComponentType GetComponentType() const = 0;
		virtual std::string ToString() const = 0; 
	};

	class AE_API PositionComponent : public Component
	{
	public:
		float x = 0.0f;
		float y = 0.0f;

		PositionComponent() {}; 
		PositionComponent(int x_in, int y_in)
			:x(x_in), 
			y(y_in)
		{}

		virtual ComponentType GetComponentType() const override
		{
			return ComponentType::Position;
		}

		std::string ToString() const override
		{
			std::stringstream ss; 
			ss << "Position Component: ";
			ss << x << "," << y; 
			return ss.str();
		}	

	};

	class AE_API NameComponent : public Component
	{
	public:
		std::string name = "default";

		NameComponent() {};
		NameComponent(std::string name_in)
			:name(name_in)
		{}


		virtual ComponentType GetComponentType() const override
		{
			return ComponentType::Name;
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Name Componenrt: ";
			ss << name;
			return ss.str();
		}
	};


	inline std::ostream& operator<<(std::ostream& os, const Component& c)
	{
		return os << c.ToString();
	}
}
