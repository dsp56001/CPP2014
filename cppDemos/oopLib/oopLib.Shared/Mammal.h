/* oopLib */

#include "pch.h"

namespace oopLib
{
	class Mammal
	{
	public:
		Mammal();
		~Mammal();

		int Weight;
		std::string Name;

		virtual std::string About();
	};
}