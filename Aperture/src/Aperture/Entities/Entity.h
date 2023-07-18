#pragma once

#include "aepch.h"
#include "../Core.h"
#include "../Components/component.h"

namespace Aperture
{

	class AE_API Entity
	{
	public: 
		std::shared_ptr<PositionComponent> cPosition;
		std::shared_ptr<NameComponent> cName; 

		std::string ToString() const 
		{
			std::stringstream ss;
			ss << "Entity " << cName->name;
			ss << " Position " << cPosition->x << "," << cPosition->y;
			return ss.str();
		}
	};

	inline std::ostream& operator<<(std::ostream& os, const Entity& e)
	{
		return os << e.ToString();
	}
}
