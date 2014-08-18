/* oopLib */

#include "oopLib.h"
#include "Mammal.h"

namespace oopLib
{ 
	class Dog :
		public Mammal
	{
	public:
		Dog();
		Dog(std::string name);
		~Dog();
		virtual std::string Bark();
		std::string About() override;
		std::string BarkSound;

		int GetDogCount();
	protected:
		int age;
	};
}