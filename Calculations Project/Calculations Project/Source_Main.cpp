#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include <texture.h>


#include <math3d.h>
#include "Shape.h"
#include "Collision_Data.h"
#include "Collision_Shpere.h"


#include <iostream>



HDC			hDC = NULL;		// Private GDI Device Context
HGLRC		hRC = NULL;		// Permanent Rendering Cntext
HWND		hWnd = NULL;		// Holds Our Window Handle
HINSTANCE	hInstance;		// Holds The Instance Of The Application

bool	keys[256];			// Array Used For The Keyboard Routine
bool	active = TRUE;		// Window Active Flag Set To TRUE By Default
bool	fullscreen = FALSE;	// Fullscreen Flag Set To Fullscreen Mode By Default

LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc

GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height == 0)										// Prevent A Divide By Zero By
	{
		height = 1;										// Making Height Equal One
	}

	glViewport(0, 0, width, height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

														// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 1000.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}

//TODO:The paramitives for SkyBox
int Up;
int Down;
int Left;
int Right;
int Front;
int Back;



int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
{
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

	//TODO: Our Enable
	glEnable(GL_TEXTURE_2D);


	//TODO:Set the Value for the photo of SkyBox
	Up = LoadTexture("top.bmp",255);
	Down = LoadTexture("grass.bmp",255);
	Left = LoadTexture("left.bmp",255);
	Right = LoadTexture("right.bmp",255);
	Front = LoadTexture("front.bmp",255);
	Back = LoadTexture("back.bmp",255);

	return TRUE;										// Initialization Went OK
}



//TODO: For The camera
double movX, movY, movZ;
double lX, lY;
void Camera()
{
	gluLookAt(movX, movY, movZ, lX, lY, -5, 0, 1, 0);
	if (keys['D'])
		movX += 0.01;
	if (keys['A'])
		movX -= 0.01;
	if (keys['W'])
		movY += 0.01;
	if (keys['S'])
		movY -= 0.01;
	if (keys['Z'])
		movZ += 0.01;
	if (keys['X'])
		movZ -= 0.01;
	if (keys[VK_LEFT])
		lX += 0.01;
	if (keys[VK_RIGHT])
		lX -= 0.01;
	if (keys[VK_UP])
		lY += 0.01;
	if (keys[VK_DOWN])
		lY -= 0.01;
}


//TODO:To draw SkyBox

void skybox()
{
	//TODO:The Front Face
	glBindTexture(GL_TEXTURE_2D, Front);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-200, -200, -200);
	glTexCoord2d(1, 0);
	glVertex3d(200, -200, -200);
	glTexCoord2d(1, 1);
	glVertex3d(200, 200, -200);
	glTexCoord2d(0, 1);
	glVertex3d(-200, 200, -200);
	glEnd();

	//TODO:The Back Face
	glBindTexture(GL_TEXTURE_2D, Back);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-200, -200, 200);
	glTexCoord2d(1, 0);
	glVertex3d(200, -200, 200);
	glTexCoord2d(1, 1);
	glVertex3d(200, 200, 200);
	glTexCoord2d(0, 1);
	glVertex3d(-200, 200, 200);
	glEnd();

	//TODO:The Left Face
	glBindTexture(GL_TEXTURE_2D, Left);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-200, -200, 200);
	glTexCoord2d(1, 0);
	glVertex3d(-200, -200, -200);
	glTexCoord2d(1, 1);
	glVertex3d(-200, 200, -200);
	glTexCoord2d(0, 1);
	glVertex3d(-200, 200, 200);
	glEnd();

	//TODO:The Right Face
	glBindTexture(GL_TEXTURE_2D, Right);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3d(200, -200, 200);
	glTexCoord2d(0, 0);
	glVertex3d(200, -200, -200);
	glTexCoord2d(0, 1);
	glVertex3d(200, 200, -200);
	glTexCoord2d(1, 1);
	glVertex3d(200, 200, 200);
	glEnd();

	//TODO:The Top Face
	glBindTexture(GL_TEXTURE_2D, Up);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-200, 200, -200);
	glTexCoord2d(1, 0);
	glVertex3d(200, 200, -200);
	glTexCoord2d(1, 1);
	glVertex3d(200, 200, 200);
	glTexCoord2d(0, 1);
	glVertex3d(-200, 200, 200);
	glEnd();

	//TODO:The Down Face
	glBindTexture(GL_TEXTURE_2D, Down);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-200, -50, -200);
	glTexCoord2d(1, 0);
	glVertex3d(200, -50, -200);
	glTexCoord2d(1, 1);
	glVertex3d(200, -50, 200);
	glTexCoord2d(0, 1);
	glVertex3d(-200, -50, 200);
	glEnd();



}





