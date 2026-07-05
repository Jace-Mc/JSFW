#include <JSFW/jsfw1.h>
#include <stdio.h>

JSFWvec2 pos = { 0, 0 };

int main()
{
    JSFWinit();
    JSFWwindow* window = CreateNewWindow(400, 400, "My JFW App", pos);
        
    while (!JSFWwindowHasClosed(window))
    {
        JSFWpollEvents();
        JSFWdisplayWindow(window);
    }

    JSFWend();
    return 0;
}