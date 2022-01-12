#pragma once
#include <EntryPoint.h> 
#include <iostream>
#include <string>


int main(int argc, char** argv) 
{
	Application* app = CreateApplication();
	app->OnPreload();
	app->Init();
	{
		std::string args = "";
		if (argc == 2)
			args = std::string(argv[1]);
		app->OnStart(args);
	}
	app->Run();
	delete app;
}

