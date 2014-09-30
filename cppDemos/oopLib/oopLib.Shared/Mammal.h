/* oopLib */

#include "pch.h"

namespace oopLib
{
	class Mammal
	{
	protected:
		int m_weight;
		std::string m_name;
		Mammal(const std::string&);

	public:
		Mammal();
		~Mammal();

		int getWeight();
		void setWeight(int);

		std::string getName();
		void setName(std::string);
		
		virtual std::string About();
	};
}