#pragma once
#include "Window.h"
#include "Timer.h"

class App
{
public:
	App(); // Constructor

	int Go();
private:
	void DoFrame(); // Logic for each frame
private:
	Window wnd;
	Timer timer;
};