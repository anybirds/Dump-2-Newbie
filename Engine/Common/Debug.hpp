#pragma once

/*
DEBUG macros enable compile-time choice of logging messages.
Per-file debugging can be done by turning on/off #define DEBUG.
Per-module debugging can be done by turning on/off #define DEBUG_[MODULE].

Example

#ifdef DEBUG_Core
#define DEBUG
#endif
...
#ifdef DEBUG
// log messages
#endif
*/

#define DEBUG_Core
#define DEBUG_GRAPHICS
#define DEBUG_INTERACTION
#define DEBUG_PHYSICS
