#include <GLAL/GLALapi.h>
#include <stdio.h>

int main()
{
    XAL* root = initX11Display(XAL_INIT_VIDEO, 0);
    XAL* window = CreateX11Window(400, 400, "My XAL Application", 100, 200, COLOR_BLACK);

    while (!X11WindowClosed())
    {
        X11Event e;
        while (PollX11WindowEvents(&e))
        {
            if (e.type == X11_MOUSE_EVENT)
            {
                return true;
            }
        }

        DisplayX11Window();
    }
    
    CloseX11();
    return 0;
}