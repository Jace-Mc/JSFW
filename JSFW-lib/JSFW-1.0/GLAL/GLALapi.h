/************************************
 * Welcome to GLAL, 
 * Or Graphics Library Abstraction Layer.
 * 
 * NOTE:
 * It is used to configure JSFW library for different OSes for simplicity.
 * 
 * GLAL works together with JSFW, for eazyness of coding, a distributing it to different operating systems.
 * 
 * For LINUX:
 *     X11,
 * For MACOS:
 *     Cocoa
 * 
 * DEPENDENCIES:
 * X11 ~ CREDITS: xorg.freedesktop.org
 * Cocoa ~ CREDITS: https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/CocoaFundamentals/WhatIsCocoa/WhatIsCocoa.html
 * 
 * LICENSE: zlib/libpng
 * Copyright (c) 2026 Jace McCartney
 *
 * This software is provided ‘as-is’, without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 * 
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 * 
 *      1. The origin of this software must not be misrepresented; you must not
 *      claim that you wrote the original software. If you use this software
 *      in a product, an acknowledgment in the product documentation would be
 *      appreciated but is not required.
 * 
 *      2. Altered source versions must be plainly marked as such, and must not be
 *      misrepresented as being the original software.
 *
 *      3. This notice may not be removed or altered from any source
 *      distribution.
 */
# if! defined(GLAL_API_H__)
#   define GLAL_API_H__

# if defined(__cplusplus)
    extern "C" {
# endif

# if defined(_STDBOOL_H)
#   error stdbool.h is already included.
# endif

# if defined(__cplusplus)
#   include <cstdbool>
# else
#   include <stdbool.h>
# endif

# if! defined(func)
#   define func void
# endif

# if defined(__linux__)

# if! defined(XALAPI)
#   define XALAPI
# endif

# define XAL_VERSION_MAJOR 1 // The Major Version of XAL, expands to: 1
# define XAL_VERSION_MINOR 0 // The Minor Version of XAL, expands to: 0

/*!
 * The XAL struct,
 * It stores Window and Graphics Related functions,
 * for X11 of course.
 * \param struct XAL
 */
typedef struct XAL XAL;

/*! 
 * The X11Color struct,
 * You can set a Background color,
 * and RGBA values.
 * \param struct X11Color 
 */
typedef struct X11Color 
{
    unsigned long BGColor; // Its a unsigned long because of X11.
} X11Color;

/*!
 * The X11InputEvent enum.
 * 
 * This stores X11 Input Event types.
 * \param enum X11InputEvent
 */
typedef enum X11InputEvent
{
    NO_X11_EVENT = 0x0003, // No Event Recieved.
    X11_QUIT_EVENT = 0x0006, // Window interrupted by user (closed).
    X11_KEYPRESSED_EVENT = 0x0009, // Key Was Pressed.
    X11_KEYRELEASED_EVENT = 0x00012, // Key Was Released.
    X11_MOUSE_EVENT = 0x00015 // Mouse was moved.
} X11InputEvent;

/*!
 * The X11Event struct.
 * 
 * Stores events that happen in the window.
 * \param struct X11Event
 */
typedef struct X11Event 
{
    X11InputEvent type;
} X11Event;

// Stores the A Macro that holds values, needed for a struct in here.
// For example: COLOR_BLACK, expands to: MACRO(<Struct Name>) { <Values> }
# if! defined(MACRO)
#   define MACRO(Type) (Type)
# endif

// A static cast macro
# if defined(__cplusplus)
#   define static_cast(type, express) \
        static_cast<type, express>
# else
#   define static_cast(type, express) (type)(express)
# endif

// Since X11 Uses Hex Values for the Colors, so for simplicity. So, I had to Store them in Macro.
// The color names are self - explanatory of the type of the color.
#define COLOR_DARK_CYAN MACRO(X11Color) { 0x008B8B } 
#define COLOR_BLACK MACRO(X11Color) { 000000 }

XALAPI XAL * CreateX11Window(int width, int height, const char* title, int window_pos_X, int window_pos_Y, X11Color color); // Creates a X11 Window With a postion, a title, a width and height, and a Background Color.
XALAPI XAL * InitX11Display(const char* InitStyle, const char* SpecialInfo); // Initializes the X11 display.
XALAPI func CloseX11(void); // Closes X11.
XALAPI func DisplayX11Window(void); // Displays X11 Window.
XALAPI int PollX11WindowEvents(X11Event* event_holder); // Polls X11 Window Events.
XALAPI int X11WindowClosed(void); // Checks if X11 Window Closed.

# define XAL_INIT_VIDEO "$$@ *INIT* $$@ *X11* $$@ @!ENDOFSTRING[(*(void*(0)))]" // Just a Bunch of random text.

# endif // if defined __linux__

# if defined(__APPLE__)

// Not configured yet...

# endif // if defined __APPLE__

# if defined(__cplusplus)
   }
# endif

# endif // GLAL_API_H__