GLUquadric *NewQuadric = gluNewQuadric();






Shpere s1(NewQuadric, 1.0, 32, 32, 0.4, 0.4, 0.4, 5.0, 5.0, 5.0, 5.0, Vector3f(0.0f, 0.0f, 0.0f));
Shpere s2(NewQuadric, 1.0, 32, 32, 0.4, 0.4, 0.4, 5.0, 5.0, 5.0, 5.0, Vector3f(0.0f, 3.0f, 0.0f));
Shpere s3(NewQuadric, 1.0, 32, 32, 0.4, 0.4, 0.4, 5.0, 5.0, 5.0, 5.0, Vector3f(0.0f, 0.0f, 10.0f));
Shpere s4(NewQuadric, 1.0, 32, 32, 0.4, 0.4, 0.4, 5.0, 5.0, 5.0, 5.0, Vector3f(1.0f, 0.0f, 0.0f));


Collision_Data c1(0.0f, false);
Collision_Data c2(0.0f, false);
Collision_Data c3(0.0f,false);



bool JustOne = true;
void JustPrint() {

	


}
//float A = 0.0f;
float Acce =0.0f;

int DrawGLScene(GLvoid)									// Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslated(0,0,-15);
	Camera();

	//TODO:Objects

	//Draw Quad
	//  Quad q1(1,1,1,0.5,0.5,0.5,4);
     // q1.draw_2D(1,1);

	Collision_Data c1 = s1.Collision(s2);
	Collision_Data c2 = s1.Collision(s3);
	Collision_Data c3 = s1.Collision(s4);






	//Shpere s1(NewQuadric, 2, 32, 32, 0.4, 0.4, 0.4,5,5,5,5);
	//glTranslated(A, 0, 0);
	//s1.Move_Shape(0, 10, 10, 5);

	//s1.Move_Shape(2, 10, 20, 2);
	//Draw Cube
	/*Cube c1(NewQuadric,2,2,2,32,32,1,1,1);
	c1.Draw_Cube();*/


	//        HERE WHERE WE START DRAWING :D
	skybox();


	// to study the collision
	bool Collision_C1 = c1.getisCollision();
	bool Collision_C2 = c2.getisCollision();
	bool Collision_C3 = c3.getisCollision();


	if (JustOne == true) {
		//JustPrint();
		std::cout << "The shpere is colliusion ?" << c1.getisCollision() << "The Distance: " << c1.getDistance() <<"Raduis"<<s1.getRadius()<<std::endl;
		std::cout << "The shpere is colliusion ?" << c2.getisCollision() << "The Distance: " << c2.getDistance() << std::endl;
		std::cout << "The shpere is colliusion ?" << c3.getisCollision() << "The Distance: " << c3.getDistance() << std::endl;
	}
	JustOne = false; // to print the previous thing just one time


	//Draw Shpere
	glPushMatrix();
	{
		s1.Draw_Shpere();
		//s2.Draw_Shpere();
		//s3.Draw_Shpere();
		glPopMatrix();
	}
	glPushMatrix();

	 

	//TODO: to move the shape 
	glPushMatrix();
	{
		if (Collision_C1 == false) {
			glTranslated(Acce, 0, 0);
		}
		s3.Draw_Shpere();
		

	}glPopMatrix();
	//A = A + 0.01;
	Acce += s3.Move_Shape(0.02, 0.02, 0.02);
	

	return TRUE;
}

