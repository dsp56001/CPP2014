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
	CDog *  milo = new CDog();
	milo->name = "milo";
	milo->age = 2;

	aboutCDog(*milo);
	
	CDog * milo2 = milo;
	aboutCDog(*milo2);
	//delete milo;		//try deleting the pointer here!!! ops
	aboutCDog(*milo2);
	
	//unique pointer
	unique_ptr<CDog> uspot(new CDog());
	
	
	//shared pointer
	shared_ptr<CDog> rover (new CDog());
	rover->name = "milo";
	rover->age = 2;
	
	aboutCDog(*rover);


	cin.get();

	return 0;
}

void aboutCDog(const CDog& dog)
{
	cout << dog.name.c_str() << " is " << dog.age << " years old." << endl;
}

