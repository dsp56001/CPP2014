// CPPConsoleApplicationStructPointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <memory>

using namespace std;

struct CDog
{
	std::string name;
	int age;
};

void aboutCDog(const CDog& dog);

class CPPDog
{
public:
	std::string name;
	int age;
	
	//constructor
	CPPDog()      
	{ 
		std::cout << "CPPDog::CPPDog\n"; 
	}
	
	//destructor
	~CPPDog()     
	{ 
		std::cout << "CPPDog::~CPPDog\n"; 
	}

	//method
	void about()	
	{ 
		std::cout << "CPPDog::about\n"; 
	}

	
};

int _tmain(int argc, _TCHAR* argv[])
{
	
	CDog fido;
	fido.name = "fido";
	fido.age = 7;

	aboutCDog(fido); //pass fido

	CDog * roover = new CDog();
	roover->name = "roover";
	roover->age = 4;

	aboutCDog(*roover); //pass roover
	delete roover;		//remember to delete pointer

	//first time with C pointer
	//unique pointer
	CDog *  cmilo = new CDog();
	cmilo->name = "c milo";
	cmilo->age = 2;

	aboutCDog(*cmilo);

	//for scope
	if (true)
	{
		//unique pointer
		CDog *cspot = new CDog();
		cspot = cmilo;

		aboutCDog(*cspot);
		delete cspot;
	}
	//no more spot
	aboutCDog(*cmilo); //cmilo is not fine

	//unique pointer
	unique_ptr<CDog> milo (new CDog());
	milo->name = "milo";
	milo->age = 2;
	
	aboutCDog(*milo);

	//for scope
	if (true)
	{
		//unique pointer
		unique_ptr<CDog> spot(new CDog());
		*spot = *milo;

		aboutCDog(*spot);
	}
	//no more spot
	aboutCDog(*milo); //milo is fine
	


	cin.get();

	return 0;
}

void aboutCDog(const CDog& dog)
{
	cout << dog.name.c_str() << " is " << dog.age << " years old." << endl;
}

