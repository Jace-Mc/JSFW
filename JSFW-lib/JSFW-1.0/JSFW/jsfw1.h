/********************
 * Welcome to JSFW, a simple cross - platform graphics Framework.
 * 
 * DEPENDENCIES:
 * GLAL ~ for communcation with the operating systems.
 * 
 * LICENSE:
 * Look a LICENSE.md
 */
#ifndef JSFW1_H__
#   define JSFW1_H__

#ifdef __cplusplus
    extern "C" {
#endif

typedef unsigned int int32;
typedef signed int Uint32;

/*!
 * The struct JFWvec2.
 * 
 * This hold a vector with two (2) attributes (x, y).
 * \param struct JFWvec2
 */
typedef struct JSFWvec2 
{
    int32 x;
    int32 y;
} JSFWvec2;

/*!
 * The struct JFWwindow.
 * 
 * This holds all window related functions for JFW.
 * \param struct JFWwindow
 */
typedef struct JSFWwindow JSFWwindow;

// initializes JFW and the X11 context.
int JSFWinit(void);

// JFWwindow function: CreateNewWindow(int width, int height, const char* title, JFWvec2 pos).
JSFWwindow * CreateNewWindow(int width, int height, const char* title, JSFWvec2 pos);

// Displays Window.
void JSFWdisplayWindow(JSFWwindow* window);

// Polls Important events like allowing the window to close.
int JSFWpollEvents(void);

// Ends JFW context Loop.
void JSFWend(void);

// Checks if JFWwindow has Closed.
int JFWwindowHasClosed(JSFWwindow* window);

#ifdef __cplusplus
    }
#endif
#endif
