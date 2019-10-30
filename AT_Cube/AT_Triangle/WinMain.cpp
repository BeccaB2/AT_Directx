//#include <Windows.h>
//#include <string>
//#include <sstream>
//#include "Window.h"
#include "App.h"

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR	  lpCmdLine,
	int       nCmdShow )
{
	try {

		return App{}.Go();
	}
	catch (const Exception& e)
	{
		MessageBox(nullptr, e.what(), e.GetType(), MB_OK | MB_ICONEXCLAMATION);
	}
	catch (const std::exception& e)
	{
		MessageBox(nullptr, e.what(), "Standard Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	catch (...)
	{
		MessageBox(nullptr, "No details available", "Unknown Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	return -1;
}
		// INIITAL TESTING 
		//Window wnd(800, 600, "Triangle window!");

		//MSG msg;
		//BOOL getResult;

		//while ((getResult = GetMessage(&msg, nullptr, 0, 0)) > 0) 
		//{
		//	TranslateMessage(&msg); 
		//	DispatchMessage(&msg);
		//}

		//if (getResult == -1)
		//{
		//	return -1;
		//}

		//return msg.wParam;
/////
		//const auto pClassName = "DirectXTriangle";

		// Create window class
		//WNDCLASSEX wc = {0}; 
		//wc.cbSize = sizeof(wc); 
		//wc.style = CS_OWNDC; 
		//wc.lpfnWndProc = WndProc; 
		//wc.cbClsExtra = 0;
		//wc.cbWndExtra = 0;
		//wc.hInstance = hInstance;
		//wc.hIcon = nullptr;
		//wc.hCursor = nullptr;
		//wc.hbrBackground = nullptr; 
		//wc.lpszMenuName = nullptr; 
		//wc.lpszClassName = pClassName; 
		//wc.hIconSm = nullptr;

		//RegisterClassEx(&wc); 

		//HWND hWnd = CreateWindowEx(
		//	0, pClassName,
		//	"Window Test",
		//	WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU | WS_MAXIMIZEBOX,
		//	200, 200, 640, 480,
		//	nullptr, nullptr, hInstance, nullptr
		//);

		//ShowWindow(hWnd, SW_SHOW);

//// Custom windows procedure - parameters handle to an individual window (hWnd), the message ID (msg) and additional data that relates to the messages (l/w param)
		//LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
		//{
		//	switch (msg)
		//	{
		//	case WM_CLOSE: 
		//		PostQuitMessage(10);
		//		break;
		//	case WM_KEYDOWN: // On key press - can be used to trigger actions/events
		//		if (wParam == 'F') // In this instance wParam is the key pressed
		//		{
		//			SetWindowText(hWnd, "RESPECT GIVEN");
		//		}
		//		break; 
		//	case WM_KEYUP: // On key release
		//		if (wParam == 'F')
		//		{
		//			SetWindowText(hWnd,"RESPECT REVOKED");
		//		}
		//		break;
		//
		//	case WM_CHAR: // Used for specific keys that can be represented by text - Can handle upper/lower case - usually used for inputting/outputting text
		//		{
		//			static std::string title;
		//			title.push_back((char)wParam); // Adds characters to the end of the string - enables typing
		//			SetWindowText(hWnd, title.c_str()); // Changes the window text
		//		}
		//		break;
		//	case WM_LBUTTONDOWN:
		//		{
		//			const POINTS pt = MAKEPOINTS(lParam); // Plots points
		//			std::ostringstream oss;
		//			oss << "(" << pt.x << "," << pt.y << ")";
		//			SetWindowText(hWnd, oss.str().c_str()); // Sets window title to the coordinates of the mouse when LMB is pressed
		//		}
		//		break;
		//	//}
		//
		//	//return DefWindowProc(hWnd, msg, wParam, lParam);
		//}