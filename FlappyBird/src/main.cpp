#include <iostream>
#include <tyrant.h>
#include <SFML/Graphics.hpp>
#include <Application.h>
int main()
{
	ty::Application app{1024,768, "test app"};
	app.Run();
	
	return 0;
}