GLvoid KillGLWindow(GLvoid)								// Properly Kill The Window
{
	if (fullscreen)										// Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL, 0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);								// Show Mouse Pointer
	}

	if (hRC)											// Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL, NULL))					// Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL, "Release Of DC And RC Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC))						// Are We Able To Delete The RC?
		{
			MessageBox(NULL, "Release Rendering Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}
		hRC = NULL;										// Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd, hDC))					// Are We Able To Release The DC
	{
		MessageBox(NULL, "Release Device Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hDC = NULL;										// Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd))					// Are We Able To Destroy The Window?
	{
		MessageBox(NULL, "Could Not Release hWnd.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hWnd = NULL;										// Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL", hInstance))			// Are We Able To Unregister Class
	{
		MessageBox(NULL, "Could Not Unregister Class.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hInstance = NULL;									// Set hInstance To NULL
	}
}

/*	This Code Creates Our OpenGL Window.  Parameters Are:					*
*	title			- Title To Appear At The Top Of The Window				*
*	width			- Width Of The GL Window Or Fullscreen Mode				*
*	height			- Height Of The GL Window Or Fullscreen Mode			*
*	bits			- Number Of Bits To Use For Color (8/16/24/32)			*
*	fullscreenflag	- Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE)	*/

BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
	WNDCLASS	wc;						// Windows Class Structure
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left = (long)0;			// Set Left Value To 0
	WindowRect.right = (long)width;		// Set Right Value To Requested Width
	WindowRect.top = (long)0;				// Set Top Value To 0
	WindowRect.bottom = (long)height;		// Set Bottom Value To Requested Height

	fullscreen = fullscreenflag;			// Set The Global Fullscreen Flag

	hInstance = GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc = (WNDPROC)WndProc;					// WndProc Handles Messages
	wc.cbClsExtra = 0;									// No Extra Window Data
	wc.cbWndExtra = 0;									// No Extra Window Data
	wc.hInstance = hInstance;							// Set The Instance
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground = NULL;									// No Background Required For GL
	wc.lpszMenuName = NULL;									// We Don't Want A Menu
	wc.lpszClassName = "OpenGL";								// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		MessageBox(NULL, "Failed To Register The Window Class.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	if (fullscreen)												// Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth = width;				// Selected Screen Width
		dmScreenSettings.dmPelsHeight = height;				// Selected Screen Height
		dmScreenSettings.dmBitsPerPel = bits;					// Selected Bits Per Pixel
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL, "The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?", "GL template", MB_YESNO | MB_ICONEXCLAMATION) == IDYES)
			{
				fullscreen = FALSE;		// Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL, "Program Will Now Close.", "ERROR", MB_OK | MB_ICONSTOP);
				return FALSE;									// Return FALSE
			}
		}
	}

	if (fullscreen)												// Are We Still In Fullscreen Mode?
	{
		dwExStyle = WS_EX_APPWINDOW;								// Window Extended Style
		dwStyle = WS_POPUP;										// Windows Style
		ShowCursor(FALSE);										// Hide Mouse Pointer
	}
	else
	{
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle = WS_OVERLAPPEDWINDOW;							// Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size

																	// Create The Window
	if (!(hWnd = CreateWindowEx(dwExStyle,							// Extended Style For The Window
		"OpenGL",							// Class Name
		title,								// Window Title
		dwStyle |							// Defined Window Style
		WS_CLIPSIBLINGS |					// Required Window Style
		WS_CLIPCHILDREN,					// Required Window Style
		0, 0,								// Window Position
		WindowRect.right - WindowRect.left,	// Calculate Window Width
		WindowRect.bottom - WindowRect.top,	// Calculate Window Height
		NULL,								// No Parent Window
		NULL,								// No Menu
		hInstance,							// Instance
		NULL)))								// Dont Pass Anything To WM_CREATE
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Window Creation Error.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	static	PIXELFORMATDESCRIPTOR pfd =				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		bits,										// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// 16Bit Z-Buffer (Depth Buffer)  
		0,											// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};

	if (!(hDC = GetDC(hWnd)))							// Did We Get A Device Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Device Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd)))	// Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Find A Suitable PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!SetPixelFormat(hDC, PixelFormat, &pfd))		// Are We Able To Set The Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Set The PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(hRC = wglCreateContext(hDC)))				// Are We Able To Get A Rendering Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!wglMakeCurrent(hDC, hRC))					// Try To Activate The Rendering Context
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Activate The GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	ShowWindow(hWnd, SW_SHOW);						// Show The Window
	SetForegroundWindow(hWnd);						// Slightly Higher Priority
	SetFocus(hWnd);									// Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height);					// Set Up Our Perspective GL Screen

	if (!InitGL())									// Initialize Our Newly Created GL Window
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Initialization Failed.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	return TRUE;									// Success
}

