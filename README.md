# Welcome to JSFW.
<p style="font-size: 24px;">
Aka Jace's Simple Framework.
A Simple Cross - Platform Graphics Framework.
</p>

# Dependencies: All are included.
[![DEPS](https://img.shields.io/badge/X11-Linux-orange)](https://www.x.org/XorgFoundation/)
[![DEPS](https://img.shields.io/badge/Cocoa-MacOS-orange)](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/CocoaFundamentals/WhatIsCocoa/WhatIsCocoa.html)

<h1> X11 </h1>
<p style="font-size: 24px;">
The Graphics Library used by Unix and Unix  - like systems.
</p>

<h1> Cocoa </h1>
<p style="font-size: 24px;">
The Graphics System used by Apple devices.
</p>

<h1> Licenses </h1>
<p style="font-size: 24px;">
Registered under the zlib/libpng license.

Other Licenses located in the LICENSES.md file.

</p1>

# Some Test Code 
```c
#include <JSFW/jsfw1.h>
#include <stdio.h>

JSFWvec2 pos = { 0, 0 };

int main()
{
    if (!JSFWinit()) return -1;
    JSFWwindow* window = CreateNewWindow(400, 400, "My JFW App", pos);
        
    while (!JSFWwindowHasClosed(window))
    {
        JSFWpollEvents();
        JSFWdisplayWindow(window);
    }

    JSFWend();
    return 0;
}
```

# JSFW functions.
```c
int JSFWinit(void); 
JSFWwindow * CreateNewWindow(int width, int height, const char* title, JSFWvec2 pos); 
void JSFWdisplayWindow(JSFWwindow* window); 
int JSFWpollEvents(void);
void JSFWend(void);
int JSFWwindowHasClosed(JSFWwindow* window);
```
# Use of Any AI.
<p>
    Any US of A.I. is not allowed in any shape or form.
    All documentation are in a HOWTO.md file.
</p>
