#include "stdafx.h"
#include "Basenji.h"
#include <sstream>
#include <iostream>

using namespace std;

Basenji::Basenji() : Basenji("Cheddar")
{
	
}

Basenji::Basenji(std::string name)
{
	Name = Name;
}

Basenji::~Basenji()
{
}

string Basenji::Bark()
{
	return "Basenji's dont ark they howl and growl!";
}
