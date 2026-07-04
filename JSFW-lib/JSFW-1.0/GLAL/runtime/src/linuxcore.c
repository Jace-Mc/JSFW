# include <X11/Xlib.h>
# include <stdio.h>
# include <unistd.h>
# include <GLAL/GLALapi.h>

// The Display Object for X11.
Display* display;
// The Window Object.
Window window;
// The Root Window Object.
Window root;
// The Atom Object.
Atom action;

XAL * InitX11Display(const char* InitStyle, const char* SpecialInfo)
{
    display = XOpenDisplay(SpecialInfo); // Opens X11 Display.
    return 0;
}

XAL * CreateX11Window(int width, int height, const char* title, int window_pos_X, int window_pos_Y, X11Color color)
{
    root = XDefaultRootWindow(display); // Creates root Window Object
    window = XCreateSimpleWindow(display, root, window_pos_X, window_pos_Y, width, height, 0, 0, color.BGColor); // Creates Window with, a height, a width, a postion in x, y, and a Background Color.
    XStoreName(display, window, title); // Stores the window title.
    return 0; 
}

func DisplayX11Window(void)
{
    XMapWindow(display, window); // Maps Window.
    XFlush(display); // Flushes Display.

//  for (;;) sleep(1); IDK why... but it's here.
}

func CloseX11(void) 
{
    XDestroyWindow(display, window); // Destroys X11 Window.
    XCloseDisplay(display); // Closes X11 Display.
}

int PollX11WindowEvents(X11Event* event_holder)
{
    if (!XPending(display)) return false; 

    XEvent x11EventHolder;
    XNextEvent(display, &x11EventHolder);

    event_holder->type = NO_X11_EVENT;

    switch (x11EventHolder.type)
    {
        case ClientMessage:
            if ((Atom)x11EventHolder.xclient.data.l[0] == action) event_holder->type = X11_QUIT_EVENT;
        break;

        case KeyPress:
            event_holder->type = X11_KEYPRESSED_EVENT;
        break;

        case KeyRelease:
            event_holder->type = X11_KEYRELEASED_EVENT;
        break;

        case MotionNotify:
            event_holder->type = X11_MOUSE_EVENT;
        break;
    }

    return true;
}

int X11WindowClosed(void)
{
    return false; 
}

