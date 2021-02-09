#include <iostream>
#include <tyrant.h>
#include <SFML/Graphics.hpp>
#include <Application.h>
#include <Level.h>
int main()
{
	ty::Application* app= new ty::Application{1024,768, "test app"};
	app->LoadLevel(new ty::Level(app));
	app->Run();
	delete app;
	return 0;
}