#include <iostream>
#include <tyrant.h>
#include <SFML/Graphics.hpp>
#include <Application.h>
#include <Level.h>
#include "FlappyBirdApp.h"
#include <EntryPoint.h>
#include "MainLevel.h"
ty::Application* createApplication()
{
	FlappyBirdApp* app = new FlappyBirdApp();
	app->LoadLevel(new MainLevel(app));
	return app;
}