LRESULT CALLBACK WndProc(HWND	hWnd,			// Handle For This Window
	UINT	uMsg,			// Message For This Window
	WPARAM	wParam,			// Additional Message Information
	LPARAM	lParam)			// Additional Message Information
{
	switch (uMsg)									// Check For Windows Messages
	{
	case WM_ACTIVATE:							// Watch For Window Activate Message
	{
		if (!HIWORD(wParam))					// Check Minimization State
		{
			active = TRUE;						// Program Is Active
		}
		else
		{
			active = FALSE;						// Program Is No Longer Active
		}

		return 0;								// Return To The Message Loop
	}

	case WM_SYSCOMMAND:							// Intercept System Commands
	{
		switch (wParam)							// Check System Calls
		{
		case SC_SCREENSAVE:					// Screensaver Trying To Start?
		case SC_MONITORPOWER:				// Monitor Trying To Enter Powersave?
			return 0;							// Prevent From Happening
		}
		break;									// Exit
	}

	case WM_CLOSE:								// Did We Receive A Close Message?
	{
		PostQuitMessage(0);						// Send A Quit Message
		return 0;								// Jump Back
	}

	case WM_KEYDOWN:							// Is A Key Being Held Down?
	{
		keys[wParam] = TRUE;					// If So, Mark It As TRUE
		return 0;								// Jump Back
	}

	case WM_KEYUP:								// Has A Key Been Released?
	{
		keys[wParam] = FALSE;					// If So, Mark It As FALSE
		return 0;								// Jump Back
	}

	case WM_SIZE:								// Resize The OpenGL Window
	{
		ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));  // LoWord=Width, HiWord=Height
		return 0;								// Jump Back
	}
	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE	hInstance,			// Instance
	HINSTANCE	hPrevInstance,		// Previous Instance
	LPSTR		lpCmdLine,			// Command Line Parameters
	int			nCmdShow)			// Window Show State
{
	MSG		msg;									// Windows Message Structure
	BOOL	done = FALSE;								// Bool Variable To Exit Loop

														// Ask The User Which Screen Mode They Prefer
														//if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
	{
		fullscreen = FALSE;							// Windowed Mode
	}

	// Create Our OpenGL Window
	if (!CreateGLWindow("OpenGL template", 640, 480, 16, fullscreen))
	{
		return 0;									// Quit If Window Was Not Created
	}

	while (!done)									// Loop That Runs While done=FALSE
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))	// Is There A Message Waiting?
		{
			if (msg.message == WM_QUIT)				// Have We Received A Quit Message?
			{
				done = TRUE;							// If So done=TRUE
			}
			else									// If Not, Deal With Window Messages
			{
				TranslateMessage(&msg);				// Translate The Message
				DispatchMessage(&msg);				// Dispatch The Message
			}
		}
		else										// If There Are No Messages
		{
			// Draw The Scene.  Watch For ESC Key And Quit Messages From DrawGLScene()
			if (active)								// Program Active?
			{
				if (keys[VK_ESCAPE])				// Was ESC Pressed?
				{
					done = TRUE;						// ESC Signalled A Quit
				}
				else								// Not Time To Quit, Update Screen
				{
					DrawGLScene();					// Draw The Scene
					SwapBuffers(hDC);				// Swap Buffers (Double Buffering)
				}
			}

			if (keys[VK_F1])						// Is F1 Being Pressed?
			{
				keys[VK_F1] = FALSE;					// If So Make Key FALSE
				KillGLWindow();						// Kill Our Current Window
				fullscreen = !fullscreen;				// Toggle Fullscreen / Windowed Mode
														// Recreate Our OpenGL Window
				if (!CreateGLWindow("OpenGL template", 640, 480, 16, fullscreen))
				{
					return 0;						// Quit If Window Was Not Created
				}
			}
		}
	}

	// Shutdown
	KillGLWindow();									// Kill The Window
	return (msg.wParam);							// Exit The Program
}
