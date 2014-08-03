// CPPConsoleApplicationCLRHello.cpp : main project file.

#include "stdafx.h"

using namespace System;

int main(array<System::String ^> ^args)
{
    Console::WriteLine(L"Hello World");
	Console::ReadKey();
	Console::Write(L"What is yout name?");
	String^ name = Console::ReadLine();
	Console::WriteLine(String::Format("Hello {0}", name));
	Console::ReadKey();
    return 0;
}
