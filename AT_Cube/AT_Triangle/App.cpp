#include "App.h"
#include <sstream>
#include <iomanip>

App::App()
	:
	wnd(800, 600, "Cube Window!!") // Creating a window - also destroys when closed
{}

int App::Go()
{
	while (true)
	{
		if (const auto ecode = Window::ProcessMessages())
		{
			return *ecode;
		}

		DoFrame();
	}
}

void App::DoFrame()	
{
	const float c = sin(timer.Peek()) / 2.0f + 0.5f; // Range from 0 - 1

	wnd.Gfx().ClearBuffer(0.2f, 0.8f, c); // Range colour

	wnd.Gfx().DrawTestTriangle(
		timer.Peek(), 
		wnd.mouse.GetPosX() / 400.0f - 1.0f, 
		-wnd.mouse.GetPosY() / 300.0f + 1.0f);

	wnd.Gfx().EndFrame();

	/*const float t = timer.Peek();
	std::ostringstream oss;
	oss << "Time elapsed" << std::setprecision(1) << std::fixed << t << "s";*/
	//wnd.SetTitle(oss.str()); // Display time in seconds as the title
}


// INITIAL CODE
	// Handling messages
	//MSG msg; // Message structure - holds the messages that need to be sent to the window
	//BOOL getResult;

	//while ((getResult = GetMessage(&msg, nullptr, 0, 0)) > 0) // Continuously process messages if not exiting - parameters control which windoes messages come from and enable message filtering
	//{
	//	TranslateMessage(&msg); // Constant pointer to message - translate won't modify the processed message - allows char messages to be translated to screen
	//	DispatchMessage(&msg); // Pass message along to the window

	//	DoFrame();
	//}

	//// Error handling
	//if (getResult == -1)
	//{
	//	throw CHWND_LAST_EXCEPT(); // Getting the message has errored
	//}

	//return msg.wParam; // Exit code