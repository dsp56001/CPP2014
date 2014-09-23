// CPPConsoleApplicationDogFromLib.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../oopLib/oopLib.Shared/Dog.h"
#include <memory>

using namespace std;
using namespace oopLib;

int _tmain(int argc, _TCHAR* argv[])
{
	Dog * d = new Dog();
	std::shared_ptr<Dog> milo(new Dog("Milo"));

	std::cout << d->Bark() << std::endl;
	std::cout << milo->Bark() << std::endl;
	
	return 0;
}

