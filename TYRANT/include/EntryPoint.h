#pragma once
#include <Application.h>
extern ty::Application* createApplication();
int main()
{
	ty::Application* app = createApplication();
	if (app)
	{
		app->Run();
	}
	delete app;
	return 0;
}