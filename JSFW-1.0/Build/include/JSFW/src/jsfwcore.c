#include <JSFW/jsfw1.h>
#include <GLAL/GLALapi.h>

#ifdef __linux__

XAL* disp;
XAL* win;

int JSFWinit(void)
{
    disp = InitX11Display(XAL_INIT_VIDEO, 0);
    return 0;
}

JSFWwindow * CreateNewWindow(int width, int height, const char* title, JSFWvec2 pos)
{
    win = CreateX11Window(width, height, title, pos.x, pos.y, COLOR_BLACK); // By default the window background color is black.
    return 0;
}

void JSFWdisplayWindow(JSFWwindow* window)
{
    DisplayX11Window();
}

void JSFWend(void) 
{
    CloseX11();
}

int JSFWwindowHasClosed(JSFWwindow* window)
{
    return X11WindowClosed();
}

int JSFWpollEvents(void)
{
    X11Event e;
    while (PollX11WindowEvents(&e))
        if (e.type == X11_QUIT_EVENT) return true;
}

#elif __APPLE__

// Not configured yet...

#endif